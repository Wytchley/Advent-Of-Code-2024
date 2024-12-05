#pragma once
#include <string>
#include <vector>

namespace AOCDay3
{
	/// <summary>
	/// Reads the contents of the input file for this question into a string
	/// </summary>
	/// <param name="filePath">The path to the file that contains day 3's input</param>
	/// <returns>A string of containing the contents of the file at the given path</returns>
	std::string readFileInputToStr(const std::string& filePath);

	/// <summary>
	/// Given a string, this method will filter out all "mul(x,y)" operations and return them as a vector of strings. If ignoreDoAndDontInstructions
	/// is set to false, this method will respect all "do()" and "don't()" instructions in the string and will not include any mul operations between
	/// after a "don't()" and before a "do()".
	/// </summary>
	/// <param name="str">The string to extract mul operations from</param>
	/// <param name="ignoreDoAndDontInstructions">Whether or not do() and don't() operations should be ignored when extracting valid mul operations</param>
	/// <returns>A vector of valid mul operation strings</returns>
	std::vector<std::string> filterStringForValidMulOperations(const std::string& str, bool ignoreDoAndDontInstructions=true);

	/// <summary>
	/// Given a vector of mul operation strings in the format "mul(x,y)", this function will multiply the x and y of each
	/// mul operation and sum the results to return a total. (e.g. a vector containing "mul(a,b)" and "mul(x,y)" would return
	/// the result of (a*b + x*y)
	/// </summary>
	/// <param name="mulOperations">The mul operations to compute</param>
	/// <returns>The sum of all mul operations</returns>
	unsigned long computeMulOperationsSum(const std::vector<std::string>& mulOperations);

	/// <summary>
	/// Calls all necessary methods to calculate results for both questions in Advent of Code 2024: Day 3 and prints the output.
	/// </summary>
	/// <param name="filePath">The path to the file that contains day 2's input</param>
	void printDay3Solutions(const std::string& filePath);
};

