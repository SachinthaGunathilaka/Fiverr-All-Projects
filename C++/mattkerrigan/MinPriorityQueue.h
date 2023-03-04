#pragma once

#include "Edge.h"

// Priority Queue Class
class MinPriorityQueue
{
public:
    // Constructor
	MinPriorityQueue(size_t initialCapacity)
		:size(0), capacity(initialCapacity)
	{
		elements = new Edge *[capacity + 1]{ nullptr };
	}

    // Destructor
	~MinPriorityQueue()
	{
		delete[] elements;
	}

	// Add the specified element to the queue
	void enqueue( Edge * element)
	{
		if (size == capacity-1) grow(2 * capacity);

		elements[++size] = element;
		auto i = size;
		while(i > 1 && (elements[parentOf(i)]->getWeight() > elements[i]->getWeight()))
		{
			swap(elements[i], elements[parentOf(i)]);
			i = parentOf(i);
		}
	}

	// Remove and return the minimum element from the queue
	Edge * dequeue()
	{
		if (size == 0) throw std::underflow_error("Nothing in the heap");

		auto min = elements[1];
		
		elements[1] = elements[size];
		elements[size--] = nullptr;
		minHeapify(1);

		return min;
	}

	// Increases the capacity of the queue. The new capacity must be greater than the previous capacity
	void grow(size_t s)
	{
		if (s <= capacity) throw std::runtime_error("New capacity must be greater than current capacity");

		Edge ** newElements = new Edge *[s];
		for(auto i = 0; i <= capacity; i++)
		{
			newElements[i] = elements[i];
			elements[i] = nullptr;
		}

		delete[] elements;
		elements = newElements;
		capacity = s;
	}

	// Returns true iff the queue contains no elements
	bool isEmpty() const { return size == 0; }

	// Returns the number of elements in the queue
	size_t Size() const	{ return size; }
	// Returns the maximum number of elements in the queue
	size_t Capacity() const	{ return capacity; }
private:

	size_t size;
	size_t capacity;
	Edge ** elements;

	// Returns the index of the parent of the element at the specified index
	static size_t parentOf(size_t index) { return floor(index / 2); }
	// Returns the index of the left child of the element at the specified index
	static size_t leftOf(size_t index) { return 2 * index; }
	// Returns the index of the right child of the element at the specified index
	static size_t rightOf(size_t index) { return 2 * index + 1; }


    void swap(Edge *& a, Edge *& b)
    {
        Edge* c = b;
        b = a;
        a = c;
    }

	// Ensures that the subtree at the specified index is a min-heap
	void minHeapify(size_t index)
	{
		auto l = leftOf(index);
		auto r = rightOf(index);
		size_t smallest = 0;

		if ( l <= size && (elements[l]->getWeight() < elements[index]->getWeight()))
		{
			smallest = l;
		}
		else
		{
			smallest = index;
		}

		if ( r <= size && elements[r]->getWeight() < elements[smallest]->getWeight())
		{
			smallest = r;
		}

		if (smallest != index)
		{
			swap(elements[index], elements[smallest]);
			minHeapify(smallest);
		}
	}
};
