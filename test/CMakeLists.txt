add_executable(test_win_diagonal test_win_diagonal.c)       #add test file to be able to run
target_link_libraries(test_win_diagonal WinCheck) #link to the libary "functions" to access functions to test
add_test(NAME test_win_diagonal                    #add test and give it a name
        COMMAND test_win_diagonal)

add_executable(test_win_horizontal test_win_horizontal.c)       #add test file to be able to run
target_link_libraries(test_win_horizontal WinCheck) #link to the libary "functions" to access functions to test
add_test(NAME test_win_horizontal                    #add test and give it a name
        COMMAND test_win_horizontal)

add_executable(test_win_vertical test_win_vertical.c)       #add test file to be able to run
target_link_libraries(test_win_vertical WinCheck) #link to the libary "functions" to access functions to test
add_test(NAME test_win_vertical                    #add test and give it a name
        COMMAND test_win_vertical)