add_library(imgui)
target_sources(imgui
    PRIVATE
        src/imgui_demo.cpp
        src/imgui_draw.cpp
        src/imgui_impl_glfw.cpp
        src/imgui_impl_opengl3.cpp
        src/imgui_tables.cpp
        src/imgui_widgets.cpp
        src/imgui.cpp
)
target_include_directories(imgui
    PUBLIC
        include
)

