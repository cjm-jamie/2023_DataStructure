#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        int complement = x - a;
        if (mp.count(complement)) {
            cout << mp[complement] << " " << i << "\n";
            return 0;
        }

        mp[a] = i;
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}