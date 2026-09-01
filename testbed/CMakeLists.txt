add_executable(testbed
  src/main.c
)

target_compile_definitions(testbed
  PRIVATE
    _DEBUG
    KIMPORT
)

target_compile_options(testbed
  PRIVATE
    -fdeclspec
)

target_link_libraries(testbed
  PRIVATE
    engine
)
