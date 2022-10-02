
#include <iostream>
using namespace std;

class node
{

public:
	int data;
	int power;
	node *next;
	// Empty constructor
	node() {}

	//  Assign value
	node(int data, int power)
	{
		this->data = data;
		this->power = power;
	}

	//  how to print link list
	void printLinkedlist(node *ptr)
	{
		while (ptr != NULL)
		{
			cout << ptr->data << "x^" << ptr->power << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}

	//  how to insert at start of linked list

	void insertatstart(node *&head, int element, int power)
	{

		node *n = new node(element, power);
		n->next = head;
		head = n;
	}

	//  how to insert at end of linked list

	void insertatend(node *&head, int element, int power)
	{
		node *n = new node(element, power);
		node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
};

//  TO SORT LIST

void sort(node *&head)
{
	node *temp = head;

	while (temp != NULL)
	{
		node *t = head;
		while (t->next != NULL)
		{
			if (t->power > t->next->power)
			{
				int k = t->power;
				t->power = t->next->power;
				t->next->power = k;
				int d = t->data;
				t->data = t->next->data;
				t->next->data = d;
			}
			t = t->next;
		}
		temp = temp->next;
	}
}

//  TO ADD LIST

node *addlist(node *&head1, node *&head2)
{
	node *temp1 = head1;
	node *temp2 = head2;
		node * ans = new node(-1,-1);;
	node *dummy = ans;
	while (temp1 != NULL && temp2 != NULL)
	{
		// temp1 = temp1->next;
			// temp2 = temp2->next;
		if (temp1->power == temp2->power)
		{
			node *n = new node(temp1->data + temp2->data, temp1->power);
			dummy ->next= n;
			dummy = dummy->next;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1->power < temp2->power)
		{
			node *n = new node(temp1->data, temp1->power);

			dummy ->next= n;
			dummy = dummy->next;
			temp1 = temp1->next;
		}
		else
		{
			node *n = new node(temp2->data, temp2->power);

			dummy ->next= n;
			dummy = dummy->next;
			temp2 = temp2->next;
		}
	}

	while (temp1 != NULL)
	{
		node *n = new node(temp1->data, temp1->power);

		dummy ->next= n;
		dummy = dummy->next;
		temp1 = temp1->next;
	}

	while (temp2 != NULL)
	{
		node *n = new node(temp2->data, temp2->power);

		dummy ->next= n;
		dummy = dummy->next;
		temp2 = temp2->next;
	}
	return ans->next;
}

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif
	node *head1 = NULL;
	head1->insertatstart(head1, 10, 4);
	head1->insertatstart(head1, 20, 2);
	head1->insertatstart(head1, 30, 6);
	head1->insertatstart(head1, 76, 3);
	node *head2 = NULL;
	head2->insertatstart(head2, 11, 4);
	head2->insertatstart(head2, 22, 3);
	head2->insertatstart(head2, 32, 2);
	head2->insertatstart(head2, 96, 1);
	head2->insertatstart(head2, 32, 10);
	head2->insertatstart(head2, 96, 0);

	head1->printLinkedlist(head1);

	head2->printLinkedlist(head2);
	cout << "List After sort " << endl;
	sort(head1);
	sort(head2);
	head1->printLinkedlist(head1);
	head2->printLinkedlist(head2);

	cout << "New List after addition " << endl;
	node *ans = addlist(head1,head2);
		head1->printLinkedlist(ans);

	return 0;
}
