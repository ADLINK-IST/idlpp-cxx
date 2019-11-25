#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
find_package(Java 1.8 REQUIRED)

if(NOT IDLCPP_C_JAR)
  # Check if this is run in an install directory.
  if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/idlcpp-c-jar-with-dependencies.jar")
    set(IDLCPP_C_JAR "${CMAKE_CURRENT_LIST_DIR}/idlcpp-c-jar-with-dependencies.jar")
  endif()
endif()

if(NOT IDLCPP_C_JAR)
  # Use default for build hierarchy.
  set(IDLCPP_C_JAR "${CMAKE_CURRENT_BINARY_DIR}/idlc/target/idlcpp-c-jar-with-dependencies.jar")
endif()

if(NOT IDLPP_EXE)
  set(IDLPP_EXE "${CMAKE_CURRENT_LIST_DIR}/idlpp${CMAKE_EXECUTABLE_SUFFIX}")
endif()

if(NOT IDLPP_TEMPLATES_DIR)
  set(IDLPP_TEMPLATES_DIR "${CMAKE_CURRENT_LIST_DIR}/templates")
endif()

get_filename_component(IDLCPP_JARS_DIR "${IDLCPP_C_JAR}" DIRECTORY)

set(LINE_ENDINGS "UNIX")
if(WIN32)
  set(EXTENSION ".bat")
  set(LINE_ENDINGS "WIN32")
endif()

set(ISOCPPIDL_DIR "${CMAKE_CURRENT_BINARY_DIR}" CACHE STRING "")
set(ISOCPPIDL "isocpp_idlpp${EXTENSION}" CACHE STRING "")
mark_as_advanced(ISOCPPIDL_DIR ISOCPPIDL)

set(ISOCPPIDL_SCRIPT_IN "${CMAKE_CURRENT_LIST_DIR}/isocpp_idlpp${EXTENSION}.in")

configure_file(
  "${ISOCPPIDL_SCRIPT_IN}" "${ISOCPPIDL}"
  @ONLY
  NEWLINE_STYLE ${LINE_ENDINGS})

if(NOT ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows"))
  execute_process(COMMAND chmod +x "${ISOCPPIDL_DIR}/${ISOCPPIDL}")
endif()

add_custom_target(isocpp_idlpp ALL DEPENDS "${IDLCPP_C_JAR}")
if (TARGET idlpp)
  # The idlpp target is only available in the build hierarchy.
  # Not in the install hierarchy where the exe is present.
  add_dependencies(isocpp_idlpp idlpp)
endif()

function(IDL_DDSCXX_GENERATE _target)
  if(NOT ARGN)
    message(FATAL_ERROR "idl_ddscxx_generate called without any idl files")
  endif()

  if (NOT ISOCPPIDL_ARGS)
     set(ISOCPPIDL_ARGS)
  endif()

  set(_dir "${CMAKE_CURRENT_BINARY_DIR}")
  set(_sources)
  set(_headers)
  foreach(FIL ${ARGN})
    get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
    get_filename_component(FIL_WE ${FIL} NAME_WE)

    set(_source1 "${_dir}/${FIL_WE}.cpp")
    set(_source2 "${_dir}/${FIL_WE}-cyclone.c")
    set(_source3 "${_dir}/${FIL_WE}SplDcps.cpp")
    set(_header1 "${_dir}/${FIL_WE}.h")
    set(_header2 "${_dir}/${FIL_WE}-cyclone.h")
    set(_header3 "${_dir}/${FIL_WE}_DCPS.hpp")
    set(_header4 "${_dir}/${FIL_WE}SplDcps.h")
    list(APPEND _sources "${_source1}" "${_source2}" "${_source3}")
    list(APPEND _headers "${_header1}" "${_header2}" "${_header3}" "${_header4}")

    add_custom_command(
      OUTPUT   "${_source1}" "${_source2}" "${_source3}" "${_header1}" "${_header2}" "${_header3}" "${_header4}"
      COMMAND  "${ISOCPPIDL_DIR}/${ISOCPPIDL}"
      ARGS     ${ISOCPPIDL_ARGS} ${ABS_FIL}
      DEPENDS  "${ABS_FIL}" isocpp_idlpp
      COMMENT  "Running isocpp_idlpp on ${FIL}"
      VERBATIM)
  endforeach()

  add_custom_target(
    "${_target}_idl_isocpp_generate"
    DEPENDS "${_sources}" "${_headers}"
  )

  set_source_files_properties(
    ${_sources} ${_headers} PROPERTIES GENERATED TRUE)
  add_library(${_target} INTERFACE)
  target_sources(${_target} INTERFACE ${_sources} ${_headers})
  target_include_directories(${_target} INTERFACE "${_dir}")
  add_dependencies(${_target} "${_target}_idl_isocpp_generate")
endfunction()

