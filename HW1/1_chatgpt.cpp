#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, x;
    // cin >> n >> x;
    n = 4;
    x = 8;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

   sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    while (i < j) {
        int sum = a[i].first + a[j].first;
        if (sum == x) {
            int first_index = min(a[i].second, a[j].second);
            int second_index = max(a[i].second, a[j].second);
            cout << first_index << " " << second_index << endl;
            return 0;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return 0;
}