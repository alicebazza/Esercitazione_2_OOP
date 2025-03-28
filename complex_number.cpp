#include <iostream>
#include <concepts>
#include "complex_number.hpp"

using namespace std;

int main()
{
    ComplexNumber<float> c1(1.0f, 2.0f);  // Un numero complesso: 1 + 2i
    ComplexNumber<float> c2(3.0f, -4.0f); // Un altro numero complesso: 3 - 4i

    // Stampa dei numeri complessi
    cout << "Numero complesso 1: " << c1 << endl;
    cout << "Numero complesso 2: " << c2 << endl;

    // Somma di due numeri complessi
    ComplexNumber<float> c3 = c1 + c2;
    cout << "Somma: " << c3 << endl;

    // Somma usando l'operatore +=
    c1 += c2;
    cout << "Somma usando +=: " << c1 << endl;

    // Moltiplicazione di due numeri complessi
    ComplexNumber<float> c4 = c1 * c2;
    cout << "Moltiplicazione: " << c4 << endl;

    // Moltiplicazione usando l'operatore *=
    c1 *= c2;
    cout << "Moltiplicazione usando *=: " << c1 << endl;

    // Coniugato di un numero complesso
    ComplexNumber<float> c5 = c1.conjugate();
    cout << "Coniugato di c1: " << c5 << endl;

    return 0;
}