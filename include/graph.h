#ifndef CRYPT_GRAPH_GRAPH_H
#define CRYPT_GRAPH_GRAPH_H

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

void print(int x);

template <typename T> struct Node {
  T data;
};

template <typename T> struct Edge {
  Node<T> *from;
  Node<T> *to;
  long unsigned weight;
};

template <typename T> class Graph {
  using NodeType = Node<T>;
  std::vector<NodeType> m_nodes;
  std::unordered_map<NodeType *, std::vector<Edge<T>>> m_node_to_edge{};

public:
  Graph(std::vector<NodeType> nodes) : m_nodes(nodes) {}
  void addEdge(unsigned a, unsigned b, unsigned weight = 0);
  void traverseDebthFirst(unsigned start);
  std::vector<T> dijkstra(unsigned start, unsigned end);
};

#endif
