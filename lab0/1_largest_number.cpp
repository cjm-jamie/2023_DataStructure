#include <iostream>

using namespace std;

int main(void)
{
    int arraysize;
    scanf("%d", &arraysize);
    int arr[arraysize], largestIndex;
  	int largestNum = 0;
    for (int i = 0; i < arraysize; i++)
    {
      cin >> arr[i];
      if (arr[i] > largestNum)
      {
        largestNum = arr[i];
        largestIndex = i;
      }
    }
	cout << largestIndex + 1 ;      
    return 0;
}