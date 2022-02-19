#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    for (int i = 0; i < k; i++) {
        int new_a = (a * b) - c;
        if (new_a <= 0) { cout << 0; return 0; }
        if (new_a >= d) { cout << d; return 0; }
        if (new_a == a) { cout << a; return 0; }
        a = new_a;
    }

    cout << a;
}
