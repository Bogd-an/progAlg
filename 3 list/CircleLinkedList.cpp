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
    CircularLinkedList circularLinkedList;

    // Додавання елементів у зв'язний список
    for(int i=5; i>0; i--) circularLinkedList.insertNode(i);

    const int dataNodeNext3 = circularLinkedList.searchNode(3)->next->data;
    cout << "Next Node 3 Node " << dataNodeNext3  << endl;

    circularLinkedList.printList();
    circularLinkedList.deleteNode(1);
    circularLinkedList.deleteNode(5);
    circularLinkedList.deleteNode(10);
    circularLinkedList.printList();

    return 0;
}

/* Результат
1 2 3 4 5
2 3 4
*/