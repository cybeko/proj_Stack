#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 20 };
	char st[FULL + 1];
	int top;
public:
	Stack();

	void Push(char c);
	char Pop();

	void Clear();

	bool IsEmpty();
	bool IsFull();
	void IsCorrect();

	int GetCount();

	void Print()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << st[i] << "\t";
		}
		cout << endl;
	}
};


Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}
void Stack::IsCorrect()
{
	bool isfind = false;
	for (int i = 0; i <= top; i++)
	{
		if (st[i] == '{' || st[i] == '(' || st[i] == '[')
		{
			for (int j = i; j <= top; j++)
			{
				if (st[i] == '{' && st[j] == '}')
				{
					isfind = true;
				}
				else if (st[i] == '(' && st[j] == ')')
				{
					isfind = true;
				}
				else if (st[i] == '[' && st[j] == ']')
				{
					isfind = true;
				}
			}
		}
	}
	if (isfind)
	{
		cout << "correct." << endl;
	}
	else
	{
		cout << "not correct." << endl;
	}
}

int Stack::GetCount()
{
	return top + 1;
}

void Stack::Push(char c)
{
	if (!IsFull())
	{
		st[++top] = c;
	}
}

char Stack::Pop()
{
	if (!IsEmpty())
	{
		return st[top--];
	}
	else
	{
		return 0;
	}
}

void main()
{
	Stack ST;
	char userStr;

	cout << "\tEnter a string. Type \";\" to fiinish." << endl;
	while (true)
	{
		cin >> userStr;
		if (userStr != ';')
		{
			ST.Push(userStr);
		}
		else
		{
			break;
		}
	}
	ST.IsCorrect();
}
