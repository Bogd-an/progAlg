// Використовуючи клас unordered_map, створити хеш-таблицю.
// Заповнити таблицю даними, виконати операції видалення елементів, вставку
// елементів, вивести розмір таблиці.

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> hashTable;

    // Вставка елементів у хеш-таблицю
    hashTable.insert({1, "one"});
    hashTable.insert({2, "two"});
    hashTable.insert({3, "three"});

    // Видалення елемента з ключем 2
    hashTable.erase(2);

    // Вставка нового елемента
    hashTable[4] = "чотири";

    // Виведення розміру таблиці 
    cout << "size: " << hashTable.size() << endl;

    return 0;
}

/* Результат
size: 3
*/