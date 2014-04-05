#include <iostream>
#include <string>

#include "../../entetes/animal.h"

using namespace std;

int main() {
    Animal Moi;
    cout << Moi;

    cout << endl;

    Tigre Diego;
    cout << Diego;

    cout << endl;

    Tigre Helico(105, 654, "Diego", 001);
    cout << Helico;

    cout << endl;

    Basque Pantxica;
    cout << Pantxica;

    cout << endl;

    Basque Xabi(125, 63, 1, 9999999, "Xabi", 2);
    cout << Xabi;

    cout << endl;

    Marmotte Milka;
    cout << Milka;

    cout << endl;

    Marmotte Miam(95, 6544, "Diego", 001);
    cout << Miam;
    return 0;
}
