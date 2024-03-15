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

int main() {

    LinkedList linkedList;
    CircularLinkedList circularLinkedList;
    int dataNodeNext3;

    // Додавання елементів у зв'язний список
    for(int i=5; i>0; i--) linkedList.insertNode(i);

    dataNodeNext3 = linkedList.searchNode(3)->next->data;
    cout << "linkedList node 3 next node - " << dataNodeNext3  << endl;

    linkedList.printList();
    linkedList.deleteNode(1);
    linkedList.deleteNode(5);
    linkedList.deleteNode(10);
    linkedList.printList();

    // Додавання елементів у зв'язний список
    for(int i=5; i>0; i--) circularLinkedList.insertNode(i);

    dataNodeNext3 = circularLinkedList.searchNode(3)->next->data;
    cout << "circularLinkedList node 3 next node - " << dataNodeNext3  << endl;

    circularLinkedList.printList();
    circularLinkedList.deleteNode(1);
    circularLinkedList.deleteNode(5);
    circularLinkedList.deleteNode(10);
    circularLinkedList.printList();
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