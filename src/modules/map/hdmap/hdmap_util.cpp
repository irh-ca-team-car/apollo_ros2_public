#include "modules/map/hdmap/hdmap_util.h"

#include <string>
#include <vector>

#include "absl/strings/str_split.h"
#include "cyber/cyber.h"
#include "modules/map/relative_map/proto/navigation.pb.h"

namespace apollo
{
  namespace hdmap
  {

    namespace
    {

      // Find the first existing file from a list of candidates: "file_a|file_b|...".
      std::string FindFirstExist(const std::string &dir, const std::string &files)
      {
        const std::vector<std::string> candidates = absl::StrSplit(files, '|');
        for (const auto &filename : candidates)
        {
          const std::string file_path = absl::StrCat(FLAGS_map_dir, "/", filename);
          if (cyber::common::PathExists(file_path))
          {
            return file_path;
          }
        }
        AERROR << "No existing file found in " << dir << "/" << files
               << ". Fallback to first candidate as default result.";
        ACHECK(!candidates.empty()) << "Please specify at least one map.";
        return absl::StrCat(FLAGS_map_dir, "/", candidates[0]);
      }

    } // namespace

    std::string BaseMapFile()
    {
      if (FLAGS_use_navigation_mode)
      {
        AWARN << "base_map file is not used when FLAGS_use_navigation_mode is true";
      }
      return FLAGS_test_base_map_filename.empty()
                 ? FindFirstExist(FLAGS_map_dir, FLAGS_base_map_filename)
                 : FindFirstExist(FLAGS_map_dir, FLAGS_test_base_map_filename);
    }

    std::string SimMapFile()
    {
      if (FLAGS_use_navigation_mode)
      {
        AWARN << "sim_map file is not used when FLAGS_use_navigation_mode is true";
      }
      return FindFirstExist(FLAGS_map_dir, FLAGS_sim_map_filename);
    }


    std::string RoutingMapFile()
    {
      if (FLAGS_use_navigation_mode)
      {
        AWARN << "routing_map file is not used when FLAGS_use_navigation_mode is "
                 "true";
      }
      return FindFirstExist(FLAGS_map_dir, FLAGS_routing_map_filename);
    }

    std::unique_ptr<HDMap> CreateMap(const std::string &map_file_path)
    {
      std::unique_ptr<HDMap> hdmap(new HDMap());
      if (hdmap->LoadMapFromFile(map_file_path) != 0)
      {
        AERROR << "Failed to load HDMap " << map_file_path;
        return nullptr;
      }
      AINFO << "Load HDMap success: " << map_file_path;
      return hdmap;
    }

    std::unique_ptr<HDMap> CreateMap(const apollo_msgs::msg::ApollorelativeMapMapMsg &map_msg)
    {
      std::unique_ptr<HDMap> hdmap(new HDMap());
      if (hdmap->LoadMapFromProto(map_msg.hdmap) != 0)
      {
        AERROR << "Failed to load RelativeMap: "
               << map_msg.apolloheader.frameid;
        return nullptr;
      }
      AINFO_EVERY(60000) << "Load HDMap success: ";
      return hdmap;
    }

    std::unique_ptr<HDMap> HDMapUtil::base_map_ = nullptr;
    int32_t HDMapUtil::base_map_seq_ = 0;
    std::mutex HDMapUtil::base_map_mutex_;

    std::unique_ptr<HDMap> HDMapUtil::sim_map_ = nullptr;
    std::mutex HDMapUtil::sim_map_mutex_;

    const HDMap *HDMapUtil::BaseMapPtr(const apollo_msgs::msg::ApollorelativeMapMapMsg &map_msg)
    {
      if (base_map_ != nullptr &&
          base_map_seq_ == map_msg.apolloheader.timestampsec)
      {
        // avoid re-create map in the same cycle.
        return base_map_.get();
      }
      else
      {
        base_map_ = CreateMap(map_msg);
        base_map_seq_ = map_msg.apolloheader.timestampsec;
      }
      return base_map_.get();
    }

    const HDMap *HDMapUtil::BaseMapPtr()
    {
      // TODO(all) Those logics should be removed to planning
      /*if (FLAGS_use_navigation_mode) {
    auto* relative_map = AdapterManager::GetRelativeMap();
    if (!relative_map) {
      AERROR << "RelativeMap adapter is not registered";
      return nullptr;
    }
    if (relative_map->Empty()) {
      AERROR << "RelativeMap is empty";
      return nullptr;
    }
    const auto& latest = relative_map->GetLatestObserved();
    if (base_map_ != nullptr &&
        base_map_seq_ == latest.header().sequence_num()) {
      // avoid re-create map in the same cycle.
      return base_map_.get();
    } else {
      base_map_ = CreateMap(latest);
      base_map_seq_ = latest.header().sequence_num();
    }
  } else*/
      if (base_map_ == nullptr)
      {
        if (base_map_ == nullptr)
        { // Double check.
          base_map_ = CreateMap(BaseMapFile());
        }
      }
      return base_map_.get();
    }


    const HDMap &HDMapUtil::BaseMap()
    {
      CHECK_NOTNULL(BaseMapPtr());
      return *BaseMapPtr();

    }


    const HDMap *HDMapUtil::SimMapPtr()
    {
      if (FLAGS_use_navigation_mode)
      {
        return BaseMapPtr();
      }
      else if (sim_map_ == nullptr)
      {
        if (sim_map_ == nullptr)
        { // Double check.
          sim_map_ = CreateMap(SimMapFile());
        }
      }
      return sim_map_.get();
    }

    const HDMap &HDMapUtil::SimMap()
    {
      CHECK_NOTNULL(SimMapPtr());
      return *(SimMapPtr());
    }

    bool HDMapUtil::ReloadMaps()
    {
      {
        base_map_ = CreateMap(BaseMapFile());
      }
      {
        sim_map_ = CreateMap(SimMapFile());
      }
      return base_map_ != nullptr && sim_map_ != nullptr;
    }

  } // namespace hdmap
} // namespace apollo

