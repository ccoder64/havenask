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
#ifndef __INDEXLIB_TEMPERATURE_LAYER_CONFIG_IMPL_H
#define __INDEXLIB_TEMPERATURE_LAYER_CONFIG_IMPL_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/temperature_condition.h"

namespace indexlib { namespace config {

class TemperatureLayerConfigImpl : public autil::legacy::Jsonizable
{
public:
    TemperatureLayerConfigImpl();
    ~TemperatureLayerConfigImpl();

    TemperatureLayerConfigImpl(const TemperatureLayerConfigImpl& other)
        : mDefaultProperty(other.mDefaultProperty)
        , mConditions(other.mConditions)
    {
    }

    TemperatureLayerConfigImpl& operator=(const TemperatureLayerConfigImpl&) = delete;
    TemperatureLayerConfigImpl(TemperatureLayerConfigImpl&&) = delete;
    TemperatureLayerConfigImpl& operator=(TemperatureLayerConfigImpl&&) = delete;

public:
    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void Check(const AttributeSchemaPtr& attribtueSchema) const;
    const std::vector<TemperatureConditionPtr>& GetConditions() const;
    const std::string GetDefaultProperty() const;
    void AssertEqual(const TemperatureLayerConfigImpl& other) const;

public:
    bool operator==(const TemperatureLayerConfigImpl& other) const;

private:
    std::string mDefaultProperty;
    std::vector<TemperatureConditionPtr> mConditions;
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(TemperatureLayerConfigImpl);
}} // namespace indexlib::config

#endif //__INDEXLIB_TEMPERATURE_LAYER_CONFIG_IMPL_H
