#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Funkcja do dodawania bardzo dużych liczb
string dodaj(string a, string b) {
    string wynik = "";
    int przeniesienie = 0;
    
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || przeniesienie > 0) {
        int suma = przeniesienie;
        
        if (i >= 0) {
            suma += (a[i] - '0');
            i--;
        }
        
        if (j >= 0) {
            suma += (b[j] - '0');
            j--; 
        }
        
        wynik = char(suma % 10 + '0') + wynik;
        przeniesienie = suma / 10;
    }
    
    return wynik;
}

int main() {
    // Obliczamy F(80) krok po kroku
    string poprzedni = "1";  // F(0)
    string obecny = "1";     // F(1) 
    
    cout << "F(0) = " << poprzedni << " (cyfr: " << poprzedni.length() << ")" << endl;
    cout << "F(1) = " << obecny << " (cyfr: " << obecny.length() << ")" << endl;
    
    for (int i = 2; i <= 80; i++) {
        string nowy = dodaj(poprzedni, obecny);
        poprzedni = obecny;
        obecny = nowy;
        
        if (i <= 10 || i % 10 == 0 || i == 80) {
            cout << "F(" << i << ") = " << obecny << " (cyfr: " << obecny.length() << ")" << endl;
        }
    }
    
    // Teoretyczna długość używając wzoru Bineta
    double phi = (1.0 + sqrt(5.0)) / 2.0;  // Złoty podział
    double log_phi = log10(phi);
    double log_sqrt5 = log10(sqrt(5.0));
    
    int theoretical_length = (int)(80 * log_phi - log_sqrt5) + 1;
    cout << "\nTeoretyczna długość F(80): około " << theoretical_length << " cyfr" << endl;
    
    return 0;
}
