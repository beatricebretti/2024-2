#include <iostream>
#include "criba.h"

using namespace std;

int main() {
    unsigned long num;
    cout << "Ingrese un número: ";
    cin >> num;

    unsigned long count = criba(num);
    cout << "Cantidad de números primos menores o iguales a " << num << ": " << count << endl;

    return 0;
}