//
// Created by Timur Guliamov on 06.03.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> prices(n);
    std::for_each(prices.begin(), prices.end(),
                  [](auto &elem) { std::cin >> elem; });

    std::sort(prices.begin(), prices.end());
    std::reverse(prices.begin(), prices.end());

    int result = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (i % k == k - 1)
            continue;
        result += prices[i];
    }

    std::cout << result;
}
