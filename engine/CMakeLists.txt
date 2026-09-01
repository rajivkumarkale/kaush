add_library(engine SHARED
  src/test.c
)

target_compile_definitions(engine
  PRIVATE
    _DEBUG
    KEXPORT
)

target_compile_options(engine
  PRIVATE
    -fdeclspec
)

target_include_directories(engine
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    $ENV{VULKAN_SDK}/include
)

target_link_directories(engine
  PRIVATE
    $ENV{VULKAN_SDK}/lib
    /usr/X11R6/lib
)

target_link_libraries(engine
  PRIVATE
    vulkan
    xcb
    X11
    X11-xcb
    xkbcommon
)

