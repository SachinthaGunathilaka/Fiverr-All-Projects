#pragma once
#include "WeightedGraph.h"

// A wrapper around a standard vertex that includes a pointer to the parent vertex
// and the weight of the branch taken to get from the parent vertex to here. This
// is used when calculating the minimum spanning tree using Prim's algorithm
struct PrimVertex : Vertex
{
	explicit PrimVertex(Vertex* v) : Vertex(v->ID, v->Name), QKey(INT64_MAX), pi(nullptr) {}

	bool operator==(const PrimVertex& rhs) const { return rhs.Name == Name; }

	// The weight of the branch taken to get to this vertex, used as
	// the key in the minimum priority queue
	int64_t QKey;

	// The parent vertex
	PrimVertex* pi;
};
