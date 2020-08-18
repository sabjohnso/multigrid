configure_file(config.hpp.in config.hpp)

add_library(multigrid_header INTERFACE)
set_target_properties(multigrid_header PROPERTIES EXPORT_NAME header)
target_include_directories(multigrid_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${multigrid_INSTALL_INCLUDEDIR}>)

add_library(multigrid::header ALIAS multigrid_header)
  
install(TARGETS multigrid_header
  EXPORT multigrid_EXPORTS
  RUNTIME DESTINATION ${multigrid_INSTALL_BINDIR}
  LIBRARY DESTINATION ${multigrid_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${multigrid_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${multigrid_INSTALL_INCLUDEDIR})
