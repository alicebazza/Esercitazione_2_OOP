#include <iostream>
#include "complex_number.hpp"

int main()
{
    ComplexNumber<float> c1(1.0f, 2.0f);  // Un numero complesso: 1 + 2i
    ComplexNumber<float> c2(3.0f, -4.0f); // Un altro numero complesso: 3 - 4i

    // Stampa dei numeri complessi
    std::cout << "Numero complesso c1: " << c1 << std::endl;
    std::cout << "Numero complesso c2: " << c2 << std::endl;
    
    // Somma di due numeri complessi
    ComplexNumber<float> c3 = c1 + c2;
    std::cout << "Somma tra complessi: c3 = (" << c1 << ") + (" << c2 << ") = " << c3 << std::endl;

    // Moltiplicazione di due numeri complessi
    ComplexNumber<float> c4 = c1 * c2;
    std::cout << "Moltiplicazione tra complessi: c4 = (" << c1 << ") * (" << c2 << ") = " << c4 << std::endl;

    // Coniugato di un numero complesso
    ComplexNumber<float> c5 = c1.conjugate();
    std::cout << "Coniugato di " << c1 << " : c5 = "<<  c5 << std::endl;
    
    // Somma di un numero complesso e uno reale
    float f1 = 7.0;
    ComplexNumber<float> c6 = c1 + f1;
    std::cout << "Somma con un reale: c6 = (" << c1 << ") + " << f1 << " = " << c6 << std::endl;
    
    // Moltiplicazione di un numero complesso e uno reale
    ComplexNumber<float> c7 = c1 * f1;
    std::cout << "Moltiplicazione con un reale: c7 = (" << c1 << ") * " << f1 << " = " << c7 << std::endl;
    
    return 0;
}