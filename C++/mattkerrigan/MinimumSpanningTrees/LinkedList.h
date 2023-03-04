#pragma once
#include <functional>

struct None{};

// A node in a generic linked list
template <typename T>
struct Node
{
	explicit Node(T* p) : Payload(p), Next(nullptr){}
	~Node()
	{
		if (Next != nullptr) delete Next;
	}

	// The payload of the node
	const T* Payload;
	// The next node in the list
	Node<T>* Next;
};

// A generic linked list
template <typename T>
class LinkedList
{
public:
	explicit LinkedList(){}
	~LinkedList()
	{
		if (root != nullptr) delete root;
	}

	// Add the specified element to the list
	void add(T* key)
	{
		auto n = new Node<T>(key);
		n->Next = root;
		root = n;
		count++;
	}

	// Add all elements in the specified linked list to this list
	void addAll(LinkedList<T> other)
	{
		other.each([&](T* t) { add(t); });
	}

	// Returns true iff the specified element is in this list
	bool Contains(T* element)
	{
		Node<T>* candidate = root;

		while(candidate != nullptr)
		{
			if(candidate->Payload == element)
			{
				return true;
			}
			candidate = candidate->Next;
		}

		return false;
	}

	// Applys the specified function to every element in this list
	void each(std::function<void(T*)> func)
	{
		Node<T>* candidate = root;

		while(candidate != nullptr)
		{
			func(const_cast<T*>(candidate->Payload));
			candidate = candidate->Next;
		}
	}

	// Returns the number of elements this list contains
	size_t Count() const { return count; }
private:
	Node<T>* root = nullptr;

	size_t count = 0;
};
