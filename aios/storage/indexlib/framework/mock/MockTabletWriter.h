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
#include "gmock/gmock.h"
#include <memory>

#include "indexlib/base/Status.h"
#include "indexlib/framework/TabletWriter.h"

namespace indexlibv2::framework {

class MockTabletWriter : public TabletWriter
{
public:
    MockTabletWriter() {}
    ~MockTabletWriter() {}

    MOCK_METHOD(Status, Open, (const std::shared_ptr<TabletData>&, const BuildResource&, const framework::OpenOptions&),
                (override));
    MOCK_METHOD(Status, Build, (const std::shared_ptr<document::IDocumentBatch>&), (override));
    MOCK_METHOD(std::unique_ptr<SegmentDumper>, CreateSegmentDumper, (), (override));
    MOCK_METHOD(size_t, GetTotalMemSize, (), (const, override));
    MOCK_METHOD(size_t, GetBuildingSegmentDumpExpandSize, (), (const, override));
    MOCK_METHOD(void, ReportMetrics, (), (override));
    MOCK_METHOD(bool, IsDirty, (), (const, override));
    void Close() override {}
};
} // namespace indexlibv2::framework
