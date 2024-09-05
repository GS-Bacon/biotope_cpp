cmake_minimum_required(VERSION 3.22)
project(hello_world CXX)
add_executable(main_app main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)

enable_testing()

# 単体テストの定義
add_executable(MyLibTest MyLibTest.cpp)
target_link_libraries(MyLibTest PRIVATE mylib gtest_main)

# CTestへ単体テストを登録
include(GoogleTest)
gtest_discover_tests(MyLibTest)