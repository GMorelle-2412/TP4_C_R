#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct student{
    char nom[500];
    char prenom[500];
    char adresse[500];
    char classe[500];
}eleve[100];


int addStudent(eleve etudent, int actu_student) {
    int nb_total_eleves_enregistres_apres_la_saisie = 0;
    bool saisie_return = 0;
   
    if (actu_student == 100) {
        cout << "\nVous ne pouvais pas enregistres de nouveau etudient\n";
        return nb_total_eleves_enregistres_apres_la_saisie;
    }

    for (int i = actu_student; i < 100; i++) {
        
        cout << "Mettre un nom : ";
        cin.ignore();
        fgets(etudent[i].nom, 500, stdin);

        cout << "\nMettre un Prenom : ";
        fgets(etudent[i].prenom, 500, stdin);

        cout << "\nMettre une adresse : ";
        fgets(etudent[i].adresse, 500, stdin);

        cout << "\nMettre une classe : ";
        fgets(etudent[i].classe, 500, stdin);

        nb_total_eleves_enregistres_apres_la_saisie++;

        cout << "\nVoulais vous coninuer ? (oui = 0 | non = 1) : ";
        cin >> saisie_return;

        if (saisie_return == 1) return nb_total_eleves_enregistres_apres_la_saisie;
    }
}

void displayStudent(eleve etudent, int actu_student) {

    for (int i = 0; i < actu_student; i++) {
        cout << "\n" << etudent[i].nom << " | " << etudent[i].prenom << " | " << etudent[i].adresse << " | " << etudent[i].classe << "\n";
    }
}

void saveStudent(eleve etudent, FILE *fichier, int actu_student) {

    fichier = fopen("toto.txt", "r+");

    for (int i = 0; i < actu_student; i++) {

        fputs(etudent[i].nom, fichier);
        fputs(" | ", fichier);
        fputs(etudent[i].prenom, fichier);
        fputs(" | ", fichier);
        fputs(etudent[i].adresse, fichier);
        fputs(" | ", fichier);
        fputs(etudent[i].classe, fichier);
        fputs(" | ", fichier);
        fputs("\n", fichier);
    }

    fclose(fichier);
}

void loadStudent() {

}


int main() {
    FILE fichier;

    student eleve;

    int actu_student = 0;
    int select = 0;

    while (true) {
        cout << "\n| 0 = Fonction addStudent | 1 = Fonction displayStudent | 2 = saveStudent | 3 = loadStudent |\n";
        cout << ">>> : ";
        cin >> select;

        if (select == 0) actu_student = actu_student + addStudent(&eleve, actu_student);
        else if (select == 1) displayStudent(&eleve, actu_student);
        else if (select == 2) saveStudent(&eleve, &fichier, actu_student);
        else if (select == 3) loadStudent();
        else cout << "\nSaisire un valeur corecte\n";
    }

    return 0;
}