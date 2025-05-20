#include <iostream>
#include <list>
using namespace std;

// LRU Cache - Least Recently Used Cache
// Approach: Doubly Linked List and Hashmap
class Node {
private:
	int key;
	int value;

public:
	Node(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	int getKey() {
		return key;
	}
};

class LRUCache {
	int capacity;
	list<Node> l;
	unordered_map<int, list<Node>::iterator> mp;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	// O(1)
	int get(int key) {
		// C1: If the key is not present in the Map
		if (mp.find(key) == mp.end()) return -1;

		// C2: If the key is already present in the Map
		auto nodeIt = mp[key];
		l.push_front(*nodeIt);

		l.erase(nodeIt);
		mp[key] = l.begin();
		return nodeIt->getValue();
	}

	// O(1)
	void put(int key, int value) {
		// C1: If key is already present in LRU Cache
		if (mp.find(key) != mp.end()) {
			// 1. Replace the old value
			auto oldIt = mp[key];
			oldIt->setValue(value);

			// 2. Push node in front of the list
			l.push_front(*oldIt);

			// 3. Delete the prev occurence of node
			l.erase(oldIt);

			// 4. Update the map to point new position
			mp[key] = l.begin();
		}
		// C2: If key is absent
		else {
			// If List is already full, delete the least used item
			if (l.size() == capacity) {
				auto lastNodeIt = prev(l.end());
				mp.erase(lastNodeIt->getKey());
				l.pop_back();
			}

			Node newNode = Node(key, value);
			l.push_front(newNode);
			mp[key] = l.begin();
		}
	}

	// O(1)
	int getMostRecentKey() {
		return l.empty() ? -1 : l.begin()->getKey();
	}
};

int main() {
	LRUCache lru(5);
	return 0;
}