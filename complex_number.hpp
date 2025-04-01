#pragma once

// template che modella i numeri complessi
template <typename T> requires std::floating_point<T>
class ComplexNumber
{
private:
    T real;  // Parte reale
    T imag;  // Parte immaginaria

public:
    // Costruttore di default (inizializza a 0 + 0i)
    ComplexNumber()
        : real(0), imag(0)
    {}
     
     // Costruttore user-defined con un solo input
     // restituisce un numero complesso imponendo la parte immaginaria = 0
     explicit ComplexNumber (T r)
         : real(r), imag(0)
     {
	     std::cout<< "converting constructor called" <<std::endl;
     }
     
    // Costruttore user-defined con due input
    ComplexNumber(T r, T i)
        : real(r), imag(i)
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
    
    // Overload dell'operatore += tra un numero complesso e un numero reale T
    ComplexNumber& operator+=(const T& number) {
	    real += number;
	    return *this;
	 }
	 
	 // Overload dell'operatore + tra un numero complesso e un numero reale T
	 ComplexNumber operator+(const T& number) const {
		 ComplexNumber temp = *this;
		 temp += number;
		 return temp;
	}
	
	// Overload dell'operatore *= tra un numero complesso e un numero reale T
	ComplexNumber& operator*=(const T& number) {
		real *= number;
		imag *= number;
		return *this;
	}
	
	// Overload dell'operatore * tra un numero complesso e un numero reale T
	ComplexNumber operator*(const T& number) const {
		ComplexNumber temp = *this;
		temp *= number;
		return temp;
	}
	
};

// Overload dell'operatore + tra un numero reale T e un numero complesso
template<typename T>
ComplexNumber<T> operator+(const T& number, const ComplexNumber<T>& c) {
    return c + number;
}

// Overload dell'operatore * tra un numero reale T e un numero complesso
template<typename T>
ComplexNumber<T> operator*(const T& number, const ComplexNumber<T>& c) {
    return c * number;
}

// Overload dell'operatore << per stampare il numero complesso
template<typename T>
std::ostream& 
operator<<(std::ostream& os, const ComplexNumber<T>& c) {
    os << c.getReal();
    if (c.getImag() != 0.0) {
        if (c.getImag() == 1.0)
            os << "+i";
        else if (c.getImag() == -1.0)
            os << "-i";
        else if (c.getImag() < 0.0)
            os << c.getImag() << "i";
        else
            os << "+" << c.getImag() << "i";
    }
    return os;
}

