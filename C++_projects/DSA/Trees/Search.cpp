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
    Node* root;
public:
    BST() {
        root = nullptr;
    }

    // 🌱 Recursive Insertion
    Node* insert(Node* node, int value)
     {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) 
    {
        root = insert(root, value);
    }

    // 🔍 Recursive Search
    Node* search(Node* node, int key)
     {
        if (node == nullptr || node->data == key)
            return node;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
     void searching(int key){
        Node* result = search(root, key);
        if (result)
            cout << "Element " << key << " found in BST.\n";
        else
            cout << "Element " << key << " not found.\n";
     }
    
    

    // Helper to find minimum node (used in deletion)
    Node* findMin(Node* node)
     {
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

    void print() {
        inorder(root);
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
    tree.print();
    cout << endl;

    // 🔍 Search
    int key = 4;
    tree.searching( key);
    
}
