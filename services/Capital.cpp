//
// Created by casa- on 13/11/2024.
//

#include "Capital.h"
#include <climits>

#include "../structs/Graph.h"

std::string findCapital(const std::map<std::string, std::vector<std::string>>& graph) {
    std::string betterCapital;
    int smallestBiggestDistance = INT_MAX;

    for (const auto& pair : graph) {
        std::string center = pair.first;
        std::map<std::string, int> distances = bfsDistances(graph, center);

        int biggerDistance = 0;
        for (const auto& distPair : distances) {
            if (distPair.second > biggerDistance) {
                biggerDistance = distPair.second;
            }
        }

        if (biggerDistance < smallestBiggestDistance) {
            smallestBiggestDistance = biggerDistance;
            betterCapital = center;
        }
    }

    return betterCapital;
}
