# include <iostream>
# include <ncurses>

const int WIDTH = 20;
const int HEIGHT = 20;


bool gameOver;
int x, y, fruitX, fruitY, score;

enum eDirection{ STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;

	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;
}

void Draw()
{
	system("clear"); //system("cls");

	// Upper wall
	for(int i = 0; i < WIDTH+1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;


	// Sidewall
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(j == 0 || j == WIDTH-1)
			{
				std::cout << "#";
			}

			if(i == y && j == x)
			{
				std::cout << "0";
			}
			else if(j == fruitX && i == fruitY)
			{
				std::cout << "F";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	
	// Lower Wall
	for(int i = 0; i < WIDTH+1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
}

void Input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case "a":
				dir = LEFT;
				break;
			case "d":
				dir = RIGHT;
				break;
			case "w":
				dir = UP;
				break;
			case "s":
				dir = DOWN;
				break;
			case "x":
				gameOver = true;
				break;
		}
	}
}

void Logic()
{

}

int main()
{
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}
