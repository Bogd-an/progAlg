/*
Завдання 7. Двійковий пошук:
Реалізуйте алгоритм бінарного пошуку.

Вхідні дані: У першому рядку вхідних даних містяться натуральні числа N та K (0<N,K<=100000).
У другому рядку задаються N елементів першого масиву, відсортованого за зростанням, а
третьому рядку – K елементів другого масиву. Елементи обох масивів - цілі числа, кожне з яких за
модулем не перевищує 109
Вихідні дані: Потрібно для кожного K чисел вивести в окремий рядок "YES", якщо це число
зустрічається в першому масиві, і "NO" в іншому випадку.
Яка часова та просторова складність алгоритму?

Вхідні дані

10 5
1 2 3 4 5 6 7 8 9
10
-2 0 4 9 12

Вихідні дані
NO
NO
YES
YES
NO
*/

#include <iostream>

using namespace std;

string binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if      (arr[mid] == target) return "YES";
        else if (arr[mid] <  target) left = mid + 1;
        else                         right = mid - 1;
    }
    return "NO";
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int firstArray[N];
    int secondArray[K];
    
    for (int i = 0; i < N; i++) cin >> firstArray[i];
    for (int i = 0; i < K; i++) cin >> secondArray[i];
    
    
    for (int i = 1; i < N; ++i) {
        int key = firstArray[i];
        int j = i - 1;
        while (j >= 0 && firstArray[j] > key) {
            firstArray[j + 1] = firstArray[j];
            j = j - 1;
        }
        firstArray[j + 1] = key;
    }
    
    for (int i = 0; i < K; i++)
        cout << binarySearch(firstArray, N, secondArray[i]) << endl;
    return 0;
}
