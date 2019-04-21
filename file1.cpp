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
void linklist::display()
{
                node *q;
                cout << endl;
                for (q = p; q != NULL; q = q->link)
                                cout << endl << q->data;
}
 
void linklist::operator=(linklist t)
{
                p = t.p;
}
 
int linklist::operator==(linklist t)
{
                int flag = FALSE;
                node *a = p, *b = t.p;
                if (a == NULL && b == NULL)
                {
                                flag = TRUE;
                                return flag;
                }
                while (a != NULL && b != NULL)
                {
                                if (a->data != b->data)
                                                return flag;
                                a = a->link;
                                b = b->link;
                }
                flag = TRUE;
                return flag;
}

#include<iostream>
#include<cstring>
#include<conio.h>

using namespace std;

class String
{
protected:
	char str[200];
public:
	String(){}
	String(char* xstr){ strcpy(str, xstr);	}
        void show() { cout << str << endl; }
	char* operator+(String);
	char* operator=(String);
	char *operator+=(String);
        int stringlen();
        int stringsize();
	void tolower();
	void toupper();
};

char* String::operator+(String xstr)
{
	strcat(str, xstr.str);
	return str;
}
char* String::operator+=(String xstr)
{
	strcat(str, xstr.str);
	return str;
}
int String::stringsize()
{
	return (strlen(str) + 1);
}
char* String::operator=(String xstr)
{
	strcpy(str, xstr.str);
	return str;
}
int String::stringlen()
	{
		return strlen(str);
	}


void String::tolower()
{
	for (int i = 0; str[i] != '\0'; i++)
		if (isupper(str[i]))
			str[i] += 32;
}
void String::toupper()
{
	for (int i = 0; str[i] != '\0'; i++)
		if (islower(str[i]))
			str[i] -= 32;
}
#include<iostream>
#include<conio.h>
using namespace std;

class B1
{
public:
	B1()
	{
		cout << "Constructor of B1" << endl;
	}
	~B1()
	{
		cout << "Destructor of B1" << endl;
	}
};

class B2
{
public:
	B2()
	{
		cout << "Constructor of B2" << endl;
	}
	~B2()
	{
		cout << "Destructor of B2" << endl;
	}
};

class D : public B1, public B2
{
public:
	D() : B1(), B2()
	{
		cout << "Construtor of D" << endl;
	}
	~D()
	{
		cout << "Destructor of D" << endl;
	}
};

int main()
{
	D a;
	_getch();
	return 0;
}

/*Destructor of that class will run first whose constructor is executed
last. It follows LIFO concept.*/
