

#pragma once
#include <string>

// Parses any options passed on the command line
struct Options
{
	// The path to the graph
	std::string TestFilePath = "";

	// Whether or not the help menu was requested
	bool help = false;
	// Whether or not errors were encountered while parsing arguments
	bool errors = false;
	// Whether or not to enable verbose mode
	bool verboseEnable = false;

	// Any errors encountered while parsing arguments
	std::string errorMessage = "";

	explicit Options(int argc, char* argv[])
	{
		for (auto i = 1; i < argc; i++)
		{
			std::string arg = argv[i];

			if(arg == "-h" || arg == "--help")
			{
				help = true;
			}
			else if(arg == "-f" || arg == "--file")
			{
				if(i < argc-1)
				{
					TestFilePath = argv[++i];
				}
				else
				{
					errors = true;
					errorMessage += "\t* ";
					errorMessage += arg;
					errorMessage += ": Not enough parameters (must be <string>)\n";
				}
			}
			else if(arg == "-v" || arg == "--verbose")
			{
				verboseEnable = true;
			}
			else
			{
				errors = true;
				errorMessage += "\t* ";
				errorMessage += arg;
				errorMessage += ": unrecognized argument\n";
			}
		}
	}
};
