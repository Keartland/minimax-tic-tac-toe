#include <stdio.h>
#include <stdlib.h>


char board[10];
int running;
void drawBoard(){
    //print the a b c for location
    printf("   a   b   c\n");
    for(int i=0;i<9;i+=3){
        //prints each line and the number of the line for the user to input
        printf("%d: %c | %c | %c \n",1+(i+1)/3, board[i], board[i+1], board[i+2]);
    }
}
void doGo(char letter){
    int entered=0;
    char pos[4];
    do{
        printf("please input where you want to put your %c[example a1]: ", letter);
        fgets(pos,4,stdin);
        if(pos[0] >= 'a' && pos[0] <= 'c' && pos[1] > '0' && pos[1] <= '3'){
            entered = 1;
        }
    } while(!entered);
    printf("%d",(pos[0]-'a')+3*(pos[1]-'1'));
    board[(pos[0]-'a')+3*(pos[1]-'1')] = letter;
    printf("you entered %s\n", pos);
}
void doOGo(){
}
int getValue(){
    
}
//returns wether the game is over by saying the player that wins, 0 is continue, 120 is player x, 111 is player o
int checkIfContinue(char checkBoard[10]){
    //rows
    if (checkBoard[0] == checkBoard[1] && checkBoard[0]==checkBoard[2] && checkBoard[0] != 32) return checkBoard[0];
    if (checkBoard[3] == checkBoard[4] && checkBoard[3]==checkBoard[5] && checkBoard[3] != 32) return checkBoard[3];
    if (checkBoard[6] == checkBoard[7] && checkBoard[6]==checkBoard[8] && checkBoard[6] != 32) return checkBoard[6];
    //columns
    if (checkBoard[0] == checkBoard[3] && checkBoard[0]==checkBoard[6] && checkBoard[0] != 32) return checkBoard[0];
    if (checkBoard[1] == checkBoard[4] && checkBoard[1]==checkBoard[7] && checkBoard[1] != 32) return checkBoard[1];
    if (checkBoard[2] == checkBoard[5] && checkBoard[2]==checkBoard[8] && checkBoard[2] != 32) return checkBoard[2];
    //diags
    if (checkBoard[0] == checkBoard[4] && checkBoard[0]==checkBoard[8] && checkBoard[0] != 32) return checkBoard[0];
    if (checkBoard[2] == checkBoard[4] && checkBoard[2]==checkBoard[6] && checkBoard[2] != 32) return checkBoard[2];
    return 0;
}
int main(){
    for(int i=0;i<10;i++){
        board[i] = ' ';
    }
    int ended=0;
    char cur = 'x';
    while(!ended){
        drawBoard();
        doGo(cur);
        ended = checkIfContinue(board);
        if (cur == 'x') { cur = 'o' }
        else { cur = 'x' }
    }
    printf("\nwinner: %c\n", ended);
}
