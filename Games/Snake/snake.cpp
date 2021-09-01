# include <iostream>
# include <conio.h> // Input-output library
// # include <windows.h>

const int WIDTH = 20;
const int HEIGHT = 20;


bool gameOver;
int x, y, fruitX, fruitY, score;

// Create an array of max 100 items
int tailX[100], tailY[100];
int nTail;

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
	system("cls"); //system("clear");

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
                bool print = false;
                for(int k = 0; k < nTail; k++)
                {
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }

                if(!print)
                {
                    std::cout << " ";
                }
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
    std::cout << "Score: " << score << std::endl;
}

void Input()
{
    // Control keyboard inputs
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];

    int prev2X, prev2Y;

    // Append new tail to array
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    // Control the movements
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // Hit the wall = game over
    // if(x > WIDTH || x < 0 || y > HEIGHT || y < 0)
    // {
    //     gameOver = true;
    // }
    
    // Hit the wall will teleport to the other side
    if(x >= WIDTH)
    {
        x = 0;
    }
    else if(x < 0)
    {
        x = WIDTH - 1;
    }

    if(y >= HEIGHT)
    {
        y = 0;
    }
    else if(y < 0)
    {
        y = HEIGHT - 1;
    }

    // Game over if the snake eat its own tail
    for(int i = 0; i < nTail; i++)
    {
        if(tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }

    // If the snake eat the fruits
    if(x == fruitX && y == fruitY)
    {
        // Add score
        score += 10;

        // Spawn the fruit in another location
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;

        // increase the tail length
        nTail++;
    }
}

int main()
{
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();

        // use this to make the game run slower if it a bit too fast
        // Sleep{10} or sleep(10)
        // Don't forget un-comment the # include <windows.h> at the top of script
	}
	return 0;
}
