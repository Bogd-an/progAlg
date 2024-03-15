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

int main() {
    LinkedList linkedList;

    // Додавання елементів у зв'язний список
    for(int i=5; i>0; i--) linkedList.insertNode(i);

    const int dataNodeNext3 = linkedList.searchNode(3)->next->data;
    cout << "Next Node 3 Node " << dataNodeNext3  << endl;

    linkedList.printList();
    linkedList.deleteNode(1);
    linkedList.deleteNode(5);
    linkedList.deleteNode(10);
    linkedList.printList();

    return 0;
}

/* Результат
1 2 3 4 5
2 3 4 
*/