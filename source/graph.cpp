#include "../include/graph.h"

void print(int x) { std::cout << x << ' '; }

template <> void Graph<int>::addEdge(unsigned a, unsigned b, unsigned weight) {
  if (a >= m_nodes.size() || b >= m_nodes.size())
    return;
  m_node_to_edge[&m_nodes[a]].push_back({&m_nodes[a], &m_nodes[b], weight});
  m_node_to_edge[&m_nodes[b]].push_back({&m_nodes[b], &m_nodes[a], weight});
}

template <> void Graph<int>::traverseDebthFirst(unsigned start) {
  if (start >= m_nodes.size())
    return;
  std::unordered_map<NodeType *, bool> visited;
  std::stack<NodeType *> visit_list;
  visit_list.push(&m_nodes[start]);
  visited[&m_nodes[start]] = true;
  while (!visit_list.empty()) {
    NodeType *current = visit_list.top();
    visit_list.pop();
    print(current->data);
    for (Edge<int> edge : m_node_to_edge[current]) {
      if (visited.find(edge.to) != visited.end())
        continue;
      visited[edge.to] = true;
      visit_list.push(edge.to);
    }
  }
}

template <>
std::vector<int> Graph<int>::dijkstra(unsigned start, unsigned end) {
  if (start >= m_nodes.size() || end >= m_nodes.size())
    return std::vector<int>{0};
  std::unordered_map<NodeType *, bool> visited;
  std::queue<NodeType *> visit_list;
  visit_list.push(&m_nodes[start]);
  std::unordered_map<NodeType *, unsigned> distance{{&m_nodes[start], 0}};
  while (!visit_list.empty()) {
    NodeType *current = visit_list.front();
    visit_list.pop();
    for (Edge edge : m_node_to_edge[current]) {
      long unsigned tentative_distance = edge.weight + distance[current];
      if (distance.find(edge.to) == distance.end())
        distance[edge.to] = tentative_distance;
      else
        distance[edge.to] = tentative_distance < distance[edge.to]
                                ? tentative_distance
                                : distance[edge.to];
      if (visited.find(edge.to) == visited.end()) {
        visited[edge.to] = true;
        visit_list.push(edge.to);
      }
    }
  }

  std::vector<int> shortest_path_reversed{};
  NodeType *current = &m_nodes[end];
  shortest_path_reversed.push_back(current->data);
  while (current != &m_nodes[start]) {
    NodeType *closest_node = nullptr;
    unsigned shortest_distance;
    for (Edge edge : m_node_to_edge[current]) {
      if (!closest_node || shortest_distance > distance[edge.to]) {
        closest_node = edge.to;
        shortest_distance = distance[edge.to];
      }
    }
    shortest_path_reversed.push_back(closest_node->data);
    current = closest_node;
  }
  std::vector<int> shortest_path;
  while (!shortest_path_reversed.empty()) {
    shortest_path.push_back(shortest_path_reversed.back());
    shortest_path_reversed.pop_back();
  }

  return shortest_path;
}
