cmake_minimum_required(VERSION 3.23)

project(PublishJavaScriptCore)

add_executable(JavaScriptCoreTest main.cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Find JavaScriptCore
find_package(JavaScriptCore REQUIRED)
if (NOT TARGET JavaScriptCore)
    add_library(JavaScriptCore SHARED IMPORTED)
    set_target_properties(JavaScriptCore PROPERTIES
    IMPORTED_LOCATION "${JavaScriptCore_LOCATION_RELEASE}"
    IMPORTED_LOCATION_DEBUG "${JavaScriptCore_LOCATION_DEBUG}"
    IMPORTED_IMPLIB "${JavaScriptCore_IMPLIB_RELEASE}"
    IMPORTED_IMPLIB_DEBUG "${JavaScriptCore_IMPLIB_DEBUG}"
    INTERFACE_INCLUDE_DIRECTORIES "${JavaScriptCore_INCLUDE_DIRS}"
    IMPORTED_CONFIGURATIONS "Release;Debug"
  )
endif()

target_link_libraries(JavaScriptCoreTest PRIVATE JavaScriptCore)

