configure_file(config.hpp.in config.hpp)

add_library(multigrid INTERFACE)
target_include_directories(multigrid
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${multigrid_INSTALL_INCLUDEDIR}>)

add_library(multigrid::multigrid ALIAS multigrid)
  
install(TARGETS multigrid
  EXPORT multigrid_EXPORTS
  RUNTIME DESTINATION ${multigrid_INSTALL_BINDIR}
  LIBRARY DESTINATION ${multigrid_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${multigrid_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${multigrid_INSTALL_INCLUDEDIR})
