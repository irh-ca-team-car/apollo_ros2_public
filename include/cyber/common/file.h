/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 */

#ifndef CYBER_COMMON_FILE_H_
#define CYBER_COMMON_FILE_H_

#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "cyber/common/log.h"
#include "cyber/cyber.h"
#include "cyber/componentbase.h"
#include "cyber/adapter.h"
#include "cyber/nameof.hpp"
#include "nlohmann/json.hpp"
#ifndef NVVC
#include <filesystem>
#endif
/**
 * @namespace apollo::common::util
 * @brief apollo::common::util
 */
namespace apollo
{
    namespace cyber
    {
        namespace common
        {
            enum ASCIIType
            {
                MODE_HEX,
                MODE_JSON
            };
            // file type: file or directory
            enum FileType
            {
                TYPE_FILE,
                TYPE_DIR
            };
            std::string replaceString(std::string str,
                                      const std::string &replace,
                                      const std::string &with);
            std::string trim(std::string const &source, char const *delims = " \t\r\n");
            /**
             * @brief Parses the content of the file specified by the file_name as ascii
             *        representation of messages, and merges the parsed content to the
             *        proto.
             * @param file_name The name of the file to parse whose content.
             * @param message The proto to carry the parsed content in the specified file.
             * @return If the action is successful.
             */
            template <typename T>
            bool GetProtoFromASCIIFile(const std::string &filename,
                                       T *message)
            {

                std::string file_name = filename;
                apollo::cyber::ComponentBase::instance()->replaceRoot(file_name);
                if (!std::filesystem::exists(file_name))
                    return false;

                std::fstream input(file_name, std::ios::in);
                if (!input.good())
                {
                    AERROR << "Failed to open file " << file_name;
                    return false;
                }
                T t;

                std::string line;
                bool json = false;
                bool config = false;
                std::transform(file_name.begin(), file_name.end(), file_name.begin(), ::toupper);
                json = (file_name.find(".JSON") != std::string::npos);
                config = (file_name.find(".CONFIG") != std::string::npos);
                if (!json && !config)
                {
                    ADEBUG << "Trying to guess ascii type of "<<file_name;
                    std::getline(input, line);
                    if (line != NAMEOF_FULL_TYPE(T))
                    {
                        AERROR << "Incorrectly message type";
                        input.close();
                        return false;
                    }
                    std::getline(input, line);
                }
                else if (json)
                    line = "JS";
                else if (config)
                    line = "CF";
                rclcpp::SerializedMessage m = serialize_msg(t);
                if (line.substr(0, 2) == "0x") //MODE_HEX
                {
                    line = line.substr(2);
                    if (line.length() / 2 != m.size())
                    {
                        AERROR << "Incorrectly formatted hex file for requested message";
                        input.close();
                        return false;
                    }
                    auto ptr = (char *)m.get_rcl_serialized_message().buffer;
                    for (size_t i = 0; i < m.size(); i++)
                    {
                        int val;
                        sscanf(line.c_str(), "%2x", &val);
                        ptr[i] = (uint8_t)val;
                        line = line.substr(2);
                    }
                    //input.read((char *)m.get_rcl_serialized_message().buffer, m.size());
                    *message = deserialize_msg<T>(m);
                    input.close();
                    return true;
                }
                else if (line.substr(0, 2) == "JS") //MODE_JSON
                {
                    std::istreambuf_iterator<char> eos;
                    std::string strtoe(std::istreambuf_iterator<char>(input), eos);
                    try
                    {
                        auto json_object = nlohmann::json::parse(strtoe);
                        if (!json_object.is_discarded())
                        {
                            *message = apollo_msgs::msg::from_json<T>(json_object);
                            input.close();
                            return true;
                        }
                    }
                    catch (nlohmann::json::parse_error &err)
                    {
                        AERROR << err.what();
                    }
                }
                else if (line.substr(0, 2) == "CF") //MODE_CONFIG basic only simple files, no object
                {
                    std::istreambuf_iterator<char> eos;
                    std::string strtoe(std::istreambuf_iterator<char>(input), eos);
                    try
                    {
                        std::istringstream stream(strtoe);
                        nlohmann::json json_object;

                        while (std::getline(stream, line))
                        {
                            if (!line.length())
                                continue;
                            if (line[0] == '#')
                                continue;
                            if (line[0] == ';')
                                continue;

                            auto posEqual = line.find(':');
                            std::string name = trim(line.substr(0, posEqual));
                            auto value = nlohmann::json::parse(trim(line.substr(posEqual + 1)));
                            name = replaceString(name, "_", "");
                            if (json_object.contains(name))
                            {
                                if (json_object[name].is_array())
                                    json_object[name].push_back(value);
                                else
                                {
                                    nlohmann::json arr;
                                    arr.push_back(json_object[name]);
                                    arr.push_back(value);
                                    json_object[name] = arr;
                                }
                            }
                            else
                            {
                                json_object[name] = value;
                            }
                        }
                        ADEBUG << "parsed : " << json_object.dump();
                         if (!json_object.is_discarded())
                        {
                            *message = apollo_msgs::msg::from_json<T>(json_object);
                            input.close();
                            return true;
                        }
                    }
                    catch (nlohmann::json::parse_error &err)
                    {
                        AERROR << err.what();
                    }
                }
                input.close();
                return false;
            }

            /**
             * @brief Sets the content of the file specified by the file_name to be the
             *        binary representation of the input.
             * @param message The proto to output to the specified file.
             * @param file_name The name of the target file to set the content.
             * @return If the action is successful.
             */

            template <typename T>
            inline bool SetProtoToBinaryFile(T message,
                                             const std::string &file_name)
            {
                std::fstream output(file_name,
                                    std::ios::out | std::ios::trunc | std::ios::binary);

                rclcpp::SerializedMessage s = serialize_msg(message);
                auto t = s.get_rcl_serialized_message();
                if (output.is_open())
                {
                    output.write((char *)t.buffer, s.size());
                    output.flush();
                    output.close();
                    return true;
                }
                else
                    return false;
            }
            template <typename T>
            bool SetProtoToBinaryFile(const std::shared_ptr<T> message,
                                      const std::string &file_name)
            {
                return SetProtoToBinaryFile(*message, file_name);
            }
            template <typename T>
            inline bool SetProtoToASCIIFile(T message,
                                            const std::string &file_name, ASCIIType type = ASCIIType::MODE_JSON)
            {
                std::fstream output(file_name,
                                    std::ios::out | std::ios::trunc);

                static rclcpp::Serialization<T> serializer;
                rclcpp::SerializedMessage s = serialize_msg(message);

                output << NAMEOF_FULL_TYPE(T) << std::endl;
                switch (type)
                {
                case MODE_HEX:
                {
                    auto t = s.get_rcl_serialized_message();
                    output << "0x";
                    for (size_t i = 0; i < t.buffer_length; i++)
                    {
                        char buffer[3];
                        snprintf(buffer, 3, "%02x", (int)t.buffer[i]);
                        output << buffer;
                    }
                    output << std::endl;
                }
                break;
                case MODE_JSON:
                {
                    output << "JS" << std::endl;
                    output << to_json(message) << std::endl;
                }
                break;
                }

                output.flush();
                output.close();
                return true;
            }
            template <typename T>
            bool SetProtoToASCIIFile(const std::shared_ptr<T> message,
                                     const std::string &file_name)
            {
                return SetProtoToASCIIFile(*message, file_name);
            }
            /**
             * @brief Parses the content of the file specified by the file_name as binary
             *        representation of messages, and merges the parsed content to the
             *        proto.
             * @param file_name The name of the file to parse whose content.
             * @param message The proto to carry the parsed content in the specified file.
             * @return If the action is successful.
             */
            std::ifstream::pos_type filesize(std::string filename);
            template <typename T>
            bool GetProtoFromBinaryFile(const std::string &file_name,
                                        T *message)
            {
                std::fstream input(file_name, std::ios::in | std::ios::binary);
                if (!input.good())
                {
                    AERROR << "Failed to open file " << file_name << " in binary mode.";
                    return false;
                }
                T t;

                int f_len = (int)filesize(file_name);

                //rclcpp::SerializedMessage m(t);
                rclcpp::SerializedMessage m = serialize_msg(t);

                m.reserve(f_len);
                if (f_len <=0)
                {
                    AERROR << "Incorrectly formatted binary file for requested message";
                    input.close();
                    return false;
                }
                input.read((char *)m.get_rcl_serialized_message().buffer, f_len);
                m.get_rcl_serialized_message().buffer_length = f_len;
                *message = deserialize_msg<T>(m);
                input.close();
                ADEBUG << "read of "<<file_name << " success";
                return true;
            }

            /**
             * @brief Parses the content of the file specified by the file_name as a
             *        representation of messages, and merges the parsed content to the
             *        proto.
             * @param file_name The name of the file to parse whose content.
             * @param message The proto to carry the parsed content in the specified file.
             * @return If the action is successful.
             */
            template <typename T>
            bool GetProtoFromFile(const std::string &file_name,
                                  T *message)
            {
                // Try the binary parser first if it's much likely a binary proto.
                static const std::string kBinExt = ".bin";
                if (std::equal(kBinExt.rbegin(), kBinExt.rend(), file_name.rbegin()))
                {
                    return GetProtoFromBinaryFile(file_name, message) ||
                           GetProtoFromASCIIFile(file_name, message);
                }

                return GetProtoFromASCIIFile(file_name, message) ||
                       GetProtoFromBinaryFile(file_name, message);
            }
            /**
             * @brief Get file content as string.
             * @param file_name The name of the file to read content.
             * @param content The file content.
             * @return If the action is successful.
             */
            bool GetContent(const std::string &file_name, std::string *content);

            /**
             * @brief Get absolute path by concatenating prefix and relative_path.
             * @return The absolute path.
             */
            std::string GetAbsolutePath(const std::string &prefix,
                                        const std::string &relative_path);

            /**
             * @brief Check if the path exists.
             * @param path a file name, such as /a/b/c.txt
             * @return If the path exists.
             */
            bool PathExists(const std::string &path);

            /**
             * @brief Check if the directory specified by directory_path exists
             *        and is indeed a directory.
             * @param directory_path Directory path.
             * @return If the directory specified by directory_path exists
             *         and is indeed a directory.
             */
            bool DirectoryExists(const std::string &directory_path);

            /**
             * @brief Expand path pattern to matched paths.
             * @param pattern Path pattern, which may contain wildcards [?*].
             * @return Matched path list.
             */
            std::vector<std::string> Glob(const std::string &pattern);

            /**
             * @brief Copy a file.
             * @param from The file path to copy from.
             * @param to The file path to copy to.
             * @return If the action is successful.
             */
            bool CopyFile(const std::string &from, const std::string &to);

            /**
             * @brief Copy a directory.
             * @param from The path to copy from.
             * @param to The path to copy to.
             * @return If the action is successful.
             */
            bool CopyDir(const std::string &from, const std::string &to);

            /**
             * @brief Copy a file or directory.
             * @param from The path to copy from.
             * @param to The path to copy to.
             * @return If the action is successful.
             */
            bool Copy(const std::string &from, const std::string &to);

            /**
             * @brief Check if a specified directory specified by directory_path exists.
             *        If not, recursively create the directory (and its parents).
             * @param directory_path Directory path.
             * @return If the directory does exist or its creation is successful.
             */
            bool EnsureDirectory(const std::string &directory_path);

            /**
             * @brief Remove all the files under a specified directory. Note that
             *        sub-directories are NOT affected.
             * @param directory_path Directory path.
             * @return If the action is successful.
             */
            bool RemoveAllFiles(const std::string &directory_path);

            /**
             * @brief List sub-paths.
             * @param directory_path Directory path.
             * @param d_type Sub-path type, DT_DIR for directory, or DT_REG for file.
             * @return A vector of sub-paths, without the directory_path prefix.
             */
            std::vector<std::string> ListSubPaths(const std::string &directory_path,
                                                  const unsigned char d_type = DT_DIR);

            std::string GetFileName(const std::string &path,
                                    const bool remove_extension = false);

            std::string GetCurrentPath();

            // delete file including file or directory
            bool DeleteFile(const std::string &filename);

            bool GetType(const std::string &filename, FileType *type);

            bool CreateDir(const std::string &dir);

        } // namespace common
    }     // namespace cyber
}

#endif // CYBER_COMMON_FILE_H_luding file or directorybool DeleteFile(const std::string &filename);
