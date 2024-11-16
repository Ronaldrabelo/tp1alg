//
// Created by casa- on 07/11/2024.
//

#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <vector>
#include <string>

std::map<std::string, std::vector<std::string>> buildGraph(int numCenters, int numWays);

std::map<std::string, int> bfsDistances(const std::map<std::string, std::vector<std::string>>& graph, const std::string& origin);




#endif
