#include <iostream>
#include <string>
#include <limits>  // Pour gérer les erreurs d'entrée
#include <iomanip> // Pour la manipulation des nombres
using namespace std;

const int NB_CARBURANTS = 3;
const string NOM_CARBURANTS[NB_CARBURANTS] = {"E10", "SP98", "Gasoil"};
const float PRIX_CARBURANTS[NB_CARBURANTS] = {1.40, 2.10, 1.80};
float STOCK_CARBURANTS[NB_CARBURANTS] = {500.0, 700.0, 1000.0};
const float LITRES_MAX[NB_CARBURANTS] = {50.0, 50.0, 100.0};

// Fonction pour afficher le menu
void afficherMenu() {
    cout << "=== Pompe à essence ===" << endl;
    cout << "1. E10" << endl;
    cout << "2. SP98" << endl;
    cout << "3. Gasoil" << endl;
    cout << "4. Quitter" << endl;
}

// Fonction pour demander et vérifier le choix du carburant
int choisirCarburant() {
    int choix;
    while (true) {
        cout << "Votre choix : ";
        cin >> choix;

        // Vérifie si l'entrée est un nombre valide et dans les limites acceptées
        if (cin.fail() || choix < 1 || choix > 4) {
            cin.clear();  // Nettoie le flag d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore les mauvaises entrées
            cout << "Entrée invalide. Veuillez entrer un nombre entre 1 et 4." << endl;
        } else {
            return choix;  // Retourne le choix valide
        }
    }
}

// Fonction pour afficher les informations du carburant choisi
void afficherInfoCarburant(int choix) {
    cout << "Prix au litre de " << NOM_CARBURANTS[choix-1] << " : " << fixed << setprecision(2) << PRIX_CARBURANTS[choix-1] << "€" << endl;
}

// Fonction pour vérifier la disponibilité du stock
float verifierStock(int choix) {
    float litres;
    while (true) {
        cout << "Combien de litres de " << NOM_CARBURANTS[choix-1] << " souhaitez-vous ? ";
        cin >> litres;

        // Vérifie si l'entrée est un nombre valide et s'il y a assez de stock
        if (cin.fail() || litres <= 0) {
            cin.clear();  // Nettoie le flag d'erreur
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore les mauvaises entrées
            cout << "Veuillez entrer un nombre de litres valide." << endl;
        } else if (litres > STOCK_CARBURANTS[choix-1]) {
            cout << "Désolé, il ne reste que " << STOCK_CARBURANTS[choix-1] << " litres de " << NOM_CARBURANTS[choix-1] << "." << endl;
        } else {
            return litres;  // Retourne le nombre de litres valide
        }
    }
}

// Fonction pour calculer le montant à payer
float calculerMontant(float litres, float prix) {
    return litres * prix;
}

// Fonction pour afficher le stock restant
void afficherStock(int choix, float litres_max) {
    cout << "Il reste " << STOCK_CARBURANTS[choix-1] << " litres de " << NOM_CARBURANTS[choix-1] << " dans le stock." << endl;
    if (STOCK_CARBURANTS[choix-1] < litres_max) {
        cout << "Attention, le stock de " << NOM_CARBURANTS[choix-1] << " est faible. Veuillez le remplir dès que possible." << endl;
    }
}

int main() {
    int choixCarburant;
    float litresCarburant;
    float prixCarburant;
    float montant;

    while (true) {
        afficherMenu();
        choixCarburant = choisirCarburant();

        if (choixCarburant == 4) {
            cout << "Au revoir, à bientôt !" << endl;
            break;
        }

        afficherInfoCarburant(choixCarburant);
        litresCarburant = verifierStock(choixCarburant);
        prixCarburant = PRIX_CARBURANTS[choixCarburant-1];
        montant = calculerMontant(litresCarburant, prixCarburant);

        cout << "Vous devez payer : " << fixed << setprecision(2) << montant << "€" << endl;
        STOCK_CARBURANTS[choixCarburant-1] -= litresCarburant;

        cout << "Merci de votre achat." << endl;
        afficherStock(choixCarburant, LITRES_MAX[choixCarburant-1]);
    }

    return 0;
}
