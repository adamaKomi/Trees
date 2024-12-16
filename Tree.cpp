#include "Tree.h"

// construceur
Tree::Tree() : root(nullptr) {}


// inserer une valeur
void Tree::insert(int val) {
    this->root = insert(this->root, val);
}
// inserer une valeur
Node* Tree::insert(Node* root, int val) {
    // si le noeud est null, on crée un noeud et on return
    if (root == nullptr) return new Node(val);
    // si la valeur est inferieur au noeud, on passe a gauche
    if (val <= root->value)
        root->left = insert(root->left, val);
    // si la valeur est superieur au noeud, on passe a droit
    else
        root->right = insert(root->right, val);
    // retourner le noeud
    return root;
}

// supprimer une valeur de l'arbre
void Tree::pop(int val) {
    if (!find(val))// verifier l'existence de la valeur avant la suppression
    {
        std::cout << "Erreur, la valeur \"" << val << "\" n'exite pas dans l'arbre" << std::endl;
        return;
    }
    this->root = remove(this->root, val);
}

// retirer une valeur de l'arbre
Node* Tree::remove(Node* root, int val) {
    // si 
    if (root == nullptr) return nullptr;

    // la valeur est inferieur au noeud
    if (val < root->value) {
        root->left = remove(root->left, val);
    }
    // la valeur est superieur au noeud
    else if (val > root->value) {
        root->right = remove(root->right, val);
    }
    // la valeur est trouvee, on doit le supprimer
    else {
        // Cas 1: Nœud sans enfant
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Cas 2: Nœud avec un seul enfant
        if (root->left == nullptr) {// pas de fils gauche
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {// pas de fils droit
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Cas 3: Nœud avec deux enfants
        Node* temp = findMin(root->right);// chercher l'element le plus a gauche du fils droit
        root->value = temp->value;// remplacer le noeud par l'element le plus a gauche du fils droit
        root->right = remove(root->right, temp->value);// supprimer l'element le plus a gauche du fils droit
    }
    return root;
}


// trouver le minimun d'un arbre
Node* Tree::findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// verifier si un element existe dans un arbre
bool Tree::find(int val) const {
    return find(this->root, val);
}
// verifier si un element existe dans un arbre
bool Tree::find(Node* root, int val) const {
    if (root == nullptr) return false;// non trouvé
    if (val == root->value) return true;// element trouvé
    if (val < root->value)
        return find(root->left, val);// chercher a gauche
    return find(root->right, val);// chercher a droite
}


// verifier si l'arbre est vide
bool Tree::isEmpty() const {
    return this->root == nullptr;
}


// afiichage prefixé
void Tree::print_prefixe() const {
    print_prefixe(this->root);
    std::cout << std::endl;
}


//affichage prefixé
void Tree::print_prefixe(Node* root) const {
    if (root == nullptr) return;
    std::cout << root->value << " ";
    print_prefixe(root->left);
    print_prefixe(root->right);
}


//affichage infixé
void Tree::print_infixe() const {
    print_infixe(this->root);
    std::cout << std::endl;
}
//affichage infixé
void Tree::print_infixe(Node* root) const {
    if (root == nullptr) return;
    print_infixe(root->left);
    std::cout << root->value << " ";
    print_infixe(root->right);
}


//affichage postfixé
void Tree::print_postfixe() const {
    print_postfixe(this->root);
    std::cout << std::endl;
}

//affichage postfixé
void Tree::print_postfixe(Node* root) const {
    if (root == nullptr) return;
    print_postfixe(root->left);
    print_postfixe(root->right);
    std::cout << root->value << " ";
}

void Tree::printTreeForm() const
{
    printTreeForm(this->root, 0, 4);
}


void Tree::printTreeForm(Node* root, int space, int indent) const {
    if (root == nullptr) return;

    // Ajoute l'espace pour le niveau actuel
    space += indent;

    // Afficher le fils droit
    printTreeForm(root->right, space, indent);

    // Afficher la valeur du nœud courant avec l'espacement
    std::cout << std::endl;
    for (int i = indent; i < space; i++)
        std::cout << " ";
    std::cout << root->value;

    // Afficher le fils gauche
    printTreeForm(root->left, space, indent);
}
//affichage en largeur
void Tree::print_largeur() const {

    if (isEmpty()) {// l'arbre est vide
        std::cout << "L'arbre est vide.\n";
        return;
    }


    std::queue<Node*> file;// file pour stocker les noeuds
    file.push(this->root);// enfiler la racine

    while (!file.empty()) {// on repète tant que la file n'est pas vide
        Node* current = file.front();// l'element en tête de la file
        file.pop();// supprimer l'element en tête

        std::cout << current->value << " ";// afficher

        if (current->left)// enfiler le fils gauche
            file.push(current->left);
        if (current->right)// enfiler le fils droit
            file.push(current->right);
    }
    std::cout << std::endl;
}

