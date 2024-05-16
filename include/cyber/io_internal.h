#pragma once
#include "cyber/writer.h"
#include "cyber/reader.h"
#include "cyber/common/macros.h"
#include <map>
#include <vector>
namespace apollo
{
    namespace cyber
    {
        template <class M0>
        class Reader_INTERNAL
        {
        public:
            Reader_INTERNAL(std::string name, int queue = 1, const typename std::function<void(const typename std::shared_ptr<M0>)> reader_func = nullptr)
            {
                this->name = name;
                this->queue = queue;
                callback_function = reader_func;
            }
            void Observe() {}
            typename std::shared_ptr<M0> GetLatestObserved() { return last_observed; }
            void read(const typename std::shared_ptr<M0> msg)
            {
                last_observed = msg;
                if (callback_function != nullptr)
                    callback_function(msg);
            }
            typename std::shared_ptr<M0> last_observed = nullptr;
            typename std::function<void(const typename std::shared_ptr<M0>)> callback_function;
            std::string name;
            int queue;
        };
        template <class M0>
        class Reader_INTERNAL_LST
        {
        public:
            static Reader_INTERNAL_LST *Instance(bool create_if_needed = true)
            {
                static Reader_INTERNAL_LST *instance = nullptr;
                if (!instance && create_if_needed)
                {
                    static std::once_flag flag;
                    std::call_once(flag,
                                   [&] { instance = new (std::nothrow) Reader_INTERNAL_LST(); });
                }
                return instance;
            }
            std::vector<typename std::shared_ptr<Reader_INTERNAL<M0>>> data;
            void Register(std::string str, typename std::shared_ptr<Reader_INTERNAL<M0>> reader)
            {
                reader->name = str;
                data.push_back(reader);
            }
            void Publish(std::string str, const typename std::shared_ptr<M0> msg)
            {
                for (auto r : data)
                {
                    if (r->name == str)
                        r->read(msg);
                }
            }
            void Publish(std::string str, const M0 &msg)
            {
                std::shared_ptr<M0> ptr = std::make_shared<M0>(msg);
                //ptr = std::shared_ptr<M0>>(msg,[=](M0 * msg) {delete msg;});
                Publish(str, ptr);
            }

        private:
            Reader_INTERNAL_LST()
            {
            }
        };
        template <class M0>
        class Writer_INTERNAL
        {
        public:
            Writer_INTERNAL(std::string name, int queue = 1)
            {
                this->name = name;
                this->queue = queue;
            }
            void Write(const std::shared_ptr<M0> &msg)
            {
                Reader_INTERNAL_LST<M0>::Instance(true)->Publish(name, msg);
            }
            void Write(const M0 &msg)
            {
                Reader_INTERNAL_LST<M0>::Instance(true)->Publish(name, msg);
            }

        protected:
            std::string name;
            int queue;
        };
    }
}