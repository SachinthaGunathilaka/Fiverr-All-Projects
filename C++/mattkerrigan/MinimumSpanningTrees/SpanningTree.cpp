/*
 * SpanningTree.cpp - Implementation of a minimum spanning tree
 *
 * Built for EECS2510 - Nonlinear Data Structures
 *	at The University of Toledo, Spring 2016
*/
#include "stdafx.h"
#include <iostream>

#include "SpanningTree.h"


SpanningTree::SpanningTree()
{
	// Store the edges as a minimum priority queue sorted first by the first vertex alphabetically,
	// then by the second vertex alphabetically. This lets us print the tree without having to sort
	// the edges later
	edges = new MinPriorityQueue<VertexPair>([](VertexPair* lhs, VertexPair* rhs)
	{
		auto firstKey = lhs->A->Name.compare(rhs->A->Name);
		return firstKey == 0 ? lhs->B->Name.compare(rhs->B->Name) : firstKey;
	}, 16);
}


SpanningTree::~SpanningTree()
{
	delete edges;
}

// Add the specified edge to the tree. Does not perform any validation
void SpanningTree::accept(VertexPair* edge) const
{
	edges->enqueue(edge);
}

// Print the total weight and all edges taken to standard output
void SpanningTree::print() const
{
	auto totalWeight = 0.0;
	edges->each([&](VertexPair* e) { totalWeight += e->EdgeWeight; });

	std::cout << totalWeight << std::endl;
	
	while(edges->Size() > 0)
	{
		auto edge = edges->dequeue();
		std::cout << edge->A->Name << "-" << edge->B->Name << ": " << edge->EdgeWeight << std::endl;
	}
}
