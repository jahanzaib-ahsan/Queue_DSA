//Array based implementation of Stack
#include<iostream>
#include<string>
using namespace std;
class stack
{
	int top;
public:
	int arr[5];
	stack()
	{
		top = -1;
	}
	void push(int a)
	{
		if (isfull())
		{
			cout << "stack fill.";
		}
		else
		{
			top++;
			arr[top] = a;
		}
	}
	int pop()
	{
		if (isempty())
		{
			return -1;
		}
		else
		{
			cout << "poped value = " << arr[top] << endl;
			--top;
		}
	}
	bool isempty()
	{
		if (top == -1)
		{
			cout << "THE STACK IS EMPTY" << endl;
			return true;
		}
		return false;

	}
	bool isfull()
	{
		if (top == 5 - 1)
		{
			cout << "STACK IS FULL" << endl;
			return true;
		}
		return false;

	}
	int count()
	{
		return top;
	}
	void display()
	{
		cout << "ELEMENTS Are :" << endl;
		int temp = top;
		while (temp != -1)
		{
			cout << arr[temp] << endl;
			temp--;
		}
	}
};
class Queue
{
public:
	stack obj1, obj2; //multiple stacks 
	//constructor
	Queue() {}
	void Enqueue(int data)
	{
		obj1.push(data);
	}
	void Dequeue()
	{
		int data1;//poped element form first stack
		int data2;//poped element from second stack
		while (!obj1.isempty())
		{
			data1 = obj1.pop();
			obj2.push(data1);
			//phalay sa data lea jana hay 
			//dosray ma push kri jana
			// is sa sab sa akhri waala pahla access hoga
		}
	}
	void print()
	{
		obj1.display();
	}
};
int main()
{
	Queue obj;
	int key, opt = 0;
	cout << "--------Menu---------" << endl;
	cout << "Press 1 for Insertion" << endl;
	cout << "Press 2 for Deletion " << endl;
	cout << "Press 3 for Display  " << endl;
	cout << "Press 4 to  Exit     " << endl;
	while (opt != 4)
	{
		cin >> opt;
		if (opt == 1)
		{
			cout << "Enter the value " << endl;
			cin >> key;
			obj.Enqueue(key);
		}
		else if (opt == 2) { obj.Dequeue(); }
		else if (opt == 3) { obj.print(); }
		else if (opt == 4) { break; }
		cout << "Choose From Menu Again" << endl;
	}

	system("Pause>0");
}
