#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>

void generator(const int rows, const int columns, char field[rows][columns]){
    int i;
    int j;
    int hodnota1 = 16;

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){

        }
    }

    char balls[16] = {'^','^','^','^','@','@','@','@','*','*','*','*','+','+','+','+'};

    srand(time(NULL));

    int hodnota2 = rand() % 3;
    
    int hodnota3 = (rand() % 3) + 3;

    int nahodny = 0;

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            if(j == hodnota2 || j == hodnota3){
                field[i][j] = '\0';
            }else{
                nahodny = rand() % hodnota1;

                if(balls[nahodny] != '\0'){
                    field[i][j] = balls[nahodny];
                    balls[nahodny] = '\0';
                }else{
                    while(balls[nahodny] == '\0'){
                        nahodny = rand() % hodnota1;
                    }
                    field[i][j] = balls[nahodny];
                    balls[nahodny] = '\0';
                }
                printf("\n");
            }
        }
    }
}

bool check(const int rows, const int columns, char field[rows][columns]){
int i;
int j;

int hodnota1 = 0;
int stlpec = 0;

    for(i = 0; i < columns; i++){
        for(j = 1; j < rows; j++){
           if(field[i][j] == field[j - 1][i]){ 
              hodnota1++;
           }else{
              hodnota1 = 0;
            }
        }
        if(rows - 1 == hodnota1){
            stlpec++;
        }
        hodnota1 = 0;
    }
        if(columns == stlpec){
            return true;
        }else{
            return false;
        }
}
