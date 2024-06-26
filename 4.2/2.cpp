// Завдання 2. Написати програму для створення бінарного дерева, яке буде
// зберігати цілі числа. Програма повинна мати наступні функції:
// 1. Вставка елемента в дерево
// 2. Пошук елемента в дереві
// 3. Видалення елемента з дерева
// 4. Виведення всіх елементів дерева у порядку зростання
// 5. Створити бінарне дерево з числами від 1 до 10 та вивести всі елементи
// дерева у порядку зростання та видалити з дерева елементи з номерами 3 та
// 7. Після цього, вивести всі елементи дерева у порядку зростання знову.


#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct Node {
  int data;  Node* left;  Node* right;
  Node(int data){ this->data = data; left = right = nullptr;}
};
// Функція для вставки елемента в бінарне дерево
void insertNode(Node* &root, int data) {
  if (root == nullptr) {
    root = new Node(data);
    return;
  }
  insertNode((data < root->data)?root->left:root->right,data);
}
// Функція для пошуку елемента в бінарному дереві
bool searchNode(Node* root, int data) {
  if (root == nullptr)    return false;
  if (root->data == data) return true;
  return searchNode((data < root->data)?
                    root->left : root->right, data);
}
// Функція для пошуку найменшого значення в піддереві
Node* minValueNode(Node* node) {
  Node* current = node;
  while (current && current->left != nullptr)
    current = current->left;
  return current;
}
// Функція для видалення елемента з бінарного дерева
Node* deleteNode(Node* root, int data) {
  if (root == nullptr) return root;
  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root; return temp;
    } else if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}
// Функція для виведення всіх елементів дерева у порядку зростання
void inOrderTraversal(Node* root) {
  if (root == nullptr) return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}
int main(){
  // Створення бінарного дерева з числами від 1 до 10
  Node* root = nullptr;
  for (int i = 1; i <= 10; ++i)  insertNode(root, i);
  // Виведення всіх елементів дерева у порядку зростання
  cout << "All elements in ascending order: ";
  inOrderTraversal(root); cout << endl;
  // Пошук та видалення елементів з номерами 3 та 7
  int elementsToDelete[] = {3, 7};
  for (int i = 0; i < 2; ++i) {
    int element = elementsToDelete[i];
    if (searchNode(root, element)) {
      root = deleteNode(root, element);
      cout << "Element " << element << " deleted.\n";
    } else cout << "Element " << element << " not found.\n";
  }
  // Виведення всіх елементів дерева у порядку зростання після видалення
  cout << "All elements after deletion in ascending order: ";
  inOrderTraversal(root);
  cout << endl;
  return 0;
}
