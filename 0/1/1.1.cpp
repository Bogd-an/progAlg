// Завдання1. Сформуватимасив з n елементівта заповнити його за допомогою
// генератора випадкових чисел значеннями в діапазоні[a ... b] (n, a, b обирається з 
// таблиці за варіантом). Роздрукуватиотриманиймасив.
// Виконатиопераціюз отриманиммасивомза варіантом(варіантзавданняв таблиці). 
// Результат вивестина екран

// Варіант a  b   m  n 
// 12      85 800 15 9 
// Операція з отриманим масивом
// Поміняти місцями максимальний і третій елементи.

#include <iostream>
#include <cstdlib>  // для використання rand() та srand()
#include <ctime>    // для використання time()

using namespace std;

const int a = 85;
const int b = 800;
const int m = 15;
const int n = 9;

// Функція для генерації випадкового числа в діапазоні [a, b]
int generateRandomNumber() {
    return rand() % (b - a + 1) + a;
}

void coutArray(int array[]){
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << "]\n";
}

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    // Створення та заповнення масиву
    int array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = generateRandomNumber();
    }

    // Вивід отриманого масиву
    cout << "Отриманий масив = [ ";
    coutArray(array);

    // Знайти індекс максимального елементу
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (array[i] > array[maxIndex]) maxIndex = i;
    }

    // Обмін місцями максимального і третього елементів
    int temp = array[maxIndex];
    array[maxIndex] = array[2];
    array[2] = temp;

    // Вивід масиву після обміну
    cout << "Масив після обміну = [ ";
    coutArray(array);

    return 0;
}

// Приклад
// Отриманий масив = [ 337 528 456 446 694 324 773 371 417 ]
// Масив після обміну = [ 337 528 773 446 694 324 456 371 417 ]