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
#ifndef __INDEXLIB_SPLIT_SEGMENT_STRATEGY_H
#define __INDEXLIB_SPLIT_SEGMENT_STRATEGY_H

#include <array>
#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/index_partition_schema.h"
#include "indexlib/index/normal/attribute/accessor/offline_attribute_segment_reader_container.h"
#include "indexlib/index/segment_metrics_updater/segment_metrics_updater.h"
#include "indexlib/index_base/index_meta/segment_merge_info.h"
#include "indexlib/index_base/index_meta/segment_temperature_meta.h"
#include "indexlib/indexlib.h"
#include "indexlib/merger/index_partition_merger_metrics.h"
#include "indexlib/merger/merge_plan.h"
#include "indexlib/merger/segment_directory.h"
#include "indexlib/util/KeyValueMap.h"
#include "indexlib/util/metrics/MetricProvider.h"

namespace indexlib { namespace merger {

class SplitSegmentStrategy
{
public:
    // static constexpr size_t MAX_SEGMENT_COUNT = 256;

public:
    SplitSegmentStrategy(index::SegmentDirectoryBasePtr segDir, config::IndexPartitionSchemaPtr schema,
                         index::OfflineAttributeSegmentReaderContainerPtr attrReaders,
                         const index_base::SegmentMergeInfos& segMergeInfos, const MergePlan& plan,
                         std::map<segmentid_t, index::SegmentMetricsUpdaterPtr> hintDocInfos,
                         const util::MetricProviderPtr& metrics);

    virtual ~SplitSegmentStrategy();

public:
    virtual bool Init(const util::KeyValueMap& parameters) = 0;

public:
    void SetAttrUpdaterGenerator(std::function<index::SegmentMetricsUpdaterPtr()> fn)
    {
        mUpdaterGenerator = std::move(fn);
    }
    segmentindex_t Process(segmentid_t oldSegId, docid_t oldLocalId);
    std::vector<autil::legacy::json::JsonMap> GetSegmentCustomizeMetrics();
    bool GetTargetSegmentTemperatureMeta(size_t idx, index_base::SegmentTemperatureMeta& meta);

protected:
    virtual segmentindex_t DoProcess(segmentid_t oldSegId, docid_t oldLocalId, int64_t& hintValue) = 0;

protected:
    index::SegmentDirectoryBasePtr mSegDir;
    config::IndexPartitionSchemaPtr mSchema;
    index::OfflineAttributeSegmentReaderContainerPtr mReaderContainer;
    index_base::SegmentMergeInfos mSegMergeInfos;
    MergePlan mPlan;
    std::function<index::SegmentMetricsUpdaterPtr()> mUpdaterGenerator;
    std::vector<index::SegmentMetricsUpdaterPtr> mMetricsUpdaters;
    std::map<segmentid_t, index::SegmentMetricsUpdaterPtr> mHintDocInfos;
    int64_t mProcessLatencyInMs;
    util::MetricProviderPtr mMetricsProvider;
    // metrics
    IE_DECLARE_METRIC(splitLatency);

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(SplitSegmentStrategy);
}} // namespace indexlib::merger

#endif //__INDEXLIB_SPLIT_SEGMENT_STRATEGY_H
