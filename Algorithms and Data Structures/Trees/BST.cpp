#include <iostream>
#include <stack>
#include <queue>

template <typename T>
class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    T data;
public:
    TreeNode(T m_data):left(nullptr),right(nullptr),data(m_data){}
};

template <typename T>
class BST {
public:
    TreeNode<T>* root;
public:
    BST():root(nullptr){}
private:
    void recursiv_add(TreeNode<T>* node, T newData) {
        if (node == nullptr) {
            node = new TreeNode<T>(newData);
            return;
        }

        if (node->data > newData) {
            recursiv_add(node->left);
        }
        else if (node->data < newData) {
            recursiv_add(node->right);
        }
    }


    void r_inorder(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        r_inorder(node->left);
        std::cout << node->data << " ";
        r_inorder(node->right);
    }

    void r_preorder(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        r_preorder(node->left);
        r_preorder(node->right);
    }

public:

    // ITERATIVE METHOD TO ADD ELEMENT
    void add(T newData) {
        if (root == nullptr) {
            root = new TreeNode<T>(newData);
        }

        TreeNode<T>** current = &root;

        while (*current != nullptr) {
            if ((*current)->data > newData) {
                current = &((*current)->left);
            }
            else if((*current)->data < newData){
                current = &((*current)->right);
            }
            else {
                return;
            }
            
        }
        *current = new TreeNode<T>(newData);
    }

    // RECURSIVE METHOD TO ADD ELEMENT
    void r_add(T newData) {
        recursiv_add(root, newData);
    }


    // PRINT NODES INORDER

    void inorder() {
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
            std::cout << current->data << " ";
            current = current->right;
        }
    }

    // RECURSIVE METHOD INORDER

    void inord() {
        r_inorder(root);
    }

    void preorder() {
        if (root == nullptr) {
            return;
        }

        std::stack<TreeNode<T>*> st;
        st.push(root);
        TreeNode<T>* current = root;

        while (!st.empty()) {
            current = st.top();                                                                                    
            st.pop();
            std::cout << current->data << " " ;
            
            if (current->right != nullptr) {
                st.push(current->right);
            }

            if (current->left != nullptr) {
                st.push(current->left);
            }
            
        }
        
    }

    void recursiv_inorder_hak(TreeNode<T>* node) {
        if (node != nullptr) {

            std::cout << "\t";
            recursiv_inorder_hak(node->right);
            std::cout << node->data << " " << std::endl;
            
            
            recursiv_inorder_hak(node->left);
      

            
        }
    }

    void pred() {
        r_preorder(root);
    }

    void l_order() {
        if (root == nullptr) {
            return;
        }

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode<T>* node = q.front();
            q.pop();
            std::cout << node->data;
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
 
        }
    }

    int get_height() {
        if (root == nullptr) {
            return -1;
        }

        std::queue<TreeNode<T>*> q;

        q.push(root);
        int height = 0;

        while (!q.empty()) {
            int level = q.size();

            for (int i = 0; i < level; ++i) {
                TreeNode<T>* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            height++;
        }
        return height;
    }
};

