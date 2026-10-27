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
        src/Triangle.cpp
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

function(engine_copy_shaders target)
  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Shaders
            $<TARGET_FILE_DIR:${target}>/Shaders)
endfunction()