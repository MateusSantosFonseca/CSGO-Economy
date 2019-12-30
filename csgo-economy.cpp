#include <iostream>
#include <vector>
#include <sstream>
#include <string>
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

    cout << "\n\tWelcome to the economy preview CSGO software -- updated in 29/12\n\n";
    cout << "\tTo understand the rules of CSGO economy and to use this software correctly, please, see the README.txt\n\n";
    cout << "\tTo answer the questions, answer everything on a comma-separated line, examples in README.txt\n\n";
    cout << "\tT ou CT? - Lost how many consecutive rounds? - Write, comma separated, all of the 5 players economy.\n\n";

    string answer;
    std::vector<string> answerAsVector;

    do
    {
        fflush(stdin);
        cout << "\tAnswer: ";
        cin >> answer;
        answerAsVector = answerToVector(answer);
    } while (testAnswer(answerAsVector) == false);
    fflush(stdin);

    //testing-purpose prints
    cout << "\n\t"+ answerAsVector[0];
    cout << "\n\t"+answerAsVector[1];
    cout << "\n\t"+answerAsVector[2];
    cout << "\n\t"+answerAsVector[3];
    cout << "\n\t"+answerAsVector[4];
    cout << "\n\t"+answerAsVector[5];
    cout << "\n\t"+answerAsVector[6]+"\n";


    //inserir valores em variaveis do tipo string (para o TR ou CT) e INT para os outros, no caso do int, usar try catch

    //a partir dos valores inseridos, fazer a logica necessaria, dentro de um while para quando  ele quiser refazer o calculo


}


//This method isnt trimming yet
bool testAnswer(std::vector<string> answerAsVector)
{

    //Quantity of answers whas different from expected
    if(answerAsVector.size() != 7)
        return false;

    //Type of player out of format
    if(!(answerAsVector[0] == "T" || answerAsVector[0] == "CT"))
        return false;

    //Its impossible to have lost negative consecutive rounds
    try
    {
        int aux = std::stoi(answerAsVector[1]);
        if(aux < 0)
            return false;
    }

    catch(std::invalid_argument const &e)
    {
        cout << "\n\n\tYou insert string argument when an integer was being expected, system is shutting down...";
    }

    //A player cannot have less of U$0 or more of U$16000
    for (int i = 2; i < 7; i++)
    {
        try
        {
            int aux = std::stoi(answerAsVector[i]);
            if(aux < 0 || aux > 16000)
                return false;
        }

        catch(std::invalid_argument const &e)
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
    while(ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        vectorAnswer.push_back(substr);
    }

    return vectorAnswer;
}
