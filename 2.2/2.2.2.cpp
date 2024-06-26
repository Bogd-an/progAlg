/*
Завдання 2. Лінійний пошук:
У заданому масиві необхідно знайти значення елемента, що дорівнює значенню Х. X вводиться із
клавіатури. Додайте умову до програми, щоб виконати завдання. Нумерація елементів
починається із нуля.
*/

#include<iostream>
using namespace std;

int main() {
    const int Nmax = 1000;
    int A[Nmax], i, N, X;
    cin >> X >> N;
    for (i = 0; i < N; i++) cin >> A[i];
    i = 0;
    // запишіть правильну умову
    while (i < N && A[i] != X) i++;
    cout << X << " index " << (i < N ? to_string(i) : "not found");
    return 0;
}
