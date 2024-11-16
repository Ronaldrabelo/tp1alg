#include <iostream>

#include "services/Battalion.h"
#include "services/Capital.h"
#include "structs/Graph.h"
using namespace std;

int main()
{
    int numCenters, numRoads;
    std::cin >> numCenters >> numRoads;

    auto graph = buildGraph(numCenters, numRoads);

    std::string capital = findCapital(graph);
    int extraBattalions = calculateExtraBattalion(graph, capital);

    std::cout << capital << std::endl;
    std::cout << extraBattalions << std::endl;


    return 0;
}
