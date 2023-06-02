#include <iostream>
using namespace std;

const long long MOD = 1e9+7;

/* compute (x^y) % MOD */
long long pp(long long x, long long y) {
    if (y == 0) // special casd: 0 次方
        return 1;
    if (y == 1) // special casd: 1 次方
        return x % MOD;
    long long ret = pp(x, y >> 1); // y 除以 2 ，y right shift by 1
    ret = (ret * ret) % MOD; 
    if (y & 1) // true if y is odd
        ret = (ret * x) % MOD;
    return ret;
}

int main() {
    int n;
    cin >> n;
    long long a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        long long result = pp(a, b);
        cout << result << endl;
    }
    return 0;
}
