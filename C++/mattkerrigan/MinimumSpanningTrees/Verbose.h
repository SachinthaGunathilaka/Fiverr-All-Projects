#pragma once
#include <string>
#include <iostream>

namespace verbose
{
	// A global flag to enable or disable verbose output
	// The implementation is defined in MinimumSpanningTrees.cpp so that multiple files can access this flag
	extern bool enable;

	// Write a verbose message to standard output if enabled
	inline void write(std::string msg)
	{
		if (enable) std::cout << msg << std::endl;
	}
}
