#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    int t, n, q, num;
    string op;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        list<int> nums;
        unordered_map<int, list<int>::iterator> num_map;
        for (int i = 0; i < n; i++) 
        {
            nums.push_back(i+1) ;
            num_map[i + 1] = prev(nums.end());
        }
        for (int i = 0; i < q; i++) 
        {
            cin >> op >> num;
            auto it = num_map[num];
            if (op == "H") 
            {
                nums.splice(nums.begin(), nums, it);
                num_map[num] = nums.begin();
            } 
            if (op == "T") 
            {
                nums.splice(nums.end(), nums, it);
                num_map[num] = prev(nums.end());
            }
        }
        for (int num : nums) 
            cout << num << " ";
        cout << endl;
    }
    return 0;
}