find_package(JsonCpp REQUIRED)

file(GLOB HEADERS *.h)
aux_source_directory(. SOURCES)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${JSONCPP_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC ${JSONCPP_LIBRARIES}
)
