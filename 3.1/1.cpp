// Завдання 1.Реалізуйте програму за наступним алгоритмом:
// 1. Запитайте у користувача, скільки чисел він хоче відсортувати.
// 2. Створіть масив з цих чисел.
// 3. Реалізуйте алгоритм сортування бульбашкою. Для цього використовуйте
// цикл while, який буде повторюватися, доки масив не буде відсортований. У
// циклі while використовуйте цикл for для проходження по масиву та
// порівняння кожного числа з наступним. Якщо поточне число більше
// наступного, то поміняйте їх місцями.
// 4. Виведіть відсортований масив на екран.

#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Number count: ";
  cin >> n;

  int numbers[n];

  cout << "Enter number:\n";
  for (int i = 0; i < n; ++i) cin >> numbers[i];

  // Алгоритм сортування бульбашкою
  bool swapped;
  do {
    swapped = false;
    for (int i = 0; i < n - 1; ++i) {
      if (numbers[i] > numbers[i + 1]) {
        int temp = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);

  cout << "Sorted array:\n";
  for (int i = 0; i < n; ++i) cout << numbers[i] << " ";
  cout << endl;

  return 0;
}
