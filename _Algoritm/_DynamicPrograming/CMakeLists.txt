string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_NAME ${CURRENT_FOLDER})

add_subdirectory(DP_Knapsack)
add_subdirectory(DP_ChangeMaking)
add_subdirectory(DP_CoinRow)
add_subdirectory(DP_Fibonacci)
add_subdirectory(DP_CoinCollection)