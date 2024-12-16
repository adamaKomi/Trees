// Trees.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cctype>
#include "Tree.h"


int main()
{
	srand(time(0));

	Tree* T = new Tree();// instancier l'arbre
	int val;
	
	// inserer des valeurs aleatoires
	for (int i = 0; i < 10; i++)
	{
		T->insert(rand() % 11);
	}

	// Affichage prefixe
	std::cout << "Affichage prefixe : " << std::endl;
	T->print_prefixe();
	std::cout << std::endl;
	// Affichage infixe
	std::cout << "Affichage infixe : " << std::endl;
	T->print_infixe();
	std::cout << std::endl;
	// Affichage postfixe
	std::cout << "Affichage postfixe : " << std::endl;
	T->print_postfixe();
	std::cout << std::endl;
	// Affichage parcourt en largeur
	std::cout << "Affichage parcourt en largeur : " << std::endl;
	T->print_largeur();
	std::cout << std::endl;
	//Affichage sous forme d'arbre
	std::cout << "Affichage sous forme d'arbre : " << std::endl;
	T->printTreeForm();
	std::cout << std::endl;
	//Rechercher une valeur
	std::cout << "Rechercher une valeur : " ;
	std::cin >> val;
	if (T->find(val))
	{
		std::cout <<val<< " existe dans l'arbre " << std::endl;
	}
	else
		std::cout << "Valeur non trouvee " << std::endl;
	std::cout << std::endl;
	//Supprimer une valeur
	std::cout << "Supprimer une valeur : ";
	std::cin >> val;
	T->pop(val);
	//Affichage sous forme d'arbre
	std::cout << std::endl;
	std::cout << "Affichage sous forme d'arbre : " << std::endl;
	T->printTreeForm();

	delete T;
}
