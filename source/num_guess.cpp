#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int gameExit()
{
	return 0;
}
void breakline(int line_num)
{
	for (int i = 0; i <= line_num; i++)
	{
		cout << "\n";
	}
}
void printTitle()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "---------------------------------------------------------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "  _____                    _____ _          _____           _           " << endl;
	cout << " |   __|_ _ ___ ___ ___   |_   _| |_ ___   |   | |_ _ _____| |_ ___ ___ " << endl;
	cout << " |  |  | | | -_|_ -|_ -|    | | |   | -_|  | | | | | |     | . | -_|  _|" << endl;
	cout << " |_____|___|___|___|___|    |_| |_|_|___|  |_|___|___|_|_|_|___|___|_|  " << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "---------------------------------------------------------------------------" << endl;
}
void printRules()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	cout << "__________      .__                 " << endl;
	cout << "\\______   \\__ __|  |   ____   ______" << endl;
	cout << " |       _/  |  \\  | _/ __ \\ /  ___/" << endl;
	cout << " |    |   \\  |  /  |_\\  ___/ \\___ \\ " << endl;
	cout << " |____|_  /____/|____/\\___  >____  >" << endl;
	cout << "        \\/                \\/     \\/ " << endl;
	breakline(2);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "1. A Number is randomly generated.\n";
	cout << "2. You and a Computor try to guess what the number is.\n";
	cout << "3. Closest guess wins.\n";
	SetConsoleTextAttribute(hConsole, 7);
}
void setTextColor(int color, string text)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
void difficulty(int &x, int &y)
{
	HANDLE hConsole;
	int red = 4;
	int white = 7;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int diff;
	cout << "Difficulty: " << endl;
	cout << "[0] Easy (between 1 and 10.)" << endl;
	cout << "[1] Medium (between 1 and 100.)" << endl;
	cout << "[2] Hard (between 1 and 1000.)" << endl;
	cout << "[3] Custom  (you decide.)" << endl;
	cin >> diff;
	if (diff == 0)
	{
		x = 1;
		y = 10;
	}
	else if (diff == 1)
	{
		x = 1;
		y = 100;
	}
	else if (diff == 2)
	{
		x = 1;
		y = 1000;
	}
	else if (diff == 3)
	{
		cout << "Enter the minimum number." << endl;
		cin >> x;
		cout << endl;
		cout << "The minimum number is " << x << "." << endl;
		cout << "Enter the maximum number." << endl;
		cin >> y;
		cout << endl;
		cout << "The maximum number is " << y << "." << endl;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, red);
		cout << "Please choose a valid option." << endl;
		SetConsoleTextAttribute(hConsole, white);
		gameExit();
	}
}
void result(int playerGuess, int computorGuess, int goalNumber)
{
	int playerScore, computorScore, holdP, holdC;
	holdP = goalNumber - playerGuess;
	holdC = goalNumber - computorGuess;
	playerScore = abs(holdP);
	computorScore = abs(holdC);
	if (playerScore > computorScore)
	{
		cout << "You lose!" << endl;
		cout << "The Number was " << goalNumber << ".\nYour Guess was off by " << playerScore << ".\nThe Computor guessed " << computorGuess;
		if (computorGuess == goalNumber)
		{
			cout << ".\nThe computor got the right number!\n";
		}
		else if (computorGuess != goalNumber)
		{
			cout << ".\nThe computer was off by " << computorScore << "." << endl;
		}
	}
	else if (playerScore < computorScore)
	{
		cout << "You Win!" << endl;
		cout << "The Number was " << goalNumber << ".\nThe Computor guessed " << computorGuess << ".\nIt's guess was off by " << computorScore << "." << endl;
		if (playerGuess == goalNumber)
		{
			cout << "You got the right number!\n";
		}
		else if (playerGuess != goalNumber)
		{
			cout << "You were off by " << playerScore << "." << endl;
		}
	}
	else if (playerScore == computorScore)
	{
		cout << "It's a draw!" << endl;
		cout << "The Number was " << goalNumber << ".\nThe Computor guessed " << computorGuess << ".\nYou guessed " << playerGuess << "." << endl;
		if (playerGuess == goalNumber)
		{
			cout << "You both got the right number!\n";
		}
		else if (playerGuess != goalNumber)
		{
			cout << "You were both off by " << playerScore << "." << endl;
		}
	}
}

int main()
{
	int min_num = 0;
	int max_num = 0;
	int num;
	string again;
	srand(time(NULL));
	int player_guess;
	int computor_guess;
	string play;
	printTitle();
	breakline(1);
	printRules();
	breakline(1);
	cout << "Play?" << endl;
	cout << "y/n" << endl;
	cin >> play;
	cout << endl;

	if (play == "y")
	{
		difficulty(min_num, max_num);
		num = rand() % max_num + min_num;
		computor_guess = rand() % max_num + min_num;
		cout << "Game Start!\n";
		cout << "Make your guess!\n";
		cin >> player_guess;
		result(player_guess, computor_guess, num);
		cout << "Play again?" << endl;
		cout << "y/n" << endl;
		cin >> again;
		if (again == "y")
		{
			main();
		}
		else
			return 0;
	}
	else
		return 0;
}

// We gave up, just add another few functions and call it a day.
// nvm learned how to use  references
