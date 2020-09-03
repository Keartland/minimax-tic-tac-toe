#include <stdio.h>
#include <stdlib.h>


char board[9];
int running;
void drawBoard(char printedBoard[10]){
    //print the a b c for location
    printf("   a   b   c\n");
    for(int i=0;i<9;i+=3){
        //prints each line and the number of the line for the user to input
        printf("%d: %c | %c | %c \n",1+(i+1)/3, printedBoard[i], printedBoard[i+1], printedBoard[i+2]);
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
    board[(pos[0]-'a')+3*(pos[1]-'1')] = letter;
    printf("you entered %s\n", pos);
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
    for(int i=0;i<9;i++){
        if(checkBoard[i] == 32){
            return 0;
        }
    }
    return 'd';
}

int getValue(char toBeCopiedBoard[10], char curGo,char playerGo){
    char checkBoard[10];
    for (int i=0;i<9;i++){
        checkBoard[i] = toBeCopiedBoard[i];
    }
    int win = checkIfContinue(checkBoard);
    if(win != 0){
        if (win == playerGo){
            return 10;
        } else if (win == 'd'){
            return 0;
        } else { 
            return -10;
        }
    } else {
        int movePos[10];
        for (int i=0;i<9;i++){
            // if board at i is empty
            movePos[i] = 0;
            if(checkBoard[i] == 32){
                checkBoard[i] = curGo;
                char nextGo = curGo == 'x' ? 'o' : 'x'; 
                int g = getValue(checkBoard, nextGo ,playerGo);
                movePos[i] = g;
                // set value for this move;
            }
        }


        int bestMove;
        if (curGo == playerGo){
            int bestScore = -10000;
            for (int i=0;i<9;i++){
                if (movePos[i] > bestScore){
                    bestScore = movePos[i];
                    bestMove = i;
                }
            }
        } else {
            int bestScore = 10000;
            for (int i=0;i<9;i++){
                if (movePos[i] < bestScore){
                    bestScore = movePos[i];
                    bestMove = i;
                }
            }
        }
        return bestMove;
    }
}
int main(){
    for(int i=0;i<9;i++){
        board[i] = ' ';
    }
    char ended=0;
    char cur = 'x';
    while(!ended){
        drawBoard(board);
        int val = getValue(board, cur, cur);
        printf("\nwinning pos for %c: %c%c %d\n",cur,'a' +  val%3,'1' + val/3, val);
        doGo(cur);
        ended = checkIfContinue(board);
        cur = cur == 'x' ? 'o' : 'x'; 
    }
    printf("\nwinner: %c\n", ended);
}
