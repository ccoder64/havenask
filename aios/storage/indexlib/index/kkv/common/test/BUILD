load('//aios/storage:defs.bzl', 'strict_cc_fast_test')
strict_cc_fast_test(
    name='ChunkWriterTest',
    srcs=['ChunkWriterTest.cpp'],
    deps=[
        '//aios/storage/indexlib/index/kkv/common:ChunkWriter',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='OnDiskPKeyOffsetTest',
    srcs=['OnDiskPKeyOffsetTest.cpp'],
    deps=[
        '//aios/storage/indexlib/index/kkv/common:OnDiskPKeyOffset',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='ChunkReaderTest',
    srcs=['ChunkReaderTest.cpp'],
    deps=[
        '//aios/storage/indexlib/index/kkv/common:ChunkReader',
        '//aios/storage/indexlib/index/kkv/common:ChunkWriter',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='ChunkDefineTest',
    srcs=['ChunkDefineTest.cpp'],
    deps=[
        '//aios/storage/indexlib/index/kkv:Constant',
        '//aios/storage/indexlib/index/kkv/common:ChunkDefine',
        '//aios/unittest_framework'
    ]
)
