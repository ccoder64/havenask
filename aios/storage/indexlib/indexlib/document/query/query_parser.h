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
#ifndef __INDEXLIB_QUERY_PARSER_H
#define __INDEXLIB_QUERY_PARSER_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/document/query/query_base.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace document {

class QueryParser
{
public:
    QueryParser() {}
    virtual ~QueryParser() {}

public:
    virtual QueryBasePtr Parse(const std::string& string) = 0;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(QueryParser);
}} // namespace indexlib::document

#endif //__INDEXLIB_QUERY_PARSER_H
