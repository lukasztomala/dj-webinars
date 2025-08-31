#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Funkcja do dodawania bardzo dużych liczb (jako stringi)
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
    int N = 80;
    
    if (N == 0 || N == 1) {
        cout << "1" << endl;
        return 0;
    }
    
    string poprzedni = "1";  // F₀ = 1
    string obecny = "1";     // F₁ = 1
    
    for (int i = 2; i <= N; i++) {
        string nowy = dodaj(poprzedni, obecny);
        poprzedni = obecny;
        obecny = nowy;
    }
    
    cout << "F(80) = " << obecny << endl;
    cout << "Liczba cyfr F(80): " << obecny.length() << endl;
    
    // Sprawdźmy też kilka mniejszych wartości dla porównania
    poprzedni = "1";
    obecny = "1";
    
    for (int n = 2; n <= 20; n += 2) {
        for (int i = (n > 2 ? n-1 : 2); i <= n; i++) {
            string nowy = dodaj(poprzedni, obecny);
            poprzedni = obecny;
            obecny = nowy;
        }
        cout << "F(" << n << ") ma " << obecny.length() << " cyfr" << endl;
    }
    
    return 0;
}
