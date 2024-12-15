#pragma once
#include <vector>
#include <string>
#include <filesystem>

namespace AOCDay2
{
	/// <summary>
	/// Reads the file at the provided path to create a vector of report vectors (a vector of reports from the Red-Nosed reactor
	/// at the Red-Nosed Reindeer nuclear fusion/fission plant).
	/// </summary>
	/// <param name="filePath">The location of the file containing the reactor reports</param>
	/// <returns>A vector of reports</returns>
	std::vector<std::vector<int>> readInputFile(const std::filesystem::path& path);

	/// <summary>
	/// Checks that a given report from the Red-Nosed reactor is considered 'safe' under the following conditions:
	/// 1. all elements are either all increasing or all decreasing.
	/// 2. Any two adjacent levels differ by at least one and at most three.
	/// </summary>
	/// <param name="report">The report from Red-Nosed reactor to check for safety</param>
	/// <returns>true if the report is safe, false otherwise.</returns>
	bool checkReportIsSafe(const std::vector<int>& report);

	/// <summary>
	/// Checks that a given report from the Red-Nosed reactor is considered 'safe' under the following conditions:
	/// 1. all elements are either all increasing or all decreasing.
	/// 2. Any two adjacent levels differ by at least one and at most three.
	/// However, in this implementation, it will also check if a report would be safe if some number of levels (elements) from the report
	/// were to be removed specified by the parameter 'problemDampenerTolerance'.
	/// </summary>
	/// <param name="report">The report to check for safety</param>
	/// <param name="numRemoved">The number of elements removed from the initial report (this should be 0 when first called)</param>
	/// <param name="problemDampenerTolerance">The amount of levels (elements) that can be removed from the initial report to make a safe report (the question requires this to be set to 1)</param>
	/// <returns></returns>
	bool checkReportIsSafeUsingProblemDampener(const std::vector<int>& report, size_t problemDampenerTolerance, size_t numRemoved = 0);

	/// <summary>
	/// Copies a vector but omits the value held at the same location as the iterator passed to it.
	/// </summary>
	/// <param name="vecToCopy">The vector to copy</param>
	/// <param name="elementToOmit">The iterator hold the pointer to the element to be omitted</param>
	/// <returns>A copy of the vector with the desired element omitted</returns>
	std::vector<int> copyVectorOmmitingElement(const std::vector<int>& originalVec, const std::vector<int>::const_iterator& elementToOmit);

	/// <summary>
	/// Given a vector of reports, this function will check the safety of each one and return how many of them were found to be safe.
	/// </summary>
	/// <param name="reports">The vector of reports to check</param>
	/// <param name="problemDampenerTolerance">The tolerance that the problem dampener should use (i.e. how many levels are allowed to be removed -> this should be set to 1 for question 2 and 0 for question 1)</param>
	/// <returns>The number of safe reports found in the vector of reports</returns>
	int countSafeReports(const std::vector<std::vector<int>>& reports, size_t problemDampenerTolerance = 0);

	/// <summary>
	/// Calls all necessary methods to calculate results for both questions in Advent of Code 2024: Day 2 and prints the output.
	/// </summary>
	/// <param name="filePath">The path to the file that contains day 2's input</param>
	void printDay2Solutions(const std::filesystem::path& filePath);
};

