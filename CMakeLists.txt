#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

# Set module path before defining project so platform files will work.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/idlpp/cmake/modules)
set(CMAKE_PROJECT_NAME_FULL "CXX Idl compiler for Eclipse CycloneDDS")
set(PROJECT_NAME "Idlpp-cxx")
set(PROJECT_VERSION 1.0.0)
set(PROJECT_VERSION_UUID "ad0056c1-e1eb-4bd7-b420-5bd06c865001")
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})


# Set some convenience variants of the project-name
string(REPLACE " " "-" CMAKE_PROJECT_NAME_DASHED "${CMAKE_PROJECT_NAME_FULL}")
string(TOUPPER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME_CAPS)
string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_PROJECT_NAME_SMALL)

set(CMAKE_C_STANDARD 99)

if(${CMAKE_C_COMPILER_ID} STREQUAL "SunPro")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -xc99 -D__restrict=restrict -D__deprecated__=")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -m64")
endif()

# Set reasonably strict warning options for clang, gcc, msvc
# Enable coloured ouput if Ninja is used for building
if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
  add_definitions(-Wall -Wextra -Wconversion -Wunused)
  if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
    add_definitions(-Xclang -fcolor-diagnostics)
  endif()
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  add_definitions(-Wall -Wextra -Wconversion)
  if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
    add_definitions(-fdiagnostics-color=always)
  endif()
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
  add_definitions(/W3)
endif()


# Make it easy to enable one of Clang's/gcc's analyzers, and default to using
# the address sanitizer for ordinary debug builds; gcc is giving some grief on
# Travis, so don't enable it for gcc by default
if(NOT USE_SANITIZER)
  if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug" AND
      NOT ("${CMAKE_GENERATOR}" STREQUAL "Xcode") AND
      ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"
        OR "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang"))
    message(STATUS "Enabling address sanitizer; set USE_SANITIZER=none to prevent this")
    set(USE_SANITIZER address)
  else()
    set(USE_SANITIZER none)
  endif()
endif()
if(NOT (${USE_SANITIZER} STREQUAL "none"))
  message(STATUS "Sanitizer set to ${USE_SANITIZER} for ${CMAKE_PROJECT_NAME}")
  add_compile_options(-fno-omit-frame-pointer -fsanitize=${USE_SANITIZER})
  link_libraries(-fno-omit-frame-pointer -fsanitize=${USE_SANITIZER})
endif()


include(GNUInstallDirs)

if(APPLE)
  set(CMAKE_INSTALL_RPATH "@loader_path/../${CMAKE_INSTALL_LIBDIR}")
else()
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()

# Build all executables and libraries into the top-level /bin and /lib folders.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(idlpp)

# Pull-in CPack and support for generating <Package>Config.cmake and packages.
include(Packaging)
