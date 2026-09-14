#include <iostream>

using namespace std;

void echange(int *var1, int *var2) {
    int sauve = *var1;

    *var1 = *var2;
    *var2 = sauve;
}

int main() {
    int var1 = 0;
    int var2 = 0;

    cout << "Saisir la premiere variable : ";
    cin >> var1;

    cout << "Saisir la deuxieme variable : ";
    cin >> var2;

    cout << "\nAvant la modification premiere variable : " << var1 << " deuxieme variable : " << var2 << "\n";

    echange(&var1, &var2);

    cout << "\nApres la modification premiere variable : " << var1 << " deuxieme variable : " << var2 << "\n";

    return 0;
}