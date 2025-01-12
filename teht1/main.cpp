#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum){
    srand(time(0));

    int oikeaLuku = rand() % maxnum + 1;
    int arvaus;
    int arvaustenMaara = 0;

    while (true){
        cout << "Arvaa luku (1-" << maxnum << "): ";
        cin >> arvaus;

        arvaustenMaara++;

        if (arvaus < oikeaLuku){
            cout << "Luku on suurempi." << endl;
        } else if (arvaus > oikeaLuku){
            cout << "Luku on pienempi." << endl;
        } else {
            cout << "Oikea vastaus! Luku oli " << oikeaLuku << "." << endl;
            break;
        }
    }

    return arvaustenMaara;
}

int main(){
    int maxnum;
    cout << "Anna suurin mahdollinen luku: ";
    cin >> maxnum;

    int arvaustenMaara = game(maxnum);
    cout << "Pelasit " << arvaustenMaara << " arvausta." << endl;

    return 0;
}
