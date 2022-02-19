#include <iostream>
#include <string> 
#include <vector> 
#include <cctype>
#include <tuple>
#include <algorithm>

using namespace std;

enum ItemType { ANIMAL, TRAP };

struct Item {
    ItemType type;
    char name;
    int position;
    bool is_valid;
};

char to_lower(char ch) {
    return static_cast<char>(tolower(static_cast<unsigned char>(ch)));
}

bool is_combined(Item item1, Item item2) {
    return item1.name == item2.name && item1.type != item2.type;
}

int main() {
    string str;
    cin >> str;
    
    vector<Item> items(str.size());
    vector< pair<int, int> > trap_to_animal;

    int animals_count = 0;
    int traps_count = 0;
    for (int i = 0; i < str.size(); ++i) {
        bool is_animal = islower(str[i]);
        items[i] = (Item) {
            .type = is_animal ? ANIMAL : TRAP,
            .name = to_lower(str[i]),
            .position = is_animal ? animals_count++ : traps_count++,
            .is_valid = true
        };
    }
    
    for (int i = 1; i < items.size(); ++i) {
        Item first = items[i];
        Item second = items[i-1];
        if (!is_combined(first, second)) continue;
        
        trap_to_animal.push_back(make_pair(
            first.type == TRAP ? first.position : second.position,
            first.type == ANIMAL ? first.position : second.position
        ));
        items[i].is_valid = false;
        items[i-1].is_valid = false;
        i++;
    }
    
    vector<Item> filtered_items;
    for (int i = 0; i < items.size(); ++i) {
        if (!items[i].is_valid) continue;
        filtered_items.push_back(items[i]);
    }
    
    for (int i = 0; i < filtered_items.size() / 2; ++i) {
        Item first = filtered_items[i];
        Item second = filtered_items[filtered_items.size()-i-1];
        if (!is_combined(first, second)) {
            cout << "Impossible";
            return 0;
        };
        trap_to_animal.push_back(make_pair(
            first.type == TRAP ? first.position : second.position,
            first.type == ANIMAL ? first.position : second.position
        ));
    }

    sort(trap_to_animal.begin(), trap_to_animal.end());
    
    cout << "Possible" << "\n";
    for (auto pair: trap_to_animal) cout << pair.second + 1<< " ";
    
    return 0;
}
