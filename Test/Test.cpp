#include <iostream>
#include <string>
#include "HashTable.cpp"

using std::cin;
using std::cout;
using std::string;

int main()
{
    HashTable* ht = new HashTable();
    ht->set("mand", 18);
    ht->set("rofl", 25);
    ht->set("a", 2);
    ht->set("a", 12);

    cout << ht->get("mand") << "\n";
    cout << ht->get("rofl") << "\n";
    cout << ht->get("a")    << "\n";
    
    cin.get();
}