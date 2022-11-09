#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

class SnakeGame {
private:
	enum Direction {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	Direction SnakeDirection;
	int SnakeBodyCount;
	bool GameOver;
	bool BodyPrintFlag;
	const int Width;
	const int Height;
	int SnakeHeadX, SnakeHeadY, FruitX, FruitY;
	int SnakeX[100], SnakeY[100];
	static void DisplayMainMenu();
	static void DisplayGameOver();
	static void DisplayInstructions();
	static void DisplayCredits();
	void ControllerInput();
	void SetupGame();
	void PrintStage();
	void PlayStage();
	void PlayGame();
public:
	SnakeGame();
	void StartGame();
};

SnakeGame::SnakeGame() :Height(22), Width(52) {
	SnakeBodyCount = 0;
	GameOver = false;
	BodyPrintFlag = false;
	SnakeHeadX = 0;
	SnakeHeadY = 0;
	FruitX = 0;
	FruitY = 0;
	for (int i = 0; i < 100; i++) {
		SnakeX[i] = 0;
		SnakeY[i] = 0;
	}
}
void SnakeGame::DisplayMainMenu() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           *SNAKE GAME*                                ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                      __    __    __    __                             ||\n";
	cout << " ||                     /  \\  /  \\  /  \\  /  \\                            ||\n";
	cout << " ||____________________/  __\\/  __\\/  __\\/  __\\___________________________||\n";
	cout << " ||___________________/  /__/  /__/  /__/  /______________________________||\n";
	cout << " ||                   | / \\   / \\   / \\   / \\  \\____                      ||\n";
	cout << " ||                   |/   \\_/   \\_/   \\_/   \\    o \\                     ||\n";
	cout << " ||                                           \\_____/--<                  ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                              *Menu*                                   ||\n";
	cout << " ||									  ||\n";
	cout << " ||                         -> 1. Play Game                               ||\n";
	cout << " ||                         -> 2. Instructions                            ||\n";
	cout << " ||                         -> 3. Credits                                 ||\n";
	cout << " ||                         -> 4. Exit                                    ||\n";
	cout << " ||				                                          ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::DisplayGameOver() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||           ____    _    __  __ _____ _____     _______ ____            ||\n";
	cout << " ||          / ___|  / \\  |  \\/  | ____/ _ \\ \\   / / ____|  _ \\           ||\n";
	cout << " ||         | |  _  / _ \\ | |\\/| |  _|| | | \\ \\ / /|  _| | |_) |          ||\n";
	cout << " ||         | |_| |/ ___ \\| |  | | |__| |_| |\\ V / | |___|  _ <           ||\n";
	cout << " ||          \\____/_/   \\_\\_|  |_|_____\\___/  \\_/  |_____|_| \\_\\          ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::DisplayInstructions() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           *Instructions*                              ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                           ____                        ||\n";
	cout << " ||                  ________________________/ O  \\___/                   ||\n";
	cout << " ||                 <_____________________________/   \\                   ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||             1. W,A,S,D to change direction of the Snake.              ||\n";
	cout << " ||             2. Eat the Fruit to Make the Snake Grow. With             ||\n";
	cout << " ||                each fruit 10 Points will be Added to the              ||\n";
	cout << " ||                score.                                                 ||\n";
	cout << " ||             3. If Snake eats itself, game will be over.               ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::DisplayCredits() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                               *Credits*                               ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           Game Developed by                           ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  )             (      (      (      (                 ||\n";
	cout << " ||               ( /(     (       )\\ )   )\\ )   )\\ )   )\\ )              ||\n";
	cout << " ||               )\\())    )\\     (()/(  (()/(  (()/(  (()/(              ||\n";
	cout << " ||              ((_)\\  ((((_)(    /(_))  /(_))  /(_))  /(_))             ||\n";
	cout << " ||               _((_)  )\\ _ )\\  (_))   (_))   (_))   (_))               ||\n";
	cout << " ||              | || |  (_)_\\(_) | _ \\  | _ \\  |_ _|  / __|              ||\n";
	cout << " ||              | __ |   / _ \\   |   /  |   /   | |   \\__ \\              ||\n";
	cout << " ||              |_||_|  /_/ \\_\\  |_|_\\  |_|_\\  |___|  |___/              ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                    PRESS ANY KEY TO RETURN TO MENU                    ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::ControllerInput() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			SnakeDirection = LEFT;
			break;
		case 'd':
			SnakeDirection = RIGHT;
			break;
		case 'w':
			SnakeDirection = UP;
			break;
		case 's':
			SnakeDirection = DOWN;
			break;
		case 'A':
			SnakeDirection = LEFT;
			break;
		case 'D':
			SnakeDirection = RIGHT;
			break;
		case 'W':
			SnakeDirection = UP;
			break;
		case 'S':
			SnakeDirection = DOWN;
			break;
		default:
			break;
		}
	}
}
void SnakeGame::SetupGame() {
	GameOver = false;
	SnakeDirection = STOP;
	SnakeHeadX = Width / 2;
	SnakeHeadY = Height / 2;
	FruitX = rand() % Width;
	FruitY = rand() % Height;
}
void SnakeGame::PrintStage() {
	cout << flush;
	system("cls");
	for (int i = 0; i < Width + 4; i++)
	{
		printf("=");
	}
	cout << "\n";
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (j == 0)
			{
				printf("||");
			}
			if (i == SnakeHeadY && j == SnakeHeadX)
			{
				cout << "O";
			}
			else if (i == FruitY && j == FruitX)
			{
				cout << "#";
			}
			else
			{
				BodyPrintFlag = false;
				for (int k = 0; k < SnakeBodyCount; k++)
				{
					if (SnakeX[k] == j && SnakeY[k] == i)

					{
						cout << "o";
						BodyPrintFlag = true;
					}
				}
				if (!BodyPrintFlag)
				{
					printf(" ");
				}
			}
			if (j == Width - 1)
			{
				printf("||");
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < Width + 4; i++)
	{
		printf("=");
	}
}
void SnakeGame::PlayStage() {
	int prevX = SnakeX[0];
	int prevY = SnakeY[0];
	int prev2X, prev2Y;
	SnakeX[0] = SnakeHeadX;
	SnakeY[0] = SnakeHeadY;
	for (int i = 1; i < SnakeBodyCount; i++)
	{
		prev2X = SnakeX[i];
		prev2Y = SnakeY[i];
		SnakeX[i] = prevX;
		SnakeY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (SnakeDirection)
	{
	case 1:
		SnakeHeadX--;
		break;
	case 2:
		SnakeHeadX++;
		break;
	case 3:
		SnakeHeadY--;
		break;
	case 4:
		SnakeHeadY++;
		break;
	default:
		break;
	}
	if (SnakeHeadX >= Width)
	{
		SnakeHeadX = 0;
	}
	else if (SnakeHeadX < 0)
	{
		SnakeHeadX = Width - 1;
	}
	if (SnakeHeadY >= Height)
	{
		SnakeHeadY = 0;
	}
	else if (SnakeHeadY < 0)
	{
		SnakeHeadY = Height - 1;
	}
	for (int i = 0; i < SnakeBodyCount; i++)
	{
		if (SnakeX[i] == SnakeHeadX && SnakeY[i] == SnakeHeadY)
		{
			GameOver = true;
		}
	}
	if (SnakeHeadX == FruitX && SnakeHeadY == FruitY)
	{
		FruitX = rand() % Width;
		FruitY = rand() % Height;
		SnakeBodyCount += 1;;
	}
}
void SnakeGame::PlayGame() {
	SetupGame();
	while (!GameOver)
	{
		PrintStage();
		ControllerInput();
		PlayStage();
		Sleep(100);
	}
}
void SnakeGame::StartGame() {
	char opt = '\0';
	while (true) {
		system("cls");
		DisplayMainMenu();
		opt = _getch();
		system("cls");
		switch (opt) {
		case '1':
			PlayGame();
			system("cls");
			DisplayGameOver();
			_getch();
			break;
		case '2':
			DisplayInstructions();
			_getch();
			break;
		case '3':
			DisplayCredits();
			_getch();
			break;
		case '4':
			cout << "Closing Snake Game";
			for (int i = 0; i < 4; i++) {
				Sleep(600);
				cout << ".";
				exit(-1);
			}
			break;
		default:
			break;
		}
	}
}

int main() {
	SnakeGame Snake;
	Snake.StartGame();
	return 0;
}