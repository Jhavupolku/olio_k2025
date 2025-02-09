#include <iostream>
#include "teht5.h"

using namespace std;

int main() {
    Notifikaattori notif;

    notif.lisaa("A");
    notif.lisaa("B");
    notif.lisaa("C");

    std::cout << "Seuraajat:" << std::endl;
    notif.tulosta();

    std::string viesti = "Ilmoitus numero yksi";
    std::cout << "\nPostitetaan viesti kaikille seuraajille:" << std::endl;
    notif.postita(viesti);

    std::cout << "\nPoistetaan B:" << std::endl;
    notif.poista("B");

    std::string viesti2 = "Ilmoitus numero kaksi";
    std::cout << "\nPostitetaan viesti kaikille seuraajille:" << std::endl;
    notif.postita(viesti2);

    std::cout << "\nJaljella olevat seuraajat:" << std::endl;
    notif.tulosta();

    return 0;
}
