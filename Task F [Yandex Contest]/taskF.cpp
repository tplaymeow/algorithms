//
// Created by Timur Guliamov on 05.03.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() { // O (n * log(n))
    std::vector<std::string> lines;
    std::string line;
    while (std::cin >> line)
        lines.push_back(line);

    std::sort(lines.begin(), lines.end(),
              [](std::string left, std::string right) {
                  return left + right > right + left;
              });

    for (auto &l : lines)
        std::cout << l;
    std::cout << std::endl;
}
