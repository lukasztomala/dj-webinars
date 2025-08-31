# Zadanie: Liczby Fibonacciego 🐰

## Co to jest zadanie?

Wyobraź sobie, że masz króliki! 🐰🐰

**Ciąg Fibonacciego** to taka magiczna kolejka liczb:
- Na początku mamy **1** królika i jeszcze **1** królika = 2 króliki
- Kolejne liczby to: **1, 1, 2, 3, 5, 8, 13, 21...**
- Każda nowa liczba to suma dwóch poprzednich!

**Przykład:**
- F₀ = 1 (pierwszy królik)
- F₁ = 1 (drugi królik)  
- F₂ = 1 + 1 = 2 (razem mamy 2 króliki)
- F₃ = 1 + 2 = 3 (teraz mamy 3 króliki)
- F₄ = 2 + 3 = 5 (już 5 królików!)

**Zadanie:** Podaj mi numer N, a ja powiem Ci, jaka jest N-ta liczba Fibonacciego!

---

## ROZWIĄZANIE 1: Proste jak drut! ⚡
**(Dla N ≤ 30 - 50 punktów)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Przypadki specjalne - jak mamy 0 lub 1 królika
    if (N == 0 || N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // Obliczamy krok po kroku
    int poprzedni = 1;      // F₀ = 1
    int obecny = 1;         // F₁ = 1
    
    // Liczymy kolejne liczby Fibonacciego
    for (int i = 2; i <= N; i++) {
        int nowy = poprzedni + obecny;  // Dodajemy dwa poprzednie
        poprzedni = obecny;             // Przesuwamy liczby
        obecny = nowy;                  // Nowa liczba staje się obecną
    }
    
    cout << obecny << endl;
    return 0;
}
```

### 🧒 Jak to działa (dla 10-latka):
1. **Wczytujemy N** - jaka liczba Fibonacciego nas interesuje
2. **Sprawdzamy przypadki specjalne** - jeśli N=0 lub N=1, odpowiedź to 1
3. **Zaczynamy od początku**: poprzedni=1, obecny=1
4. **Liczymy w pętli**: 
   - Dodajemy poprzedni + obecny = nowy
   - Przesuwamy liczby: poprzedni staje się obecny, a obecny staje się nowy
5. **Wypisujemy wynik!**

**Przykład dla N=4:**
- Start: poprzedni=1, obecny=1
- i=2: nowy=1+1=2, teraz: poprzedni=1, obecny=2  
- i=3: nowy=1+2=3, teraz: poprzedni=2, obecny=3
- i=4: nowy=2+3=5, teraz: poprzedni=3, obecny=5
- **Odpowiedź: 5** ✅

---

## ROZWIĄZANIE 2: Rekurencja (ale powolna!) 🐌
**(Tylko dla bardzo małych N - może nie zda wszystkich testów)**

```cpp
#include <iostream>
using namespace std;

// Funkcja, która sama siebie wywołuje!
long long fibonacci(int n) {
    // Przypadki bazowe - tutaj się zatrzymujemy
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Wywołujemy funkcję dla mniejszych liczb
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int N;
    cin >> N;
    
    cout << fibonacci(N) << endl;
    return 0;
}
```

### 🧒 Jak to działa:
1. **Tworzymy funkcję fibonacci()** - ona sama siebie wywołuje!
2. **Jeśli N=0 lub N=1**, zwracamy 1 (koniec!)
3. **W przeciwnym razie**: wywołujemy funkcję dla (N-1) i (N-2), dodajemy wyniki
4. **To jest jak drzewo** - funkcja rozgałęzia się na mniejsze problemy

**Problem:** To rozwiązanie jest **BARDZO WOLNE** dla dużych N, bo liczy te same liczby wielokrotnie!

---

## ROZWIĄZANIE 3: Rekurencja z pamięcią! 🧠
**(Dla N ≤ 45 - 70 punktów)**

```cpp
#include <iostream>
using namespace std;

long long memo[81]; // Tablica do zapamiętywania wyników

long long fibonacci(int n) {
    // Jeśli już liczyliśmy, po co liczyć ponownie?
    if (memo[n] != 0) {
        return memo[n];
    }
    
    // Przypadki bazowe
    if (n == 0 || n == 1) {
        memo[n] = 1;
        return 1;
    }
    
    // Liczymy i zapamiętujemy wynik
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}

int main() {
    int N;
    cin >> N;
    
    // Zerujemy tablicę pamięci
    for (int i = 0; i <= 80; i++) {
        memo[i] = 0;
    }
    
    cout << fibonacci(N) << endl;
    return 0;
}
```

### 🧒 Jak to działa:
1. **Mamy tablicę memo[]** - to nasza pamięć!
2. **Przed liczeniem** sprawdzamy: "Czy już to liczyłem?"
3. **Jeśli tak** - po co liczyć ponownie? Bierzemy z pamięci!
4. **Jeśli nie** - liczymy i zapisujemy w pamięci
5. **To jest o wiele szybsze!** 🚀

---

## ROZWIĄZANIE 4: Super szybkie z dużymi liczbami! 🏆
**(Dla N ≤ 80 - 100 punktów)**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Funkcja do dodawania bardzo dużych liczb (jako stringi)
string dodaj(string a, string b) {
    string wynik = "";
    int przeniesienie = 0;
    
    // Dodajemy od końca (jak w szkole!)
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || przeniesienie > 0) {
        int suma = przeniesienie;
        
        if (i >= 0) {
            suma += (a[i] - '0');  // Zamieniamy znak na liczbę
            i--;
        }
        
        if (j >= 0) {
            suma += (b[j] - '0');
            j--;
        }
        
        wynik = char(suma % 10 + '0') + wynik;  // Dodajemy cyfrę na początek
        przeniesienie = suma / 10;              // Przeniesienie na następną pozycję
    }
    
    return wynik;
}

int main() {
    int N;
    cin >> N;
    
    if (N == 0 || N == 1) {
        cout << "1" << endl;
        return 0;
    }
    
    string poprzedni = "1";  // F₀ = 1
    string obecny = "1";     // F₁ = 1
    
    // Liczymy jak w rozwiązaniu 1, ale z bardzo dużymi liczbami!
    for (int i = 2; i <= N; i++) {
        string nowy = dodaj(poprzedni, obecny);
        poprzedni = obecny;
        obecny = nowy;
    }
    
    cout << obecny << endl;
    return 0;
}
```

### 🧒 Jak to działa:
1. **Problem:** Dla dużych N liczby Fibonacciego są OGROMNE (miliardy cyfr!)
2. **Rozwiązanie:** Traktujemy liczby jako teksty (stringi)
3. **Funkcja dodaj():** Dodaje dwie duże liczby jak w szkole - cyfra po cyfrze
4. **Przeniesienie:** Jeśli 7+8=15, to zapisujemy 5 i przenosimy 1
5. **To może obsłużyć nawet F₈₀!** 🎉

---

## ROZWIĄZANIE 5: Najszybsze - iteracyjne z long long! ⚡
**(Dla N ≤ 45 - idealne dla większości testów)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if (N == 0 || N == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    long long poprzedni = 1;  // Używamy long long - większe liczby!
    long long obecny = 1;
    
    for (int i = 2; i <= N; i++) {
        long long nowy = poprzedni + obecny;
        poprzedni = obecny;
        obecny = nowy;
    }
    
    cout << obecny << endl;
    return 0;
}
```

### 🧒 Dlaczego to najlepsze:
1. **Super szybkie** - tylko jedna pętla
2. **long long** obsługuje większe liczby niż int
3. **Proste do zrozumienia**
4. **Mało pamięci** - tylko 3 zmienne
5. **Działa dla N ≤ 45** (70 punktów!)

---

## 🎯 Które rozwiązanie wybrać?

| N (zakres) | Rozwiązanie | Punkty | Dlaczego? |
|------------|-------------|---------|-----------|
| **N ≤ 30** | Rozwiązanie 1 lub 5 | 50 | Proste i szybkie |
| **N ≤ 45** | Rozwiązanie 5 | 70 | `long long` wystarczy |
| **N ≤ 80** | Rozwiązanie 4 | 100 | Duże liczby jako stringi |

## 🏆 Moja rekomendacja dla Ciebie:

**Zacznij od Rozwiązania 5** - jest proste, szybkie i da Ci 70 punktów!

Gdy opanujesz podstawy, spróbuj Rozwiązania 4 z dużymi liczbami - to da Ci pełne 100 punktów! 🎉

**Pamiętaj:**
- Zawsze testuj na przykładzie: N=4 → wynik=5
- Zwracaj uwagę na przypadki brzegowe (N=0, N=1)
- Im prostsze rozwiązanie, tym mniej błędów! 😊
