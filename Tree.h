#pragma once
#include <iostream>
#include <queue>

// Définition du nœud
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val)
        : value(val), left(nullptr), right(nullptr) {
    }
};

// Classe Tree
class Tree {
private:
    Node* root;

    // Méthodes privées
    Node* insert(Node* root, int val);
    Node* remove(Node* root, int val);
    bool find(Node* root, int val) const;
    void print_prefixe(Node* root) const;
    void print_infixe(Node* root) const;
    void print_postfixe(Node* root) const;
    void printTreeForm(Node* root, int space, int indent) const;
    // Méthode pour trouver le minimum d'un sous-arbre
    Node* findMin(Node* root);

public:
    // Constructeur
    Tree();

    // Méthodes publiques
    void insert(int val); // Surcharge de insert
    void pop(int val);    // Suppression d'une valeur
    bool find(int val) const;
    bool isEmpty() const;
    void print_prefixe() const;
    void print_infixe() const;
    void print_postfixe() const;
    void print_largeur() const;
    void printTreeForm() const;
};
