// 1_LRUCache.cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	string key;
	int value;

	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};


class LRUCache {
	int capacity;
	list<Node> l;
	unordered_map<string, list<Node>::iterator> mp;
public:
	LRUCache(int capacity) {
		// set min size as 1
		this->capacity = capacity > 1 ? capacity : 1;
	}
	// O(1)
	void insert(string key, int value) {
		// C1: If the key is already present in the Map,
		if(mp.count(key) != 0) {
			// replace the old value with the new value
			auto it = mp[key];   // get the address of the node with the given key
			it->value = value;     // update its value...

			// update krne ke baad, 
			// node ko utha ke sabse aage leke ao!
			auto node_add = mp[key];
			l.push_front(*node_add);
			l.erase(node_add);
			mp[key] = l.begin();
		}

		// C2: If the key is not present in the Map
		else {
			// if lst is FULL!
			if(l.size() == capacity) {
				// delete the least recently used item from the cache
				Node last_node = l.back();
				mp.erase(last_node.key); // remove the entry from the hashmap
				l.pop_back();            // remove the last node
			}
			
			// now add new {key:val} on head!
			Node newnode(key,value);    // create newnode
			l.push_front(newnode);      // push it onto the head
			mp[key] = l.begin();        // make the entry in mp
		}
		return;
	}
	// O(1)
	int* getValue(string key) {
		// C1: If the key is not present in the Map
		if(mp.count(key) == 0) return NULL;
		// C2: If the key is already present in the Map
		else {
			auto node_add = mp[key];
			// int value = node_add->value;
			l.push_front(*node_add);
			l.erase(node_add);
			mp[key] = l.begin();
			return &l.begin()->value;
		}
	}
	// O(1)
	string getMostRecentKey() {
		// C1: If the List is Empty
		return l.empty() ? return "" : l.front().key;
		// C2: If we have Non-Empty List
	}
};


int main() {
	LRUCache lru(5);
	return 0;
}