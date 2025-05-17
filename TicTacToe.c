//Minor Project--Tic-Tac-Toe Game
#include <stdio.h>
//The Tic-Tac-Toe Board
char board[3][3];
//Function to initialize the Tic-Tac-Toe Board
void initializeBoard(){
    char K='1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=K;
            K++; 
        }
    }
}
//Function to display the Tic-Tac-Toe Board
void print_board(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ",board[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i<2){
                printf("---|---|---\n");
            }
    }
}
//Function to handle the player's move
void playerMove(int player) {
    int move;
    char symbol = (player == 1) ? 'X' : 'O';
    do {
        printf("Player %d, enter your move (box number 1-9): ", player);
        scanf("%d", &move);
        int x = (move - 1) / 3;
        int y = (move - 1) % 3;
        if(move >= 1 && move <= 9 && board[x][y] != 'X' && board[x][y] != 'O') {
            board[x][y] = symbol;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    } while(1);
}

//Function to check if there is a winner or if the game is over
char checkWinner(){
    //check rows
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
            return board[0][i];
        }
    }
    //check diagonals
     if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]) {
        return board[0][0];
    }
    if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
        return board[0][2];
    }
    
    // check whether the board is full
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (board[i][j] != 'X' && board[i][j] != 'O') {
            // If the game is not over
            return ' ';
        }
    }
  }
    // If no blocks are empty and no winner, the game is over
    return 'T';  // T for Tie or draw

}
// Function to start the Tic Tac Toe game
void startGame() {
    printf("===Tic-Tac-Toe-Game===\n");
    int player = 1;
    initializeBoard();
     while (1) {
        print_board();
        playerMove(player);
        char winner = checkWinner();

        if (winner != ' ') {
            if (winner == 'T') {
                printf("Game Over! It's a tie.\n");
            } else {
                printf("Player %d wins!\n", player);
            }
            break;
        }
        // Switch player turns
        if(player==1){
            player=2;
        }
        else{
            player=1;
        }
    }
}
int main(){
    startGame();
    return 0;
}