#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define WIDTH 20
#define HEIGHT 20

void snake(void) 
{
	int restart=0;
	while (restart==0)
	{
        int x, y, fruitX, fruitY, score, gameOver, i, j, k;
        int tailX[100], tailY[100];
        int nTail = 0;
        char direction;
        int flag = 0;
        // Initial position
        x = WIDTH / 2;
        y = HEIGHT / 2;
        // Initial fruit position
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        score = 0;
        gameOver = 0;
        while (!gameOver) 
		{
            system("cls"); // Clear the screen
            for (i = 0; i < WIDTH + 2; i++)
            {
            	printf("-"); // Top wall
            }
                printf("\n");
            for (i = 0; i < HEIGHT; i++) 
			{
                for (j = 0; j < WIDTH; j++) 
				{
                    if (j == 0)
                    {
                    	printf("|"); // Left wall
					}
                    if (i == y && j == x)
                    {
                    	printf("S"); // Snake head
					}
                    else if (i == fruitY && j == fruitX)
                    {
                	    printf("*"); // Fruit
				    }
                    else 
					{
                        flag = 0;
                        for (k = 0; k < nTail; k++) 
						{
                            if (tailX[k] == j && tailY[k] == i) 
							{
                                printf("s"); // Snake tail
                                flag = 1;
                            }
                        }
                        if (flag == 0)
                        {
                        	printf(" "); // Empty space
						}       
                    }
                    if (j == WIDTH - 1)
                    {
                        printf("|"); // Right wall	
					}
                }
                printf("\n");
            }
            for (i = 0; i < WIDTH + 2; i++)
            {
            	printf("-"); // Bottom wall
			}
            printf("\n");
            printf("Score: %d\n", score);
            // Snake movement
            if (_kbhit()) 
			{
                switch (_getch()) 
				{
                    case 75:
                    case 'a':
					case 'A':	
                        direction = 'L';
                        break;
                    case 77:
                    case 'd':
					case 'D':	
                        direction = 'R';
                        break;
                    case 72:
                    case 'w':
					case 'W':	
                        direction = 'U';
                        break;
                    case 80:
                    case 's':
					case 'S':	
                        direction = 'D';
                        break;
                }
            }
            // Move the tail
            int prevX = tailX[0];
            int prevY = tailY[0];
            int prev2X, prev2Y;
            tailX[0] = x;
            tailY[0] = y;
            for (i = 1; i < nTail; i++) 
			{
                prev2X = tailX[i];
                prev2Y = tailY[i];
                tailX[i] = prevX;
                tailY[i] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }
            // Move the head
            switch (direction) 
			{
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y--;
                    break;
                case 'D':
                    y++;
                    break;
                default:
                    break;
            }
            // Game over conditions
            if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
            {
            	gameOver = 1;
			}
            for (i = 0; i < nTail; i++) 
			{
                if (tailX[i] == x && tailY[i] == y)
                {
                    gameOver = 1;	
				}
            }
            // Eat fruit
            if (x == fruitX && y == fruitY) 
			{
                score += 10;
                fruitX = rand() % WIDTH;
                fruitY = rand() % HEIGHT;
                nTail++;
            }
            Sleep(100); // Control game speed
        }
        printf("KHATAM TATA BYE BYE!\n");
        printf("Your score: %d\n", score);
        char reset;
        printf("If you want to play again Press Y/y else Press N/n.\n");
        scanf(" %c", &reset);
        if (reset=='N' || reset=='n')
        {
    	    restart=1;
	    }
	    else if( reset=='y'||reset=='Y')
	    {
	    	restart=0;
		}
		else{
			printf("Ayein yeh kya daba dia!");
		}
    }
}
