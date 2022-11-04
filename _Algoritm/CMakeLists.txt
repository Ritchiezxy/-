string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(BIG_MODULE_NAME ${CURRENT_FOLDER})

add_subdirectory(_DynamicPrograming)
add_subdirectory(_Greedy)
add_subdirectory(_DevideAndConquer)
add_subdirectory(_BranchAndBound)
add_subdirectory(_BackTracking)