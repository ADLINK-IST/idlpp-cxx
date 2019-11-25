#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

set(IDLPP_SRC_DIR "${IDLPP_OSPLI}/src/tools/idlpp/code")
set(SOURCES
    "${IDLPP_SRC_DIR}/idl_catsDef.c"
    "${IDLPP_SRC_DIR}/idl_constSpecifier.c"
    "${IDLPP_SRC_DIR}/idl_databaseValidation.c"
    "${IDLPP_SRC_DIR}/idl_dependencies.c"
    "${IDLPP_SRC_DIR}/idl_dll.c"
    "${IDLPP_SRC_DIR}/idl_fileMap.c"
    "${IDLPP_SRC_DIR}/idl_genCHelper.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCCopyin.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCCopyout.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCHelper.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCxxCcpp.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCxxCopyin.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCxxCopyout.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCxxHelper.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaCxxStreamsCcpp.c"
    "${IDLPP_SRC_DIR}/idl_genCorbaJavaHelper.c"
    "${IDLPP_SRC_DIR}/idl_genCxxHelper.c"
    "${IDLPP_SRC_DIR}/idl_genCxxStreamsDefs.c"
    "${IDLPP_SRC_DIR}/idl_genCxxStreamsIdl.c"
    "${IDLPP_SRC_DIR}/idl_genCxxStreamsImpl.c"
    "${IDLPP_SRC_DIR}/idl_genCxxTypedClassDefs.c"
    "${IDLPP_SRC_DIR}/idl_genCxxTypedClassImpl.c"
    "${IDLPP_SRC_DIR}/idl_genIdl.c"
    "${IDLPP_SRC_DIR}/idl_genIdlHelper.c"
    "${IDLPP_SRC_DIR}/idl_genISOCxx2Copyout.c"
    "${IDLPP_SRC_DIR}/idl_genISOCxx2Header.c"
    "${IDLPP_SRC_DIR}/idl_genISOCxx2Helper.c"
    "${IDLPP_SRC_DIR}/idl_genISOCxx2Type.c"
    "${IDLPP_SRC_DIR}/idl_genISOCxxHeader.c"
    "${IDLPP_SRC_DIR}/idl_genJavaHelper.c"
    "${IDLPP_SRC_DIR}/idl_genLanguageHelper.c"
    "${IDLPP_SRC_DIR}/idl_genLiteCxxCopyin.c"
    "${IDLPP_SRC_DIR}/idl_genLiteCxxCopyout.c"
    "${IDLPP_SRC_DIR}/idl_genLiteHelper.c"
    "${IDLPP_SRC_DIR}/idl_genLiteISOCxxCopyin.c"
    "${IDLPP_SRC_DIR}/idl_genLiteISOCxxCopyout.c"
    "${IDLPP_SRC_DIR}/idl_genLiteISOCxxHeader.c"
    "${IDLPP_SRC_DIR}/idl_genMetaHelper.c"
    "${IDLPP_SRC_DIR}/idl_genSacHelper.c"
    "${IDLPP_SRC_DIR}/idl_genSacMeta.c"
    "${IDLPP_SRC_DIR}/idl_genSacObjectControl.c"
    "${IDLPP_SRC_DIR}/idl_genSACPPType.c"
    "${IDLPP_SRC_DIR}/idl_genSACPPTypedClassDefs.c"
    "${IDLPP_SRC_DIR}/idl_genSACPPTypedClassImpl.c"
    "${IDLPP_SRC_DIR}/idl_genSACPPTypeImpl.c"
    "${IDLPP_SRC_DIR}/idl_genSACSHelper.c"
    "${IDLPP_SRC_DIR}/idl_genSACSSplDcps.c"
    "${IDLPP_SRC_DIR}/idl_genSACSType.c"
    "${IDLPP_SRC_DIR}/idl_genSACSTypedClassDefs.c"
    "${IDLPP_SRC_DIR}/idl_genSacType.c"
    "${IDLPP_SRC_DIR}/idl_genSacTypedClassDefs.c"
    "${IDLPP_SRC_DIR}/idl_genSacTypedClassImpl.c"
    "${IDLPP_SRC_DIR}/idl_genSajHolder.c"
    "${IDLPP_SRC_DIR}/idl_genSajMeta.c"
    "${IDLPP_SRC_DIR}/idl_genSajType.c"
    "${IDLPP_SRC_DIR}/idl_genSajTypedClass.c"
    "${IDLPP_SRC_DIR}/idl_genSplHelper.c"
    "${IDLPP_SRC_DIR}/idl_genSpliceDep.c"
    "${IDLPP_SRC_DIR}/idl_genSpliceLiteISOCxxType.c"
    "${IDLPP_SRC_DIR}/idl_genSpliceLiteType.c"
    "${IDLPP_SRC_DIR}/idl_genSpliceLoad.c"
    "${IDLPP_SRC_DIR}/idl_genSpliceType.c"
    "${IDLPP_SRC_DIR}/idl_genTypeDescriptors.c"
    "${IDLPP_SRC_DIR}/idl_genTypeSize.c"
    "${IDLPP_SRC_DIR}/idl_keyDef.c"
    "${IDLPP_SRC_DIR}/idl_main.c"
    "${IDLPP_SRC_DIR}/idl_map.c"
    "${IDLPP_SRC_DIR}/idl_parser.c"
    "${IDLPP_SRC_DIR}/idl_registerType.c"
    "${IDLPP_SRC_DIR}/idl_scope.c"
    "${IDLPP_SRC_DIR}/idl_sematicRules.c"
    "${IDLPP_SRC_DIR}/idl_stacDef.c"
    "${IDLPP_SRC_DIR}/idl_streamsDef.c"
    "${IDLPP_SRC_DIR}/idl_tmplExp.c"
    "${IDLPP_SRC_DIR}/idl_typeSpecifier.c"
    "${IDLPP_SRC_DIR}/idl_unsupported.c"
    "${IDLPP_SRC_DIR}/idl_walk.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/idl_base.c")

add_executable(idlpp ${SOURCES})

target_link_libraries(idlpp PRIVATE ppresources)
if(NOT WIN32)
  target_link_libraries(idlpp PRIVATE m)
endif()

target_include_directories(idlpp PRIVATE
                           "${IDLPP_OSPLI}/src/tools/idlpp/include"
                           "${IDLPP_OSPLI}/src/tools/idlpp/code")
add_dependencies(idlpp idlcpp_c)

# Force the idlpp to be at the same location, no matter what platform or build type.
set_target_properties(
        idlpp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY                "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     "${CMAKE_BINARY_DIR}/bin" )
# Let all of CMake know the location and name of the idl application.
set(IDLPP_EXE "${CMAKE_BINARY_DIR}/bin/idlpp${CMAKE_EXECUTABLE_SUFFIX}" PARENT_SCOPE)

# Let all of CMake know the location of the idl templates.
set(IDLPP_TEMPLATES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/templates" PARENT_SCOPE)

install(
  TARGETS idlpp
  DESTINATION "${IDLPP_DESTINATION_INSTALL}"
  COMPONENT dev)

install(
  DIRECTORY templates
  DESTINATION "${IDLPP_DESTINATION_INSTALL}"
  COMPONENT dev)

