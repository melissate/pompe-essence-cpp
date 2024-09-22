#include <iostream>
#include <string>
using namespace std;

const int NB_CARBURANTS = 3;
const string NOM_CARBURANTS[NB_CARBURANTS] = {"E10", "SP98", "Gasoil"};
const float PRIX_CARBURANTS[NB_CARBURANTS] = {1.40, 2.10, 1.80};
float STOCK_CARBURANTS[NB_CARBURANTS] = {500.0, 700.0, 1000.0};
const float LITRES_MAX[NB_CARBURANTS] = {50.0, 50.0, 100.0};

void afficherMenu() {
    cout << "=== Pompe à essence ===" << endl;
    cout << "1. E10" << endl;
    cout << "2. SP98" << endl;
    cout << "3. Gasoil" << endl;
    cout << "4. Quitter" << endl;
}

int choisirCarburant() {
    int choix;
    cout << "Votre choix : ";
    cin >> choix;
    while (choix < 1 || choix > 4) {
        cout << "Choix invalide. Veuillez réessayer : ";
        cin >> choix;
    }
    return choix;
}

void afficherInfoCarburant(int choix) {
    cout << "Prix au litre de " << NOM_CARBURANTS[choix-1] << " : " << PRIX_CARBURANTS[choix-1] << "€" << endl;
}

float verifierStock(int choix) {
    float litres;
    do {
        cout << "Combien de litres de " << NOM_CARBURANTS[choix-1] << " souhaitez-vous ? ";
        cin >> litres;
        if (litres > STOCK_CARBURANTS[choix-1]) {
            cout << "Désolé, il ne reste que " << STOCK_CARBURANTS[choix-1] << " litres de " << NOM_CARBURANTS[choix-1] << "." << endl;
        }
    } while (litres > STOCK_CARBURANTS[choix-1]);
    return litres;
}

float calculerMontant(float litres, float prix) {
    return litres * prix;
}

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
        cout << "Vous devez payer : " << montant << "€" << endl;

        STOCK_CARBURANTS[choixCarburant-1] -= litresCarburant;
        cout << "Merci de votre achat." << endl;
        afficherStock(choixCarburant, LITRES_MAX[choixCarburant-1]);
    }

    return 0;
}
