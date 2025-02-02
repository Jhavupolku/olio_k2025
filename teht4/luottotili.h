#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoraja;

public:
    Luottotili(double luottoraja) : luottoraja(luottoraja) {
        saldo = 0; // saldo alkaa 0
    }

    bool withdraw(double amount) {
        if (amount > 0 && saldo - amount >= luottoraja) {
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

#endif // LUOTTOTILI_H
