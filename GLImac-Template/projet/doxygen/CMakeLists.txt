find_package (Doxygen)

message("vectorD_SOURCE_DIR     " ${vectorD_SOURCE_DIR})
message("vectorD_BINARY_DIR     " ${vectorD_BINARY_DIR})
message("DOXYGEN_EXECUTABLE     " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${vectorD_SOURCE_DIR}/doc/Doxyfile-html.cmake ${vectorD_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${vectorD_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)
