//
// Created by casa- on 09/11/2024.
//

#ifndef BATTALION_H
#define BATTALION_H

#include <map>
#include <string>
#include <vector>

int calculateExtraBattalion(const std::map<std::string, std::vector<std::string>>& graph, const std::string& capital);

bool verifyCompleteConnects(const std::map<std::string, std::vector<std::string>>& graph, const std::string& capital);


#endif
