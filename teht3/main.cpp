#include <iostream>
#include <teht3.h>

int main() {
    Chef chef("John");
    chef.makeSalad(20);
    chef.makeSoup(9);

    ItalianChef italianChef("Luigi", 25, 25);
    italianChef.askSecret("pizza");  // salasana oikein
    italianChef.askSecret("wrong");  // salasana väärin

    return 0;
}
