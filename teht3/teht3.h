#ifndef TEHT3_H
#define TEHT3_H
#include <string>
#include <iostream>

class Chef {

public:
    Chef(std::string name);
    ~Chef();

    int makeSalad(int ingredients);
    int makeSoup(int ingredients);

private:
    std::string chefName;
};

class ItalianChef : public Chef {

public:
    ItalianChef(std::string name, int flour, int water);
    ~ItalianChef();

    int flour, water;

    bool askSecret(std::string password);

private:
    std::string secretPassword = "pizza";
    void makePizza();
};

#endif // TEHT_3
