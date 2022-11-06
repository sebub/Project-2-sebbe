add_executable(game_of_lines  game_of_lines.c game_of_lines.h global.h global.c WinCheck.c WinCheck.h)

add_library(WinCheck WinCheck.c)