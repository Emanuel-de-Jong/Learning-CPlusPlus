/*
 *      Word guessing game.
 */

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <map>

using std::cout;
using std::cin;
using std::string;

bool checkStringConvertableToUnsignedInt(const string &str)
{
    if (str.empty()) return false;

    for (const char &c : str) {
        if (!isdigit(c)) return false;
    }

    return true;
}

unsigned int askUnsignedInterger(const string &question)
{
    cout << question << "\n";

    string answer;
    cin >> answer;

    if (checkStringConvertableToUnsignedInt(answer)) {
        return stoul(answer);
    }
    else {
        throw "Input is not a positive number";
    }
}


void readCsv(const string &filename, std::map<const unsigned int, std::vector<string>> &words)
{
    std::ifstream file(filename);

    if (!file.is_open()) throw std::runtime_error("Could not open file");
    if (!file.good()) throw std::runtime_error("File stream has errors");

    string value;

    while (getline(file, value, ','))
    {
        words[value.size()].push_back(value);
    }

    file.close();
}


void guessWord(const string& word, unsigned int chances)
{
    cout << "Word: " << word << "\nChances: " << chances << "\n";
    //system("pause");
}


int main()
{
    srand(time(NULL));

    std::map<const unsigned int, std::vector<string>> words;
    readCsv("Words.csv", words);

    unsigned int wordLength;
    string question = "Choose the length of the word to guess (possible options are:";
    for (auto const& wl : words) {
        question += " " + std::to_string(wl.first);
    }
    question += "):";

    bool conditionResult;
    do {
        try {
            wordLength = askUnsignedInterger(question);
        }
        catch (string error) {
            cout << error;
        }

        conditionResult = words.count(wordLength) ;
        if (conditionResult) cout << "There are no words of length " << wordLength << "\n\n";
    } while (conditionResult);
    cout << "\n";
    
    string word = words[wordLength][rand() % (words.size() - 1)];

    unsigned int chances = askUnsignedInterger("Choose the amount of times you can guess:");
    cout << "\n";
    guessWord(word, chances);

    return 0;
}