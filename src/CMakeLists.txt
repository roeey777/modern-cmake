set(FACT_VERSION 1.0.0)
add_library(Fact fact.cpp)
add_library(Fact::Fact ALIAS Fact)

set_target_properties(Fact PROPERTIES EXPORT_NAME Fact)
target_include_directories(
    Fact PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>)

find_package(spdlog REQUIRED)
target_link_libraries(Fact PRIVATE project_options project_warnings
                                    spdlog::spdlog)

# Install
include(GNUInstallDirs)
message(STATUS "Generating install")
set(PROJECT_CONFIG_IN "${PROJECT_SOURCE_DIR}/cmake/FactConfig.cmake.in")
set(PROJECT_CONFIG_OUT "${CMAKE_CURRENT_BINARY_DIR}/FactConfig.cmake")
set(CONFIG_TARGETS_FILE "FactConfigTargets.cmake")
set(VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/FactConfigVersion.cmake")
set(INSTALL_CONFIG_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/Fact")
set(PC_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
set(PC_FILE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc")

# Install the library and add the target to export-set
install(
    TARGETS Fact project_options project_warnings
    EXPORT FactTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Install public headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# ----------------------------------------------------------------------------
# Install pkg-config file
# ----------------------------------------------------------------------------
get_target_property(PKG_CONFIG_DEFINES Fact INTERFACE_COMPILE_DEFINITIONS)
string(REPLACE ";" " -D" PKG_CONFIG_DEFINES "${PKG_CONFIG_DEFINES}")
string(CONCAT PKG_CONFIG_DEFINES "-D" "${PKG_CONFIG_DEFINES}")
configure_file("${PROJECT_SOURCE_DIR}/cmake/fact.pc.in" "${PC_FILE}" @ONLY)
install(FILES "${PC_FILE}" DESTINATION "${PC_INSTALL_DIR}")

# Install Targets.cmake file
install(
    EXPORT FactTargets
    FILE FactTargets.cmake
    NAMESPACE Fact::
    DESTINATION ${INSTALL_CONFIG_DIR})

# Create FactConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${VERSION_FILE}
    VERSION ${FACT_VERSION}
    COMPATIBILITY SameMajorVersion)

# Create FactConfig.cmake file
configure_package_config_file(${PROJECT_CONFIG_IN} ${PROJECT_CONFIG_OUT}
                              INSTALL_DESTINATION ${INSTALL_CONFIG_DIR})

# Install the config, configversion and custom find modules
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/FactConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/FactConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIG_DIR})
