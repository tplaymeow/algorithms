#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using block = unordered_map<string, int>;

int find_value(string name, vector<block> blocks) {
    for (vector<block>::reverse_iterator it = blocks.rbegin(); it != blocks.rend(); ++it) { 
        block::iterator block_it = it->find(name);
        if (block_it != it->end()) { 
            return block_it->second;
        }
    } 
    return 0;
}

int main() {
    vector<block> blocks;
    blocks.push_back(block());
    
    string line;
    while (cin >> line) {
        if (line == "{") {
            blocks.push_back(block());
        }
        else if (line == "}") {
            blocks.pop_back();
        }
        else {
            size_t delemiter_idx = line.find("=");
            string key = line.substr(0, delemiter_idx);
            string value_str = line.substr(delemiter_idx + 1, line.length() - 1);

            char* p;
            int value_int = strtol(value_str.c_str(), &p, 10);
            if (*p == NULL) {
                blocks.back()[key] = value_int;
            }
            else {
                value_int = find_value(value_str, blocks);
                cout << value_int << "\n";
                blocks.back()[key] = value_int;
            }
        }
    }
}