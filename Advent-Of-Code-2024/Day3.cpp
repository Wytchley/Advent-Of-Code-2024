#include "Day3.h"
#include "Resources.h"
#include <regex>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> AOCDay3::filterStringForValidMulOperations(const std::string& str, bool ignoreDoAndDontInstructions)
{
	// Stores all the mul operations found in the string
	std::vector<std::string> mulOperations;

	// Regex expression matches any 'mul(' followed by any number, followed by ',' followed by any positive number, followed by ')'
	// Therefore, it would match any variation of the following: "mul(1,1)", "mul(20,10)", "mul(300,400", ... etc.
	// Or it matches the exact strings "do()" and "don't()"
	std::regex regexExpr = std::regex("(mul\\([0-9]+,[0-9]+\\))|(do\\(\\))|(don't\\(\\))");
	std::smatch match;

	// Keeps track of whether or not mul operations are enabled by a do() or implicitly at the start of the string
	// or if they have been disabled by a don't()
	bool isMulEnabled = true;

	// Iterate over the string finding all the mul operations and adding them to the vector
	std::string::const_iterator it = std::string::const_iterator(str.begin());
	while (std::regex_search(it, str.end(), match, regexExpr)) {

		// If the match is a do() or don't(), enable or disable mul operations respectively
		if (match[0] == "do()") {
			isMulEnabled = true;
		}
		else if (match[0] == "don't()") {
			isMulEnabled = false;
		}
		// If do() and don't() instructions are set to be ignored, add the mul operation.
		// Or, if they are not set to be ignored but mul is currently enabled by a previous do(),
		// then add the mul operation
		else if (ignoreDoAndDontInstructions || isMulEnabled) {
			mulOperations.push_back(match[0]);
		}
		
		// Set the iterator the position of the first char in the string that follows the matched mul operation
		it = match.suffix().first;
	}

	return mulOperations;
}

unsigned long AOCDay3::computeMulOperationsSum(const std::vector<std::string>& mulOperations)
{
	unsigned long total = 0;

	for (const std::string mulOperation : mulOperations) {
		// Regex expression matches positive number of any size
		std::regex regexExpr = std::regex("[0-9]+");
		std::smatch numMatch;

		// Iterate through the mul operation string to extract the first and second numbers, multiply them and add the result to the total 
		std::string::const_iterator it = std::string::const_iterator(mulOperation.begin());
		while (std::regex_search(it, mulOperation.end(), numMatch, regexExpr)) {
			// Convert the first number retrieved to an int ready for multiplication
			int num1 = std::stoi(numMatch[0]);

			// Set the iterator the position of the first char in the string that follows the matched number
			it = numMatch.suffix().first;
			
			// Get the second number to multiply and convert it to an int
			std::regex_search(it, mulOperation.end(), numMatch, regexExpr);
			int num2 = std::stoi(numMatch[0]);

			// Set the iterator the position of the first char in the string that follows the matched number
			it = numMatch.suffix().first;

			// Add the result of the mul operation to the total
			total += (num1 * num2);
		}
	}

	return total;
}

void AOCDay3::printDay3Solutions(const std::string& filePath)
{
	std::cout << "\t[Day 3]\n";
	
	// Read in the corrupt memory string and calculate the sum of the valid mul operations
	std::string corruptMemoryStr = Resources::readFileInputToStr(filePath);
	// Ignore all any of the Do() or Don't() instructions for Part I (i.e. don't interpret them)
	std::vector<std::string> mulOperations = filterStringForValidMulOperations(corruptMemoryStr, true);
	unsigned long mulOperationsSum = computeMulOperationsSum(mulOperations);

	std::cout << "Q1. Mul Operations Sum: " << mulOperationsSum << "\n";

	// For Part II, calculate the mul operations sum again, but this time do interpret the Do() and Don't() instructions
	mulOperations = filterStringForValidMulOperations(corruptMemoryStr, false);
	mulOperationsSum = computeMulOperationsSum(mulOperations);

	std::cout << "Q2. Mul Operations Sum When Interpreting Do() and Don't(): " << mulOperationsSum << "\n";
}
