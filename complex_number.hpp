#pragma once
#include <iostream>
#include <concepts>

// template che modella i numeri complessi
template <typename T>
requires std::floating point<T>
class ComplexNumber 
{
private:
    T real;  // Parte reale
    T imag;  // Parte immaginaria

public:
    // Costruttore di default (inizializza a 0 + 0i)
    ComplexNumber() : 
        real(0), imag(0)
    {}
     
     // prende come input un solo valore e restituisce un numero complesso
     // imponendo la parte immaginaria = 0
     explicit ComplexNumber (T r) :
          real(r), imag(0)
     {}
     
    // Costruttore con parametri user-defined
    ComplexNumber(T r, T i) :
        real(r), imag(i)
    {}

    // Metodo per ottenere la parte reale
    T getReal(void) const { 
	    return real;
	 }

    // Metodo per ottenere la parte immaginaria
    T getImag(void) const { 
	    return imag; 
	 }

    // Metodo per ottenere il coniugato
    ComplexNumber conjugate(void) const {
        return ComplexNumber(real, -imag);
    }

    // Overload dell'operatore << per stampare il numero complesso
     // Stampa il numero complesso
    void print(void) const {
        std::cout << real;
        if (imag >= 0) {
            std::cout << "+" << imag << "i";
        } else {
            std::cout << imag << "i";
        }
        std::cout << std::endl;
    }
    
    // Overload dell'operatore += (somma del numero complesso)
    ComplexNumber& operator+=(const ComplexNumber& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload dell'operatore + (somma tra due numeri complessi)
    ComplexNumber operator+(const ComplexNumber& other) const {
        ComplexNumber temp = *this;
        temp += other;
        return temp;
    }

    // Overload dell'operatore *= (moltiplicazione del numero complesso)
    ComplexNumber& operator*=(const ComplexNumber& other) {
        T r = real * other.real - imag * other.imag;
        T i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    // Overload dell'operatore * (moltiplicazione tra due numeri complessi)
    ComplexNumber operator*(const ComplexNumber& other) const {
        ComplexNumber temp = *this;
        temp *= other;
        return temp;
    }
}
