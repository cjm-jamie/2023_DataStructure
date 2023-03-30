#include <iostream>
#include <cstdlib>
#include <stddef.h>

using namespace std;

struct node
{
	int key;
	struct node *next;
};

typedef struct node node;
node *Head = NULL; 

void insert(int x)
{
	node *newnode, *current;
	// newnode = (node *)malloc(sizeof(node)); /* previous usage of "malloc" */
	newnode = new node; /* use "new" */
	newnode -> key = x;
	newnode -> next = NULL;
	
	/*newnode is insert in the beginning of the list*/

	if(Head == NULL || Head -> key > x)
	{
		newnode -> next = Head;
		Head = newnode;
	}

	/*newnode is insert in somewhere of the list*/
	
	else
	{
		current = Head;
		while(current -> next == NULL || current -> next -> key > x)
		{
			newnode -> next = current -> next;
			current -> next = newnode;
		}
	}
}

node *Delete(int x)
{
	node *current = Head;

	/* if head is the node to be deleted */
	if( Head != NULL && Head -> key == x)
	{
		Head = Head -> next;
		return current;
	}

	/* Search for the node to be deleted */
	while (current != NULL && current -> next != NULL)
	{
		if( current -> next -> key == x)
		{
			node *answer = current -> next;
			current -> next = answer -> next;
			return answer;
		}
		else if( current -> next -> key > x)
			return NULL;

		current = current -> next;
	}

	return NULL;
	
}

void print()
{
	node *current;
	if(Head == NULL)
		cout << "The list is empty" << "\n";
	else
	{
		current = Head;
		// is "current != NULL" not "current -> next != NULL"
		while(current != NULL)
		{
			cout << current -> key << " " ;
			current = current -> next;
		}
		
		cout << "\n";
	}
}

int main()
{
	node *x, *y;

	insert(10);

	cout <<"after insert 10 in the list is ";
	print();
	cout <<"\n";

	insert(8);
	cout <<"after insert 8 in the list is ";
	print();
	cout <<"\n";

	insert(0);
	insert(7);
	insert(6);

	cout <<"after insert 10, 8, 0, 7, 6 in the list is ";
	print();
	cout <<"\n";

	x = Delete(0);
	if(x != NULL)
		delete x;

	cout <<"after delete 0 in the list is ";
	print();
	cout <<"\n";

	y = Delete(10);
	if(y != NULL)
		delete y;

	cout <<"after delete 10 in the list is ";
	print();
	cout <<"\n";
	
	return 0;
}
