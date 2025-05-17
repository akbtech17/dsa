// 2_LRUCache_LeetCode.cpp
// https://leetcode.com/problems/lru-cache/
#include <iostream>
#include <list>
using namespace std;

class Node {
public:
	int key;
	int value;

	Node(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class LRUCache {
	int capacity;
	list<Node> l;
	unordered_map<int, list<Node>::iterator> mp;

public:
	LRUCache(int capacity) {
		// set min size as 1
		this->capacity = capacity > 1 ? capacity : 1;
	}
	// O(1)
	void put(int key, int value) {
		// C1: If the key is already present in the Map,
		if (mp.count(key) != 0) {
			// replace the old value with the new value
			auto it = mp[key]; // get the address of the node with the given key
			it->value = value; // update its value...

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
			if (l.size() == capacity) {
				// delete the least recently used item from the cache
				Node last_node = l.back();
				mp.erase(last_node.key); // remove the entry from the hashmap
				l.pop_back();			 // remove the last node
			}

			// now add new {key:val} on head!
			Node newnode(key, value); // create newnode
			l.push_front(newnode);	  // push it onto the head
			mp[key] = l.begin();	  // make the entry in mp
		}
		return;
	}
	// O(1)
	int get(int key) {
		// C1: If the key is not present in the Map
		if (mp.count(key) == 0) return -1;
		// C2: If the key is already present in the Map
		else {
			// node ko utha ke sabse aage leke ao!
			auto node_add = mp[key];
			int value = node_add->value;
			l.push_front(*node_add);
			l.erase(node_add);
			mp[key] = l.begin();
			return value;
		}
	}
};