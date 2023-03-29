#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    int q; cin >> q;
    list<int> mylist;
    while (q--) {
        string op; cin >> op;
        if (op == "IH") {
            int i; cin >> i;
            mylist.emplace_front(i);
        } else if (op == "IT") {
            int i; cin >> i;
            mylist.emplace_back(i);
        } else if (op == "RH") {
            if (!mylist.empty()) {
                mylist.pop_front();
            } 
        } else if (op == "RT") {
            if (!mylist.empty()) {
                mylist.pop_back();
            }
        } else if (op == "S") {
            int i; cin >> i;
            if (mylist.empty()) {
                cout << "E\n";
            } else if (find(mylist.begin(), mylist.end(), i) != mylist.end()) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        } else if (op == "O") {
            if (mylist.empty()) {
                cout << "E\n";
            } else {
                for (auto x : mylist) {
                    cout << x << " ";
                }
                cout << "\n";
            }
        } else {
            assert(false && "unreachable");
        }
    }
}