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
#ifndef __INDEXLIB_PLUGIN_MODULEFACTORY_H
#define __INDEXLIB_PLUGIN_MODULEFACTORY_H

#include "indexlib/common_define.h"
#include "indexlib/util/KeyValueMap.h"

namespace indexlib { namespace plugin {
class ModuleFactory
{
public:
    ModuleFactory() {}
    virtual ~ModuleFactory() {}

public:
    virtual bool init() { return true; }
    virtual void destroy() = 0;
};

// extern "C" ModuleFactory* createFactory();
// extern "C" void destroyFactory(ModuleFactory *factory);

}} // namespace indexlib::plugin

#endif //__INDEXLIB_PLUGIN_MODULEFACTORY_H
