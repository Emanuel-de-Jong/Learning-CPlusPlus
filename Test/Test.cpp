/*
 *      Word guessing game.
 */

#include <iostream>
#include <time.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::map;
using std::vector;


void readCsv(const string& filename, map<unsigned int, vector<string>>& values)
{
    std::ifstream file(filename);

    if (!file.is_open()) throw std::runtime_error("Could not open file");
    if (!file.good()) throw std::runtime_error("File stream has errors");

    string value;
    while (getline(file, value, ',')) {
        values[value.size()].push_back(value);
    }

    file.close();
}


bool checkStringToUnsignedInt(const string &str)
{
    if (str.empty()) return false;

    for (const char &c : str) {
        if (!isdigit(c)) return false;
    }

    return true;
}

unsigned int askUnsignedInt(const string &question)
{
    cout << question << "\n";

    string answer;
    bool conditionResult;
    do {
        cin >> answer;

        conditionResult = checkStringToUnsignedInt(answer);
        if (!conditionResult) cout << "Input is not a positive number\n";
    } while (!conditionResult);

    return stoul(answer);
}


void guessWord(const string word, unsigned int chances)
{
    cout << "Word: " << word << "\nChances: " << chances << "\n";
    //system("pause");
}


int main()
{
    srand(time(NULL));

    map<unsigned int, vector<string>> words;
    readCsv("Words.csv", words);

    string question = "Choose the length of the word to guess (possible options are:";
    for (const std::pair<const unsigned int, vector<string>> &pair : words) {
        question += " " + std::to_string(pair.first);
    }
    question += "):";

    unsigned int wordLength;
    bool conditionResult;
    do {
        wordLength = askUnsignedInt(question);

        conditionResult = words.count(wordLength) ;
        if (!conditionResult) cout << "There are no words of length " << wordLength << "\n\n";
    } while (!conditionResult);
    cout << "\n";
    
    const string word = words[wordLength][rand() % (words[wordLength].size() - 1)];
    unsigned int chances = askUnsignedInt("Choose the amount of times you can guess:");
    cout << "\n";
    guessWord(word, chances);

    return 0;
}