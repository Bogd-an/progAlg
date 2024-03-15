// Завдання по Зв'язних списках: потрібно реалізувати свою програму, 
// використовуючи зв'язний список та круговий однозв'яний список 
// для таких функцій як формування вузла спису, вставка вузла та 
// видалення, пошук

#include <iostream>

using namespace std;

struct Node { // Структура вузла зв'язного списку
    int data; // дані,  які зберігаються у вузлі
    Node* next; // вказівник на наступний вузол
    // Конструктор структури
    Node(int data, Node* next) : data(data), next(next) {}
};

class LinkedList {
private:
    Node* head; // вказівник на початковий вузол списку
public:
    LinkedList() : head(nullptr) {} // Конструктор класу

    void insertNode(int data) { //в початок
        Node* temp = new Node(data, head);
        head = temp;
    }

    Node* searchNode(int data){
        Node* temp = head;
        do {
            if (temp->data == data) return temp;
            temp = temp->next;
        } while (temp->next);
        return nullptr; // якщо вузол не знайдено
    }

    void deleteNode(int data) {
        Node* temp = head;
        if(head->data == data){ // якщо перший вузол містить data
            head = head->next; 
            delete temp;
            return;
        }
        // ітеруємся до кінця, або поки не знайдемо data
        for (; temp->next; temp = temp->next) 
            if (temp->next->data == data) break;
        if (!temp->next) return ; // якщо вузол не знайдено
        Node* nodeToDelete = temp->next; // зберігаємо вказівник на вузол, який буде видалено
        temp->next = temp->next->next; // прив'язуємо попередній вузол до наступного вузла
        delete nodeToDelete;
    }

    // Метод для виводу всіх вузлів зв'язного списку
    void printList() {
        Node* temp = head;
        for (; temp; temp = temp->next) 
            cout << temp->data << " "; // вивід значення вузла
        cout << endl;
    }
};

class CircularLinkedList {
private:
    Node* head; // вказівник на початковий вузол списку
public:
    CircularLinkedList() : head(nullptr) {} // Конструктор класу

    void insertNode(int data) { //в початок
        if (!head) {
            head = new Node(data, nullptr);
            head->next = head; // встановлюємо посилання на себе для кругового списку
        } else {
            Node* temp = new Node(head->data, head->next);
            head->data = data;
            head->next = temp;
        }
    }

    Node* searchNode(int data){
        if (!head) return nullptr;
        Node* temp = head;
        do {
            if (temp->data == data) return temp;
            temp = temp->next;
        } while (temp != head);
        return nullptr; // якщо вузол не знайдено
    }

    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = head;
        // Шукаємо вузол і його попередник
        for (; prev->next != head; prev = prev->next) 
            if (prev->next->data == data) break;
        temp = prev->next;
        if (temp->data != data) return ; // якщо вузол не знайдено
        // Якщо вузол для видалення не перший
        if (temp != head) {
            prev->next = temp->next;
            delete temp;
            return ;
        }
        // while (temp->next != head) temp = temp->next;
        prev->next = head->next;
        head = prev->next;
    }

    // Метод для виводу всіх вузлів зв'язного списку
    void printList() {
        Node* temp = head;
        for (; temp->next != head; temp = temp->next) 
            cout << temp->data << " "; // вивід значення вузла
        cout << temp->data << endl;
    }
};

#define TEST_LIST(name) \
for(int i=5; i>0; i--) name.insertNode(i);\
    dataNodeNext3 = name.searchNode(3)->next->data;\
    cout << #name << " node 3 next node - " << dataNodeNext3  << endl;\
    name.printList();\
    name.deleteNode(1);\
    name.deleteNode(5);\
    name.deleteNode(10);\
    name.printList();

int main() {

    LinkedList linkedList;
    CircularLinkedList circularLinkedList;
    int dataNodeNext3;

    TEST_LIST(linkedList);
    TEST_LIST(circularLinkedList);

    return 0;
}

/* Результат
linkedList node 3 next node - 4    
1 2 3 4 5 
2 3 4 
circularLinkedList node 3 next node - 4
1 2 3 4 5
2 3 4
*/


// TODO:
/*
Уникайте використання простору імен using namespace std: Використання 
цього оператора може призвести до конфліктів імен, що може бути проблематичним 
у великих проектах. Замість цього краще вказати std:: перед об'єктами стандартної 
бібліотеки, як у вашому випадку.

Використання const:

У методах searchNode та printList ви можете використовувати ключове слово const, 
щоб позначити, що ці методи не змінюють стан об'єкту класу.
Параметр data в методі searchNode також може бути помічений як const, оскільки 
він не має змінюватися.
Перевірка на nullptr: У методі searchNode в кінці циклу ви використовуєте while 
(temp->next), але потім перевіряєте if (!temp->next). Це може призвести до помилки 
сегментації у випадку, якщо temp->next вказує на nullptr. Краще перевіряти на 
nullptr сам вузол temp.

Оптимізація методу вставки в CircularLinkedList: При вставці нового вузла у методі 
insertNode в CircularLinkedList, ви копіюєте дані з першого елементу вузла, а потім 
встановлюєте нові дані в початковий вузол. Це непотрібне копіювання. Простіше просто
встановити нові дані в новий вузол, а потім перемістити посилання на початковий 
вузол.

Зменшення зайвої логіки у методі deleteNode в CircularLinkedList: У методі deleteNode
ви використовуєте зайвий цикл while та перевірку на temp->next != head для того, 
щоб знайти останній елемент у круговому списку перед видаленням. Це може бути 
оптимізовано, оскільки останній елемент можна знайти за допомогою перевірки, чи 
наступний елемент вказує на початковий вузол.

Додавання коментарів до коду: Хоча код написаний досить зрозуміло, додавання 
коментарів 
може допомогти іншим розуміти вашу імплементацію.

Перевірка на наявність пам'яті: Ваш код не перевіряє, чи була успішно виділена 
пам'ять під нові вузли. Це може призвести до витоку пам'яті у випадку, якщо new не 
може виділити пам'ять. Тому слід додати перевірку на nullptr після new.
*/