cmake_minimum_required(VERSION 3.18)

project(PublishJavaScriptCore)

add_library(JavaScriptCore SHARED IMPORTED)
set_property(TARGET JavaScriptCore PROPERTY
  IMPORTED_LOCATION_RELEASE
  ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/bin/JavaScriptCore.dll)
set_property(TARGET JavaScriptCore PROPERTY
  IMPORTED_IMPLIB
  ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/lib/JavaScriptCore.lib)
set_property(TARGET JavaScriptCore PROPERTY
  IMPORTED_LOCATION_DEBUG
  ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/debug/bin/JavaScriptCore.dll)
set_property(TARGET JavaScriptCore PROPERTY
  IMPORTED_IMPLIB_DEBUG
  ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/debug/lib/JavaScriptCore.lib)
set_property(TARGET JavaScriptCore PROPERTY
  INTERFACE_INCLUDE_DIRECTORIES
  ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/include)

add_executable(TestJavaScriptCore main.cpp)
target_link_libraries(TestJavaScriptCore JavaScriptCore)

include(GNUInstallDirs)
install(TARGETS TestJavaScriptCore
  RUNTIME_DEPENDENCIES)
