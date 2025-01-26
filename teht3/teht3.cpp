#include <iostream>
#include <string>
#include "teht3.h"

Chef::Chef(std::string name) : chefName(name) {
    std::cout << "Chef " << chefName << " created.\n";
}

Chef::~Chef() {
    std::cout << "Chef " << chefName << " destroyed.\n";
}

int Chef::makeSalad(int ingredients) {
    int servings = ingredients / 5;
    std::cout << "Chef " << chefName << " made " << servings << " salad(s).\n";
    return servings;
}

int Chef::makeSoup(int ingredients) {
    int servings = ingredients / 3;
    std::cout << "Chef " << chefName << " made " << servings << " soup(s).\n";
    return servings;
}

ItalianChef::ItalianChef(std::string name, int flour, int water)
    : Chef(name), flour(flour), water(water) {
    std::cout << "ItalianChef " << name << " created with flour: "
              << flour << " and water: " << water << ".\n";
}

ItalianChef::~ItalianChef() {
    std::cout << "ItalianChef destroyed.\n";
}

bool ItalianChef::askSecret(std::string password) {
    if (password == secretPassword) {
        std::cout << "Password correct. Making pizza...\n";
        makePizza();
        return true;
    } else {
        std::cout << "Incorrect password.\n";
        return false;
    }
}

void ItalianChef::makePizza() {
    int pizzas = std::min(flour / 5, water / 5);
    std::cout << "ItalianChef made " << pizzas << " pizza(s).\n";
}
