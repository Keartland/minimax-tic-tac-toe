#include <stdio.h>
#include <stdlib.h>


char board[10];
int running;
void drawBoard(){
    //print the a b c for location
    printf("   a   b   c\n");
    for(int i=0;i<3;i++){
        //prints each line and the number of the line for the user to input
        printf("%d: %c | %c | %c \n",i+1, board[i], board[i+1], board[i+2]);
    }
}
void doXGo(){
    int entered=0;
    char pos[3];
    while(!entered){
        printf("please input where you want to put your x[example a1]: ");
        fgets(pos,3,stdin);
        if(pos[0] >= 'a' && pos[0] <= 'c' && pos[1] > '0' && pos[1] <= '3'){
            entered = 1;
            break;
        }
    }
    printf("you entered %s\n", pos);
}
void doOGo(){

}
int checkIfContinue(){
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
        printf("%d", running);
    }
}