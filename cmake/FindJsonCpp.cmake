include (FindPackageHandleStandardArgs)

if (NOT JSONCPP_FOUND)
  find_path(JSONCPP_INCLUDE_DIRS NAMES jsoncpp/json/json.h PATHS /usr PATH_SUFFIXES include)
  find_library(JSONCPP_LIBRARIES NAMES jsoncpp PATHS /usr PATH_SUFFIXES lib)
  find_package_handle_standard_args(JsonCpp DEFAULT_MSG JSONCPP_LIBRARIES JSONCPP_INCLUDE_DIRS)
  mark_as_advanced(JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)
endif ()
