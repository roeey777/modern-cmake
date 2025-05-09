# Doxygen-related
find_package(Doxygen REQUIRED)

# Find all the public headers
get_target_property(FACT_PUBLIC_HEADER_DIR Fact INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB_RECURSE FACT_PUBLIC_HEADERS ${FACT_PUBLIC_HEADER_DIR}/*.h)

set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/include)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs/)
set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# Replace variables inside @@ with the current values
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) # Doxygen won't create this for us
add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
                    DEPENDS ${FACT_PUBLIC_HEADER_DIR}
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                    MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                    COMMENT "Generating docs with Doxygen")

add_custom_target(Doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})


# Sphinx-related
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(Sphinx REQUIRED)
list(REMOVE_AT CMAKE_MODULE_PATH -1)

set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/docs/sphinx)
set(DOXYGEN_XML_DIRECTORY ${DOXYGEN_OUTPUT_DIR}/xml)
set(SPHINX_CONF_PY_COMMENT "This file was generated by cmake from conf.py.in - do not edit")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/source/conf.py.in
            ${CMAKE_CURRENT_SOURCE_DIR}/source/conf.py)

add_custom_target(Sphinx ALL
                  COMMAND
                  ${SPHINX_EXECUTABLE} -b html
                  ${SPHINX_SOURCE} ${SPHINX_BUILD}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                  COMMENT "Generating documentation with Sphinx")
add_dependencies(Sphinx Doxygen)

# Add an install target to install the docs
include(GNUInstallDirs)
install(DIRECTORY ${SPHINX_BUILD} DESTINATION ${CMAKE_INSTALL_DOCDIR})
