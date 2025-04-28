#pragma once
#include <vector>
#include <list>
#include <string>


class Hash_Table {
private:
	int size;
	int count;
	std::vector<std::list<std::pair<int, int>>> table;

	double load_factor() {
		return double(count) / size;
	}

	void rehash() {
		int new_size = size * 2;
		std::vector<std::list<std::pair<int, int>>> newTable(new_size);

		for (int i = 0; i < size; ++i) {
			for (const auto& node : table[i]) {
				int index = node.first % new_size;
				newTable[index].push_back(node);
			}
		}
		size = new_size;
		table = std::move(newTable);

	}
	
public:
	Hash_Table(int SIZE = 10) :size(SIZE),count(0),table(SIZE){}

	
	int get_hash_i(const int &key) {
		return key >= 0 ? key % table.size() : -1;
	}
	/*
	int get_hash_s(const std::string &key) {
		int hash = 0;

		for (int i = 0; i < key.size(); ++i) {
			hash = (hash << 5) - hash + key[i];
		}
		return hash;
	}
	 for string keys*/

	//for int keys
	void insert_or_update_i(const int &key, int value) {
		if (load_factor() > 0.75) {
			rehash();
		}

		int index = get_hash_i(key);

		for (auto& pair : table[index]) {
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		table[index].push_back({ key,value });
		count++;
	}

	/*void insert_or_update_s(const std::string& key, int value) {
		int index = get_hash_s(key);

		for (auto& pair : table[index]) {
			for(int i = 0; i < pair.first)
			if (pair.first == key) {
				pair.second = value;
				return;
			}
		}
		table[index].push_back({ key,value });
	}*/


	bool search(const int key, int& value) {
		int index = get_hash_i(key);

		for (auto& pair : table[index]) {
			if (pair.first == key) {
				value = pair.second;
				return true;
			}
		}
		return false;
	}

	void remove(int key) {
		int index = get_hash_i(index);
		auto &list = table[index];

		for (auto it = list.begin(); it != list.end(); ++it) {
			if (it->first == key) {
				list.erase(it);
				count--;
				return;
			}
		}
	}

	void display() {
		for (int i = 0; i < size; ++i) {
			std::cout << "Index " << i << ": ";
			for (const auto& node : table[i]) {
				std::cout << "(" << node.first << ", " << node.second << ") ";
			}
			std::cout << std::endl;
		}
	}

};