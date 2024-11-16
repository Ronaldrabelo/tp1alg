//
// Created by casa- on 07/11/2024.
//

#include "graph.h"
#include <climits>
#include <iostream>

#include "CustomQueue.h"

std::map<std::string, std::vector<std::string>> buildGraph(int numCenters, int numWays) {
    std::map<std::string, std::vector<std::string>> graph;
    for (int i = 0; i < numWays; ++i) {
        std::string c1, c2;
        std::cin >> c1 >> c2;
        graph[c1].push_back(c2);
    }
    return graph;
}


std::map<std::string, int> bfsDistances(const std::map<std::string, std::vector<std::string>>& graph, const std::string& origin) {
    std::map<std::string, int> distances;
    for (const auto& pair : graph) {
        distances[pair.first] = INT_MAX;
    }
    distances[origin] = 0;

    CustomQueue queue;
    queue.enqueue(origin);

    while (!queue.isEmpty()) {
        std::string current = queue.peek();
        queue.dequeue();

        for (const auto& neighbor : graph.at(current)) {
            if (distances[neighbor] == INT_MAX) {
                distances[neighbor] = distances[current] + 1;
                queue.enqueue(neighbor);
            }
        }
    }
    return distances;
}
