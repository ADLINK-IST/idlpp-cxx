#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

unset(SOURCES)

# OS abstraction 'common'
set(OSAB_SRC_DIR "${IDLPP_OSPLI}/src/abstraction/os/code")
list(APPEND SOURCES
     "${OSAB_SRC_DIR}/os_atomics.c"
     "${OSAB_SRC_DIR}/os_cfg.c"
     "${OSAB_SRC_DIR}/os_cond.c"
     "${OSAB_SRC_DIR}/os_config.c"
     "${OSAB_SRC_DIR}/os_defs.c"
     "${OSAB_SRC_DIR}/os_diag.c"
     "${OSAB_SRC_DIR}/os_errno.c"
     "${OSAB_SRC_DIR}/os_heap.c"
     "${OSAB_SRC_DIR}/os_init.c"
     "${OSAB_SRC_DIR}/os_iterator.c"
     "${OSAB_SRC_DIR}/os_mutex.c"
     "${OSAB_SRC_DIR}/os_process.c"
     "${OSAB_SRC_DIR}/os_report.c"
     "${OSAB_SRC_DIR}/os_rwlock.c"
     "${OSAB_SRC_DIR}/os_semaphore.c"
     "${OSAB_SRC_DIR}/os_stdlib.c"
     "${OSAB_SRC_DIR}/os_string.c"
     "${OSAB_SRC_DIR}/os_thread.c"
     "${OSAB_SRC_DIR}/os_time.c"
     "${OSAB_SRC_DIR}/os_uri.c"
     "${OSAB_SRC_DIR}/os_utsname.c")

# OS abstraction 'specific'
if(APPLE)
  set(IDLPP_OS darwin10)
  set(OSOS_SRC_DIR "${IDLPP_OSPLI}/src/abstraction/os/${IDLPP_OS}/code")
  list(APPEND SOURCES
       "${OSOS_SRC_DIR}/os__cfg_weak.c"
       "${OSOS_SRC_DIR}/os__process.c")
elseif(WIN32)
  set(IDLPP_OS win32)
  set(OSOS_SRC_DIR "${IDLPP_OSPLI}/src/abstraction/os/${IDLPP_OS}/code")
  list(APPEND SOURCES
       "${OSOS_SRC_DIR}/os__cfg_weak.c"
       "${OSOS_SRC_DIR}/os__debug.c"
       "${OSOS_SRC_DIR}/os__process.c"
       "${OSOS_SRC_DIR}/os__sync.c")
else()
  string(TOLOWER ${CMAKE_SYSTEM_NAME} IDLPP_OS)
  set(OSOS_SRC_DIR "${IDLPP_OSPLI}/src/abstraction/os/${IDLPP_OS}/code")
  list(APPEND SOURCES
       "${OSOS_SRC_DIR}/os__cfg_weak.c"
       "${OSOS_SRC_DIR}/os__process.c")
endif()
message(STATUS "Using \"${IDLPP_OS}\" as OS")

# Database
set(DABA_SRC_DIR "${IDLPP_OSPLI}/src/database/database/code")
list(APPEND SOURCES
     "${DABA_SRC_DIR}/c_base.c"
     "${DABA_SRC_DIR}/c_clone.c"
     "${DABA_SRC_DIR}/c_collection.c"
     "${DABA_SRC_DIR}/c_field.c"
     "${DABA_SRC_DIR}/c_iterator.c"
     "${DABA_SRC_DIR}/c_laptime.c"
     "${DABA_SRC_DIR}/c_metabase.c"
     "${DABA_SRC_DIR}/c_metafactory.c"
     "${DABA_SRC_DIR}/c_misc.c"
     "${DABA_SRC_DIR}/c_mmbase.c"
     "${DABA_SRC_DIR}/c_querybase.c"
     "${DABA_SRC_DIR}/c_refcheck.c"
     "${DABA_SRC_DIR}/c_scope.c"
     "${DABA_SRC_DIR}/c_stringSupport.c"
     "${DABA_SRC_DIR}/c_sync.c"
     "${DABA_SRC_DIR}/c_time.c"
     "${DABA_SRC_DIR}/c_typebase.c"
     "${DABA_SRC_DIR}/q_expr.c"
     "${DABA_SRC_DIR}/q_parser.c")

# Serialization
set(SERL_SRC_DIR "${IDLPP_OSPLI}/src/database/serialization/code")
list(APPEND SOURCES
     "${SERL_SRC_DIR}/sd_cdr.c"
     "${SERL_SRC_DIR}/sd_contextItem.c"
     "${SERL_SRC_DIR}/sd_deepwalk.c"
     "${SERL_SRC_DIR}/sd_deepwalkMeta.c"
     "${SERL_SRC_DIR}/sd_errorReport.c"
     "${SERL_SRC_DIR}/sd_list.c"
     "${SERL_SRC_DIR}/sd_misc.c"
     "${SERL_SRC_DIR}/sd_randomizer.c"
     "${SERL_SRC_DIR}/sd_serializerBigE.c"
     "${SERL_SRC_DIR}/sd_serializer.c"
     "${SERL_SRC_DIR}/sd_serializerXML.c"
     "${SERL_SRC_DIR}/sd_serializerXMLMetadata.c"
     "${SERL_SRC_DIR}/sd_serializerXMLTypeinfo.c"
     "${SERL_SRC_DIR}/sd_string.c"
     "${SERL_SRC_DIR}/sd_stringsXML.c"
     "${SERL_SRC_DIR}/sd_typeInfoParser.c"
     "${SERL_SRC_DIR}/sd_xmlNode.c"
     "${SERL_SRC_DIR}/sd_xmlParser.c")

# Utilities
set(UTIL_SRC_DIR "${IDLPP_OSPLI}/src/utilities/code")
list(APPEND SOURCES
     "${UTIL_SRC_DIR}/ut_stack.c"
     "${UTIL_SRC_DIR}/ut_collection.c"
     "${UTIL_SRC_DIR}/ut_avl.c")

# Utilities
set(CPP_SRC_DIR "${IDLPP_OSPLI}/src/cpp/code")
list(APPEND SOURCES
     "${CPP_SRC_DIR}/accum.c"
     "${CPP_SRC_DIR}/at.c"
     "${CPP_SRC_DIR}/autodef.c"
     "${CPP_SRC_DIR}/copyof.c"
     "${CPP_SRC_DIR}/debug.c"
     "${CPP_SRC_DIR}/define.c"
     "${CPP_SRC_DIR}/dump.c"
     "${CPP_SRC_DIR}/error.c"
     "${CPP_SRC_DIR}/eval.c"
     "${CPP_SRC_DIR}/expand.c"
     "${CPP_SRC_DIR}/expr.c"
     "${CPP_SRC_DIR}/if.c"
     "${CPP_SRC_DIR}/include.c"
     "${CPP_SRC_DIR}/io.c"
     "${CPP_SRC_DIR}/is.c"
     "${CPP_SRC_DIR}/line.c"
     "${CPP_SRC_DIR}/pragma.c"
     "${CPP_SRC_DIR}/predefs.c"
     "${CPP_SRC_DIR}/preprocess.c"
     "${CPP_SRC_DIR}/set.c"
     "${CPP_SRC_DIR}/sharp.c"
     "${CPP_SRC_DIR}/symtbl.c"
     "${CPP_SRC_DIR}/unctrl.c"
     "${CPP_SRC_DIR}/undef.c"
     "${CPP_SRC_DIR}/while.c")

add_library(ppresources INTERFACE)
target_sources(ppresources INTERFACE ${SOURCES})

target_include_directories(ppresources INTERFACE
                           "${IDLPP_OSPLI}/src/abstraction/os/include"
                           "${IDLPP_OSPLI}/src/database/database/include"
                           "${IDLPP_OSPLI}/src/database/serialization/include"
                           "${IDLPP_OSPLI}/src/utilities/include"
                           "${IDLPP_OSPLI}/src/cpp/code"
                           "${IDLPP_OSPLI}/src/cpp/include"
                           "${IDLPP_OSPLI}/src/abstraction/os/${IDLPP_OS}"
                           "${IDLPP_OSPLI}/src/database/database/code")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
target_link_libraries(ppresources INTERFACE Threads::Threads)
target_compile_definitions(ppresources INTERFACE -DOSPL_BUILD_CORE)

if(UNIX)
  target_link_libraries(ppresources INTERFACE m)
  if(NOT APPLE)
    target_link_libraries(ppresources INTERFACE rt)
  endif()
endif()

if(${CMAKE_C_COMPILER_ID} STREQUAL "SunPro")
  target_link_libraries(ppresources INTERFACE socket nsl)
endif()
