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
        values[value.size()].push_back(value);  // values[size of string][vector of strings with that size]
    }
}


unsigned int askUnsignedInt(const string& question)
{
    cout << question << "\n";

    unsigned int answer;
    string line;
    // loops untill the user input is an unsigned int
    while (!(cin >> answer))
    {
        cin.clear();
        getline(std::cin, line);
        cout << "Input is not a positive number\n";
    }

    return answer;
}


// main game
void guessWord(const string word, unsigned int chances)
{
    cout << "Word: " << word << "\nChances: " << chances << "\n";
    //system("pause");
}


int main()
{
    srand(time(NULL));

    // reads all the words in Words.csv and sorts them by length in 'words'
    map<unsigned int, vector<string>> words;
    readCsv("Words.csv", words);

    string question = "Choose the length of the word to guess (possible options are:";
    // appends 'question' with all keys (word lengths) in 'words'
    for (const std::pair<const unsigned int, vector<string>>& pair : words) {
        question += " " + std::to_string(pair.first);
    }
    question += "):";

    unsigned int wordLength;
    // loops untill the user input is a word length existent in 'words'
    while ((wordLength = askUnsignedInt(question)) && !words.count(wordLength)) {
        cout << "There are no words of length " << wordLength << "\n\n";
    }
    cout << "\n";
    
    // chooses a random index in the vector at words[wordLength]
    const string word = words[wordLength][rand() % (words[wordLength].size() - 1)];

    unsigned int chances = askUnsignedInt("Choose the amount of times you can guess:");
    cout << "\n";
    guessWord(word, chances);

    return 0;
}