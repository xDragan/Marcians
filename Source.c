#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand (time(NULL));
	int lives = 5, contX = 4, contRand = 0;
	char direction = '\0';
	char matrix[10][10] =
	{
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ '1', '2', '3', '4', '5', '6', '7', '8', '9', '10'},
	};

	do
	{
		system("cls");

		//Player printing
		matrix[8][contX] = '@';

		//Map printing
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				printf("%c", matrix[i][j]);
			}
			printf("\n");
		}

		//Player movement
		printf("\nLives = %d\nLEFT = 'a'| RIGHT = 'd'| SKIP turn = 'Enter' -> ", lives);
		scanf_s("%c", &direction);
		fflush(stdin);
		if (direction == 97)
		{
			contX--;
		}
		if (direction == 100)
		{
			contX++;
		}
		
		//Clean previous position
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (matrix[i][j]== '@')
				{
					matrix[i][j] = ' ';
				}
			}
			printf("\n");
		}
		//Enemy move
		for (int i = 8; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (matrix[i][j] == '*')
				{
					matrix[i][j] = ' ';
					if (matrix[i + 1][j] == ' ')
					{
						matrix[i + 1][j] = '*';
					}
				}
			}
		}

		//Enemy spawn
		contRand = rand() % 10;
		matrix[0][contRand] = '*';

		//Player health
		if (matrix[8][contX] == '*')
		{
			lives--;
		}

	}while (lives != 0);

	system("cls");
	printf("GAME OVER\n");

	system("PAUSE");
	return 0;
}