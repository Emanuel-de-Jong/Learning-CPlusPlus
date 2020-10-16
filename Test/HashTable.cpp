#include <string>
#include <functional>
#include <list>

using std::string;
using std::list;

//template<typename Key, typename Value>
struct Pair {
	string key;
	int value;
};

//template<typename Key, typename Value>
class HashTable {
private:
	static const int valuesLen = 100;
	list<Pair*> values[valuesLen];
	std::hash<string> hash;
	
	int getIndex(string key) {
		return hash(key) % valuesLen;
	}

	Pair* getPairWithKey(list<Pair*> element, string key) {
		for (Pair* pair : element) {
			if (pair->key == key) {
				return pair;
			}
		}
		return NULL;
	}
public:
	HashTable() {}

	~HashTable() {
		for (list<Pair*> element : values) {
			for (Pair* pair : element) {
				delete pair;
			}
		}
	}

	void set(string key, int value) {
		int index = getIndex(key);
		Pair* currentPair = getPairWithKey(values[index], key);
		if (currentPair) {
			currentPair->value = value;
		}
		else {
			Pair* newPair = new Pair();
			newPair->key = key;
			newPair->value = value;

			values[index].push_back(newPair);
		}
	}

	int get(string key) {
		Pair* currentPair = getPairWithKey(values[getIndex(key)], key);
		if (currentPair) {
			return currentPair->value;
		}

		return NULL;
	}
};