// Завдання 4. Зчитати введене користувачем слово та посимвольно записати до черги.
// Парні елементи в черзі перевести у верхній регістр, непарні – нижній. Результат
// вивести в консоль.

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> myQueue;
    string inputWord;

    cout << "Введіть слово: ";
    cin >> inputWord;

    for (int i = 0; i <= inputWord.length(); i++)
        myQueue.push(
            (i % 2 != 0) ? toupper(inputWord[i]) : tolower(inputWord[i])
        );

    cout << "Значення в черзі: ";
    while (!myQueue.empty()) {
        cout << myQueue.front();
        myQueue.pop();
    }

    return 0;
}