find_package (Doxygen)

message("ProjetOGL_SOURCE_DIR     " ${ProjetOGL_SOURCE_DIR})
message("ProjetOGL_BINARY_DIR     " ${ProjetOGL_BINARY_DIR})
message("DOXYGEN_EXECUTABLE     " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${ProjetOGL_SOURCE_DIR}/projet/doxygen/Doxyfile-html.cmake ${ProjetOGL_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${ProjetOGL_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
