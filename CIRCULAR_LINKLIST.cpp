#include <iostream>
using namespace std;

class node
{

public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
	}

	// PRINT LINKLIST
	void display(node *&head)
	{

		if (head == NULL)
			return;

		node *temp = head;
		// cout<<"main"<<endl;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}

	//  INSERT AT START

	void Insert_At_Start(node *&head, int element)
	{
		node *n = new node(element);
		if (head == NULL)
		{
			head = n;
			head->next = head;
			return;
		}

		node *temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->next = head;
		head = n;
	}

	//  INSERT AT Last

	void Insert_At_End(node *&head, int element)
	{
		node *n = new node(element);
		if (head == NULL)
		{
			head = n;
			head->next = head;
			return;
		}

		node *temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->next = head;
	}

	//  INSERT AT ANY INDEX

	void Insert_At_AnyIndex(node *&head, int element, int index)
	{

		if (head == NULL || index == 0)
		{
			Insert_At_Start(head, element);
			return;
		}

		node *n = new node(element);
		node *temp = head;
		int cnt = 0;
		while (temp->next != head && cnt != index - 1)
		{
			temp = temp->next;
			cnt++;
		}
		if (cnt == index - 1)
		{
			n->next = temp->next;
			temp->next = n;
		}
	}

	// DELETION

	//  DLETION AT START

	void Delete_At_Start(node *&head)
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == head)
		{

			head = NULL;
			return;
		}
		node *temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = head->next;
		head = head->next;
	}
	//  DLETION AT END

	void Delete_At_End(node *&head)
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == head)
		{

			head = NULL;
			return;
		}
		node *temp = head;
		while (temp->next->next != head)
		{
			temp = temp->next;
		}

		temp->next = head;
	}

	// DELTION AT ANY INDEX

	void Delete_At_AnyIndex(node *&head, int element)
	{

		if (head == NULL)
		{
			return;
		}
		if (head->next == head)
		{
			if (head->data == element)
			{
				head = NULL;
			}
			return;
		}
		if (head->data == element)
		{
			Delete_At_Start(head);
		}
		else
		{
			node *temp = head;
			while (temp->next != head && temp->next->data != element)
			{
				temp = temp->next;
			}
			if (temp->next->data == element)
			{
				temp->next = temp->next->next;
			}
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif

	node *head = NULL;
	node *n1;
	n1->Insert_At_Start(head, 10);
	n1->Insert_At_Start(head, 5);
	// n1->Insert_At_Start(head,1);
	n1->Insert_At_End(head, 20);
	n1->Insert_At_End(head, 30);
	n1->Insert_At_End(head, 40);

	// n1->Insert_At_AnyIndex(head,2,0);
	// n1->Insert_At_AnyIndex(head,100,0);
	n1->display(head);

	// n1->Delete_At_Start(head);
	// n1->Delete_At_Start(head);
	// n1->Delete_At_End(head);
	// n1->Delete_At_End(head);
	// n1->Delete_At_End(head);
	n1->Delete_At_AnyIndex(head, 5);
	n1->Delete_At_AnyIndex(head, 10);
	n1->Delete_At_AnyIndex(head, 40);
	n1->Delete_At_AnyIndex(head, 200);
	n1->Delete_At_AnyIndex(head, 20);
	n1->Delete_At_AnyIndex(head, 20);
	n1->Delete_At_AnyIndex(head, 30);

	n1->display(head);
}
