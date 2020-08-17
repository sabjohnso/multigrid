find_package(GTest)

macro(multigrid_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    multigrid::multigrid
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()
