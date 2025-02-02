#ifndef TEHT4_H
#define TEHT4_H

#include <iostream>

using namespace std;

class Pankkitili {
protected:
    double saldo;

public:
    Pankkitili() : saldo(0) {}
    virtual ~Pankkitili() {}

    double getBalance() const {
        return saldo;
    }

    bool deposit(double amount) {
        if (amount > 0) {
            saldo += amount;
            return true;
        }
        return false;
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && saldo >= amount) {
            saldo -= amount;
            return true;
        }
        return false;
    }
};

class Luottotili : public Pankkitili {
private:
    double luottoraja;

public:
    Luottotili(double luottoraja) : luottoraja(luottoraja) {
        saldo = 0; // saldo alkaa 0
    }

    bool withdraw(double amount) override {
        if (amount > 0 && saldo - amount >= -luottoraja) {
            saldo -= amount;
            return true;
        }
        return false;
    }

    bool luotonMaksu(double amount) {
        if (amount > 0 && saldo + amount <= 0) {
            saldo += amount;
            return true;
        }
        return false;
    }
};

class Asiakas {
private:
    Pankkitili* pankkitili;
    Luottotili* luottotili;

public:
    Asiakas(double luottoraja) {
        pankkitili = new Pankkitili();
        luottotili = new Luottotili(luottoraja);
    }

    ~Asiakas() {
        delete pankkitili;
        delete luottotili;
    }

    void showSaldo() {
        cout << "Pankkitilin saldo: " << pankkitili->getBalance() << endl;
        cout << "Luottotilin saldo: " << luottotili->getBalance() << endl;
    }

    bool talletus(double amount) {
        return pankkitili->deposit(amount);
    }

    bool nosto(double amount) {
        return pankkitili->withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili->luotonMaksu(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili->withdraw(amount);
    }

    void tiliSiirto(double amount, Asiakas& vastaanottaja) {
        if (amount <= 0) {
            throw std::invalid_argument("Summa ei voi olla negatiivinen tai nolla");
        }

        if (this->pankkitili->getBalance() < amount) {
            throw std::runtime_error("Tililla ei ole tarpeeksi rahaa");
        }

        if (!this->pankkitili->withdraw(amount)) {
            throw std::runtime_error("Rahansiirto epaonnistui nostossa.");
        }

        if (!vastaanottaja.pankkitili->deposit(amount)) {
            throw std::runtime_error("Rahansiirto epaonnistui talletuksessa.");
        }

        cout << "Siirto onnistui! " << amount << " euroa siirretty.\n";
    }
};

#endif // TEHT4_H
