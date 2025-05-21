
#include <vector>
#include <iostream>

class Node {
public:
    int data;
    Node* next;
public:
    Node(int m_data):data(m_data),next(nullptr){}

};


class Slist {
private:
    Node* head;
public:
    Slist() :head(nullptr) {}
    Slist(int m_data) {
        head = new Node(m_data);
        head->next = nullptr;
    }

    ~Slist() {
        clear();
    }

public:
    bool is_empty() {
        if (head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void push_front(int data) {
        Node* tmp = new Node(data);
        tmp->next = head;
        head = tmp;
    }

    void pop_front() {
        if (is_empty()) {
            throw std::out_of_range("list is empty");
        }

        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    void insert_after(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            throw std::out_of_range("List has no previous Node");
        }
        Node* tmp = new Node(data);
        tmp->next = prevNode->next;
        prevNode->next = tmp;
    }

    void erase_after(Node* prevNode) {
        if (prevNode == nullptr) {
            throw std::out_of_range("List has no previous Node");
        }

        Node* tmp = prevNode->next;
        prevNode->next = tmp->next;
        delete tmp;
    }

    void clear() {
        if (is_empty()) {
            throw std::out_of_range("The List has already cleared");
        }

        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int front() {
        if (is_empty()) {
            throw std::out_of_range("The list is empty");
        }
        return head->data;
    }

    void print() {
        if (is_empty()) {
            throw std::out_of_range("The list is empty");
        }

        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

    }

    void reverse() {

        Node* current = head;
        Node* next = nullptr;
        Node* prev = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }
        head = prev;
    }

    void merge(Slist& list) {
        Node* current = head;

        while (current != nullptr) {
            current = current->next;
        }

        current = list.head;

    }

    Node* mergeSortList(Node* left, Node* right) {
        if (!left) return right;
        if (!right)return left;

        Node* result = nullptr;

        if (left->data <= right->data) {
            result = left;
            result->next = mergeSortList(left->next, right);
        }
        else {
            result = right;
            result->next = mergeSortList(left, right->next);
        }

        return result;
    }

    void splitList(Node* source, Node** front, Node** back) {
        Node* slow = source;
        Node* fast = source->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
    }

    Node* mergeSort(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* back;
        Node* front;

        splitList(node, &back, &front);

        front = mergeSort(front);
        back = mergeSort(back);

        return mergeSortList(front, back);
    }

    void sort() {
        head = mergeSort(head);
    }

};






int main() {
    Slist obj;

    obj.push_front(5);
    obj.push_front(4);
    obj.push_front(3);
    obj.push_front(2);
    obj.push_front(1);

    obj.reverse();
    obj.print();
   
}