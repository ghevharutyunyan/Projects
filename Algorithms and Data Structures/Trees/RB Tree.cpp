#include <iostream>
#include <stack>

enum Color{Red,Black};

template <typename T>
class TreeNode {
public:
    Color color;
    TreeNode<T>* parent;
    TreeNode<T>* left;
    TreeNode<T>* right;
    T key;

public:
    TreeNode(T m_key) :color{ Red },parent { nullptr }, left{ nullptr }, right{ nullptr }, key{ m_key } {}
};


template <typename T>
class RBTree {
public:
    TreeNode<T>* root;
    TreeNode<T>* NIL;
public:
    RBTree(){
        NIL = new TreeNode<T>(0);
        NIL->color = Black;
        root = NIL;
    }

    ~RBTree() {
        clear(root);
        delete NIL;
    }

    void clear(TreeNode<T>* current) {
        if (current != NIL) {
            clear(current->left);
            clear(current->right);
            delete current;
        }
    }

    void insert(T key) {
        TreeNode<T>* newNode = new TreeNode<T>(key);
        TreeNode<T>* parentNode = nullptr;
        TreeNode<T>* current = root;

        while (current != NIL) {
            parentNode = current;
            if (newNode->key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        newNode->parent = parentNode;

        if (parentNode == nullptr) {
            root = newNode;
        }
        else if (newNode->key < parentNode->key) {
            parentNode->left = newNode;
        }
        else {
            parentNode->right = newNode;
        }
        
        if (newNode->parent == nullptr) {
            newNode->color = Black;
            return;
        }

        if (newNode->parent->parent == nullptr) {
            return;
        }

        newNode->left = NIL;
        newNode->right = NIL;
        newNode->color = Red;

        fix_insert(newNode);

    }

    void leftRotate(TreeNode<T>* current) {
        TreeNode<T>* x = current->right;
        current->right = x->left;

        if (x->left != NIL) {
            x->left->parent = current;
        }
        x->parent = current->parent;
        
        if (current->parent == nullptr) {
            root = x;
        }
        else if (current == current->parent->left) {
            current->parent->left = x;
        }
        else if (current == current->parent->right) {
            current->parent->right = x;
        }
        x->left = current;
        current->parent = x;

    }

    void rightRotate(TreeNode<T>* current) {
        TreeNode<T>* y = current->left;
        current->left = y->right;

        if (y->right != NIL) {
            y->right->parent = current;
        }
        y->parent = current->parent;
        if (current = current->parent->right) {
            current->parent->right = y;
        }
        else if (current = current->parent->left) {
            current->parent->left = y;
        }
        y->right = current;
        current->parent = y;
    }

    void fix_insert(TreeNode<T>* newNode) {
        while (newNode->parent->color == Red) {
            if (newNode->parent == newNode->parent->parent->left) {
                TreeNode<T>* uncle = newNode->parent->parent->right;
                if (uncle->color == Red) { // CASE 1
                    newNode->parent->color = Black;
                    uncle->color = Black;
                    newNode->parent->parent->color = Red;
                    newNode = newNode->parent->parent;
                }
                else { // CASE 2
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        leftRotate(newNode);
                    } // CASE 3
                    newNode->parent->color = Black;
                    newNode->parent->parent->color = Red;
                    rightRotate(newNode->parent->parent);
                }
            }
            else {
                TreeNode<T>* uncle = newNode->parent->parent->left;
                if(uncle->color == Red){ // CASE 1
                    newNode->parent->color = Black;
                    uncle->color = Black;
                    newNode = newNode->parent->parent;
                }
                else { // CASE 2
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rightRotate(newNode);
                    } // CASE 3
                    newNode->parent->parent->color = Red;
                    newNode->parent->color = Black;
                    leftRotate(newNode->parent->parent);

                }
            }
            if (newNode == root) {
                break;
            }
        }
        root->color = Black;
    }

    void r_inorder_tree(TreeNode<T>* node) { // recursive
        if (node == NIL) {
            return;
        }
        inorder_tree(node->left);
        std::cout << node->key << " ";
        inorder_tree(node->right);
    }

    void inorder_tree() {
        if (root == NIL) {
            return;
        }

        std::stack<TreeNode<T>*> st;
        TreeNode<T>* current = root;
        
        while (current != NIL || !st.empty()) {
            while (current != NIL) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            std::cout << current->key;
            current = current->right;е
        }
    }
};


int main() {

}

