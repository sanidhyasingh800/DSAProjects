#include <iostream>
#include <queue>

// Linked implemebtation of a Binary Search Tree 
// search and insert work in log n time on average but degrade to O(n) in worst case (non balancing)
// 

using namespace std;

namespace Trees {
    // Data must be comparable!!!
    template<typename Data>
    class BinarySearchTree {
    private:
        struct Node {
            Node* left = NULL;
            Node* right = NULL;
            Data data;
        };
        Node* root;


        void insert(Data& d, Node*& root) {
            if (root == NULL) {
                root = new Node();
                root->data = d;
                return;
            }
            else if (d >= root->data) {
                insert(d, root->right);
            }
            else if (d < root->data) {
                insert(d, root->left);
            }
        }

        void inOrderTraversal(Node* root) {
            if (root->left != NULL) {
            inOrderTraversal(root->left);
            }
            cout << root->data << " ";
            if (root->right != NULL) {
            inOrderTraversal(root->right);
            }
        }

        void preOrderTraversal(Node* root) {
            cout << root->data << " ";
            if (root->left != NULL) {
            preOrderTraversal(root->left);
            }
            if (root->right != NULL) {
            preOrderTraversal(root->right);
            }
        }

        void postOrderTraversal(Node* root) {
            if (root->left != NULL) {
                postOrderTraversal(root->left);
            }
            if (root->right != NULL) {
                postOrderTraversal(root->right);
            }
            cout << root->data << " ";
        }

        void levelOrderTraversal(Node* root) {
            if (root == NULL) {
                return;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                cout << q.front()->data << " ";
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        bool search (Data data, Node* node) {
            if (data > node->data) {
                if (node->right == NULL) {
                    return false;
                }
                return search (data, node->right);
            }
            if (data < node->data) {
                if (node->left == NULL) {
                    return false;
                }
                return search (data, node->left);
            }
            return true;
        }

        int heightOfTree(Node* root) {
            if (root == NULL) {
                return -1;
            }
            if(root->right == NULL && root->left == NULL) {
                return 0;
            }
            int rightTreeHeight = 0;
            int leftTreeHeight = 0;
            if (root->right != NULL){
                rightTreeHeight = heightOfTree(root->right);
            }
            if (root->left != NULL) {
                leftTreeHeight = heightOfTree(root->left);
            }
            if (rightTreeHeight > leftTreeHeight) {
                return 1+ rightTreeHeight;
            }
            return 1 + leftTreeHeight;
        }
        public:
        BinaryTree() {
            root = NULL;
        }

        void insert(Data data) {
            insert(data, root);
        }

        bool search (Data data) {
            return search(data, root);
        }

        void preOrderTraversal(){
            preOrderTraversal(root);
        } 

        void inOrderTraversal() {
            inOrderTraversal(root);
        }

        void postOrderTraversal()  {
            postOrderTraversal(root);
        }

        void levelOrderTraversal() {
            levelOrderTraversal(root);
        }

        int heightOfTree() {
            return heightOfTree(root);
        }

        void printPaths() const {
            printPaths(root);
        }

        void printPaths(const Node* subRoot) const {
            cout << to_string(subRoot->data) << " ";
            if (subRoot->left != NULL) {
                printPaths(subRoot->left);
            }
            cout << endl;
            if (subRoot->right != NULL) {
                printPaths(subRoot->right);
            }
             cout << endl;
        }

    };
}