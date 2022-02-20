#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
    stack<vector<string>> namespaces_vars;
    namespaces_vars.push(vector<string>());
    unordered_map<string, stack<int>> name_to_val;

    string line;
    while (cin >> line) {
        if (line == "{") namespaces_vars.push(vector<string>());
        else if (line == "}") {
            for (auto& name : namespaces_vars.top())
                name_to_val[name].pop();
            namespaces_vars.pop();
        }
        else {
            size_t delemiter_idx = line.find("=");
            string name = line.substr(0, delemiter_idx);
            string value_str = line.substr(delemiter_idx + 1, line.length() - 1);

            char* p;
            int value_int = strtol(value_str.c_str(), &p, 10);
            if (*p != NULL) {
                value_int = name_to_val.find(value_str) != name_to_val.end()
                    ? (name_to_val[value_str].size() != 0 ? name_to_val[value_str].top() : 0)
                    : 0;
                cout << value_int << "\n";
            }
            if (name_to_val.find(name) == name_to_val.end())
                name_to_val[name] = stack<int>();
            name_to_val[name].push(value_int);
            namespaces_vars.top().push_back(name);
        }
    }
}
