// Створити нульовий масив із b цілочислених елементів, де b = 20+N, N –номер варіанту
// за списком. Та вивести його на екран. Створити хеш-функцію методом середнього квадрата, що
// повертає індекс елемента за формулою h(K) = h(k x k), де k - це значення ключа. Створити
// функцію, яка записує значення до комірки масива з індексом, отриманим за допомогою хеш-
// функції. Занести до масиву наступні числа: {23; 75; 11; 15; 85; 7; 56}. Вивести на екран отриманий
// масив. Після цього до масиву занести наступні елементи 55 та 76. Та знову вивести отриманий
// масив на екран. Перевірити, чи виникає колізія, якщо так, модернізувати програму, використовуючи
// метод ланцюжка.

#include <iostream>
using namespace std;

const int hashTableSize = 20 + 12;

class LinkedList {
private:
  struct Node {
    int data; Node* next;
    Node(int data, Node* next) : data(data), next(next) {}
  };
  Node* head;
public:
  LinkedList() : head(nullptr) {}

  void add(int data) {
    Node* temp = new Node(data, head);
    head = temp;
  }

  void print() {
    Node* temp = head;
    for (; temp; temp = temp->next) 
      cout << temp->data << " "; // вивід значення вузла
  }
};

LinkedList hashTable[hashTableSize];

int hashFunction(int x) {
  return (x * x) % hashTableSize;
}

void add(int value) {
  int hash = hashFunction(value);
  hashTable[hash].add(value);
}

void print() {
  cout << "HashTable";
  for (int i = 0; i < hashTableSize; i++) {
    cout << "[" << i << "]: ";
    hashTable[i].print();
  }
  cout << endl;
}

int main() {
  print(); 
  const int values[] = {23, 75, 11, 15, 85, 7, 56};
  for (int i = 0; i < sizeof(values)/sizeof(int); i++) add(values[i]);
  print(); 
  add(55); add(76); print();
  return 0;
}

/*

*/
