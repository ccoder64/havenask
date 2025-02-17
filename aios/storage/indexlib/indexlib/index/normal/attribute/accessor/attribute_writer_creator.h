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
#ifndef __INDEXLIB_ATTRIBUTE_WRITER_CREATOR_H
#define __INDEXLIB_ATTRIBUTE_WRITER_CREATOR_H

#include <memory>

#include "autil/mem_pool/Pool.h"
#include "indexlib/common_define.h"
#include "indexlib/index/normal/attribute/accessor/attribute_writer.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace index {

class AttributeWriterCreator
{
public:
    AttributeWriterCreator() {}
    virtual ~AttributeWriterCreator() {}

public:
    virtual FieldType GetAttributeType() const = 0;
    virtual AttributeWriter* Create(const config::AttributeConfigPtr& attrConfig) const = 0;
};

typedef std::shared_ptr<AttributeWriterCreator> AttributeWriterCreatorPtr;
}} // namespace indexlib::index

#endif //__INDEXLIB_ATTRIBUTE_WRITER_CREATOR_H
