#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n, char A, char B, char C)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, A, C, B);
    cout  <<  int(A)-64 <<' '<<  int(B)-64 << endl;
    towerOfHanoi(n - 1, C, B, A);
}
  
// Driver code
int main()
{
	int N;
    cin >> N;
    // A, B and C are names of rods
  	cout << pow(2,N)-1 << endl;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}