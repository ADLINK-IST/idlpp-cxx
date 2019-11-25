#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#

# Some locations.
set(IDLPP_OSPLI "${CMAKE_CURRENT_SOURCE_DIR}/ppresources/ospli")
set(IDLPP_OSPLO "${CMAKE_CURRENT_SOURCE_DIR}/ppresources/osplo")
set(IDLPP_VLITE "${CMAKE_CURRENT_SOURCE_DIR}/ppresources/vlite")
set(IDLPP_DESTINATION_INSTALL "${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}/idlpp")

# Defines that are needed to compile every component properly.
add_definitions(-DOSPL_VERSION=tmpidlpp-0.0.1 -DLITE)

if (WIN32)
macro(get_WIN32_WINNT version)
	if (CMAKE_SYSTEM_VERSION)
		set(ver ${CMAKE_SYSTEM_VERSION})
		string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
		string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
		# Check for Windows 10, b/c we'll need to convert to hex 'A'.
		if ("${verMajor}" MATCHES "10")
			set(verMajor "A")
			string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
		endif ("${verMajor}" MATCHES "10")
		# Remove all remaining '.' characters.
		string(REPLACE "." "" ver ${ver})
		# Prepend each digit with a zero.
		string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
		set(${version} "0x${ver}")
	endif(CMAKE_SYSTEM_VERSION)
endmacro(get_WIN32_WINNT)

get_WIN32_WINNT(ver)
add_definitions(-D_WIN32_WINNT=${ver})
message(STATUS "WIN32 NT version: ${ver}")
endif(WIN32)

# There are very many warnings. It doesn't make sense to solve these
# warnings for a throw-away piece of code. So, just ignore them.
# This way of working is not very nice. Oh well.
if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "AppleClang")
add_definitions(-Wno-conversion -Wno-unused -Wno-unused-parameter -Wno-deprecated-register)
if("${CMAKE_GENERATOR}" STREQUAL "Ninja")
  add_definitions(-Xclang -fcolor-diagnostics)
endif()
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
add_definitions(-Wno-conversion -Wno-unused -Wno-sign-compare -Wno-empty-body -Wno-cast-function-type)
if(${CMAKE_GENERATOR} STREQUAL "Ninja")
  add_definitions(-fdiagnostics-color=always)
endif()
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
add_definitions(/W1 /wd4116 /wd4311)
endif()

if(APPLE)
set(CMAKE_INSTALL_RPATH "@loader_path/../../${CMAKE_INSTALL_LIBDIR}")
else()
set(CMAKE_INSTALL_RPATH "$ORIGIN/../../${CMAKE_INSTALL_LIBDIR}")
endif()

add_subdirectory(ppresources)
add_subdirectory(idlc)
add_subdirectory(idlpp)
add_subdirectory(cppgen)
include(cmake/IdlDdscxxGenerate.cmake)

install(
FILES "cmake/IdlDdscxxGenerate.cmake"
DESTINATION "${IDLPP_DESTINATION_INSTALL}"
COMPONENT dev)

install(
FILES "${ISOCPPIDL_SCRIPT_IN}"
DESTINATION "${IDLPP_DESTINATION_INSTALL}"
COMPONENT dev)

