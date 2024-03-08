#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

// Linked implemebtation of an AVL Binary Search Tree 
// search and insert work in log n time on average 
// balancing invariant: for each node, left and right subtrees differ in height by at most 1

using namespace std;

namespace Trees {

    template<class Key, class Value>
    class AVLTree {
    private: 
        struct Node {
            Node* right = NULL;
            Node* left = NULL;
            int balance = 0;
            Key key;
            Value value;
            Node(Key key1, Value value1) {
                key = key1;
                value = value1;
            }
        };

        Node* root;

        Node* insert(Node*& subroot, Key key, Value value) {
            if (subroot == NULL) {
                subroot = new Node(key, value);
                return subroot;
            } else if (key > subroot->key) {
                subroot->balance = subroot->balance + 1;
                subroot->right = insert(subroot->right, key, value);
                if (subroot->balance > 1) {
                    if (subroot->right->balance < 0) {
                        subroot->right = rightRotation(subroot->right);
                    }
                    return leftRotation(subroot);
                } else {
                    return subroot;
                }
            } else if (key < subroot->key) {
                subroot->balance = subroot->balance - 1;
                subroot->left = insert(subroot->left, key, value);
                if (subroot->balance < -1) {
                    if (subroot->right->balance > 0) {
                        subroot->left = leftRotation(subroot->left);
                    }
                    return rightRotation(subroot);
                } else {
                    return subroot;
                }
            }

            return NULL;
        }

        Node* rightRotation(Node* subroot) {
            Node* leftChild = subroot->left;
            // leftChild will never be null, since we only perform rightRotation when left is heavier
            Node* leftChildright = leftChild->right;
            leftChild->right = subroot;
            subroot->left = leftChildright;
            leftChild->balance++;
            subroot->balance = 0;
            return leftChild;
        }

        Node* leftRotation(Node* subroot) {
            Node* rightChild = subroot->right;
            // rightChild will never be null, since we only perform leftRotation when right is heavier
            Node* rightChildleft = rightChild->left;
            rightChild->left = subroot;
            subroot->right = rightChildleft;
            rightChild->balance--;
            subroot->balance = 0;


            return rightChild;
        }

                
        void levelOrderTraversal(Node* root) {
            if (root == NULL) {
                return;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                cout << q.front()->value << " ";
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        void inOrderTraversal(Node* root) {
            if (root->left != NULL) {
            inOrderTraversal(root->left);
            }
            cout << root->value << " ";
            if (root->right != NULL) {
            inOrderTraversal(root->right);
            }
        }



    

    public: 
        AVLTree() {
            root = NULL;
        }

        void insert(Key key, Value value) {
            root = insert(root, key, value);
        }

        void levelOrderTraversal() {
            levelOrderTraversal(root);
        }

        void inOrderTraversal() {
            inOrderTraversal(root);
        }

    };

}