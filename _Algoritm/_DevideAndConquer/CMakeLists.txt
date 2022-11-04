string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_NAME ${CURRENT_FOLDER})

add_subdirectory(DnC_MergeSort)