/***************************************************************************

Stephen Hill Presents:

Zener Card Guessing Game

11 April 2018 Wednesday
Blues Springs, MO 64015

**************************************************************************/

#include <iostream>		//for working with input output streams, our minimum library
#include <windows.h>	//for windows console concerns
#include <stdlib.h>
#include <fstream>		//for I/O file streams
#include <string>		//for strings
#include <iomanip>		//for functions such as setting precision
#include <cctype>		//for functions such as toupper
#include <ctime>		//for randomization
#include <Mmsystem.h>	//three libraries to get mp3's running in console
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

//start prototyping functions here
//for returning program info to the user
void fileReader(ifstream& inText, char& ch);

//for quicker color changing of text
void colorText(int h);

//for colorizing the cards in the console.
void zenerText(ifstream& inText, char& ch);


int main()
{
	//Variable Declarations.

	//an int that is important to me, for return purposes at the end of the program.
	int stevesInt = 1112013;

	//Boolean to restart the program in the pop-up window,
	//and integer for restart program logic.
	bool continueYN = true;
	int YN = 0;

	//do while loop to catch incorrect user input
	bool bad = false;

	//Setting precision of outputs.
	cout << fixed << showpoint << setprecision(2);

	//off-world textfiles
	ifstream inFile1;

	//character variable for reading text from files
	char ch = ' ';

	//While loop to restart program in the pop-up window.
	while (continueYN)
	{
		//character variable for reading text for switch
		char zen = 'z';

		//character variable for reading text for switch
		char card = 'z';

		//integers for count guess 
		int count = 0;
		int correctCount = 0;
		int xRan;

		//Clears the pop-up window in case of restarting program.
		system("cls");

		//Set the console output to classic CRT green, this one
		//for the restart while loop.
		colorText(10);

		//Tell user what the program does by calling on function fileReader.
		inFile1.open("..\\ZenerDataFiles\\texts\\introText.txt");
		fileReader(inFile1, ch);
		inFile1.close();
		cout << endl;

		//pause for user to catch up with text
		cout << endl;
		system("pause");
		system("cls");
		cout << endl;

		//Ask the user if they want hint on or off.
		cout << "Do you want the hint feature on?\n";
		cout << "Enter 1 for yes and 0 for no: ";
		int hinty = 0;
		cin >> hinty;

		//pause for user to catch up with text
		cout << endl;
		system("pause");
		system("cls");
		cout << endl;

		//To play a spooky mp3 while you are focusing your psychic ability
		mciSendString("open \"..\\ZenerDataFiles\\sounds\\x_terminal.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		mciSendString("play mp3 repeat", NULL, 0, NULL);
		
		while (count < 25)
		{
			cout << endl << "Number of gusses left is: ";
			colorText(13);
			cout << 25 - count << endl;
			colorText(10);

			srand(time(0)); // This will ensure a really randomized number by help of time.
			xRan = rand() % 5 + 1; // Randomizing the number between 1-5.			

			if (xRan == 1)
				card = 'p';
			else if (xRan == 2)
				card = 'o';
			else if (xRan == 3)
				card = 'w';
			else if (xRan == 4)
				card = 'r';
			else if (xRan == 5)
				card = 's';

			if (hinty == 1)
				cout << "The card should be: " << card << endl;

			inFile1.open("..\\ZenerDataFiles\\texts\\back.txt");
			zenerText(inFile1, ch);
			inFile1.close();
			colorText(10);
			cout << endl << endl << "Focus your powers!" << endl;
			cout << "Please enter guess (p, o, w, r, s) and press enter: ";
			cin >> zen;
			cout << endl;
			system("cls");

			colorText(10);

			//card selection is in a switch statement.
			switch (zen)
			{
			case 'p': // code to be executed if zen = p;
				cout << "You entered p." << endl;
				if (zen == card)
				{
					cout << endl;
					inFile1.open("..\\ZenerDataFiles\\texts\\cross.txt");
					zenerText(inFile1, ch);
					inFile1.close();
					colorText(10);
					cout << endl << endl << "                    CORRECT!" << endl << endl;
					correctCount += 1;
					system("pause");
				}
				else
				{
					colorText(12);
					cout << endl << "          INCORRECT!" << endl;
					colorText(10);
					system("pause");
				}
				break;
			case 'o': // code to be executed if zen = p;
				cout << "You entered o." << endl;
				if (zen == card)
				{
					cout << endl;
					inFile1.open("..\\ZenerDataFiles\\texts\\circle.txt");
					zenerText(inFile1, ch);
					inFile1.close();
					colorText(10);
					cout << endl << endl << "                    CORRECT!" << endl << endl;
					correctCount += 1;
					system("pause");
				}
				else
				{
					colorText(12);
					cout << endl << "          INCORRECT!" << endl;
					colorText(10);
					system("pause");
				}
				break;
			case 'w': // code to be executed if zen = p;
				cout << "You entered w." << endl;
				if (zen == card)
				{
					cout << endl;
					inFile1.open("..\\ZenerDataFiles\\texts\\wavy.txt");
					zenerText(inFile1, ch);
					inFile1.close();
					colorText(10);
					cout << endl << endl << "                    CORRECT!" << endl << endl;
					correctCount += 1;
					system("pause");
				}
				else
				{
					colorText(12);
					cout << endl << "          INCORRECT!" << endl;
					colorText(10);
					system("pause");
				}
				break;
			case 'r': // code to be executed if zen = p;
				cout << "You entered r." << endl;
				if (zen == card)
				{
					cout << endl;
					inFile1.open("..\\ZenerDataFiles\\texts\\square.txt");
					zenerText(inFile1, ch);
					inFile1.close();
					colorText(10);
					cout << endl << endl << "                    CORRECT!" << endl << endl;
					correctCount += 1;
					system("pause");
				}
				else
				{
					colorText(12);
					cout << endl << "          INCORRECT!" << endl;
					colorText(10);
					system("pause");
				}
				break;
			case 's': // code to be executed if zen = p;
				cout << "You entered s." << endl;
				if (zen == card)
				{
					cout << endl;
					inFile1.open("..\\ZenerDataFiles\\texts\\star.txt");
					zenerText(inFile1, ch);
					inFile1.close();
					colorText(10);
					cout << endl << endl << "                    CORRECT!" << endl << endl;
					correctCount += 1;
					system("pause");
				}
				else
				{
					colorText(12);
					cout << endl << "          INCORRECT!" << endl;
					colorText(10);
					system("pause");
				}
				break;
			default: // code to be executed if n doesn't match any cases
				cout << "Please enter valid guess." << endl;
				cout << "p, o, w, r, s and press enter." << endl;
			}

			count += 1;
			system("cls");
		}

		cout << "Let's break down the guesses." << endl;
		cout << "Your number of correct guesses was: ";
		colorText(14);
		cout << correctCount << endl;
		colorText(10);
		double cCount = static_cast<double>(correctCount);
		cout << "Your correct guess percentage is: ";
		colorText(14);
		cout << (100 * (cCount / 25));		
		cout << "%" << endl;
		colorText(10);

		//Closing the mp3 file for sanitation.
		mciSendString("close mp3", NULL, 0, NULL);

		//Restart program logic, if you want to run the program 
		//again without closing the console window.
		colorText(10);
		cout << endl << "Would you like to restart the program?" << endl;

		//Change color of text with colorText function.
		colorText(12);
		cout << "Enter '1' for yes or '0' for no, and press the Enter key: " << endl;
		cin >> YN;

		//This clears the buffer in case of restarting program loop, thank you!!
		cin.clear();
		cin.ignore();

		if (YN == 0)           //only checking to see if user entered 0 since this exits loop
		{
			continueYN = false;
		}
		inFile1.close();	//close file to prevent memory leaks
		inFile1.clear();	//clear the buffer
	}
	//Remember to pause that output and return an int!
	//I added a do loop with boolean and integer variables to allow for restarting the program.

	system("pause");

	return stevesInt;	//return a number significant to me.
}	//end main

	//This function returns intro text for the user.
void fileReader(ifstream& inText, char& ch)
{
	while (!inText.eof())
	{
		cout << ch;
		inText.get(ch);
	}

}//end programInfo

 //function colorText makes changing colors less cluttered
 //say that 3 times fast.
void colorText(int h)
{
	//Define the standard handle for color manipulation.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Set the console output to classic CRT green
	SetConsoleTextAttribute(hConsole, h);
}	//end colorText

	//Surprise color!
void zenerText(ifstream& inText, char& ch)
{
	//while loop to read inText to the end of file
	//   and if certain characters are encountered, casts them as different colors.
	while (!inText.eof())
	{
		cout << ch;
		inText.get(ch);
		if (ch == '+' || ch == 'o')
			colorText(14);
		else if (ch == 'B' || ch == '*' || ch == '.' || ch == ',' || ch == '|' || ch == '-' || ch == '='
			|| ch == 'Q' || ch == '_' || ch == 'd' || ch == 'P' || ch == '"' || ch == 'Y' || ch == 'b' || ch == 'a' || ch == 'g')
			colorText(11);
		else
			colorText(6);
	}
}	//end zenerText