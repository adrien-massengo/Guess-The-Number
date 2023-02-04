#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

using namespace std;
int gameExit();
void breakline(int line_num);
void printTitle();
void printRules();
void setTextColor(int color, string text);
void difficulty(int &x, int &y);
void verifyResult(int& playerGuess, int& computerGuess, int& goalNumber);
void result(int& playerGuess, int& computorGuess, int& goalNumber, bool& guessing);

int main()
{
	int min_num = 0;
	int max_num = 0;
	int num;
	string again;
	bool guessing = true;
	srand(time(NULL));
	int player_guess;
	int computor_guess;
	string play;
	printTitle();
	breakline(1);
	printRules();
	breakline(1);
	cout << "Play?\n";
	cout << "y/n\n";
	cin >> play;
	cout << endl;

	if (play == "y")
	{
		difficulty(min_num, max_num);
		num = rand() % max_num + min_num;
		
		cout << "Game Start!\n";
		while (guessing == true)
		{
			cout << "Make your guess!\n";
			cin >> player_guess;
			computor_guess = rand() % max_num + min_num;
			result(player_guess, computor_guess, num, guessing);
		}
		cout << "Play again?" << endl;
		cout << "y/n" << endl;
		cin >> again;
		if (again == "y")
		{
			main();
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
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
	cout << "2. You and a Computer try to guess what the number is.\n";
	cout << "3. First to guess it wins.\n";
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
	switch (diff)
	{
		case 0:
		{
		x = 1;
		y = 10;
		break;
		}
		case 1:
		{
		x = 1;
		y = 100;
		break;
		}
		case 2:
		{
		x = 1;
		y = 1000;
		break;
		}
		case 3:
		{
		cout << "Enter the minimum number.\n";
		cin >> x;
		cout << "\n";
		cout << "Enter the maximum number.\n";
		cin >> y;
		cout << "\n";
		cout << "The minimum number is " << x << ".\n";
		cout << "The maximum number is " << y << ".\n";
		break;
		}
	default:
	{
		SetConsoleTextAttribute(hConsole, red);
		cout << "Please choose a valid option." << endl;
		SetConsoleTextAttribute(hConsole, white);
		gameExit();
	}
	}
}
void verifyResult(int& playerGuess, int& computerGuess, int& goalNumber, bool& guessing)
{
	if (playerGuess == goalNumber && computerGuess != goalNumber)
	{
		cout << "You win! " << "The Number was " << goalNumber << endl;
		guessing = false;
	}
	else if (playerGuess != goalNumber && computerGuess == goalNumber)
	{
		cout << "The computer wins!" << "The Number was " << goalNumber << endl;
		guessing = false;
	}
	else if (playerGuess == goalNumber && computerGuess == goalNumber)
		{
		cout << "It's a draw!" << "The Number was " << goalNumber << endl;
		guessing = false;
	}
}
void result(int& playerGuess, int& computorGuess, int& goalNumber, bool& guessing)
{
	int playerScore, computorScore, holdP, holdC;
	holdP = goalNumber - playerGuess;
	holdC = goalNumber - computorGuess;
	// abs == absolute
	if (playerGuess > goalNumber && computorGuess != goalNumber)
	{
		cout << "Your Guess was too large!\n";
		cout << "The Computor guessed " << computorGuess;
		if (computorGuess > goalNumber)
		{
			cout << ".\nThe computor's guess was too large!\n";
		}
		else if (computorGuess < goalNumber)
		{
			cout << ".\nThe computer's guess was too small!\n";
		}
	}
	else if (playerGuess < goalNumber && computorGuess != goalNumber)
	{
		cout << "Your guess was too small" << endl;
		cout << "The Computor guessed " << computorGuess;
		if (computorGuess > goalNumber)
		{
			cout << ".\nThe computor's guess was too large!\n";
		}
		else if (computorGuess < goalNumber)
		{
			cout << ".\nThe computer's guess was too small!\n";
		}
	
	}
	else if (playerGuess == goalNumber || computorGuess == goalNumber)
	{
		verifyResult(playerGuess, computorGuess, goalNumber, guessing);
	}
}

