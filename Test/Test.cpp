/*
 *      Word guessing game.
 */

#include <iostream>
#include <string>
#include <list> 
#include <time.h>

using std::cout;
using std::cin;
using std::string;
using std::list;


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
    bool conditionResult;
    // loops until input is valid
    do {
        cin >> answer;

        conditionResult = !checkStringConvertableToUnsignedInt(answer);
        if (conditionResult) cout << "Choose a positive interger\n";
    } while (conditionResult);

    return stoul(answer);
}


// loops through string array, appending all strings with 'stringLength' amount of characters to list
void addArrElementsOfStringLengthToList(const string source[], list<string> &target, unsigned int sourceSize, unsigned int stringLength)
{
    for (unsigned int i = 0; i < sourceSize; i++) {
        if (source[i].size() == stringLength) target.push_back(source[i]);
    }
}


// main game 
void guessWord(const string &word, unsigned int chances)
{
    cout << "Word: " << word << "\nChances: " << chances << "\n";
    //system("pause");
}


int main()
{
    srand(time(NULL));

    string wordArr[] = { "not", "what", "all", "were", "we", "when", "your", "can", "said", "there", "use", "an", "each", "which", "she", "do", "how", "their", "if", "will", "up", "other", "about", "out", "many", "then", "them", "these", "so", "some", "her", "would", "make", "like", "him", "into", "time", "has", "look", "two", "more", "write", "go", "see", "number", "no", "way", "could", "people", "my", "than", "first", "water", "been", "call", "who", "oil", "its", "now", "find", "long", "down", "day", "did", "get", "come", "made", "may", "part" };
    unsigned int wordArrSize = sizeof(wordArr) / sizeof(wordArr[0]);

    unsigned int wordLength;
    list<string> wordChoiceArr;
    bool conditionResult;
    // loops until the user chooses a wordLength that occurs in the wordArr
    do {
        wordLength = askUnsignedInterger("Choose the length of the word to guess:");
        addArrElementsOfStringLengthToList(wordArr, wordChoiceArr, wordArrSize, wordLength);

        conditionResult = wordChoiceArr.empty();
        if (conditionResult) cout << "There are no words of length " << wordLength << "\n\n";
    } while (conditionResult);
    cout << "\n";
    
    // chooses a random index in the wordChoiceArr as the word to guess
    list<string>::iterator wordIt = wordChoiceArr.begin();
    advance(wordIt, rand() % (wordChoiceArr.size() - 1));
    string word = *wordIt;

    unsigned int chances = askUnsignedInterger("Choose the amount of times you can guess:");
    cout << "\n";
    guessWord(word, chances);

    return 0;
}