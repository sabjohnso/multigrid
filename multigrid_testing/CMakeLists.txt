find_package(GTest)

macro(multigrid_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    multigrid::header
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

multigrid_add_test(vec vec_test vec_test.cpp)
multigrid_add_test(coordinate coordinate_test coordinate_test.cpp)
multigrid_add_test(origin origin_test origin_test.cpp)
multigrid_add_test(spacing spacing_test spacing_test.cpp)
multigrid_add_test(root root_test root_test.cpp)
multigrid_add_test(fixed_subgrid fixed_subgrid_test fixed_subgrid_test.cpp)

