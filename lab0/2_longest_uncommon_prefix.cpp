#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  	int arraySize;
    // arraySize = 6;
    cin >> arraySize;
  	vector <char> arr(arraySize);
    // vector<char> arr = {'a','b','c','b','a','c'};
  	for(auto &x:arr)
      cin >> x;
  	for(int i=0; i<arraySize-1; i++)
    {
      int l = 0;  
    //   cout << "i is " << i <<endl;
      for(int j=0; j<arraySize-i-1; j++)
      {
        if(j+i+1>=arraySize)
        {
            // cout << "The end!" << endl;
            break;
        }
        else
        {
            if(arr[j]==arr[j+i+1])
            {
                // cout << "I find it!!!" << endl;
                break;
            }
            else
            {
                // cout << "s" << j << " is not equal to s" << j+i << endl;
                l++;
            }
        }
      }
        cout << l << endl;
    }	
}
