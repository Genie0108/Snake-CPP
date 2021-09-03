//Snake Game in C++ Using Object Oriented Programming
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
using std::cin;
using std::cout;
using std::flush;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

void SetConsoleSize(int Width, int Height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, Width, Height, TRUE);
}

int SnakeBodyCount;
bool GameOver;

class MusicPlayer
{
private:
    bool Music;

public:
    bool GetMusic() const
    {
        return Music;
    }
    void SetMusic(bool M)
    {
        Music = M;
    }
    void MuteSound()
    {
        sndPlaySound("Mute.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
    }
    void PlayMusic()
    {
        if (Music == true)
        {
            sndPlaySound("Music.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
        }
        else
        {
            MuteSound();
        }
    }
    MusicPlayer()
    {
        Music = true;
    }
};

class Display
{
public:
    void SetColorBlue()
    {
        system("Color 01");
    }
    void SetColorGreen()
    {
        system("Color 02");
    }
    void SetColorRed()
    {
        system("Color 04");
    }
    void SetColorYellow()
    {
        system("Color 06");
    }
    void SetColorWhite()
    {
        system("Color 07");
    }
    void SetColorPurple()
    {
        system("Color 05");
    }
    void DisplayMainMenu()
    {
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
        cout << " ||                              *Menu*                                   ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                         -> 1. Play Game                               ||\n";
        cout << " ||                         -> 2. High Score                              ||\n";
        cout << " ||                         -> 3. Instructions                            ||\n";
        cout << " ||                         -> 4. Credits                                 ||\n";
        cout << " ||                         -> 5. Settings                                ||\n";
        cout << " ||                         -> 6. Exit                                    ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
    void DisplayInstructions()
    {
        cout << " ===========================================================================\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                           *Instructions*                              ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                           ____                        ||\n";
        cout << " ||                  ________________________/ O  \\___/                   ||\n";
        cout << " ||                 <_____________________________/   \\                   ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||             1. W,A,S,D to change direction of the Snake.              ||\n";
        cout << " ||             2. Eat the Fruit to Make the Snake Grow. With             ||\n";
        cout << " ||                each fruit 10 Points will be Added to the              ||\n";
        cout << " ||                score.                                                 ||\n";
        cout << " ||             3. If Snake eats itself, game will be over.               ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
    void DisplaySettings()
    {
        cout << " ===========================================================================\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                             *Settings*                                ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                           ____                        ||\n";
        cout << " ||                  ________________________/ O  \\___/                   ||\n";
        cout << " ||                 <_____________________________/   \\                   ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                         -> 1. Change Colors                           ||\n";
        cout << " ||                         -> 2. Music ON\\OFF                            ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                PRESS ANY OTHER KEY TO RETURN TO MENU                  ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
    void DisplayColorSettings()
    {
        cout << " ===========================================================================\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                              *Colors*                                 ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                           ____                        ||\n";
        cout << " ||                  ________________________/ O  \\___/                   ||\n";
        cout << " ||                 <_____________________________/   \\                   ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                            -> 1. Blue                                 ||\n";
        cout << " ||                            -> 2. Green                                ||\n";
        cout << " ||                            -> 3. Red                                  ||\n";
        cout << " ||                            -> 4. Yellow                               ||\n";
        cout << " ||                            -> 5. White                                ||\n";
        cout << " ||                            -> 6. Purple                               ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                PRESS ANY OTHER KEY TO RETURN TO MENU                  ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
    void DisplayCredits()
    {
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
        cout << " ||              | __ |   / _ \\   |   /  |   /   | |   \\__ \\\              ||\n";
        cout << " ||              |_||_|  /_/ \\_\\  |_|_\\  |_|_\\  |___|  |___/              ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                    PRESS ANY KEY TO RETURN TO MENU                    ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
    void DisplayGameOver()
    {
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
        cout << " ||         | |_| |/ ___ \\| |  | | |__| |_| |\\ \V / | |___|  _ <           ||\n";
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
    void DisplayAskSaveScore()
    {
        cout << " ===========================================================================\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                          *New High Score*                             ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                 __                                    ||\n";
        cout << " ||                               _|  |_                                  ||\n";
        cout << " ||                             _|      |_                                ||\n";
        cout << " ||                            |  _    _  |                               ||\n";
        cout << " ||                            | |_|  |_| |                               ||\n";
        cout << " ||                         _  |  _    _  |  _                            ||\n";
        cout << " ||                        |_|_|_| |__| |_|_|_|                           ||\n";
        cout << " ||                          |_|_        _|_|                             ||\n";
        cout << " ||                            |_|      |_|                               ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ||                       PRESS 'S' TO SAVE SCORE                         ||\n";
        cout << " ||                                 OR                                    ||\n";
        cout << " ||                PRESS ANY OTHER KEY TO RETURN TO MENU                  ||\n";
        cout << " ||                                                                       ||\n";
        cout << " ===========================================================================\n";
    }
};

class Controls
{
public:
    enum Direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction Dir;
    void ControlInput()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                Dir = LEFT;
                break;
            case 'd':
                Dir = RIGHT;
                break;
            case 'w':
                Dir = UP;
                break;
            case 's':
                Dir = DOWN;
                break;
            case 'A':
                Dir = LEFT;
                break;
            case 'D':
                Dir = RIGHT;
                break;
            case 'W':
                Dir = UP;
                break;
            case 'S':
                Dir = DOWN;
                break;
            default:
                break;
            }
        }
    }
};

class ScoreManager
{
private:
    string TempPlayerName;
    int Score, TempHighScore;

public:
    void SetScore(int Score)
    {
        this->Score = Score;
    }
    int GetScore() const
    {
        return Score;
    }
    void SetHighScore(int HighScore)
    {
        this->TempHighScore = HighScore;
    }
    int GetHighScore() const
    {
        return TempHighScore;
    }
    void ReadHighScore()
    {
        ifstream SaveGame;
        SaveGame.open("Score.txt", fstream::in | fstream::trunc);
        SaveGame >> TempHighScore;
        SaveGame.close();
    }
    void WriteHighScore()
    {
        cout << "\n\nEnter Player Name : ";
        getline(cin, TempPlayerName);
        if (TempPlayerName.length() != 6)
        {
            while (TempPlayerName.length() != 6)
            {
                cout << "\n\nPlayer Name Should be of 6 Characters. Enter Name Again\n";
                getline(cin, TempPlayerName);
            }
        }
        ofstream WritePlayer;
        WritePlayer.open("Player.txt", fstream::trunc | fstream::out);
        WritePlayer << TempPlayerName;
        WritePlayer.close();
        ofstream WriteScore;
        WriteScore.open("Score.txt", fstream::trunc | fstream::out);
        WriteScore << Score;
        WriteScore.close();
    }
    void DisplayHighScore()
    {
        system("cls");
        string TempName;
        int TempScore;
        ifstream ReadName;
        ReadName.open("Player.txt", ios::in);
        getline(ReadName, TempName);
        ReadName.close();
        ifstream ReadScore;
        ReadScore.open("Score.txt", ios::in);
        ReadScore >> TempScore;
        ReadScore.close();
        if (TempScore < 100)
        {
            cout << " ===========================================================================\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                            *High Score*                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                 __                                    ||\n";
            cout << " ||                               _|  |_                                  ||\n";
            cout << " ||                             _|      |_                                ||\n";
            cout << " ||                            |  _    _  |                               ||\n";
            cout << " ||                            | |_|  |_| |                               ||\n";
            cout << " ||                         _  |  _    _  |  _                            ||\n";
            cout << " ||                        |_|_|_| |__| |_|_|_|                           ||\n";
            cout << " ||                          |_|_        _|_|                             ||\n";
            cout << " ||                            |_|      |_|                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                           Player " << TempName << "                               ||\n";
            cout << " ||                           Score  " << TempScore << "                                   ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ===========================================================================\n";
        }
        else if (TempScore >= 100 && TempScore < 1000)
        {
            cout << " ===========================================================================\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                            *High Score*                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                 __                                    ||\n";
            cout << " ||                               _|  |_                                  ||\n";
            cout << " ||                             _|      |_                                ||\n";
            cout << " ||                            |  _    _  |                               ||\n";
            cout << " ||                            | |_|  |_| |                               ||\n";
            cout << " ||                         _  |  _    _  |  _                            ||\n";
            cout << " ||                        |_|_|_| |__| |_|_|_|                           ||\n";
            cout << " ||                          |_|_        _|_|                             ||\n";
            cout << " ||                            |_|      |_|                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                           Player " << TempName << "                               ||\n";
            cout << " ||                           Score  " << TempScore << "                                  ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ===========================================================================\n";
        }
        else if (TempScore >= 1000)
        {
            cout << " ===========================================================================\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                            *High Score*                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                 __                                    ||\n";
            cout << " ||                               _|  |_                                  ||\n";
            cout << " ||                             _|      |_                                ||\n";
            cout << " ||                            |  _    _  |                               ||\n";
            cout << " ||                            | |_|  |_| |                               ||\n";
            cout << " ||                         _  |  _    _  |  _                            ||\n";
            cout << " ||                        |_|_|_| |__| |_|_|_|                           ||\n";
            cout << " ||                          |_|_        _|_|                             ||\n";
            cout << " ||                            |_|      |_|                               ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                           Player " << TempName << "                               ||\n";
            cout << " ||                           Score  " << TempScore << "                                  ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ||                                                                       ||\n";
            cout << " ===========================================================================\n";
        }
    }
    ScoreManager()
    {
        Score = 0;
        TempHighScore = 0;
        TempPlayerName = "\0";
    }
};

class Game
{
protected:
    MusicPlayer M;
    Display D;
    Controls C;
    ScoreManager S;
    bool BodyPrintFlag;
    const int Width = 52;
    const int Height = 22;
    int SnakeHeadX, SnakeHeadY, FruitX, FruitY;
    int SnakeX[100], SnakeY[100];
    void Reset()
    {
        SnakeHeadX = 0;
        SnakeHeadY = 0;
        FruitX = 0;
        FruitY = 0;
        for (int i = 0; i < 100; i++)
        {
            SnakeX[i] = 0;
            SnakeY[i] = 0;
        }
        SnakeBodyCount = 0;
    }
    void Setup()
    {
        GameOver = false;
        C.Dir = C.STOP;
        SnakeHeadX = Width / 2;
        SnakeHeadY = Height / 2;
        FruitX = rand() % Width;
        FruitY = rand() % Height;
        S.SetScore(0);
    }
    void Print()
    {
        cout << flush;
        system("cls");
        cout << "                        SCORE : " << S.GetScore() << "\n";
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
    void Play()
    {
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
        switch (C.Dir)
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
            S.SetScore(S.GetScore() + 10);
            FruitX = rand() % Width;
            FruitY = rand() % Height;
            SnakeBodyCount++;
        }
    }

public:
    Game()
    {
        Reset();
    }
};

class SnakeGame : private Game
{
private:
    bool ExitFlag;
    char MenuOPT, SaveOPT, SettingOPT, ColorOPT;
    void Algorithm()
    {
        Setup();
        while (!GameOver)
        {
            Print();
            C.ControlInput();
            Play();
        }
    }
    void Run()
    {
        while (!ExitFlag)
        {
        Menu:
            system("cls");
            D.DisplayMainMenu();
            M.PlayMusic();
            Reset();
            MenuOPT = _getch();
            switch (MenuOPT)
            {
            case '1':
                GameOver = false;
                Reset();
                system("cls");
                Algorithm();
                if (GameOver)
                {
                    system("cls");
                    D.DisplayGameOver();
                    _getch();
                    S.ReadHighScore();
                    if (S.GetScore() > S.GetHighScore())
                    {
                        system("cls");
                        D.DisplayAskSaveScore();
                        SaveOPT = _getch();
                        if (SaveOPT == 'S' || SaveOPT == 's')
                        {
                            S.WriteHighScore();
                            cout << "\nScore Saved\nPRESS ANY KEY TO RETURN TO MENU\n";
                            _getch();
                            goto Menu;
                        }
                        else
                        {
                            goto Menu;
                        }
                    }
                    goto Menu;
                }
                break;
            case '2':
                system("cls");
                S.DisplayHighScore();
                cout << "\n\nPRESS ANY KEY TO RETURN TO MENU\n";
                _getch();
                goto Menu;
                break;
            case '3':
                system("cls");
                D.DisplayInstructions();
                _getch();
                goto Menu;
                break;
            case '4':
                system("cls");
                D.DisplayCredits();
                _getch();
                goto Menu;
                break;
            case '5':
                system("cls");
                D.DisplaySettings();
                SettingOPT = _getch();
                switch (SettingOPT)
                {
                case '1':
                    system("cls");
                    D.DisplayColorSettings();
                    ColorOPT = _getch();
                    switch (ColorOPT)
                    {
                    case '1':
                        D.SetColorBlue();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    case '2':
                        D.SetColorGreen();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    case '3':
                        D.SetColorRed();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    case '4':
                        D.SetColorYellow();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    case '5':
                        D.SetColorWhite();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    case '6':
                        D.SetColorPurple();
                        cout << "\nColor Changed...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                        break;
                    }
                    break;
                case '2':
                    if (M.GetMusic() == true)
                    {
                        M.SetMusic(false);
                        cout << "\nMusic Muted...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                    }
                    else
                    {
                        M.SetMusic(true);
                        cout << "\nMusic Un-Muted...\n";
                        cout << "Press Any Key to Return to Menu\n";
                        _getch();
                        system("cls");
                        goto Menu;
                    }
                }
                break;
            case '6':
                _Exit(0);
                break;
            }
        }
    }

public:
    SnakeGame()
    {
        ExitFlag = false;
        MenuOPT = '\0';
        SettingOPT = '\0';
        ColorOPT = '\0';
        SaveOPT = '\0';
        Run();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    SetConsoleSize(650, 525);
    SnakeGame G;
    return 0;
}
