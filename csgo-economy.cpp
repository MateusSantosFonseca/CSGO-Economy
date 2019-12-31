#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "windows.h"

using std::cout;
using std::cin;
using std::string;

/*
	This code was made to learn and practice C++ concepts
	This software will predict the next round money of all playears in a CSGO team, in every situation.
*/

int main()
{
	std::vector<string> answerToVector(string answer);
	bool testAnswer(std::vector<string> answerAsVector);
	bool testInputSide(string side);
	int parseStringToInt(string stringAux);
	void predictNextRoundEconomy(std::vector<string> answerAsVector);

	cout << "\n\tWelcome to the economy preview CSGO software\n\n";
	cout << "\tTo understand the rules of CSGO economy, to use this software\n\tcorrectly and to see input examples, please, see the README.txt\n\n";

	cout << "\n\n\n\t\tDo you want this software to repeat every round? (y/n): ";
	char hasToRepeatAux;
	cin >> hasToRepeatAux;
    bool hasToRepeat = hasToRepeatAux == 'y'? true : false;

    system("cls");
	if(hasToRepeat){
        cout << "\n\tOkay, this software will repeat until the input has exactly one character!!\n\n";
	}

	cout << "\n\n\tTo answer the question, digit everything on a comma-separated line\n";
	cout << "\tT ou CT / Consecutive lost rounds / 5 players economy - (input example: CT,3,1500,1400,1600,1250,2000):\n\n";
	string answer;
	std::vector<string> answerAsVector;


    do {
        do{
            fflush(stdin);
            cout << "\n\tAnswer: ";
            cin >> answer;
            if (answer.size() == 1)
            {
                system("cls");
                cout << "\n\n\tO sistema esta sendo finalizado...\n\n\n\n\n\n";
                Sleep(3000);
                return 0;
            }
            else
            {
                answerAsVector = answerToVector(answer);
            }

        } while ((testAnswer(answerAsVector) == false));

        predictNextRoundEconomy(answerAsVector);

        system("cls");
        cout << "\n\n\t -- Round finalizado, proximo input: \n\n";

    } while (hasToRepeat);

    system("cls");
    cout << "\n\n\tO sistema esta sendo finalizado...\n\n\n\n\n\n";
    Sleep(3000);

    return 0;


}

void predictNextRoundEconomy(std::vector<string> answerAsVector)
{
    int parseStringToInt(string stringAux); //method prototype

    string side = answerAsVector[0];
    char sideAsChar = (side[0] == 'T' || side[0] == 't') ? 't' : 'c';

    int consecutiveLostRounds = parseStringToInt(answerAsVector[1]);
    int playerOneEconomy = parseStringToInt(answerAsVector[2]);
    int playerTwoEconomy = parseStringToInt(answerAsVector[3]);
    int playerThreeEconomy = parseStringToInt(answerAsVector[4]);
    int playerFourEconomy = parseStringToInt(answerAsVector[5]);
    int playerFiveEconomy = parseStringToInt(answerAsVector[6]);

    cout << sideAsChar;
    cout << consecutiveLostRounds;
    cout << playerOneEconomy;
    cout << playerTwoEconomy;
    cout << playerThreeEconomy;
    cout << playerFourEconomy;
    cout << playerFiveEconomy;

    system("cls");

    //implementar logica

    Sleep(3000);
}


int parseStringToInt(string stringAux)
{
    std::stringstream geek(stringAux);
    int integerAux = -1;
    geek >> integerAux;
    return integerAux;
}

bool testInputSide(string side)
{
    if ((side == "T") || (side == "CT") || (side == "TR") || (side == "t") || (side == "ct") || (side == "tr")){
        return true;
    }

    return false;
}


//This method isnt trimming yet
bool testAnswer(std::vector<string> answerAsVector)
{

	//Quantity of answers whas different from expected
	if (answerAsVector.size() != 7)
		return false;

	//Type of player out of format
	if (!testInputSide(answerAsVector[0]))
		return false;

	//Its impossible to have lost negative consecutive rounds
	try
	{
		int aux = std::stoi(answerAsVector[1]);
		if (aux < 0)
			return false;
	}

	catch (std::invalid_argument const& e)
	{
		cout << "\n\n\tYou insert string argument when an integer was being expected, system is shutting down...";
	}

	//A player cannot have less of U$0 or more of U$16000
	for (int i = 2; i < 7; i++)
	{
		try
		{
			int aux = std::stoi(answerAsVector[i]);
			if (aux < 0 || aux > 16000)
				return false;
		}

		catch (std::invalid_argument const& e)
		{
			cout << "\n\n\tYou insert string argument when an integer was being expected, system is shutting down...";
		}

	}

	//insert here more conditions;

	return true;
}


std::vector<string> answerToVector(string answer)
{
	std::stringstream ss(answer);
	std::vector<string> vectorAnswer;
	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		vectorAnswer.push_back(substr);
	}

	return vectorAnswer;
}
