// Завдання 3.Реалізуйте програму, яка сортує масив розміром N у порядку
// зростання за допомогою алгоритму сортування вставкою за наступним
// алгоритмом:
// Ітерація від arr[1] до arr[N] по масиву.
// Порівняти поточний елемент (ключ) з його попередником.
// Якщо ключовий елемент менший за свого попередника, порівняйте його з
// попередніми елементами. Перемістіть більші елементи на одну позицію
// вгору, щоб звільнити місце для поміняних елементів.
// Яка часова складність, реалізованого алгоритму? Обґрунтувати

#include <iostream>
using namespace std;

// Функція для сортування масиву за допомогою сортування вставкою
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
// Порівнюємо поточний елемент з його попередником і переміщаємо більші елементи
// на одну позицію вгору, щоб звільнити місце для поміняних елементів
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, n);
  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
