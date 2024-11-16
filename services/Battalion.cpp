#include "Battalion.h"
#include <climits>
#include "../structs/CustomQueue.h"
#include "../structs/Graph.h"

// Função que verifica se há um caminho de volta para a capital a partir de cada centro urbano
std::map<std::string, int> bfsReverseDistances(const std::map<std::string, std::vector<std::string>>& reverseGraph, const std::string& capital) {
    std::map<std::string, int> reverseDistances;
    for (const auto& pair : reverseGraph) {
        reverseDistances[pair.first] = INT_MAX;
    }
    reverseDistances[capital] = 0;

    CustomQueue queue;
    queue.enqueue(capital);

    while (!queue.isEmpty()) {
        std::string current = queue.peek();
        queue.dequeue();

        if (reverseGraph.find(current) != reverseGraph.end()) {
            for (const auto& neighbor : reverseGraph.at(current)) {
                if (reverseDistances[neighbor] == INT_MAX) {
                    reverseDistances[neighbor] = reverseDistances[current] + 1;
                    queue.enqueue(neighbor);
                }
            }
        }
    }
    return reverseDistances;
}

// Função para criar o grafo reverso
std::map<std::string, std::vector<std::string>> buildReverseGraph(const std::map<std::string, std::vector<std::string>>& graph) {
    std::map<std::string, std::vector<std::string>> reverseGraph;
    for (const auto& [node, neighbors] : graph) {
        for (const auto& neighbor : neighbors) {
            reverseGraph[neighbor].push_back(node);  // Inverte a direção da estrada
        }
    }
    return reverseGraph;
}

// Função que calcula o número de batalhões extras necessários
int calculateExtraBattalion(const std::map<std::string, std::vector<std::string>>& graph, const std::string& capital) {
    // Cria o grafo reverso para verificar conectividade de retorno
    std::map<std::string, std::vector<std::string>> reverseGraph = buildReverseGraph(graph);

    // Calcula distâncias da capital usando BFS
    std::map<std::string, int> distances = bfsDistances(graph, capital);

    // Calcula distâncias de retorno à capital
    std::map<std::string, int> reverseDistances = bfsReverseDistances(reverseGraph, capital);

    // Verifica componentes fortemente conectados usando uma BFS ou DFS adaptada
    std::map<std::string, bool> visited;
    int extraBattalions = 0;

    for (const auto& node : graph) {
        if (!visited[node.first]) {
            // Realiza uma BFS para marcar todos os nodos alcançáveis
            CustomQueue queue;
            queue.enqueue(node.first);

            std::vector<std::string> component;
            while (!queue.isEmpty()) {
                std::string current = queue.peek();
                queue.dequeue();
                if (!visited[current]) {
                    visited[current] = true;
                    component.push_back(current);
                    for (const auto& neighbor : graph.at(current)) {
                        if (!visited[neighbor]) {
                            queue.enqueue(neighbor);
                        }
                    }
                }
            }

            // Se algum nodo neste componente não pode retornar à capital, precisamos de um batalhão extra
            bool needsBattalion = false;
            for (const auto& city : component) {
                if (distances[city] != INT_MAX && reverseDistances[city] == INT_MAX) {
                    needsBattalion = true;
                    break;
                }
            }

            if (needsBattalion) {
                extraBattalions++;
            }
        }
    }

    return extraBattalions;
}

// Função para verificar se todos os centros urbanos estão conectados à capital em ambos os sentidos
bool verifyCompleteConnects(const std::map<std::string, std::vector<std::string>>& graph, const std::string& capital) {
    std::map<std::string, int> distances = bfsDistances(graph, capital);
    std::map<std::string, std::vector<std::string>> reverseGraph = buildReverseGraph(graph);
    std::map<std::string, int> reverseDistances = bfsReverseDistances(reverseGraph, capital);

    for (const auto& distPair : distances) {
        if (distPair.second == INT_MAX || reverseDistances[distPair.first] == INT_MAX) {
            return false;  // Algum centro urbano não está conectado em ambas as direções
        }
    }
    return true;
}
