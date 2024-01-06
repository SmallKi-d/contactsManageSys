# 导入 GTest
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main
)

FetchContent_MakeAvailable(googletest)

# 启动测试
enable_testing()

## 单元测试
#add_executable(Test test.cpp)
#add_library(GTest::GTest INTERFACE IMPORTED)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)
#
## 添加测试
#add_test(NAME Test COMMAND gtest_main)

# 假设你的测试文件是 test_main.cpp
add_executable(google_test contactsTest.cpp saveTest.cpp
        ../header/isPhone.h
        ../source/isPhone.cpp
        ../header/contact.h
        ../source/contact.cpp
        ../header/structure.h
        ../header/save.h
        ../source/save.cpp
        ../header/clear.h
        ../source/clear.cpp
        ../header/do.h
        ../source/do.cpp
        ../header/menu.h
        ../source/menu.cpp
)
target_link_libraries(google_test gtest_main)

enable_testing()
add_test(NAME google_test COMMAND google_test)

gtest_discover_tests(google_test)

