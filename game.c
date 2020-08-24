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
void doXGo(){
    int entered=0;
    char pos[4];
    do{
        printf("please input where you want to put your x[example a1]: ");
        fgets(pos,4,stdin);
        if(pos[0] >= 'a' && pos[0] <= 'c' && pos[1] > '0' && pos[1] <= '3'){
            entered = 1;
        }
    } while(!entered);
    printf("%d",(pos[0]-'a')+3*(pos[1]-'1'));
    board[(pos[0]-'a')+3*(pos[1]-'1')] = 'x';
    printf("you entered %s\n", pos);
}
void doOGo(){

}
//returns wether the game has been won or drawn
int checkIfContinue(){
    //rows
    if (board[0] == board[1] && board[0]==board[2] && board[0] != 32) return 0;
    if (board[3] == board[4] && board[3]==board[5] && board[3] != 32) return 0;
    if (board[6] == board[7] && board[6]==board[8] && board[6] != 32) return 0;
    //columns
    if (board[0] == board[3] && board[0]==board[6] && board[0] != 32) return 0;
    if (board[1] == board[4] && board[1]==board[7] && board[1] != 32) return 0;
    if (board[2] == board[5] && board[2]==board[8] && board[2] != 32) return 0;
    //diags
    if (board[0] == board[4] && board[0]==board[8] && board[0] != 32) return 0;
    if (board[2] == board[4] && board[2]==board[6] && board[2] != 32) return 0;
    return 1;
}
int main(){
    for(int i=0;i<10;i++){
        board[i] = ' ';
    }
    running=1;
    while(running){
        drawBoard();
        doXGo();
        doOGo();
        running = checkIfContinue();
        printf("score: %d\n", running);
    }
}
