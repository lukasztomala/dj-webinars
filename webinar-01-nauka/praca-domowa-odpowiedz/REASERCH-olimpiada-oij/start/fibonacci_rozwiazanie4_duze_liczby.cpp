#include <iostream>
#include <string>
using namespace std;

// Funkcja dodająca dwie bardzo duże liczby reprezentowane jako stringi
string dodaj(string a, string b) {
    string wynik = "";
    int przeniesienie = 0;
    
    // Dodajemy od końca (od najmniej znaczącej cyfry)
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || przeniesienie > 0) {
        int suma = przeniesienie;
        
        // Dodajemy cyfrę z pierwszej liczby (jeśli istnieje)
        if (i >= 0) {
            suma += (a[i] - '0');  // Zamieniamy znak na liczbę
            i--;
        }
        
        // Dodajemy cyfrę z drugiej liczby (jeśli istnieje)
        if (j >= 0) {
            suma += (b[j] - '0');
            j--;
        }
        
        // Zapisujemy ostatnią cyfrę sumy
        wynik = char(suma % 10 + '0') + wynik;
        
        // Przeniesienie to reszta z dzielenia przez 10
        przeniesienie = suma / 10;
    }
    
    return wynik;
}

int main() {
    int N;
    cin >> N;
    
    // Przypadki specjalne
    if (N == 0 || N == 1) {
        cout << "1" << endl;
        return 0;
    }
    
    // Zaczynamy od F0 = "1", F1 = "1"
    string poprzedni = "1";
    string obecny = "1";
    
    // Liczymy F2, F3, ..., FN używając arytmetyki stringów
    for (int i = 2; i <= N; i++) {
        string nowy = dodaj(poprzedni, obecny);
        poprzedni = obecny;
        obecny = nowy;
    }
    
    cout << obecny << endl;
    return 0;
}
