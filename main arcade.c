#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "snake.h"
#include "rock paper.h"

#define WIDTH 20
#define HEIGHT 20

int main() {
    int choice;

    while (1) {
    printf("\t\t\t\t********************************\n");
    printf("\t\t\t\t* WELCOME TO  MOYE MOYE ARCADE *\n");
    printf("\t\t\t\t********************************\n\n");
    printf("\t1) MOVING SNAKE\t\t2) ROCK PAPER SCISSORS\t\t3) QUIT\n");

        if (scanf("%d", &choice) != 1) {
            printf("AYEIN YEH KYA DABA DIA!\n");
            return 1; // Exit with an error code
        }

        switch (choice) {
            case 1:
                // Snake game
                snake();
                break;
            case 2:
                // Rock-paper-scissors game
                rock();
                break;
            case 3:
                // End
                printf("User has ended the arcade.\n");
                return 0; // Exit without errors
            default:
                printf("AYEIN YEH KYA DABA DIA!\n");
        }
    }

    return 0; 
}

