typedef (*ValidMoves)(char team[5], char board[8][8], PositionHandler pos_handler);
// typedef (*PlayMove)(int position[2], int board[8][8], PositionHandler pos_handler);
// // typedef (*__init__)(int position[2]);

// typedef struct ValData {
//     int all_moves[25][2];
// }ValData;

// typedef struct Pawn {
//     char symbol;
//     char name[4];
//     char team;
//     ValidMoves valid_moves;
//     PlayMove play_move;
// }Pawn;

// ValData ValMoves(char team[5], char board[8][8], PositionHandler pos_handler){
//     // if (strcmp("white", team) == 0)
// }