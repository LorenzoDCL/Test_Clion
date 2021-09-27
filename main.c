#include <stdio.h>

#define AGE_TARIF_ENFANT 12
#define AGE_TARIF_JEUNE 17
#define AGE_TARIF_ETUDIANT 27
#define AGE_TARIF_SENIOR 65
#define TARIF_ENFANT 4
#define TARIF_JEUNE_SENIOR 6
#define TARIF_PLEIN 9

// Exercice 1 : Comparaison d'entier
void exercice1(){
    int entier1 = 0, entier2 = 0;
    printf("Entrez une valeur pour le premier entier :\n>");
    scanf("%d", &entier1);
    printf("Entrez une valeur pour le deuxieme entier :\n>");
    scanf("%d", &entier2);
    if (entier1>entier2){
        printf("Le premier entier (%i) est plus grand que le deuxieme (%i).\n", entier1, entier2);
    } else if (entier1<entier2) {
        printf("Le premier entier (%i) est plus petit que le deuxieme (%i).\n", entier1, entier2);
    } else {
        printf("Les deux entiers sont égaux\n");
    }
}

// Exercice 2 : Calcul d'aire et de perimètre
void exercice2(){
    int longueur = 0, largeur = 0;
    printf("Entrer la longueur du rectangle :\n>");
    scanf("%d", &longueur);
    printf("Entrer la largeur du rectangle :\n>");
    scanf("%d", &largeur);
    printf("Un rectangle de longueur %d et de largeur %d a un perimetre de %d et une aire de %d\n",
           largeur, longueur, 2*largeur+2*longueur, largeur*longueur);
}

// Exercice 3 : Test sur entier
void exercice3(){
    int valeur = 0;
    const int trois = 3;

    //Si on essaye de changer la valeur de trois :
    //trois = 4;
    //on obtient "error: assignment of read-only variable 'trois'"

    printf("Entrer une valeur entiere :\n>");
    scanf("%d", &valeur);
    if(valeur%trois == 0){ //Test de la divisibilité par 3
        printf("%d est divisible par 3,", valeur);
    } else {
        printf("%d n'est pas divisible par 3,", valeur);
    }
    if(valeur>=10){ //Test de la valeur compaée à 10
        printf(" et est superieur ou egal a 10.");
    } else {
        printf(" et est strictement inferieur a 10.");
    }
}

// Exercice 4 : Tarif cinéma
void exercice4(){
    //Declaration/Initialisation des variables
    int ageClient = 0, estEtudiant = -1, tarif = 0;

    //On demande son age a l'utilisateur
    printf("Quel age avez-vous ?\n>");
    do{
        scanf("%d", &ageClient);
        if(ageClient<0) printf("Veuillez entrer un nombre entier positif.\n>");
    }while(ageClient<0);

    //On verifie si on a besoin de lui demander son statut étudiant
    if (ageClient<=AGE_TARIF_ETUDIANT && ageClient>AGE_TARIF_JEUNE){
        printf("Etes-vous etudiant ? (0 pour non/1 pour oui)\n>");
        do{
            scanf("%d", &estEtudiant);
            if(estEtudiant!=0 && estEtudiant!=1) printf("Veuillez entrer 0 ou 1.\n>");
        }while(estEtudiant!=0 && estEtudiant!=1);
    } else {
        estEtudiant = 0;
    }

    // Deduction du tarif
    if (ageClient<AGE_TARIF_ENFANT){
        tarif = TARIF_ENFANT;
    } else if ((ageClient>=AGE_TARIF_ENFANT && ageClient<=AGE_TARIF_JEUNE) || (ageClient<=AGE_TARIF_ETUDIANT && estEtudiant==1) || (ageClient>=AGE_TARIF_SENIOR)){
        tarif = TARIF_JEUNE_SENIOR;
    } else {
        tarif = TARIF_PLEIN;
    }
    printf("Votre billet coute %d euros.\n", tarif);
}

//Exercice 5 : Distributeur de boissons
void exercice5(){
    int choixClient = 0;

    //Affichage des choix possibles
    printf("Quelle boisson voulez-vous ? \n"
           "1 : The glace\n"
           "2 : Eau\n"
           "3 : TGV\n"
           "10 : Chocolat chaud\n"
           "11 : Irish Cofee\n>");

    //Attente de l'entrée utilisateur et vérification de la validité de la donnée
    do{
        scanf("%d", &choixClient);
        if(choixClient !=1 && choixClient !=2 && choixClient !=3 && choixClient !=11 && choixClient !=12) printf("Veuillez entrer un numero valide !\n");
    }while(choixClient !=1 && choixClient !=2 && choixClient !=3 && choixClient !=11 && choixClient !=12);

    //Affichage du choix au client
    switch (choixClient) {
        case 1 :
            printf("Vous avez choisi le the glace\n");
            break;
        case 2 :
            printf("Vous avez choisi de boire de l'eau, merci Sam\n");
            break;
        case 3 :
            printf("Vous avez choisi le TGV, let's go\n");
            break;
        case 10:
            printf("Vous avez choisi le chocolat chaud\n");
            break;
        case 11 :
            printf("Vous avez choisi l'irish cofee\n");
            break;
        default:
            break;
    }
}

//Exercice 6 : Saisie des notes
void exercice6(){
    //Initialisaiton des variables
    float note1 = 0, note2 = 0, note3 = 0;

    //Saisie des notes
    printf("Veuillez entrer la premiere note : \n>");
    scanf("%f", &note1);
    while (note1 < 0 || note1 >20) {
        printf("la note doit être comprise entre 0 et 20 !\n");
        scanf("%f", &note1);
    }
    printf("Veuillez entrer la deuxième note : \n>");
    scanf("%f", &note2);
    while (note2 < 0 || note2 >20) {
        printf("la note doit être comprise entre 0 et 20 !\n");
        scanf("%f", &note2);
    }
    printf("Veuillez entrer la troisieme note : \n>");
    scanf("%f", &note3);
    while (note3 < 0 || note3 >20) {
        printf("la note doit être comprise entre 0 et 20 !\n");
        scanf("%f", &note3);
    }

    //Affichage de la moyenne
    printf("la moyenne des notes est de %2.2f\n", (note1 + note2 + note3)/3);
}

//Exercice 7 : Classes d'école
void exercice7(){
    int nbClasses = 0, nbElevesClasse = 0, nbElevesTotal = 0, i = 0;

    printf("Combien y a-t-il de classes ?\n>");
    scanf("%i", &nbClasses);

    for (i = 1; i<=nbClasses; i++){
        printf("Combien y a-t-il d'eleves dans la classe %i?\n>", i);
        scanf("%i", &nbElevesClasse);
        nbElevesTotal += nbElevesClasse;
    }
    printf("Il y a %i eleves au total dans l'ecole.\n", nbElevesTotal);
}

//Exercice 8 : Multiple de 7 ET 2
void exercice8(){
    int nombreATester = 0;
    printf("Veuillez sasir un entier : \n>");
    scanf("%i", &nombreATester);
    while ( (nombreATester%2 != 0) || (nombreATester%7 !=0)){
        printf("Reessayez !\n");
        scanf("%i", &nombreATester);
    }
}

//Exercice 9 : Construction de pyramide
void exercice9(){
    int nbPierres = 0, etageMax = 0, i = 0;

    printf("Combien de pierres avez-vous ?\n>");
    scanf("%i", &nbPierres);

    while (nbPierres > 0){ //On s'arrête quand toutes les pierres ont été utilisées
        i += 1;
        nbPierres -= i * i;
        if(nbPierres >=0) etageMax +=1; //On incrément uniquement si on avait assez de pierre our l'etage entier
    }

    printf("Vous pourrez au maximum construire %i etage(s).", etageMax);
}

//Exercice 10 : Moyenne d'entiers
void exercice10(){
    int somme = 0, nbEntiersSaisi = 0, saisieUtilisateur = 0, error = 0;
    char flush = 0;

    do{
        printf("Veuillez entrer un nombre entier positif pour continuer ou un negatif pour arreter (vous en etes a %i entiers saisis)\n>", nbEntiersSaisi);
        do{
            error = scanf("%i", &saisieUtilisateur);    //On recupere la valeur retournee par scanf
            if (error <= 0) {                           //On verifie ici que la valeur donnee par l'utilisateur est valide (aka un int)
                printf("Veuillez rentrer un nombre !\n>");
                scanf("%c", &flush);                    //Si ce n'etait pas un nombre, c'etait un caractere, on efface le newline
            }
        }while (error <= 0);                            //On refait tant que la data n'est pas valide

        if (saisieUtilisateur >= 0) {
            nbEntiersSaisi += 1;
            somme += saisieUtilisateur;
        }
    }while (saisieUtilisateur >= 0);
    if (nbEntiersSaisi ==0) printf("Vous n'avez rien saisi !\n");
    else printf("La moyenne des %i nombre saisis est %.2f", nbEntiersSaisi, (float)somme/(float)nbEntiersSaisi);
}

int main() {
    //exercice1();
    //exercice2();
    //exercice3();
    //exercice4();
    //exercice5();
    //exercice6();
    //exercice7();
    //exercice8();
    //exercice9();
    //exercice10();
    return 0;
}
