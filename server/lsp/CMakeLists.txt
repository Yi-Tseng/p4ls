add_library(lsp
  context.cpp
  context.h
  dispatcher.cpp
  dispatcher.h
  lsp_server.cpp
  lsp_server.h
  p4unit.cpp
  p4unit.h
  protocol.cpp
  protocol.h)

add_dependencies(lsp p4l)

target_compile_options(lsp PRIVATE
  "-g"
  "-Wall"
  "-Werror"
  "-Wextra"
  "-fvisibility=hidden"
  "-fvisibility-inlines-hidden")

target_include_directories(lsp
  PUBLIC
  ${PROJECT_SOURCE_DIR}/server/p4l)

target_link_libraries(lsp PUBLIC
  coverage_config
  RapidJSON::rapidjson)
