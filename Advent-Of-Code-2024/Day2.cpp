#include "Day2.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

std::vector<std::vector<int>> AOCDay2::readInputFile(const std::filesystem::path& filePath) {
	std::vector<std::vector<int>> reports;

	std::ifstream inputFile = std::ifstream(filePath);
	std::string reportLine;
	
	// Read lines of file while eof is not reached
	while (std::getline(inputFile, reportLine)) {
		std::vector<int> report;

		std::string numberStr;
		std::stringstream sStream(reportLine);

		// Read the numbers of the line into the numberStr one by one and add them to the report
		while (sStream >> numberStr) {
			report.push_back(std::stoi(numberStr));
		}
		
		// Add the report to the vector of all reports
		reports.push_back(report);
	}

	return reports;
}

bool AOCDay2::checkReportIsSafe(const std::vector<int>& report) {
	// If a report has 0 or 1 levels then it must be safe as it does not violate any of the conditions for being 'safe'
	if (report.size() < 2) {
		return true;
	}

	// Determine if the report is in ascending or descending order based on the values of the first to levels
	bool isAscending = true;
	if (report[0] > report[1]) {
		isAscending = false;
	}

	// Iterate across the report in pairs checking that each pair meets the required conditions
	std::vector<int>::const_iterator it;
	for (it = report.begin()+1; it != report.end(); ++it) {
		int currNum = *it;
		int prevNum = *(it - 1);
		int difference = abs(currNum - prevNum);
		
		// If the current level is less than the previous level when it should be ascending
		// or the current level is greater than the previous level when it should be descending
		// (i.e. ascending / descending rule is violated), we can return false as the report is not safe.
		if ((isAscending && currNum < prevNum) || (!isAscending && currNum > prevNum)) {
			return false;
		}
		// Otherwise, if the levels differ by more than 3 or are identical, they are also violate the safety rules
		else if (difference > 3 || difference == 0) {
			return false;
		}
	}

	// If we have not found any violations of safety rules, we will reach the end and can return true (i.e. the report is safe)
	return true;
}

// TODO: Find a neater way to implement this
bool AOCDay2::checkReportIsSafeUsingProblemDampener(const std::vector<int>& report, size_t problemDampenerTolerance, size_t numRemoved) {
	// If the number of already removed elements is greater than the number allowed (this will be 1 for part II), then this is not a safe solutiom, return false
	if (numRemoved > problemDampenerTolerance) {
		return false;
	}
	// Otherwise, as with part I, a solution with 0 or 1 elements is safe
	else if (report.size() < 2) {
		return true;
	}

	// Determine if the report is in ascending or descending order based on the values of the first to levels
	bool isAscending = true;
	if (report[0] > report[1]) {
		isAscending = false;
	}

	// Iterate across the report in pairs checking that each pair meets the required conditions
	std::vector<int>::const_iterator it;
	for (it = report.begin(); it != report.end() - 1; ++it) {
		int currNum = *it;
		int nextNum = *(it + 1);
		int difference = abs(currNum - nextNum);

		if ((isAscending && nextNum <= currNum) || (!isAscending && nextNum >= currNum) || difference > 3 || difference == 0) {
			// Create two copies of the report, one without the current number and one without the next number
			std::vector<int> currentNumRemoved = copyVectorOmmitingElement(report, it);
			std::vector<int> nextNumRemoved = copyVectorOmmitingElement(report, (it + 1));

			// Check if these now satisfy the safety requirements or are invalid due to too many removals
			bool output = (checkReportIsSafeUsingProblemDampener(currentNumRemoved, problemDampenerTolerance, numRemoved + 1) || checkReportIsSafeUsingProblemDampener(nextNumRemoved, problemDampenerTolerance, numRemoved + 1));

			// If there is a previous element, check that too
			if (it != report.begin()) {
				std::vector<int> prevNumRemoved = copyVectorOmmitingElement(report, (it - 1));

				// If removing either the previous element, current element or next element was valid and resulted in a safe report, then this will return true.
				// If it was invalid (too many removals) or was still unsafe, this will return false.
				return (output || checkReportIsSafeUsingProblemDampener(prevNumRemoved, problemDampenerTolerance, numRemoved + 1));
			}
			
			// If removing either the current element or next element was valid and resulted in a safe report, then this will return true.
		    // If it was invalid (too many removals) or was still unsafe, this will return false.
			return output;
		}
	}

	// If no issues were found, we can safely say the report was safe and return true
	return true;
}

std::vector<int> AOCDay2::copyVectorOmmitingElement(const std::vector<int>& originalVec, const std::vector<int>::const_iterator& elementToOmit) {
	std::vector<int> vecCopy;
	std::vector<int>::const_iterator copyIt;

	// Copy vecToCopy into vecCopy but do not include the element that the given iterator points to
	for (copyIt = originalVec.begin(); copyIt != originalVec.end(); ++copyIt) {
		if (copyIt != elementToOmit) {
			vecCopy.push_back(*copyIt);
		}
	}

	return vecCopy;
}

int AOCDay2::countSafeReports(const std::vector<std::vector<int>>& reports, size_t problemDampenerTolerance) {
	int numberSafe = 0;

	// Loop across the reports checking for safety. If the report is safe, increment numberSafe and proceed to the next report in the vector
	for (std::vector<int> report : reports) {
		if (problemDampenerTolerance == 0 && checkReportIsSafe(report)) {
			numberSafe++;
		}
		else if (problemDampenerTolerance > 0 && checkReportIsSafeUsingProblemDampener(report, problemDampenerTolerance)) {
			numberSafe++;
		}
	}

	return numberSafe;
}

void AOCDay2::printDay2Solutions(const std::filesystem::path& filePath) {
	std::cout << "\t[Day 2]\n";

	std::vector<std::vector<int>> reports = readInputFile(filePath);

	// Calculate number of safe reports if no bad levels are allowed
	int numSafe = countSafeReports(reports);
	std::cout << "Q1. Safe Reports: " << numSafe << "\n";

	// Calculate number of safe reports if we allow for 1 bad level to be removed
	int numSafeWithProblemDampener = countSafeReports(reports, 1);
	std::cout << "Q2. Safe Reports Using Problem Dampener: " << numSafeWithProblemDampener << "\n";
}
