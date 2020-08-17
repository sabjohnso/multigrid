cmake_minimum_required(VERSION 3.12)

project(multigrid VERSION 0.1.0 LANGUAGES C CXX)

option(multigrid_BUILD_TESTING "Build the multigrid tests" ON)

include(GNUInstallDirs)
set(multigrid_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(multigrid_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(multigrid_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR})
set(multigrid_INSTALL_CONFDIR ${multigrid_INSTALL_LIBDIR}/cmake/multigrid-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(multigrid_deps)

add_subdirectory(multigrid)

if(multigrid_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(multigrid_testing)
  endif()
endif()

install(EXPORT multigrid_EXPORTS
  NAMESPACE multigrid::
  FILE multigrid-exports.cmake
  DESTINATION ${multigrid_INSTALL_CONFDIR})

configure_file(multigrid-config.cmake.in multigrid-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/multigrid-config.cmake
  DESTINATION ${multigrid_INSTALL_CONFDIR})








