// Завдання 4. Зчитати введене користувачем слово, переставити літери в слові в
// зворотному порядку використовуючи стек. Результат вивести в консоль.
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> charStack;
    string userWord;

    cout << "Введіть слово: ";
    cin >> userWord;
    for (char c : userWord) charStack.push(c);

    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
    
    return 0;
}
