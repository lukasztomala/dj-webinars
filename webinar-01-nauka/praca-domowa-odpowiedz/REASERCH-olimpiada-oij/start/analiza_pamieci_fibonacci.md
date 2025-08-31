# Analiza użycia pamięci - Rozwiązania Fibonacci 🧠💾
## 📏 Przy założeniu N = 80 (maksymalna wartość)

## ROZWIĄZANIE 1: Proste jak drut! ⚡
**Zużycie pamięci: O(1) - stałe**

```
- int N: 4 bajty
- int poprzedni: 4 bajty  
- int obecny: 4 bajty
- int nowy: 4 bajty (w pętli)
- int i: 4 bajty (licznik pętli)
```

**Łączne zużycie pamięci: ~20 bajtów** (stałe dla N=80)

*Komentarz: Pamięć pozostaje stała niezależnie od wielkości N, ponieważ używamy tylko kilku zmiennych lokalnych.*

---

## ROZWIĄZANIE 2: Rekurencja (ale powolna!) 🐌
**Zużycie pamięci: O(N) - liniowe**

```
- int N: 4 bajty (w main)
- Stos wywołań funkcji: N * (4 bajty + overhead) 
- Każde wywołanie fibonacci(n) zajmuje ~16-32 bajtów na stosie
```

**Łączne zużycie pamięci: ~(16-32) * 80 = 1,280-2,560 bajtów** (dla N=80)

*Komentarz: Pamięć rośnie liniowo z N ze względu na głębokość rekurencji - każde wywołanie funkcji dodaje nową ramkę na stos.*

---

## ROZWIĄZANIE 3: Rekurencja z pamięcią! 🧠
**Zużycie pamięci: O(N) - liniowe**

```
- long long memo[81]: 81 * 8 bajtów = 648 bajtów (tablica globalna)
- int N: 4 bajty
- Stos wywołań funkcji: N * (8 bajty + overhead)
- Każde wywołanie fibonacci(n) zajmuje ~16-32 bajtów na stosie
```

**Łączne zużycie pamięci: ~648 + (16-32) * 80 = 2,208-3,208 bajtów** (dla N=80)

*Komentarz: Pamięć składa się ze stałej tablicy memoizacji plus liniowego zużycia stosu - kompromis między czasem a pamięcią.*

---

## ROZWIĄZANIE 4: Super szybkie z dużymi liczbami! 🏆
**Zużycie pamięci: O(N) - liniowe względem długości wyniku**

```
- int N: 4 bajty
- string poprzedni: ~15 cyfr = 15 bajtów (F(79))
- string obecny: ~17 cyfr = 17 bajtów (F(80))  
- string nowy: ~17 cyfr = 17 bajtów (w pętli)
- int i: 4 bajty (licznik)
- Overhead stringów: ~24 bajty (3 * 8 bajtów na string)
```

**Łączne zużycie pamięci: ~81 bajtów** (dla N=80)

*Komentarz: Pamięć zależy od długości konkretnych liczb Fibonacciego - F(80) ma 17 cyfr, więc stringi zajmują około 17 bajtów każdy plus overhead.*

---

## ROZWIĄZANIE 5: Najszybsze - iteracyjne z long long! ⚡
**Zużycie pamięci: O(1) - stałe**

```
- int N: 4 bajty
- long long poprzedni: 8 bajtów
- long long obecny: 8 bajtów
- long long nowy: 8 bajtów (w pętli)
- int i: 4 bajty (licznik pętli)
```

**Łączne zużycie pamięci: ~32 bajty** (stałe dla N=80)
**⚠️ UWAGA: Przepełnienie dla N>93!** long long ma zakres do ~9*10^18

*Komentarz: Podobnie jak rozwiązanie 1, używa stałej ilości pamięci, ale long long przepełni się dla N=94 (F(94) > 2^63).*

---

## 📊 Podsumowanie porównawcze:

| Rozwiązanie | Złożoność pamięciowa | Rzeczywiste zużycie dla N=80 | Wydajność pamięci |
|-------------|---------------------|------------------------------|-------------------|
| **Rozwiązanie 1** | O(1) | ~20 B | ⭐⭐⭐⭐⭐ Doskonałe |
| **Rozwiązanie 2** | O(N) | ~1,280-2,560 B | ⭐⭐ Słabe |
| **Rozwiązanie 3** | O(N) | ~2,208-3,208 B | ⭐⭐⭐ Średnie |
| **Rozwiązanie 4** | O(log F(N)) | ~81 B | ⭐⭐⭐⭐ Bardzo dobre |
| **Rozwiązanie 5** | O(1) | ~32 B ⚠️ PRZEPEŁNIENIE | ⭐⭐⭐⭐⭐ Doskonałe* |

## 🏆 Wnioski dla N=80:

**Najbardziej efektywne pamięciowo:** 
- **Rozwiązanie 1**: 20 B (ale przepełnienie int dla N>46)
- **Rozwiązanie 5**: 32 B (ale przepełnienie long long dla N>93)

**Najmniej efektywne:** Rozwiązanie 3 (~3,208 B) - memoizacja + stos

**Najlepszy kompromis dla N=80:** Rozwiązanie 4 (~81 B) - jedyne które poprawnie obsługuje N=80!

**⚠️ WAŻNE:** Dla N=80 tylko Rozwiązanie 4 da poprawny wynik bez przepełnienia!

---

## 🔢 Szczegółowe obliczenia dla N=80:

**Testowane wartości:**
- F(80) = 37889062373143906 (17 cyfr)
- F(79) = 23416728348467685 (17 cyfr)
- F(78) = 14472334024676221 (17 cyfr)

**Dlaczego Rozwiązanie 4 jest tak efektywne?**
Stringi w C++ mają optymalizację SSO (Small String Optimization):
- Stringi ≤15-23 znaki często są przechowywane lokalnie bez alokacji
- F(80) ma 17 cyfr, więc może korzystać z tej optymalizacji
- Overhead jest minimalny

**Ograniczenia typów danych:**
- `int`: maksymalnie ~2.1 miliarda ≈ F(46)
- `long long`: maksymalnie ~9.2 * 10^18 ≈ F(93)
- `string`: praktycznie bez ograniczeń

---

*💡 Wskazówka: W zadaniach algorytmicznych zawsze rozważ kompromis między czasem wykonania a zużyciem pamięci!*
