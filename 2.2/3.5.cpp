// Завдання 5*. Напишіть програму, яка читає рядок тексту, змінюючи кожну велику літеру
// на нижній регістр і розміщує кожну літеру як у черзі, так і в стеку. Потім програма
// повинна перевірити, чи є рядок тексту паліндромом (набором літер або цифри, які
// однакові незалежно від того, чи читаються вони вперед чи назад).

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    stack<char> myStack;
    queue<char> myQueue;
    string inputWord;

    cout << "Введіть слово: ";
    cin >> inputWord;

    for (char letter : inputWord) {
        myQueue.push(tolower(letter));
        myStack.push(tolower(letter));
    }
    // for (int i = 0; i < inputWord.length(); i++){
    //     char letter = tolower(inputWord[i]);
    //     myQueue.push(letter);
    //     myStack.push(letter);
    // }

    bool isPalindrom = true;
    while (!myQueue.empty()) {
        if(myStack.top() != myQueue.front()) {
            isPalindrom = false;
            break;
        }
        myStack.pop();
        myQueue.pop();
    }
    cout << "Введений текст паліндром - " 
         <<  (isPalindrom ? "правда" : "брехня");

    return 0;
}