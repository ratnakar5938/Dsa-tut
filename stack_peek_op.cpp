#include <iostream>

using namespace std;

class Stack
{
public:
	int size;
	int top;
	int *arr;
};

int isEmpty(Stack *ptr)
{
	if (ptr->top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(Stack *ptr)
{
	if (ptr->top == (ptr->size - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack_traversal(Stack *ptr)
{
	int pos = ptr->top;
	while (pos >= 0)
	{
		cout << "the element is: " << ptr->arr[pos] << endl;
		pos--;
	}
}

void push(Stack *ptr, int data)
{
	if (!isFull(ptr))
	{
		ptr->arr[ptr->top + 1] = data;
		ptr->top++;
	}
	else
	{
		cout << "Stack overflow\n"
			 << "\n";
	}
}

void pop(Stack *ptr)
{
	if (!isEmpty(ptr))
	{
		int val = ptr->arr[ptr->top];
		ptr->arr[ptr->top] = 0;
		ptr->top--;
		cout << "element poped: " << val << "\n\n";
	}
	else
	{
		cout << "Stack underflow" << endl;
	}
}

int peek(Stack *ptr, int position)
{
	int arrInd = ptr->top - position + 1;
	if (arrInd < 0)
	{
		cout << "Not a valid position"
			 << "\n";
		return -1;
	}
	else
	{
		return ptr->arr[arrInd];
	}
}

int main()
{
	Stack *s;
	s->size = 80;
	s->top = -1;
	s->arr = new int[s->size];

	// pushing element manually
	s->arr[0] = 4;
	s->top++;
	s->arr[1] = 44;
	s->top++;
	s->arr[2] = 444;
	s->top++;
	s->arr[3] = 4444;
	s->top++;

	if (isEmpty(s))
	{
		cout << "Stack is empty"
			 << "\n";
	}
	else
	{
		cout << "stack is not empty"
			 << "\n";
	}
	if (isFull(s))
	{
		cout << "stack is full\n";
	}
	else
	{
		cout << "stack is not full\n";
	}
	cout << "\n";
	push(s, 44444);
	stack_traversal(s);
	for (int j = 0; j < s->top + 1; j++)
	{
		cout << "Element at position " << j + 1 << " is: " << peek(s, j + 1) << "\n";
	}
	return 0;
}