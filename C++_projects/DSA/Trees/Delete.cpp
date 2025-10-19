#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // 🌱 Recursive Insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    

    // ❌ Recursive Delete
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr)
            return node;

        // Traverse the tree to find node
        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // 🧩 Case 1: No child (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // 🧩 Case 2: One child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // 🧩 Case 3: Two children
            else {
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }
        return node;
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // Helper to find minimum node (used in deletion)
    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // 🔁 Traversals
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

   

    
};

int main() {
    BST tree;

    // Insert some data
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "BST Inorder Traversal (Sorted): ";
    tree.inorder(tree.root);
    cout << endl;

  
    
    // ❌ Delete
    cout << "Deleting 7 from BST...\n";
    tree.deleteValue(7);

    cout << "BST Inorder after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
