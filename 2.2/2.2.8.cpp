/*
Завдання 8. Знайдіть три найбільші різні елементи в масиві:
Дано масив з усіма різними елементами, знайти три найбільші елементи. Очікувана часова
складність – O(n), а додатковий простір – O(1). Вхідні дані обирайте за варіантом з таблиці 1.
Яка часова та просторова складність алгоритму?
варіант 12 arr[] = {17, 85, 3, 5, 2, 97,69}
*/

#include <iostream>
using namespace std;

int main() {
    const int size = 7;
    int arr[7] = {17, 85, 3, 5, 2, 97, 69};

    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    int thirdMax = INT_MIN;

    for (int i = 0; i < size; i++)
        if (arr[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax && arr[i] != firstMax) {
            thirdMax = secondMax;
            secondMax = arr[i];
        } else if (arr[i] > thirdMax && arr[i] != secondMax && arr[i] != firstMax) {
            thirdMax = arr[i];
        }

    cout << "Три найбільших елементи: " << firstMax << ", " << 
            secondMax << ", " << thirdMax << endl;
    return 0;
}
// Три найбільших елементи: 97, 85, 69