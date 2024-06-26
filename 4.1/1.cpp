// Варіант 12 - 2
// ```mermaid
// graph TD;
//   3 <-- 3 --> 1; 3 <-- 7 --> 4; 3 <-- 11 --> 5;
//   2 <-- 7 --> 1; 2 <-- 2 --> 4; 2 <-- 8 --> 6;
//   6 <-- 4 --> 4; 6 <-- 6 --> 5; 4 <-- 1 --> 1;
//   4 <-- 5 --> 5;
// ```
// Дано мережу автомобільних доріг, що з'єднують міста певної області. Потрібно
// знайти найкоротшу відстань від початкового міста до кожного міста області,
// якщо рухатись тільки по дорогах.
// Використовуючи алгоритм Дейкстри реалізувати програму для знаходження
// найкоротшого шляху від першої вершини до всіх інших

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_CITIES = 7;

struct Edge { int to; int weight; };

void dijkstra(int start, int graph[MAX_CITIES][MAX_CITIES], 
       int n, int distances[MAX_CITIES]) {
  bool visited[MAX_CITIES] = { false };
  for (int i = 0; i < n; ++i) distances[i] = INF;
  distances[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.emplace(0, start);
  while (!pq.empty()) {
    int current_distance = pq.top().first;
    int current_vertex = pq.top().second;
    pq.pop();

    if (visited[current_vertex]) continue;
    visited[current_vertex] = true;

    for (int neighbor = 0; neighbor < n; ++neighbor) {
      if (graph[current_vertex][neighbor] != INF) {
        int weight = graph[current_vertex][neighbor];
        int distance = current_distance + weight;

        if (distance < distances[neighbor]) {
          distances[neighbor] = distance;
          pq.emplace(distance, neighbor);
        }
      }
    }
  }
}

int main() {
  int graph[MAX_CITIES][MAX_CITIES];
  int n = MAX_CITIES; // Кількість вершин (міст)
  // Ініціалізуємо граф нескінченностями
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) 
      graph[i][j] = INF;
  // Введення ребер (доріг)
  graph[0][2] = 3; graph[2][0] = 3;
  graph[0][4] = 7; graph[4][0] = 7;
  graph[0][5] = 11; graph[5][0] = 11;
  graph[1][0] = 7; graph[0][1] = 7;
  graph[1][3] = 2; graph[3][1] = 2;
  graph[1][5] = 8; graph[5][1] = 8;
  graph[2][4] = 7; graph[4][2] = 7;
  graph[2][5] = 11; graph[5][2] = 11;
  graph[3][4] = 7; graph[4][3] = 7;
  graph[3][6] = 8; graph[6][3] = 8;
  graph[4][6] = 4; graph[6][4] = 4;
  graph[5][6] = 6; graph[6][5] = 6;
  graph[4][5] = 5; graph[5][4] = 5;

  int distances[MAX_CITIES];
  int start_vertex = 0; // Початкова вершина (місто)
  dijkstra(start_vertex, graph, n, distances);
  // Виведення результатів
  cout << "Distance from vertex " << start_vertex + 1 
     << " to other vertices:" << endl;
  for (int i = 0; i < n; ++i) {
    cout << "To vertex " << i + 1 << " - ";
    if (distances[i] == INF)
      cout << "impossible to reach." << endl;
    else
      cout << distances[i] << endl;
  }
  return 0;
}
