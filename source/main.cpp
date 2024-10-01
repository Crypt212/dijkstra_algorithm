#include "../include/graph.h"
#include <iostream>
#include <vector>

void dijkstra(Graph<int> &gr, unsigned from, unsigned to) {
  std::cout << "\nShortest path from " << from << " to " << to << std::endl;
  std::cout << "----------------------------\n";
  std::vector<int> v = gr.dijkstra(from, to);
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i != v.size() - 1)
      std::cout << " -> ";
  }
  std::cout << std::endl;
}

std::vector<Node<int>> nodes = {{0}, {1}, {2}, {3}, {4}, {5},
                                {6}, {7}, {8}, {9}, {10}};

int main() {
  Graph gr(nodes);
  gr.addEdge(0, 1, 2);
  gr.addEdge(0, 5, 1);
  gr.addEdge(1, 2, 3);
  gr.addEdge(1, 4, 1);
  gr.addEdge(1, 5, 3);
  gr.addEdge(1, 10, 2);
  gr.addEdge(3, 4, 2);
  gr.addEdge(4, 6, 1);
  gr.addEdge(5, 8, 1);
  gr.addEdge(6, 7, 4);
  gr.addEdge(6, 8, 2);
  gr.addEdge(9, 10, 1);

  std::cout << "\n--------------------\n";
  gr.traverseDebthFirst(0);
  std::cout << std::endl;

  dijkstra(gr, 9, 3);
  dijkstra(gr, 9, 5);
  dijkstra(gr, 2, 7);
  std::cout << "\n--------------------\n";
  return 0;
}
