#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Przypadki specjalne - F0 = 1, F1 = 1
    if (N == 0 || N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // Zaczynamy od F0 = 1, F1 = 1
    long long poprzedni = 1;  // F(i-2)
    long long obecny = 1;     // F(i-1)
    
    // Liczymy F2, F3, F4, ..., FN
    for (int i = 2; i <= N; i++) {
        long long nowy = poprzedni + obecny;  // F(i) = F(i-1) + F(i-2)
        poprzedni = obecny;                   // Przesuwamy okno
        obecny = nowy;                        // Teraz obecny = F(i)
    }
    
    cout << obecny << endl;
    return 0;
}
