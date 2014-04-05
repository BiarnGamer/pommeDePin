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

    Tigre Helico(105, 654, "Diego", false, true, true, 001);
    cout << Helico;
    return 0;
}
