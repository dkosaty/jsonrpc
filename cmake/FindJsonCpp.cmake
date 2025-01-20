include(FindPackageHandleStandardArgs)
include(GNUInstallDirs)

if (NOT JSONCPP_FOUND)
  find_path(JSONCPP_INCLUDE_DIRS
    NAMES jsoncpp/json/json.h
    PATHS /usr
    PATH_SUFFIXES ${CMAKE_INSTALL_INCLUDEDIR}
  )

  find_library(JSONCPP_LIBRARIES
    NAMES jsoncpp
    PATHS /usr
    PATH_SUFFIXES ${CMAKE_INSTALL_LIBDIR}
  )

  find_package_handle_standard_args(JsonCpp DEFAULT_MSG JSONCPP_LIBRARIES JSONCPP_INCLUDE_DIRS)

  mark_as_advanced(JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)

  add_library(JsonCpp::JsonCpp SHARED IMPORTED)

  set_target_properties(JsonCpp::JsonCpp PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${JSONCPP_INCLUDE_DIRS}
    IMPORTED_LOCATION ${JSONCPP_LIBRARIES}
  )
endif ()
