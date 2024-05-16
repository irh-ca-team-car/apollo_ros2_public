#include "cyber/writer.h"
#include "cyber/reader.h"
#include "cyber/io_internal.h"

#include "std_msgs/msg/header.hpp"
#include "apollo_msgs/msg/apollocommon_header.hpp"
#include <map>
#ifndef COMPONENTBASE
#define COMPONENTBASE

namespace apollo
{
    namespace cyber
    {
        extern rclcpp::Node *currentNode;
        template <typename M0>
        class ReaderStorage
        {
            public:
                static void Register(std::string name,std::shared_ptr<Reader<M0>> rd){
                    storage()->insert_or_assign(name,rd);
                    //_instance[name]=rd;
                }
                static std::shared_ptr<Reader<M0>> Get(std::string name){
                    auto ite = storage()->find(name);
                    if(ite!=storage()->end())
                        return ite->second;
                    return nullptr;
                    //return _instance[name];
                }
                static std::map<std::string,std::shared_ptr<Reader<M0>>>* storage()
                {
                    static std::map<std::string,std::shared_ptr<Reader<M0>>> a;
                    return &a;
                }
            private:
                //static std::map<std::string,std::shared_ptr<Reader<M0>> _instance;
        };
        class ComponentBase : public rclcpp::Node
        {
        public:
            ComponentBase(std::string name) : Node(name)
            {
                AINFO << "ComponentBase set node_, currentNode";
                node_ = this;
                currentNode = this;
                init_result_ = std::async(&ComponentBase::Initialize, this);
            };
            void FillHeader(std::string name, std_msgs::msg::Header &header);
            void FillHeader(std::string name, apollo_msgs::msg::ApollocommonHeader &header);
            static ComponentBase *instance();
            template <class M0> 
            void FillHeader(std::string name, M0* msg)
            {
                FillHeader(name, msg->apolloheader);
            }
            template <class M0>
            void FillHeader(std::string name, M0 &msg)
            {
                FillHeader(name, msg.apolloheader);
            }
            std::string replaceString(std::string str,
                                      const std::string &replace,
                                      const std::string &with)
            {
                std::size_t pos = str.find(replace);
                if (pos != std::string::npos)
                    str.replace(pos, replace.length(), with);
                return str;
            }
            void replaceRoot(std::string &str )
            {
                static std::string root_dir = "<NOT SET>";
                if (root_dir == "<NOT SET>")
                    root_dir = declare_parameter<std::string>("root_dir", "");
                //AINFO << "Replacing <root> with " << root_dir << " in " << str;
                str = replaceString(str, "<root>", root_dir);
            }
            template <class M0>
            std::shared_ptr<Reader<M0>> GetReader(std::string name)
            {
                return ReaderStorage<M0>::Get(name);
            }
            template <class M0>
            std::shared_ptr<Writer<M0>> CreateWriter(std::string name)
            {
                return std::make_shared<Writer<M0>>(this->create_publisher<M0>(name, 1),name);
            }
            template <class M0>
            std::shared_ptr<Reader<M0>> CreateReader(std::string name, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                auto c= std::make_shared<Reader<M0>>(this, name, 1, reader_func);
                ReaderStorage<M0>::Register(name,c);
                return c;
            }
            template <class M0>
            std::shared_ptr<Reader<M0>> CreateReader(const ReaderConfig &config, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                auto c= std::make_shared<Reader<M0>>(this, config.channel_name, config.pending_queue_size, reader_func);
                ReaderStorage<M0>::Register(config.channel_name,c);
                return c;
            }
            template <class M0>
            std::shared_ptr<WriterJson<M0>> CreateWriterJson(std::string name)
            {
                return std::make_shared<WriterJson<M0>>(this->create_publisher<std_msgs::msg::String>(name, 1),name);
            }
            template <class M0>
            std::shared_ptr<ReaderJson<M0>> CreateReaderJson(std::string name, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                return std::make_shared<ReaderJson<M0>>(this, name, 1, reader_func);
            }
            template <class M0>
            std::shared_ptr<ReaderJson<M0>> CreateReaderJson(const ReaderConfig &config, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                return std::make_shared<ReaderJson<M0>>(this, config.channel_name, config.pending_queue_size, reader_func);
            }

            ComponentBase *node_;

        protected:
            std::future<void> init_result_;
            virtual bool Init() = 0;
            virtual void Initialize()
            {
                if (!this->Init())
                {
                    AFATAL << "INIT FAILURE";
                }
                AINFO << "INIT SUCCESS";
            }
        };
    }
}
#endif