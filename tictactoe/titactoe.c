#include <stdio.h>
int displayBoard();
int playerMove(char);
int checkFreeSpaces();
char checkWinner();

char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };
const char PLAYER[2] = {'X', 'O'};

int main()
{
    int a = 5;
    int i = 0;
    int free;
    while(a > 1 && checkFreeSpaces() != 0){
        displayBoard();
        char w = checkWinner();
        if(w == 'X' || w == 'O'){
            printf("The winner is %c\n", w);
            break;
        }
        if (playerMove(PLAYER[i]) == 0) {
         // skiip1
        }else if(playerMove(PLAYER[i]) == 1){
            playerMove(PLAYER[i]);
        }
        printf("\n\n");

        if(i==1){
            i--;
        }
        else{
            i++;
        }
        
    }
    if(checkFreeSpaces() == 0){
        printf("\nDraw!!\n");   
    }
}

int displayBoard(){
    /*
    This function displays board in console.
    */
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", board[i][j]);
            if (j<2) printf("|");
        }
            printf("\n");

        if (i<2){
            printf("---|---|---");
        }
            printf("\n");
    }
}

int playerMove(char player){
    char positon;
    printf("Player %c turn\n", player);
    printf("Enter postion: ");
    scanf(" %c", &positon); //space befoer %c will handle spaces or new line from previous input operation

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == positon){
                board[i][j] = player;
                return 0;
            }
        }
    }
    printf("\nInvalid Postion!\n");
    return 1;

}

int checkFreeSpaces(){
    int free = 9;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (board[i][j] == 'X' || board[i][j] == 'O'){
                free--;
            }
        }
    }
    return free;
}

char checkWinner(){
    // check horizontally
    for(int i=0; i<3; i++){  
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][0]){
            return board[i][0];
        }
    }

    // check vertically
    for(int i=0; i<3; i++){  
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[0][i]){
            return board[0][i];
        }
    }

    // check diagonally
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[0][0]){
        return board[0][0];
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == board[2][0]){
        return board[2][0];
    }

    return 'n';

}