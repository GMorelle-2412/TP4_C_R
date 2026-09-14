#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;


void initialisation(int* tab) {
	
	for (int i = 0; i < 100; i++) {
		tab[i] = rand() % 100;
	}

	for (int j = 0; j < 100 - 1; j++) {

		for (int i = 0; i < 100 - 1 - j; i++) {

			if (tab[i] > tab[i + 1]) {
				int sauve = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = sauve;
			}
		}
	}
}

int recherche_dichotomie(int val_recherche, int* tab) {
	int a = 0;
	int b = 99;
	int m = 0;

	while (a <= b) {
		m = (a + b) / 2;

		if (tab[m] == val_recherche)return m;

		else if (tab[m] < val_recherche)a = m + 1;

		else b = m - 1;
	}

	return -1;
}

void affichage(int return_index, int val_recherche, int* tab) {
	
	cout << "Tableau trie : ";
	for (int i = 0; i < 100; i++) {
		cout << tab[i] << " ";
	}

	cout << "\n\n";

	if (return_index == -1) cout << "La valeur " << val_recherche << " n'a pas ete trouvee dans le tableau.\n";
	
	else cout << "La valeur " << val_recherche << " est presente a l'index " << return_index << ".\n";
}


int main(){
	int tab[100];
	int val_recherche = 0;

	srand((unsigned)time(0));

	initialisation(tab);

	cout << "Quelle valeur voulais-vous recherchez : ";
	cin >> val_recherche;

	int return_index = recherche_dichotomie(val_recherche, tab);

	affichage(return_index, val_recherche, tab);
}
