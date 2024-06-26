// Завдання 2.Реалізуйте програму за наступним алгоритмом:
// 1. Створіть два масиви, перший розміром 1000 елементів, другий 10000.
// 2. Заповніть їх випадковими величинами в діапазоні від -1000 до 1000.
// 3. Реалізуйте алгоритм сортування бульбашкою.
// 4. Відсортуйте обидва масиви за допомогою алгоритму сортування
// бульбашкою.
// 5. Порівняйте час виконання сортування для двох масивів. Для цього
// використовуйте функцію clock() з бібліотеки ctime, яка повертає кількість
// тактів процесора, що пройшли з моменту запуску програми. Отримані
// значення мають бути виведені в мілісекундах.
// 6. Запишіть результати порівняння часу виконання сортування для двох
// масивів у файл .txt.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; ++i)
    for (int j = 0; j < n - i - 1; ++j) 
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

double bubbleSortWithTimmer(int arr[], int n){
  clock_t startTime = clock();
  bubbleSort(arr, n);
  clock_t endTime = clock();
  return double(endTime - startTime) / CLOCKS_PER_SEC * 1000;
}

int main() {
  const int SIZE_1 = 1000, SIZE_2 = 10000;
  int arr1[SIZE_1], arr2[SIZE_2];
  // Заповнення масивів випадковими числами
  srand(time(nullptr));
  for (int i = 0; i < SIZE_1; ++i)  arr1[i] = rand() % 2001 - 1000;
  for (int i = 0; i < SIZE_2; ++i)  arr2[i] = rand() % 2001 - 1000;
  // Сортування і вимірювання часу для першого масиву
  double elapsedTime1 = bubbleSortWithTimmer(arr1, SIZE_1);
  // Сортування і вимірювання часу для другого масиву
  double elapsedTime2 = bubbleSortWithTimmer(arr2, SIZE_2);
  // Запис результатів у файл
  ofstream outFile("sorting_times.txt");
  if (outFile.is_open()) {
    outFile << "SortTime for " << SIZE_1 << ": " << elapsedTime1 << " ms\n";
    outFile << "SortTime for " << SIZE_2 << ": " << elapsedTime2 << " ms\n";
    outFile.close();
  } else cout << "Failed to open file for writing results.\n";
  cout << "Written to the sorting_times.txt file\n";
  return 0;
}
