
void scan_setting(int *gameMode, int *gameSizeX, int *gameSizeY, int *connetToWin);
int game_of_lines(int gameMode, int columns, int rows, int connetToWin);
void reset_arena(int rows, int columns,int (*board)[rows][columns]);
void print_arena(int rows, int columns,int (*board)[rows][columns]);
void scan_move(int mode,int rows, int columns, int (*board)[rows][columns]);
void update_arena(int player, int move, int rows,int columns, int(*board)[rows][move]);
void check_if_valid(int move,int columns, int rows, int(*board)[rows][columns]);
int ai_move(int columns);
bool winnerfound(int checkHorisontal);
int checkHorisontal(int rows, int columns, int(*board)[rows][columns], int wincon);