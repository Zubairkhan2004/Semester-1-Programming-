#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(char you, char computer) {
    int result;

    if (you == computer) {
        result = -1;
    } else if (you == 'r' || you== 'R' && computer == 'p') {
        result = 0;
    } else if (you == 'p' || you== 'P' && computer == 'r') {
        result = 1;
    } else if (you == 'r' || you== 'R' && computer == 's') {
        result = 1;
    } else if (you == 'z' || you== 'Z' && computer == 'r') {
        result = 0; 
    } else if (you == 'p' || you== 'P' && computer == 's') {
        result = 0;
    } else if (you == 's' || you== 'S' && computer == 'p') {
        result = 1;
    }

    if (result == -1) {
        printf("PROGRAM TOU WARR GAYA\n");
    } else if (result == 1) {
        printf("PLAYER BHAI KE SAMNEY KOI KUCH BOL SAKTA HAI KYA!\n");
    } else {
        printf("UNFORTUNATELY MOYE MOYE HOGAYA!\n");
    }

    printf("You choose: %c and computer choose: %c\n", you, computer);
}
void rock(void)
{
    int n;
    char you, computer;
    int playAgain;

    srand(time(NULL));

    printf("Welcome to rock paper scissor game\n");
    
    

    while (1) {
        n = rand() % 3;

        if (n==1) {
            computer = 'r';
        } else if (n==2) {
            computer = 'p';
        } else {
            computer = 's';
        }

        printf("Enter your choice:\nPress r for rock\nPress p for paper\nPress s for scissor\nPress 0 to exit\n");
        scanf(" %c", &you);

        if (you != 's' && you != 'p' && you != 'r' && you != '0'&& you != 'S' && you != 'P' && you != 'R') {
            printf("AYEIN YEH KYA DABA DIA!\n");
            continue;
        }

        if (you == '0') {
            printf("BHAI DAR GAYA BHAI DAR GAYA!\n");
            break;
        }

        game(you, computer);

        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &playAgain);

        if (playAgain == 0) {
            printf("BHAI DAR GAYA BHAI DAR GAYA!\n");
            break;
        }
    }

}
