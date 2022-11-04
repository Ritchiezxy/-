string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_NAME ${CURRENT_FOLDER})

add_subdirectory(Greedy_Knapsack)
add_subdirectory(Greedy_ChangeMaking)
add_subdirectory(Greedy_CoinRow)
add_subdirectory(Greedy_Fibonacci)
add_subdirectory(Greedy_CoinCollection)
add_subdirectory(Greedy_ActivitySelect)