#ifndef __INDEXLIB_KKVINDEXCONFIGTEST_H
#define __INDEXLIB_KKVINDEXCONFIGTEST_H

#include "indexlib/common_define.h"
#include "indexlib/config/kkv_index_config.h"
#include "indexlib/test/test.h"
#include "indexlib/test/unittest.h"

namespace indexlib { namespace config {

class KKVIndexConfigTest : public INDEXLIB_TESTBASE
{
public:
    KKVIndexConfigTest();
    ~KKVIndexConfigTest();

    DECLARE_CLASS_NAME(KKVIndexConfigTest);

public:
    void CaseSetUp() override;
    void CaseTearDown() override;
    void TestSimpleProcess();
    void TestGetHashFunctionType();
    void TestValueImpact();
    void TestPlainFormat();
    void TestCheckValueFormat();
    void TestAutoValueImpact();

private:
    IE_LOG_DECLARE();
};

INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestSimpleProcess);
INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestGetHashFunctionType);
INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestValueImpact);
INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestPlainFormat);
INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestCheckValueFormat);
INDEXLIB_UNIT_TEST_CASE(KKVIndexConfigTest, TestAutoValueImpact);

}} // namespace indexlib::config

#endif //__INDEXLIB_KKVINDEXCONFIGTEST_H
