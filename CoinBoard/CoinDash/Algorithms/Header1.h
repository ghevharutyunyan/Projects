#pragma once
#include <vector>
#include <list>
#include <string>


class Hash_Table {
public:
	static const int size = 10;
	std::vector<std::list<std::pair<int, int>>> table;

public:
	Hash_Table() :table(size){}

	// for int keys
	int get_hash_i(const int &key) {
		return key >= 0 ? key % table.size() : -1;
	}
	// for string keys
	int get_hash_s(const std::string &key) {
		int hash = 0;

		for (int i = 0; i < key.size(); ++i) {
			hash = (hash << 5) - hash + key[i];
		}
		return hash;
	}
	
	//for int keys
	void insert_or_update_i(const int &key, int value) {
		int index = get_hash_i(key);

		for (auto& pair : table[index]) {
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		table[index].push_back({ key,value });
	}

	void insert_or_update_s(const std::string &key, int value) {
		int index = get_hash_s(key);

		for (auto& pair : table[index]) {
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		table[index].push_back({ key,value });
	}


	bool search(const int key, int& value) {
		int index = get_hash(key);

		for (auto& pair : table[index]) {
			if (pair.first == key) {
				value = pair.second;
				return true;
			}
		}
		return false;
	}

	void remove(int key) {
		int index = get_hash(index);
		auto &list = table[index];

		for (auto it = list.begin(); it != list.end(); ++it) {
			if (it->first == key) {
				list.erase(it);
				return;
			}
		}
	}

};