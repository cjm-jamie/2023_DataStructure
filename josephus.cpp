/*josephus*/

#include <iostream>

#define arrayNum 100

using namespace std;

int tail, head, itemNum;
int Q[arrayNum];

void enqueue(int x)
{
//
	if(!itemNum)
	{
		head = 0;
		Q[head] = x;
	}
//
	else
	{
		tail = (tail+1)%arrayNum;
		Q[tail] = x;
	}
	
	itemNum++;
}

int dequeue()
{
	int tmp = Q[head];
	head = (head+1) % arrayNum;
	itemNum--;
	
	return tmp;
}

int main()
{
	int n, tmp;
	cout << "please enter an integer between 1~100"<< "\n";
	cin >> n ;
// the beginning value of "for" loop should be i = 1, not i = 0 to represent the correct number of people
	for(int i=1; i<=n; i++)
		enqueue(i);
	for(int i=1; i<=n-1; i++)
	{
		tmp = dequeue();
		dequeue();
		enqueue(tmp);
	}
	
	cout << "answer of josephus of your input is "<< Q[head] << "\n" ;
	
	return 0;
}
