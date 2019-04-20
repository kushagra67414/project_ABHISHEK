#include<iostream>
#include<conio.h>
#define FALSE 0
#define TRUE 1
using namespace std;
class linklist
{
private:
	struct node
	{
		int data;
		node* link;
	}*p;
public:
	linklist();
	void append(int num);
	void addatbeg(int num);
	void addafter(int c, int num);
	void del(int num);
	void display();
		int operator==(linklist);

	//To copt ylist from one to another.
	void operator=(linklist);
};

linklist::linklist()
{
	p = NULL;
}
void linklist::append(int num)
{
	node *q, *t;
	if (p == NULL)
	{
		p = new node;
		p->data = num;
		p->link = NULL;
	}
	else	
	{
		q = p;
		while (q->link != NULL)
			q = q->link;
		t = new node;
		t->data = num;
		t->link = NULL;
	}
}

void linklist::addatbeg(int num)
{
	node *q;
	q = new node;
	q->data = num;
	q->link = p;
	p = q;
}

void linklist::addafter(int c, int num)
{
	node *q, *t; int i;

	for (i = 0, q = p; i < c; i++)
	{
		q = q->link;
		if (q == NULL)
		{
			cout << endl << "There are less than " << c << "elements.";
			return;
		}
	}
	t = new node;
	t->data = num;
	t->link = q->link;
	q->link = t;
}
void linklist::del(int num)
{
	node *q, *r;
	q = p;
	if(q->data == num)
	{
		p = q->link;
		delete q;
		return;
	}

	r = q;
	while (q != NULL)
	{
		if (q->data == num)
		{
			r->link = q->link;
			delete q;
			return;
		}
		r = q;
		q = q->link;
	}
	cout << endl << "Element " << num << " not found.";
}
int main()
{
	linklist a, b;
	a.addatbeg(5);
	a.addatbeg(4);
	a.addatbeg(3);
	
	b = a; //Copying two linked lists.
	cout <<"linked list : b";
	b.display();
	
	if(a == b)//Comparing two linked lists.
		cout << "a and b are quivalent.\n";
	else
		cout <<"a and b are not equivalent.\n";
	
	_getch();
	return 0;
}

