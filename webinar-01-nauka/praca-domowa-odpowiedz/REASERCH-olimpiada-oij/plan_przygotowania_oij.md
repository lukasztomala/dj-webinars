# Plan przygotowań do Olimpiady Informatycznej Juniorów (OIJ)

## Informacje podstawowe o OIJ

### Co to jest OIJ?
- Olimpiada naukowa z informatyki dla uczniów szkół podstawowych (klasy 4-8)
- Obecnie trwa XIX edycja (2024/2025)
- Składa się z 3 etapów zawodów

### Etapy olimpiady:
1. **Zawody I stopnia** - etap szkolny/powiatowy
2. **Zawody II stopnia** - etap wojewódzki  
3. **Zawody III stopnia** - etap krajowy (finał)

### Języki programowania dozwolone:
- **C++** (standardy C++20, kompilator G++ 12.2)
- **Python** (wersja 3.11)

## Plan nauki C++ od podstaw

### FAZA 1: Podstawy programowania (2-3 miesiące)

#### Tydzień 1-2: Instalacja środowiska i pierwsze kroki
- [ ] Zainstaluj kompilator G++ (dokładnie wersja 12.2 jak w OIJ)
- [ ] Zainstaluj edytor kodu (VS Code, Code::Blocks lub Dev-C++)
- [ ] Napisz pierwszy program "Hello World"
- [ ] Naucz się kompilować program z linii komend: `g++ -O3 -static program.cpp -std=c++20`

#### Tydzień 3-4: Podstawowe elementy języka
- [ ] Zmienne i typy danych (int, long long, double, char, bool)
- [ ] Operatory arytmetyczne i logiczne
- [ ] Wejście/wyjście (`cin`, `cout`)
- [ ] Komentarze w kodzie

**Przykład programu do napisania:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
```

#### Tydzień 5-6: Instrukcje warunkowe
- [ ] Instrukcja `if`, `else if`, `else`
- [ ] Operator trójargumentowy `? :`
- [ ] Instrukcja `switch`
- [ ] Zadania z warunkami logicznymi

#### Tydzień 7-8: Pętle
- [ ] Pętla `for`
- [ ] Pętla `while` i `do-while`
- [ ] Instrukcje `break` i `continue`
- [ ] Zagnieżdżone pętle

#### Tydzień 9-10: Tablice
- [ ] Tablice jednowymiarowe
- [ ] Tablice dwuwymiarowe
- [ ] Inicjalizacja tablic
- [ ] Przechodzenie przez tablice

#### Tydzień 11-12: Funkcje podstawowe
- [ ] Definicja i wywoływanie funkcji
- [ ] Parametry i wartości zwracane
- [ ] Zasięg zmiennych
- [ ] Funkcje rekurencyjne (podstawy)

### FAZA 2: Algorytmy podstawowe (2-3 miesiące)

#### Tydzień 13-14: Algorytmy sortowania
- [ ] Sortowanie bąbelkowe
- [ ] Sortowanie przez wybieranie
- [ ] Sortowanie przez wstawianie
- [ ] Funkcja `sort()` z biblioteki standardowej

#### Tydzień 15-16: Algorytmy wyszukiwania
- [ ] Wyszukiwanie liniowe
- [ ] Wyszukiwanie binarne
- [ ] Funkcje `lower_bound()` i `upper_bound()`

#### Tydzień 17-18: Algorytmy na liczbach
- [ ] Największy wspólny dzielnik (NWD)
- [ ] Najmniejsza wspólna wielokrotność (NWW)
- [ ] Sprawdzanie czy liczba jest pierwsza
- [ ] Sito Eratostenesa

#### Tydzień 19-20: Algorytmy na napisach
- [ ] Typ `string`
- [ ] Podstawowe operacje na napisach
- [ ] Porównywanie napisów
- [ ] Wyszukiwanie wzorca w tekście

#### Tydzień 21-24: Wprowadzenie do złożoności
- [ ] Pojęcie złożoności czasowej
- [ ] Notacja Big-O
- [ ] Analiza prostych algorytmów

### FAZA 3: Struktury danych i zaawansowane algorytmy (2-3 miesiące)

#### Tydzień 25-26: Biblioteka STL - kontenery
- [ ] `vector` - dynamiczna tablica
- [ ] `set` i `multiset` - zbiory
- [ ] `map` i `multimap` - słowniki
- [ ] `queue` i `stack` - kolejka i stos

#### Tydzień 27-28: Algorytmy grafowe podstawowe
- [ ] Reprezentacja grafu (lista sąsiedztwa)
- [ ] Przeszukiwanie wszerz (BFS)
- [ ] Przeszukiwanie w głąb (DFS)
- [ ] Znajdowanie składowych spójnych

#### Tydzień 29-30: Programowanie dynamiczne - podstawy
- [ ] Pojęcie programowania dynamicznego
- [ ] Ciąg Fibonacciego
- [ ] Problem plecakowy
- [ ] Najdłuższy wspólny podciąg

#### Tydzień 31-32: Algorytmy zachłanne
- [ ] Strategia zachłanna
- [ ] Planowanie zadań
- [ ] Problem wydawania reszty
- [ ] Minimalne drzewo spinające

### FAZA 4: Przygotowanie do olimpiady (2-3 miesiące)

#### Tydzień 33-36: Rozwiązywanie zadań olimpijskich
- [ ] Zadania z I etapu OIJ z poprzednich lat
- [ ] Zadania z II etapu OIJ z poprzednich lat
- [ ] Analiza rozwiązań wzorcowych
- [ ] Optymalizacja algorytmów

#### Tydzień 37-40: Zaawansowane techniki
- [ ] Złożone struktury danych (drzewo przedziałowe)
- [ ] Algorytmy na grafach (Dijkstra, Floyd-Warshall)
- [ ] Zaawansowane programowanie dynamiczne
- [ ] Geometria obliczeniowa (podstawy)

## Praktyczne wskazówki do kodowania na OIJ

### Wymagania techniczne:
- Kod źródłowy: maksymalnie 100 KB
- Kod wykonywalny: maksymalnie 10 MB
- Czas kompilacji: maksymalnie 30 sekund
- Standard: C++20
- Kompilacja: `g++ -O3 -static abc.cpp -std=c++20`

### Dobre praktyki:
- Używaj `std::ios_base::sync_with_stdio(false);` i `std::cin.tie(nullptr);` dla szybszego I/O
- Używaj `\n` zamiast `endl` 
- Kod musi działać na 64-bitowym procesorze
- Zawsze czytaj ze `stdin` i pisz do `stdout`
- Program musi kończyć się kodem wyjścia 0

### Zabronione praktyki:
- Otwieranie plików
- Tworzenie nowych procesów/wątków
- Funkcje sieciowe
- Interakcja z użytkownikiem
- Zewnętrzne biblioteki (poza STL)

## Harmonogram nauki tygodniowej

### Dla ucznia klasy 7 (czas: 8-10 godzin tygodniowo):
- **Poniedziałek, Środa, Piątek**: 2 godziny teorii i kodowania
- **Sobota**: 3 godziny rozwiązywania zadań
- **Niedziela**: 1 godzina powtórki i analizy błędów

### Struktura każdej sesji nauki:
1. **15 min** - powtórka poprzedniego materiału
2. **45 min** - nauka nowego materiału
3. **15 min** - kodowanie przykładów
4. **45 min** - rozwiązywanie zadań praktycznych

## Materiały do nauki

### Polecane książki:
- "Algorytmy i struktury danych" - Piotr Wróblewski
- "C++ dla olimpijczyków" - materiały OI

### Strony internetowe:
- oij.edu.pl - oficjalna strona olimpiady
- sio2.mimuw.edu.pl - system do przesyłania rozwiązań
- szkopul.edu.pl - zadania treningowe

### Platformy do ćwiczeń:
- Codeforces.com - zadania różnych poziomów
- AtCoder.jp - japońska platforma z dobrymi zadaniami
- SPOJ.com - międzynarodowa baza zadań

## Plan przygotowań na ostatnie miesiące

### 3 miesiące przed olimpiadą:
- [ ] Intensywne rozwiązywanie zadań z poprzednich lat
- [ ] Uczestnictwo w zawodach online (Codeforces)
- [ ] Analiza własnych błędów i słabych punktów

### 1 miesiąc przed olimpiadą:
- [ ] Symulacja zawodów (czas, warunki jak na prawdziwej olimpiadzie)
- [ ] Powtórka najważniejszych algorytmów
- [ ] Przygotowanie "ściągawki" z wzorami i algorytmami

### Tydzień przed olimpiadą:
- [ ] Lekkie powtórki bez forsowania
- [ ] Przegląd podstawowych algorytmów
- [ ] Odpoczynek i przygotowanie mentalne

## Wskazówki psychologiczne

### Jak się motywować:
- Ustaw małe, osiągalne cele tygodniowe
- Prowadź dziennik postępów
- Znajdź kolegów/koleżanki również uczących się programowania
- Pamiętaj, że każdy błąd to lekcja

### Jak radzić sobie ze stresem:
- Regularnie ćwicz rozwiązywanie zadań na czas
- Naucz się technik relaksacyjnych
- Zadbaj o odpowiednią ilość snu i aktywność fizyczną
- Nie porównuj się z innymi, skup się na własnym rozwoju

## Podsumowanie kluczowych kroków

1. **Zainstaluj środowisko programistyczne** (G++ 12.2, edytor)
2. **Naucz się podstaw C++** (zmienne, pętle, warunki, tablice)
3. **Opanuj podstawowe algorytmy** (sortowanie, wyszukiwanie)
4. **Poznaj bibliotekę STL** (vector, set, map, queue, stack)
5. **Ucz się na zadaniach olimpijskich** z poprzednich lat
6. **Trenuj regularnie** - minimum 8-10 godzin tygodniowo
7. **Analizuj błędy** i ucz się na nich
8. **Symuluj warunki zawodów** przed olimpiadą

Powodzenia w przygotowaniach do Olimpiady Informatycznej Juniorów! 🚀
