#include <iostream>  

using namespace std;

const int MOD = 1e9+7;

int fibonacci(int n) {
   int a = 0, b = 1, c;
   if (n == 0) {
      return a;
   }
   for (int i = 2; i <= n; i++) {
      c = (a + b) % MOD;
      a = b;
      b = c;
   }
   return b;
}

int main(void)
{
    int x, ans;
   //  x = 5;
    cin >> x;
    ans = fibonacci(x);
    cout << ans;
}