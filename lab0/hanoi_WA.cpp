#include <iostream>
#include <cmath>
using namespace std;

int step=0;
//(n, from, mid, to)
void hanoi(int n, char A, char B, char C){
    if(n == 1){
        cout << int(A)-64 << "   " << int(C)-64 << '\n';
        step++;
    }
    else{
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}
int main(){
    int n;
    cin >> n;
    cout << pow(2.0,n)-1 << '\n';
    hanoi(n, 'A', 'B', 'C');
}