#include <iostream>     
#include <iomanip>      
#include <ctime>        
#include <cstdlib>      
#include <windows.h>    

using namespace std;

// ---------- прототипи функцій (i - індекс поточного елемента) ----------
void Create(int* a, const int size, const int Low, const int High, int i);   // формування масиву
void Print(int* a, const int size, int i);                                   // виведення масиву
int IndexOfMax(int* a, const int size, int i, int imax);                              // індекс максимального елемента
int IndexOfMin(int* a, const int size, int i, int imin);                              // індекс мінімального елемента
void SwapElements(int* a, const int i, const int j);                     // обмін місцями двох елементів
bool SwapMaxMin(int* a, const int size);                                 // обмін місцями max та min

int main()
{
    SetConsoleCP(65001);                // кирилиця у консолі (ввід)
    SetConsoleOutputCP(65001);          // кирилиця у консолі (вивід)

    srand((unsigned)time(NULL));        // ініціалізація генератора випадкових чисел

    const int n = 10;                   // кількість елементів масиву
    int a[n];                           // оголосили масив

    int Low = -20;                      // нижня межа діапазону значень
    int High = 50;                      // верхня межа діапазону значень

    Create(a, n, Low, High, 0);        // 1. формуємо масив випадковими числами
    cout << "Початковий масив:" << endl;
    Print(a, n, 0);                    // 2. виводимо його рядком

    if (SwapMaxMin(a, n))               // 3. міняємо місцями max та min; true - масив змінився
    {
        cout << "Змінений масив:" << endl;
        Print(a, n, 0);                // 4. масив змінився - виводимо його
    }
    else
        cout << "Масив не змінився (max і min збігаються)." << endl;

    return 0;
}

// Заповнює масив випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)   // рекурсивний спосіб
{
    a[i] = Low + rand() % (High - Low + 1);         // заповнюємо поточний елемент
    if (i < size - 1)                               // якщо це ще не останній елемент
        Create(a, size, Low, High, i + 1);          // переходимо до наступного
}

// Виводить елементи масиву в один рядок, кожен у полі шириною 4 символи
void Print(int* a, const int size, int i)                                   // рекурсивний спосіб
{
    cout << setw(4) << a[i];                        // виводимо поточний елемент
    if (i < size - 1)                               // якщо це ще не останній елемент
        Print(a, size, i + 1);                      // переходимо до наступного
    else
        cout << endl;                               // після останнього - новий рядок
}

// Повертає індекс (першого) максимального елемента; imax - індекс найбільшого серед переглянутих
int IndexOfMax(int* a, const int size, int i, int imax)                     // рекурсивний спосіб
{
    if (a[i] > a[imax])                             // поточний елемент більший за максимальний
        imax = i;
    if (i < size - 1)                               // якщо це ще не останній елемент
        return IndexOfMax(a, size, i + 1, imax);    // переглядаємо решту масиву
    else
        return imax;                                // кінець масиву - результат пошуку
}

// Повертає індекс (першого) мінімального елемента; imin - індекс найменшого серед переглянутих
int IndexOfMin(int* a, const int size, int i, int imin)                     // рекурсивний спосіб
{
    if (a[i] < a[imin])                             // поточний елемент менший за мінімальний
        imin = i;
    if (i < size - 1)                               // якщо це ще не останній елемент
        return IndexOfMin(a, size, i + 1, imin);    // переглядаємо решту масиву
    else
        return imin;                                // кінець масиву - результат пошуку
}

// Міняє місцями елементи a[i] та a[j]
void SwapElements(int* a, const int i, const int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// Міняє місцями максимальний та мінімальний елементи.
// Повертає true, якщо масив змінився, і false, якщо ні (max і min - це один елемент)
bool SwapMaxMin(int* a, const int size)
{
    int imax = IndexOfMax(a, size, 0, 0);               // індекс максимального елемента
    int imin = IndexOfMin(a, size, 0, 0);               // індекс мінімального елемента

    if (imax == imin)                               // усі елементи однакові (або елемент один)
        return false;                               // міняти нічого - масив не змінився

    SwapElements(a, imax, imin);                    // міняємо місцями
    return true;                                    // масив змінено
}