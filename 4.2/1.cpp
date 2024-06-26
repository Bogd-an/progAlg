// Завдання 1. Написати програму для створення бінарного дерева, яка буде
// зберігати цілі числа та виводити на екран у вигляді дерева. Користувачу потрібно
// буде задати кількість елементів бінарного дерева від 1 до 12 та ввести елементи з клавіатури.
//C++ code for the above approach

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct Node {
  int data;  Node* left;  Node* right;
  Node(int data){
    this->data = data;
    left = right = nullptr;
  }
};

void printSpace(double n, Node* removed){
  for (; n > 0; n--) cout << " ";
  if (removed == nullptr)  cout << " ";
  else  cout << removed->data;
}

int heightOfTree(Node* root){
  if (root == nullptr) return 0;
  return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

void printBinaryTree(Node* root){
  queue<Node*> treeLevel, temp;
  treeLevel.push(root);
  int counter = 0;
  int height = heightOfTree(root) - 1;
  double numberOfElements = pow(2, (height + 1)) - 1;
  while (counter <= height) {
    Node* removed = treeLevel.front();
    treeLevel.pop();
    printSpace(numberOfElements / pow(2, counter + (temp.empty()?1:0)), removed);
    if (removed == nullptr) {
      temp.push(nullptr);
      temp.push(nullptr);
    } else {
      temp.push(removed->left);
      temp.push(removed->right);
    }
    if (treeLevel.empty()) {
      cout << endl << endl;
      treeLevel = temp;
      while (!temp.empty()) temp.pop();
      counter++;
    }
  }
}

int main(){
  int lenData;
  cout << "\nEnter the count nodes: ";
  cin >> lenData;

  if(!( 1 < lenData && lenData < 12 )){
    cout << "\nNot 1 < count < 12";
    return 1;
  }

  int rootData;
  cout << "Enter root node: ";
  cin >> rootData;
  
  Node* root = new Node(rootData);
  queue<Node*> nodeQueue;
  nodeQueue.push(root);
  while (!nodeQueue.empty()) {
    Node* current = nodeQueue.front();
    nodeQueue.pop();
    int newData;
    for(int isRight = 0; isRight<=1; isRight++){
      if(lenData-- > 1){
        cout << (!isRight?"left  ":"right ") << current->data << " (-1 if none): ";
        cin >> newData;
        if (newData == -1) {
          lenData++;
          continue;
        }
        if(!isRight){
          current->left = new Node(newData);
          nodeQueue.push(current->left);
        } else{
          current->right = new Node(newData);
          nodeQueue.push(current->right);
        }
      }
    }
  }
  printBinaryTree(root);
  return 0;
}
