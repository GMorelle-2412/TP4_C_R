#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student{
    char nom[500];
    char prenom[500];
    char adresse[500];
    char classe[500];
}eleve[100];


int addStudent(eleve etudent, int actu_student) {
    int nb_total_eleves_enregistres_apres_la_saisie = 0;
    int saisie_return = 0;
   
    if (actu_student == 100) {
        printf("\nVous ne pouvais pas enregistres de nouveau etudient\n");
        return nb_total_eleves_enregistres_apres_la_saisie;
    }

    for (int i = actu_student; i < 100; i++) {
        
        printf("Mettre un nom : ");
        fgets(etudent[i].nom, 500, stdin);
        fgets(etudent[i].nom, 500, stdin);

        printf("\nMettre un Prenom : ");
        fgets(etudent[i].prenom, 500, stdin);

        printf("\nMettre une adresse : ");
        fgets(etudent[i].adresse, 500, stdin);

        printf("\nMettre une classe : ");
        fgets(etudent[i].classe, 500, stdin);

        nb_total_eleves_enregistres_apres_la_saisie++;

        printf("\nVoulais vous coninuer ? (oui = 0 | non = 1) : ");
        scanf ("%d" , &saisie_return);
        printf("\n");

        if (saisie_return == true) return nb_total_eleves_enregistres_apres_la_saisie;
    }
}

void displayStudent(eleve etudent, int actu_student) {

    for (int i = 0; i < actu_student; i++) {
        printf("\n>> %s>> %s>> %s>> %s\n", etudent[i].nom, etudent[i].prenom, etudent[i].adresse, etudent[i].classe);
    }
}

void saveStudent(eleve etudent, FILE *fichier, int actu_student, char *nom_du_fichier, char *chemin_du_fichier) {

    fichier = fopen("toto.txt", "r+");

    for (int i = 0; i < actu_student; i++) {

        fputs(etudent[i].nom, fichier);
        fputs(etudent[i].prenom, fichier);
        fputs(etudent[i].adresse, fichier);
        fputs(etudent[i].classe, fichier);

        fputs("\n", fichier);
    }

    fclose(fichier);
}

int loadStudent(eleve etudent, FILE* fichier, int actu_student) {

    char copicat[500];
    int nouveau = 0;
    int index = 0;
    bool continu = 0;

    fichier = fopen("toto.txt", "r+");

    int n = fread(copicat, 1, 500, fichier);

    copicat[n] = '\0';
    
    while (continu == 0) {

        for (int i = 0; i < n; i++) {
            if (copicat[index] == '\n') {
                etudent[actu_student + nouveau].nom[i] = '\n';
                i++;
                etudent[actu_student + nouveau].nom[i] = '\0';
                index++;
                break;
            }
            else {
                etudent[actu_student + nouveau].nom[i] = copicat[index];
                index++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (copicat[index] == '\n') {
                etudent[actu_student + nouveau].prenom[i] = '\n';
                i++;
                etudent[actu_student + nouveau].prenom[i] = '\0';
                index++;
                break;
            }
            else {
                etudent[actu_student + nouveau].prenom[i] = copicat[index];
                index++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (copicat[index] == '\n') {
                etudent[actu_student + nouveau].adresse[i] = '\n';
                i++;
                etudent[actu_student + nouveau].adresse[i] = '\0';
                index++;
                break;
            }
            else {
                etudent[actu_student + nouveau].adresse[i] = copicat[index];
                index++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (copicat[index] == '\n') {
                etudent[actu_student + nouveau].classe[i] = '\n';
                i++;
                etudent[actu_student + nouveau].classe[i] = '\0';
                index++;
                break;
            }
            else {
                etudent[actu_student + nouveau].classe[i] = copicat[index];
                index++;
            }
        }

        if (copicat[index] == '\n' && copicat[index+1] != '\0') index++;
        else continu = 1;

        nouveau++;
    }

    fclose(fichier);

    printf("\n");

    return nouveau;
}


int main() {
    FILE fichier;

    eleve eleve;

    int actu_student = 0;
    int select = 0;

    char nom_du_fichier[555];
    char chemin_du_fichier[555];

    while (true) {
        printf("| 0 = Fonction addStudent | 1 = Fonction displayStudent | 2 = saveStudent | 3 = loadStudent |\n");
        printf(">>> : ");
        scanf ("%d", &select);

        if (select == 0) actu_student = actu_student + addStudent(eleve, actu_student);
        else if (select == 1) displayStudent(eleve, actu_student);

        else if (select == 2) {
            printf("Donner le nom du fichier que vous voulais envoiler la sauvegade\n");
            printf(">>> : ");
            fgets(nom_du_fichier, 555, stdin);

            printf("Donner le chemin du fichier que vous voulais envoiler la sauvegade\n");
            printf(">>> : ");
            fgets(chemin_du_fichier, 555, stdin);

            saveStudent(eleve, &fichier, actu_student, nom_du_fichier, chemin_du_fichier);
        }

        else if (select == 3) { 
            actu_student = actu_student + loadStudent(eleve, &fichier, actu_student);
        }

        else printf("\nSaisire un valeur corecte\n");
    }

    return 0;
}