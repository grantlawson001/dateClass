
add_executable(date_test tests.cpp)

target_link_libraries(date_test gtest_main date_lib)