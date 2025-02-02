#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <iostream>

using namespace std;

class Pankkitili {
protected:
    double saldo;

public:
    Pankkitili() : saldo(0) {}
    ~Pankkitili() {}

    bool deposit(double amount) {
        if (amount > 0) {
            saldo += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && saldo >= amount) {
            saldo -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return saldo;
    }
};


#endif // PANKKITILI_H
