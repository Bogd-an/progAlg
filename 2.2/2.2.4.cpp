/*
Завдання 4. Лінійний пошук:
У заданому масиві необхідно визначити значення елемента рівного значенню Х, яке вводиться із
клавіатури. Додайте умову до програми, щоб вона виконувала задачу. Нумерація елементів
починається із нуля. Якщо такого елемента немає, програма повинна виводити Not found. Яка
часова та просторова складність алгоритму?
*/
#include<iostream>
using namespace std;

int main() {
    const int Nmax = 1000;
    int A[Nmax], i, N, X;
    cin >> N;
    for (i = 0; i < N; i++) cin >> A[i];
    cin >> X;
    i = 0;
    // додайте правильну умову тут
    while (i < N && A[i] != X) i++;
    // додайте правильну умову тут
    if (i < N)
        cout << "A[" << i << "]=" << X;
    else
        cout << "Not found";
    return 0;
}
/*
N - кількість елементів у масиві
Часова складність цього алгоритму - O(N).
Просторова складність - O(1)
*/