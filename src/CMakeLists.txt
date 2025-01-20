find_package(JsonCpp REQUIRED)

file(GLOB HEADERS *.h)
aux_source_directory(. SOURCES)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE JsonCpp::JsonCpp
)
