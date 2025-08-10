#include <string>
#include <list>
#include <functional>

using std::string;
using std::list;

template<typename Key, typename Value>
struct Pair {
	Key key;
	Value value;
};

template<typename Key, typename Value>
class HashTable {
private:
	static const int valuesLen = 100;
	list<Pair<Key, Value>*> values[valuesLen];
	std::hash<Key> hash;
	
	int getIndex(Key key) {
		return hash(key) % valuesLen;
	}

	Pair<Key, Value>* getPairWithKey(list<Pair<Key, Value>*> element, Key key) {
		for (Pair<Key, Value>* pair : element) {
			if (pair->key == key) {
				return pair;
			}
		}
		return NULL;
	}
public:
	HashTable() {}

	~HashTable() {
		for (list<Pair<Key, Value>*> element : values) {
			for (Pair<Key, Value>* pair : element) {
				delete pair;
			}
		}
	}

	Value get(Key key) {
		Pair<Key, Value>* currentPair = getPairWithKey(values[getIndex(key)], key);
		if (currentPair) {
			return currentPair->value;
		}

		return NULL;
	}

	void set(Key key, Value value) {
		int index = getIndex(key);
		Pair<Key, Value>* currentPair = getPairWithKey(values[index], key);
		if (currentPair) {
			currentPair->value = value;
		}
		else {
			Pair<Key, Value>* newPair = new Pair<Key, Value>();
			newPair->key = key;
			newPair->value = value;

			values[index].push_back(newPair);
		}
	}

	void del(Key key) {
		int index = getIndex(key);
		for (Pair<Key, Value>* pair : values[index]) {
			if (pair->key == key) {
				values[index].remove(pair);
				break;
			}
		}
	}
};