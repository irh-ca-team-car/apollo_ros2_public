/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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
 * @brief Some map util functions.
 */

#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "cyber/common/log.h"
/**
 * @namespace apollo::common::util
 * @brief apollo::common::util
 */
namespace apollo
{
    namespace common
    {
        namespace util
        {
            template <typename T, typename Y>
            T FindCopy(std::vector<T> objs, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return objs[i];
                    }
                }
            }
            template <typename T, typename Y>
            T FindCopy(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return objs[i];
                    }
                }
            }
            template <typename T, typename Y>
            T &FindLinkedPtrOrDie(std::vector<T> objs, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL << "FindLinkedPtrOrDie";
            }
            template <typename T, typename Y>
            T &FindLinkedPtrOrDie(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL << "FindLinkedPtrOrDie";
            }
            template <typename T, typename Y>
            T *FindLinkedPtrOrDie(std::vector<T> objs, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T *FindLinkedPtrOrNull(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T FindOrDie(std::vector<T> objs, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL << "FindLinkedPtrOrDie";
            }
            template <typename T, typename Y, typename Z>
            T FindOrDie(std::unordered_map<Y, T, Z> objs, Y key)
            {
                auto d= objs.find(key);
                if(d!=objs.end())
                    return d->second;
                AFATAL << "FindLinkedPtrOrDie";
                return T();
            }
            template <typename T, typename Y>
            T FindOrDie(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL << "FindLinkedPtrOrDie";
            }
            template <typename T, typename Y>
            T FindOrDieNoPrint(std::vector<T> objs, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL ;
            }
             template <typename T, typename Y,typename Z>
            T FindOrDieNoPrint(std::unordered_map<Y,T,Z> objs, Y key)
            {
                auto d= objs.find(key);
                if(d==objs.end())
                {
                    AFATAL;
                }
                else
                    return *d;
                AFATAL ;
            }
            template <typename T, typename Y>
            T FindOrDieNoPrint(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (int i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return objs[i];
                    }
                }
                AFATAL;
            }
            template <typename T, typename Y>
            T *FindOrNull(std::unordered_map<Y,T> objs, Y key)
            {
                for (auto &&i : objs)
                {
                    if(i.first == key)
                        return &i.second;
                }

                return nullptr;
            }
            template <typename T, typename Y>
            T *FindOrNull(std::vector<T> objs, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T *FindOrNull(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T *FindPtrOrNull(std::unordered_map<Y,T*> objs, Y key)
            {
                for (auto &&i : objs)
                {
                    if(i.first == key)
                        return i.second;
                }

                return nullptr;
            }
            template <typename T, typename Y>
            T *FindPtrOrNull(std::vector<T> objs, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T *FindPtrOrNull(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return &objs[i];
                    }
                }
                return nullptr;
            }
            template <typename T, typename Y>
            T FindWithDefault(std::vector<T> objs, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return objs[i];
                    }
                }
                return T();
            }
            template <typename T, typename Y>
            T FindWithDefault(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return objs[i];
                    }
                }
                return T();
            }
            template <typename T, typename Y>
            bool ContainsKey(std::vector<T> objs, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {
                        return true;
                    }
                }
                return false;
            }
            template <typename T, typename Y>
            bool ContainsKey(std::unordered_map<Y,T> objs, Y key)
            {
                return objs.find(key)!= objs.end();
            }

            template <typename T, typename Y>
            bool ContainsKey(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        return true;
                    }
                }
                return false;
            }
            template <typename T, typename Y>
            bool ContainsKeyValuePair(std::vector<T> objs, Y key, T value)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key && objs[i].data == value)
                    {
                        return true;
                    }
                }
                return false;
            }
            template <typename T, typename Y>
            bool ContainsKeyValuePair(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key && objs[i] == value)
                    {
                        return true;
                    }
                }
                return false;
            }

            template <typename T, typename Y>
            bool DeleteExisting(std::vector<T> objs, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (objs[i].key == key)
                    {

                        objs.erase(objs.begin() + i);
                        return true;
                    }
                }
                return false;
            }
            template <typename T, typename Y>
            bool DeleteExisting(std::vector<T> objs, std::vector<Y> keys, Y key)
            {
                for (size_t i = 0; i < objs.size(); i++)
                {
                    if (keys[i] == key)
                    {
                        objs.erase(objs.begin() + i);
                        keys.erase(keys.begin() + i);
                        return true;
                    }
                }
                return false;
            }
            template <typename T, typename Y,  typename Z>
            bool InsertAndDeleteExisting(std::vector<T> objs, Y key, Z value)
            {
                DeleteExisting(objs, key);

                T t;
                t.key = key;
                t.data=value;
                objs.push_back(t);

                return true;
            }
            template <typename T, typename Y>
            bool InsertAndDeleteExisting(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                DeleteExisting(objs, keys, key);

                objs.push_back(value);
                keys.push_back(key);

                return true;
            }
            template <typename T, typename Y, typename Z>
            bool InsertOrUpdate(std::vector<T> objs, Y key, Z value)
            {
                DeleteExisting(objs, key);

                T t;
                t.key = key;
                t.data = value;
                objs.push_back(t);

                return true;
            }
            template <typename T, typename Y>
            bool InsertOrUpdate(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                DeleteExisting(objs, keys, key);

                objs.push_back(value);
                keys.push_back(key);

                return true;
            }
            template <typename T, typename Y, typename Z>
            bool InsertOrUpdateMany(std::vector<T> objs, Y key, Z value)
            {
                DeleteExisting(objs, key);

                T t;
                t.key = key;
                t.data = value;
                objs.push_back(t);

                return true;
            }
            template <typename T, typename Y>
            bool InsertOrUpdateMany(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                DeleteExisting(objs, keys, key);

                objs.push_back(value);
                keys.push_back(key);

                return true;
            }
            template <typename T, typename Y, typename Z>
            bool InsertIfNotPresent(std::vector<T> objs, Y key, Z value)
            {
                if (!ContainsKey(objs, key))
                {
                    InsertOrUpdate(objs, key, value);
                   
                    return true;
                }

                return true;
            }
             template <typename T, typename Y, typename Z>
            bool InsertIfNotPresent(std::unordered_map<Y,Z,T>* objs, Y key, Z value)
            {
                if (objs->find(key)==objs->end())
                {
                    objs->operator[](key) = value;
                    return true;
                }

                return true;
            }
            template <typename Y>
            bool InsertIfNotPresent(std::unordered_set<Y>* objs, Y key)
            {
                if(objs->find(key)==objs->end())
                    objs->insert(key);
                return true;
            }
            template <typename T, typename Y>
            bool InsertIfNotPresent(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                if (!ContainsKey(objs, keys, key))
                {
                    objs.push_back(value);
                    keys.push_back(key);
                    return true;
                }

                return false;
            }
            template <typename T, typename Y, typename Z>
            bool InsertKeyOrDie(std::vector<T> objs, Y key)
            {
                if (!ContainsKey(objs, key))
                {
                    InsertOrUpdate(objs, key, Z());

                    return true;
                }
                AFATAL << "InsertKeyOrDie";
                return true;
            }
            template <typename T, typename Y>
            bool InsertKeyOrDie(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                if (!ContainsKey(objs, keys, key))
                {
                    objs.push_back(value);
                    keys.push_back(key);
                    return true;
                }
                AFATAL << "InsertKeyOrDie";
                return false;
            }
            template <typename T, typename Y, typename Z>
            bool InsertOrDie(std::vector<T> objs, Y key, Z value)
            {
                if (!ContainsKey(objs, key))
                {
                    InsertOrUpdate(objs, key, value);

                    return true;
                }
                AFATAL << "InsertKeyOrDie";
                return true;
            }
            template <typename T, typename Y>
            bool InsertOrDie(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                if (!ContainsKey(objs, keys, key))
                {
                    objs.push_back(value);
                    keys.push_back(key);
                    return true;
                }
                AFATAL << "InsertKeyOrDie";
                return false;
            }
            template <typename T, typename Y, typename Z>
            bool InsertOrDieNoPrint(std::vector<T> objs, Y key, Z value)
            {
                if (!ContainsKey(objs, key))
                {
                    InsertOrUpdate(objs, key, value);

                    return true;
                }
                AFATAL ;
                return true;
            }
            template <typename T, typename Y>
            bool InsertOrDieNoPrint(std::vector<T> objs, std::vector<Y> keys, Y key, T value)
            {
                if (!ContainsKey(objs, keys, key))
                {
                    objs.push_back(value);
                    keys.push_back(key);
                    return true;
                }
                AFATAL;
                return false;
            }
            /*template <typename T, typename Y>
            void AddTokenCounts();
            template <typename T, typename Y>
            void LookupOrInsert();
            template <typename T, typename Y>
            void LookupOrInsertNew();
            template <typename T, typename Y>
            void LookupOrInsertNewLinkedPtr();
            template <typename T, typename Y>
            void LookupOrInsertNewSharedPtr();

            // Misc Utility Functions
            template <typename T, typename Y>
            void AppendKeysFromMap();
            template <typename T, typename Y>
            void AppendValuesFromMap();
            template <typename T, typename Y>
            void EraseKeyReturnValuePtr();
            template <typename T, typename Y>
            void InsertKeysFromMap();
            template <typename T, typename Y>
            void InsertOrReturnExisting();
            template <typename T, typename Y>
            void UpdateReturnCopy;*/

        } // namespace util
    }     // namespace common
} // namespace apollo
