#include<iostream>
using namespace std;

template<typename T>
class Stack
{
protected:
	class Node;
public:
	class Iterator;

	Stack() :head(nullptr), size(0) {}
	~Stack() {}

	void push(T num)
	{
		Node* tmp = new Node(num);
		if (this->head == nullptr)
		{
			this->head = tmp;
			size++;
		}
		else
		{
			tmp->next = this->head;
			this->head = tmp;
			size++;
		}
	}

	T operator [](int p)
	{
		Node* tmp = head;
		try
		{
			if (size < p)
				throw out_of_range("Out of memory");

			for (int run = 0; run < p; run++)
				tmp = tmp->next;

			return tmp->Nums;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
			return 0;
		}
	}

	T pop()
	{
		try
		{
			if (size <= 0)
				throw out_of_range("Out of memory");

			Node* tmp = this->head;
			T result = tmp->Nums;
			this->head = this->head->next;
			delete tmp;
			size--;
			return result;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
			return 0;
		}
	}

	bool IsEmpty()
	{
		return this->head == nullptr;
	}

	void see()
	{
		Node* current = this->head;
		try
		{
			if (size <= 0)
				throw out_of_range("Out of memory");
			if (current == nullptr)
				cout << "Is empty" << endl;
			else
			{
				while (current != nullptr)
				{
					cout << current->Nums << endl;
					current = current->next;
				}
				cout << endl;
			}
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
	}

	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	class Iterator
	{
	public:

		Iterator(const Node* point):current(point){}

		int operator *()
		{
			return current->Nums;
		}

		Iterator& operator ++()
		{
			if(current)
				current = current->next;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++ *this;
			return iterator;
		}

		bool operator!=(const Iterator& iterator)
		{
			return current != iterator.current;
		}
	protected:
		
		const Node* current;
	};
protected:
	Node* head;
	int size;
	class Node
	{
	public:
		Node(T nums):next(nullptr), Nums(nums){}
		
		~Node(){}
	protected:
		friend class Stack;
		Node* next;
		T Nums;
	};
};

int main() {
	Stack<int> stack;
	int a;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter new elem" << endl;
		cin >> a;
		stack.push(a);
	}

	cout << endl << "-----------------------" << endl << endl;

	stack.see();

	cout << "-----------------------" << endl << endl;
	
	for (auto a = stack.begin(); a != stack.end(); a++)
	{
		cout << *a << " ";
	}
	cout << endl << endl << "-----------------------" << endl << endl;

	stack.pop();
	stack.see();

	cout << "-----------------------" << endl << endl;

	cout << stack[1] << endl;

	cout << endl << "-----------------------" << endl << endl;

	Stack<string> StrStack;
	StrStack.push("UEBANISHE");
	StrStack.push("my name is gg and I'm");
	StrStack.push("HI");
	StrStack.see();
	
}
