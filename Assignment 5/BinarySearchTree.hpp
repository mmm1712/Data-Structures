#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>

template <class KeyType, class ValueType>
struct TreeNode {
    KeyType key; // Key associated with this node
    ValueType value;   // Value associated with this node
    TreeNode<KeyType, ValueType>* parent = nullptr;// Pointer to the parent of this node
    // Pointers to the right and left children of this node
    TreeNode<KeyType, ValueType>* right = nullptr;
    TreeNode<KeyType, ValueType>* left = nullptr;

    // Constructor that initializes key, value, and parent of this node
    TreeNode(KeyType key, ValueType value, TreeNode<KeyType, ValueType>* parent = nullptr)
            : key(key), value(value), parent(parent) {}
};
// A template class for a Binary Search Tree (BST), parameterized by KeyType and ValueType
template <class KeyType, class ValueType>
class BinarySearchTree {
public:
    // Constructor initializes root to nullptr, meaning an empty BST
    BinarySearchTree() :
            root(nullptr) {}
// Destructor deallocates memory used by the BST
    ~BinarySearchTree() {
        destroy(root);
    }

// Inserts a new node with the specified key and value into the BST
    void insert(KeyType key, ValueType value) {
        insert_helper(root, nullptr, key, value);
    }

    // Returns the minimum key in the BST
    KeyType min_key() {
        TreeNode<KeyType, ValueType>* node = min_node(root);
        if (node == nullptr) throw std::runtime_error("Tree is empty");
        return node->key;
    }
// Returns the maximum key in the BST
    KeyType max_key() {
        TreeNode<KeyType, ValueType>* node = max_node(root);
        if (node == nullptr) throw std::runtime_error("Tree is empty");
        return node->key;
    }
// Searches the BST for a node with the specified key
    bool search(KeyType key) {
        TreeNode<KeyType, ValueType>* node = find_node(root, key);
        return node != nullptr;
    }
// Prints the BST keys in in-order traversal
    void print_inorder() {
        inorder(root);
        std::cout << "\n";
    }
// Prints the BST keys in post-order traversal
    void print_postorder() {
        postorder(root);
        std::cout << "\n";
    }
// Prints the BST keys in pre-order traversal
    void print_preorder() {
        preorder(root);
        std::cout << "\n";
    }

private:
    // Pointer to the root of the BST
    TreeNode<KeyType, ValueType>* root;
// Helper function to deallocate memory used by the BST
    void destroy(TreeNode<KeyType, ValueType>*& node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            node = nullptr;
        }
    }

// Helper function to insert a new node into the BST
    void insert_helper(TreeNode<KeyType, ValueType>*& node, TreeNode<KeyType, ValueType>* parent, KeyType key, ValueType value) {
        if (node == nullptr) {
            node = new TreeNode<KeyType, ValueType>(key, value, parent);
        } else if (key < node->key) {
            insert_helper(node->left, node, key, value);
        } else {
            insert_helper(node->right, node, key, value);
        }
    }

// Helper functions for in-order, post-order and pre-order traversals

    // L,P,R
    void inorder ( TreeNode < KeyType , ValueType >* n ) {
        if (n != nullptr) {
            inorder(n->left);
            std::cout << n->key << ' ';
            inorder(n->right);
        }
    }

    // L R P
    void postorder(TreeNode<KeyType, ValueType>* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->key << ' ';
        }
    }

    // P L R
    void preorder(TreeNode<KeyType, ValueType>* node) {
        if (node != nullptr) {
            std::cout << node->key << ' ';
            preorder(node->left);
            preorder(node->right);
        }
    }
    // Helper function to find the node with the minimum key in the BST
    TreeNode<KeyType, ValueType>* min_node(TreeNode<KeyType, ValueType>* node) const {

        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
// Helper function to find the node with the maximum key in the BST
    TreeNode<KeyType, ValueType>* max_node(TreeNode<KeyType, ValueType>* node) const {
        while (node && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
// Helper function to find a node with a specific key in the BST
    TreeNode<KeyType, ValueType>* find_node(TreeNode<KeyType, ValueType>* node, KeyType key) const {
        if (node == nullptr || node->key == key) {
            return node;
        } else if (key < node->key) {
            return find_node(node->left, key);
        } else {
            return find_node(node->right, key);
        }
    }
};

#endif // BINARYSEARCHTREE_HPP