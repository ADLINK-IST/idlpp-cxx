#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

if (WIN32)
    add_definitions("/wd4267") # size_t to int
    add_definitions("/wd4996") # unsave function
endif(WIN32)

set(CPPGEN_SRC_DIR "${IDLPP_OSPLI}/src/tools/cppgen/code")
set(SOURCES
    "${CPPGEN_SRC_DIR}/ast_argument.cpp"
    "${CPPGEN_SRC_DIR}/ast_array.cpp"
    "${CPPGEN_SRC_DIR}/ast_attribute.cpp"
    "${CPPGEN_SRC_DIR}/ast_boxed_value.cpp"
    "${CPPGEN_SRC_DIR}/ast_check.cpp"
    "${CPPGEN_SRC_DIR}/ast_concrete_type.cpp"
    "${CPPGEN_SRC_DIR}/ast_constant.cpp"
    "${CPPGEN_SRC_DIR}/ast_decl.cpp"
    "${CPPGEN_SRC_DIR}/ast_enum.cpp"
    "${CPPGEN_SRC_DIR}/ast_enum_val.cpp"
    "${CPPGEN_SRC_DIR}/ast_exception.cpp"
    "${CPPGEN_SRC_DIR}/ast_expression.cpp"
    "${CPPGEN_SRC_DIR}/ast_field.cpp"
    "${CPPGEN_SRC_DIR}/ast_generator.cpp"
    "${CPPGEN_SRC_DIR}/ast_hdrs.cpp"
    "${CPPGEN_SRC_DIR}/ast_initializer.cpp"
    "${CPPGEN_SRC_DIR}/ast_interface.cpp"
    "${CPPGEN_SRC_DIR}/ast_interface_fwd.cpp"
    "${CPPGEN_SRC_DIR}/ast_module.cpp"
    "${CPPGEN_SRC_DIR}/ast_opaque.cpp"
    "${CPPGEN_SRC_DIR}/ast_operation.cpp"
    "${CPPGEN_SRC_DIR}/ast_predefined_type.cpp"
    "${CPPGEN_SRC_DIR}/ast_recursive.cpp"
    "${CPPGEN_SRC_DIR}/ast_redef.cpp"
    "${CPPGEN_SRC_DIR}/ast_root.cpp"
    "${CPPGEN_SRC_DIR}/ast_sequence.cpp"
    "${CPPGEN_SRC_DIR}/ast_statemember.cpp"
    "${CPPGEN_SRC_DIR}/ast_string.cpp"
    "${CPPGEN_SRC_DIR}/ast_structure.cpp"
    "${CPPGEN_SRC_DIR}/ast_type.cpp"
    "${CPPGEN_SRC_DIR}/ast_typedef.cpp"
    "${CPPGEN_SRC_DIR}/ast_union_branch.cpp"
    "${CPPGEN_SRC_DIR}/ast_union.cpp"
    "${CPPGEN_SRC_DIR}/ast_union_label.cpp"
    "${CPPGEN_SRC_DIR}/ast_value.cpp"
    "${CPPGEN_SRC_DIR}/ast_value_fwd.cpp"
    "${CPPGEN_SRC_DIR}/cppgen.cpp"
    "${CPPGEN_SRC_DIR}/drv_args.cpp"
    "${CPPGEN_SRC_DIR}/drv_fork.cpp"
    "${CPPGEN_SRC_DIR}/drv_init.cpp"
    "${CPPGEN_SRC_DIR}/drv_link.cpp"
    "${CPPGEN_SRC_DIR}/drv_main.cpp"
    "${CPPGEN_SRC_DIR}/drv_param.cpp"
    "${CPPGEN_SRC_DIR}/drv_preproc.cpp"
    "${CPPGEN_SRC_DIR}/drv_private.cpp"
    "${CPPGEN_SRC_DIR}/fe_cpp_keyword.c"
    "${CPPGEN_SRC_DIR}/fe_declarator.cpp"
    "${CPPGEN_SRC_DIR}/fe_extern.cpp"
    "${CPPGEN_SRC_DIR}/fe_init.cpp"
    "${CPPGEN_SRC_DIR}/fe_interface_header.cpp"
    "${CPPGEN_SRC_DIR}/fe_private.cpp"
    "${CPPGEN_SRC_DIR}/fe_value_header.cpp"
    "${CPPGEN_SRC_DIR}/fe_value_inheritance_spec.cpp"
    "${CPPGEN_SRC_DIR}/lex_yy.cpp"
    "${CPPGEN_SRC_DIR}/nr_narrow.cpp"
    "${CPPGEN_SRC_DIR}/std.cpp"
    "${CPPGEN_SRC_DIR}/utl_decllist.cpp"
    "${CPPGEN_SRC_DIR}/utl_error.cpp"
    "${CPPGEN_SRC_DIR}/utl_exceptlist.cpp"
    "${CPPGEN_SRC_DIR}/utl_exprlist.cpp"
    "${CPPGEN_SRC_DIR}/utl_global.cpp"
    "${CPPGEN_SRC_DIR}/utl_identifier.cpp"
    "${CPPGEN_SRC_DIR}/utl_idlist.cpp"
    "${CPPGEN_SRC_DIR}/utl_indenter.cpp"
    "${CPPGEN_SRC_DIR}/utl_labellist.cpp"
    "${CPPGEN_SRC_DIR}/utl_list.cpp"
    "${CPPGEN_SRC_DIR}/utl_namelist.cpp"
    "${CPPGEN_SRC_DIR}/utl_pragmas.cpp"
    "${CPPGEN_SRC_DIR}/utl_scope.cpp"
    "${CPPGEN_SRC_DIR}/utl_stack.cpp"
    "${CPPGEN_SRC_DIR}/utl_string.cpp"
    "${CPPGEN_SRC_DIR}/utl_strlist.cpp"
    "${CPPGEN_SRC_DIR}/utl_wstring.cpp"
    "${CPPGEN_SRC_DIR}/xbe_arglist.cpp"
    "${CPPGEN_SRC_DIR}/xbe_args.cpp"
    "${CPPGEN_SRC_DIR}/xbe_argument2.cpp"
    "${CPPGEN_SRC_DIR}/xbe_argument.cpp"
    "${CPPGEN_SRC_DIR}/xbe_array.cpp"
    "${CPPGEN_SRC_DIR}/xbe_attribute.cpp"
    "${CPPGEN_SRC_DIR}/xbe_classes.cpp"
    "${CPPGEN_SRC_DIR}/xbe_classgen.cpp"
    "${CPPGEN_SRC_DIR}/xbe_codegen.cpp"
    "${CPPGEN_SRC_DIR}/xbe_constant.cpp"
    "${CPPGEN_SRC_DIR}/xbe_cppfwd.cpp"
    "${CPPGEN_SRC_DIR}/xbe_cppname.cpp"
    "${CPPGEN_SRC_DIR}/xbe_cppscope.cpp"
    "${CPPGEN_SRC_DIR}/xbe_cpptype.cpp"
    "${CPPGEN_SRC_DIR}/xbe_direction.cpp"
    "${CPPGEN_SRC_DIR}/xbe_dispatchable.cpp"
    "${CPPGEN_SRC_DIR}/xbe_dispatcher.cpp"
    "${CPPGEN_SRC_DIR}/xbe_enum.cpp"
    "${CPPGEN_SRC_DIR}/xbe_exception.cpp"
    "${CPPGEN_SRC_DIR}/xbe_expr_val.cpp"
    "${CPPGEN_SRC_DIR}/xbe_field.cpp"
    "${CPPGEN_SRC_DIR}/xbe_generator.cpp"
    "${CPPGEN_SRC_DIR}/xbe_genlist.cpp"
    "${CPPGEN_SRC_DIR}/xbe_globals.cpp"
    "${CPPGEN_SRC_DIR}/xbe_hash.cpp"
    "${CPPGEN_SRC_DIR}/xbe_incl.cpp"
    "${CPPGEN_SRC_DIR}/xbe_init.cpp"
    "${CPPGEN_SRC_DIR}/xbe_interface2.cpp"
    "${CPPGEN_SRC_DIR}/xbe_interface3.cpp"
    "${CPPGEN_SRC_DIR}/xbe_interface.cpp"
    "${CPPGEN_SRC_DIR}/xbe_invoke.cpp"
    "${CPPGEN_SRC_DIR}/xbe_literals.cpp"
    "${CPPGEN_SRC_DIR}/xbe_module.cpp"
    "${CPPGEN_SRC_DIR}/xbe_operation.cpp"
    "${CPPGEN_SRC_DIR}/xbe_opnameset.cpp"
    "${CPPGEN_SRC_DIR}/xbe_predefined.cpp"
    "${CPPGEN_SRC_DIR}/xbe_produce.cpp"
    "${CPPGEN_SRC_DIR}/xbe_root.cpp"
    "${CPPGEN_SRC_DIR}/xbe_sequence.cpp"
    "${CPPGEN_SRC_DIR}/xbe_source.cpp"
    "${CPPGEN_SRC_DIR}/xbe_string.cpp"
    "${CPPGEN_SRC_DIR}/xbe_structure.cpp"
    "${CPPGEN_SRC_DIR}/xbe_time.cpp"
    "${CPPGEN_SRC_DIR}/xbe_type.cpp"
    "${CPPGEN_SRC_DIR}/xbe_typedef.cpp"
    "${CPPGEN_SRC_DIR}/xbe_union.cpp"
    "${CPPGEN_SRC_DIR}/xbe_utils.cpp"
    "${CPPGEN_SRC_DIR}/xbe_value.cpp"
    "${CPPGEN_SRC_DIR}/xps_string.cpp"
    "${CPPGEN_SRC_DIR}/xps_vector.cpp"
    "${CPPGEN_SRC_DIR}/y_tab.cpp")

add_executable(cppgen ${SOURCES})
target_link_libraries(cppgen PRIVATE ppresources)
target_include_directories(cppgen PRIVATE
                           "${IDLPP_VLITE}/include/cpp"
                           "${IDLPP_OSPLI}/src/tools/cppgen/code"
                           "${IDLPP_OSPLI}/src/tools/cppgen/include")
target_compile_definitions(cppgen PRIVATE -DOSPL_BULD_CPP_SHARED -DOSPL_BUILD_CPP)
add_dependencies(cppgen idlcpp_c)

# Force the cppgen to be at the same location, no matter what platform or build type.
set_target_properties(
        cppgen
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY                "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     "${CMAKE_BINARY_DIR}/bin" )
# Let all of CMake know the location and name of the idl application.
set(CPPGEN_EXE "${CMAKE_BINARY_DIR}/bin/cppgen${CMAKE_EXECUTABLE_SUFFIX}" PARENT_SCOPE)

install(
  TARGETS cppgen
  DESTINATION "${IDLPP_DESTINATION_INSTALL}"
  COMPONENT dev)
