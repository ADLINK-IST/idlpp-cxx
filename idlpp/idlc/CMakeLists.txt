#
# Copyright(c) 2006 to 2019 ADLINK Technology Limited and others
#
cmake_minimum_required(VERSION 3.7)

find_package(Maven 3.0 REQUIRED)
find_package(Java 1.8 REQUIRED)

set(IDLC_SRC_DIR "${IDLPP_VLITE}/build/java/")

file(GLOB_RECURSE IDLC_G_SOURCES    LIST_DIRECTORIES true ${IDLC_SRC_DIR} *.g)
file(GLOB_RECURSE IDLC_G4_SOURCES   LIST_DIRECTORIES true ${IDLC_SRC_DIR} *.g4)
file(GLOB_RECURSE IDLC_JAVA_SOURCES LIST_DIRECTORIES true ${IDLC_SRC_DIR} *.java)
file(GLOB_RECURSE IDLC_ST_SOURCES   LIST_DIRECTORIES true ${IDLC_SRC_DIR} *.st?)

set(IDLCPP_C_JAR "${CMAKE_CURRENT_BINARY_DIR}/target/idlcpp-c-jar-with-dependencies.jar")
mark_as_advanced(IDLCPP_C_JAR)

set(IDLC_POM_FILE "src/pom.xml.in")
configure_file(${IDLC_POM_FILE} "pom.xml" @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/Project.java.in" "${CMAKE_CURRENT_BINARY_DIR}/src/Project.java")

configure_file("${IDLPP_VLITE}/lib/java/idtpp.jar" "${CMAKE_CURRENT_BINARY_DIR}/target/idtpp.jar" COPYONLY)

add_custom_target(
    idlcpp_c
    ALL
    "${Maven_EXECUTABLE}" "-q" "package"
    DEPENDS ${IDLC_POM_FILE} ${IDLC_G_SOURCES} ${IDLC_G4_SOURCES} ${IDLC_JAVA_SOURCES} ${IDLC_ST_SOURCES}
    BYPRODUCTS "${IDLCPP_C_JAR}"
    COMMENT "Building JAR file ${IDLCPP_C_JAR}")

install(
    FILES "${IDLCPP_C_JAR}"
    DESTINATION "${IDLPP_DESTINATION_INSTALL}"
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    COMPONENT dev)

install(
    FILES "${IDLPP_VLITE}/lib/java/idtpp.jar"
    DESTINATION "${IDLPP_DESTINATION_INSTALL}"
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    COMPONENT dev)
