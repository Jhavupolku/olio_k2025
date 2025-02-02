#include <iostream>
#include <teht4.h>

using namespace std;

int main() {
    try {
        Asiakas asiakas1(200);
        Asiakas asiakas2(500);

        asiakas1.showSaldo();
        asiakas2.showSaldo();

        asiakas1.talletus(1000);
        asiakas1.showSaldo();

        cout << "\nSiirretaan 300 euroa asiakas1:lta asiakas2:lle...\n";
        asiakas1.tiliSiirto(300, asiakas2);

        asiakas1.showSaldo();
        asiakas2.showSaldo();

        // epaonnistuva siirto
        cout << "\nKokeillaan epaonnistunutta siirtoa...\n";
        asiakas1.tiliSiirto(800, asiakas2);

    } catch (const std::exception& e) {
        cout << "Virhe: " << e.what() << endl;
    }

    return 0;
}
