#include <iostream>

template <typename T>
class Node {
public:
    Node<T>* next;
    Node<T>* prev;
    T data;
public:
    Node(T m_data) :next{ nullptr }, prev{ nullptr }, data{ m_data } {}
};

template <typename T>
class Dlist {
public:
    Node<T>* head;
    Node<T>* tail;
public:
    Dlist() :head{ nullptr }, tail{ nullptr } {}

    void push_front(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            head = tail;
        }
        else {

            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node<T>* tmp = head;

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = tmp->next;
            head->prev = nullptr;
        }
        delete[] tmp;
    }

    void delete_node(T value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            pop_front();
        }

        Node<T>* tmp = head;

        while (tmp != nullptr && tmp->data != value) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            std::cout << "The Node is not found";
            return;
        }

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;

        delete[] tmp;
    }

    void clear() {
        if (head == nullptr) {
            return;
        }

        Node<T>* temp = head;

        while (temp != nullptr) {
            Node<T>* current = temp->next;
            delete[] temp;
            temp = current;
        }

        head = tail = nullptr;
    }

    Node<T>* merge_sorted_list(Node<T>* left, Node<T>* right) {
        if (left == nullptr) { return right; }
        if (right == nullptr) { return left; }

        Node<T>* result = nullptr;

        if (left->data <= right->data) {
            result = left;
            result->next = merge_sorted_list(left->next, right);
            if (result->next != nullptr) {
                result->next->prev = result;
            }
        }
        else {
            result = right;
            result->next = merge_sorted_list(left, right->next);
            if (result->next != nullptr) {
                result->next->prev = result;
            }
        }

        return result;

        
    }

    void split_list(Node<T>* current, Node<T>** back, Node<T>** front) {
        Node<T>* slow = current;
        Node<T>* fast = current->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *back = current;
        *front = slow->next;
        slow->next = nullptr;
        if (*front != nullptr) {
            (*front)->prev = nullptr;
        }
    }

    Node<T>* merge_sort(Node<T>* node) {
        if (node == nullptr && node->next == nullptr) { return node; }

        Node<T>* back;
        Node<T>* front;

        split_list(node, &back, &front);

        back = merge_sort(back);
        front = merge_sort(front);

        return merge_sorted_list(back, front);
    }
   

};



int main()
{
    std::cout << "Hello World!\n";
}

