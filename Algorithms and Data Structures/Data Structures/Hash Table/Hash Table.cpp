#include "HashTable"
#include <iostream>

int main() {
    Hash_Table ht;
    ht.insert_or_update_i(1, 10);
    ht.insert_or_update_i(2, 20);
    ht.insert_or_update_i(12, 120);
    ht.insert_or_update_i(22, 220);
    ht.insert_or_update_i(32, 320);
    ht.insert_or_update_i(42, 420);
    ht.insert_or_update_i(52, 520);
    ht.insert_or_update_i(62, 620);
    ht.insert_or_update_i(72, 720);
    ht.insert_or_update_i(82, 820);
    ht.insert_or_update_i(92, 920);
    ht.display();

    int value;
    if (ht.search(12, value)) {
        std::cout << "Found: " << value << std::endl;
    }
    else {
        std::cout << "Not Found" << std::endl;
    }

    ht.remove(2);
    ht.display();

    return 0;
}
