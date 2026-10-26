add_subdirectory(external/glad)
add_subdirectory(external/glm)
add_subdirectory(external/glfw)

add_library(engine)

target_sources(engine
    PRIVATE
        src/Shader.cpp
        src/Camera.cpp
        src/Circle.cpp
        src/App.cpp
)

target_include_directories(engine
    PUBLIC
        include
)

target_link_libraries(engine
    PUBLIC
        glad
        glm
        glfw
)
