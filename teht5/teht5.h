#ifndef TEHT5_H
#define TEHT5_H
#include <iostream>
#include <string>

class Seuraaja {

public:
    std::string nimi;
    Seuraaja* next;

    Seuraaja(std::string n) : nimi(n), next(nullptr) {}

    void paivitys(const std::string& viesti) {
        std::cout << nimi << " sai viestin: " << viesti << std::endl;
    }

    std::string getNimi() const {
        return nimi;
    }
};

class Notifikaattori {

public:
    Notifikaattori() : alku(nullptr) {}

    void lisaa(const std::string& nimi) {
        Seuraaja* uusi = new Seuraaja(nimi);
        uusi->next = alku;
        alku = uusi;
    }

    void poista(const std::string& nimi) {
        Seuraaja* edeltaja = nullptr;
        Seuraaja* nykyinen = alku;

        while (nykyinen != nullptr && nykyinen->getNimi() != nimi) {
            edeltaja = nykyinen;
            nykyinen = nykyinen->next;
        }

        if (nykyinen == nullptr) {
            std::cout << "Seuraajaa ei loytynyt." << std::endl;
            return;
        }

        if (edeltaja == nullptr) {
            alku = nykyinen->next;
        } else {
            edeltaja->next = nykyinen->next;
        }

        delete nykyinen;
        std::cout << "Seuraaja " << nimi << " poistettu." << std::endl;
    }

    void tulosta() {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            std::cout << nykyinen->getNimi() << std::endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(const std::string& viesti) {
        Seuraaja* nykyinen = alku;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }

private:
    Seuraaja* alku;
};

#endif // TEHT5_H
