#pragma once
#include "WeightedGraph.h"
#include "../MinPriorityQueue.h"

// A wrapper class for keeping track of the edges that compose a minimum spanning tree
class SpanningTree
{
public:
	SpanningTree();
	~SpanningTree();

	// Add the specified edge to the MST. No validation is performed
	void accept(VertexPair* edge) const;

	// Print the edges that compose this MST to standard out
	void print() const;

private:
	MinPriorityQueue<VertexPair>* edges;
};

