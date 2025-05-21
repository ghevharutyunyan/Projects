#include <iostream>
#include <stack>

template <typename T>
class TreeNode {
public:
    TreeNode<T>* left;
    TreeNode<T>* right;
    T value;
    int height;
    int level = 0;

    TreeNode(T val):left(nullptr),right(nullptr),value(val),height(1){}
};

template <typename T>
class AVL {
    TreeNode<T>* root;
    int level = 0;
public:
    AVL() :root(nullptr){}

    TreeNode<T>* get_root() {
        return root;
    }

    int get_height(TreeNode<T>* node) {
        return node == nullptr ? 0 : node->height;
    }

    int get_balance(TreeNode<T>* node) {
        return node ? get_height(node->left) - get_height(node->right) : 0;
    }

    void updateHeight(TreeNode<T>* node) {
        if (node != nullptr) {
            node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        }
    }

    TreeNode<T>* rightRotation(TreeNode<T>* node) {
        TreeNode<T>* x = node->left;
        TreeNode<T>* tmp = x->right;
        
        //rotation
        x->right = node;
        node->left = tmp;

        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

        return x;
    }

    TreeNode<T>* leftRotation(TreeNode<T>* node) {
        TreeNode<T>* y = node->right;
        TreeNode<T>* tmp = y->left;
        
        //rotation
        y->left = node;
        node->right = tmp;

        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    TreeNode<T>* insert(TreeNode<T>* node, T data) {
        if (!node) { return new TreeNode<T>(data); }

        if (data > node->value) {
            node->right = insert(node->right, data);
        }
        else if (data < node->value) {
            node->left = insert(node->left, data);
        }
        else {
            return node;
        }

        int balance = get_balance(node);

        if (balance > 1 && data < node->left->value) {
            return rightRotation(node);
        }

        if (balance < -1 && data > node->right->value) {
            return leftRotation(node);
        }

        if (balance > 1 && data > node->left->value) {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

        if (balance < -1 && data < node->right->value) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }

        return node;
    }
    void insert_(T data) {
        root = insert(root,data);
    }


    TreeNode<T>* remove(TreeNode<T>* node, T key) {
        if (root == nullptr) { return node; }

        if (node->value > key) {
            node->left = remove(node->left,key);
        }
        else if (node->value < key) {
            node->right = remove(node->right, key);
        }
        else {
            if (node->left == nullptr) {
                TreeNode<T>* tmp = node->right;
                delete node;
                node = tmp;
                return node;
            }
            if (node->right == nullptr) {
                TreeNode<T>* tmp = node->left;
                delete node;
                node = tmp;
                return node;
            }

            TreeNode<T>* successor = findMin(node->right);
            node->value = successor->value;
            node->right = remove(node->right, successor->value);
        }
        if (node == nullptr) {
            return node;
        }

        updateHeight(node);

        int balance = get_balance(node);

        if (balance > 1 && get_balance(node->left)>=0) {
            return rightRotation(node);
        }

        if (balance > 1 && get_balance(node->left) < 0) {
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

        if (balance < -1 && get_balance(node->right) <= 0) {
            return leftRotation(node);
        }

        if (balance < -1 && get_balance(node->right) > 0) {
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }

        return node;
    }

    void remove_(T data) {
        root = remove(root, data);
    }

    TreeNode<T>* findMin(TreeNode<T>* node) {
        if (node && node->left) {
            return node->left;
        }
        return node;
    }

    void inorderTraversal() {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode<T>*> st;
        
        TreeNode<T>* current = root;
        
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            std::cout << current->value << " ";
            current = current->right;
        }
    }

    void recursiv_inorder_hak(TreeNode<T>* node) {
        if (node != nullptr) {
            
            ++level;

            recursiv_inorder_hak(node->right);
            for (int i = 0; i < level; ++i) {
                std::cout << "\t";
            }
            std::cout << node->value << " " << std::endl;
           
            recursiv_inorder_hak(node->left);
            --level;
            
        }
    }

};

int main()
{
    AVL<int> obj;

    obj.insert_(49);
    obj.insert_(28);
    obj.insert_(83);
    obj.insert_(18);
    obj.insert_(40);
    obj.insert_(71);
    obj.insert_(97);
    obj.insert_(11);
    obj.insert_(19);
    obj.insert_(32);
    obj.insert_(44);
    obj.insert_(69);
    obj.insert_(72);
    obj.insert_(92);
    obj.insert_(99);

    obj.recursiv_inorder_hak(obj.get_root());
}

