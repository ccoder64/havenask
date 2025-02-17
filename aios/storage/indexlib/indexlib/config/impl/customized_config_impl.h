/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __INDEXLIB_CUSTOMIZED_CONFIG_IMPL_H
#define __INDEXLIB_CUSTOMIZED_CONFIG_IMPL_H

#include <memory>

#include "autil/legacy/jsonizable.h"
#include "indexlib/common_define.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace config {

class CustomizedConfigImpl : public autil::legacy::Jsonizable
{
public:
    CustomizedConfigImpl();
    CustomizedConfigImpl(const CustomizedConfigImpl& other);
    ~CustomizedConfigImpl();

public:
    const std::string& GetPluginName() const { return mPluginName; }
    const std::map<std::string, std::string>& GetParameters() const { return mParameters; }
    bool GetParameters(const std::string& key, std::string& value) const;
    const std::string& GetId() const { return mId; }

    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void AssertEqual(const CustomizedConfigImpl& other) const;

public:
    // for test
    void SetId(const std::string& id);
    void SetPluginName(const std::string& pluginName);

private:
    std::string mId;
    std::string mPluginName;
    std::map<std::string, std::string> mParameters;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(CustomizedConfigImpl);
typedef std::vector<CustomizedConfigImplPtr> CustomizedConfigImplVector;
}} // namespace indexlib::config

#endif //__INDEXLIB_CUSTOMIZED_CONFIG_IMPL_H
