#pragma once
#include <string>
#include <vector>
#include <filesystem>

namespace AOCDay1 {

	/// <summary>
    /// Reads the file at the provided path to populate the two vector arguments with integers representing the IDs present on two lists of historically significant locations where the Chief Historian might be. 
    /// </summary>
    /// <param name="filePath">The location of the file containing the two location ID lists</param>
    /// <param name="firstLocationList">A vector to store the location IDs of the first list in</param>
    /// <param name="secondLocationList">A vector to store the location IDs of the second list in</param>
	void readInputFile(const std::filesystem::path& filePath, std::vector<int>& firstLocationList, std::vector<int>& secondLocationList);

    /// <summary>
    /// Calculates a distance between two lists of location IDs where the 'distance' is defined as the difference in value of pairings of IDs from the first and second list in order when the two lists
    /// are ordered. (e.g. list1: [4, 3, 1], list2: [2, 5, 1] would generate pairings of ([1,1], [3,2], [4,5]) and therefore the distance would be (1 - 1) + (3 - 2) + (5 - 4) = 2. 
    /// Note: vectors do not have to be sorted when passed as an input, this function will sort them into ascending order when calculating.
    /// </summary>
    /// <param name="firstLocationList">A vector representing the first list of location IDs</param>
    /// <param name="secondLocationList">A vector representing the second list of location IDs</param>
    /// <returns></returns>
	int calculateDistanceBetweenLocationLists(std::vector<int>& firstLocationList, std::vector<int>& secondLocationList);

	/// <summary>
	/// Calculates a similarity score between two location ID vectors. A similarity score is calculated by multiplying the location ID in the first list of location IDs by the number of occurrences
    /// of that location ID in the second list.
	/// </summary>
	/// <param name="firstLocationList">A vector representing the first list of location IDs</param>
	/// <param name="secondLocationList">A vector representing the second list of location IDs</param>
	/// <returns></returns>
	int calculateSimilarity(const std::vector<int>& firstLocationList, const std::vector<int>& secondLocationList);

	/// <summary>
    /// Calls all necessary methods to calculate results for both questions in Advent of Code 2024: Day 1 and prints the output.
    /// </summary>
    /// <param name="filePath">The path to the file that contains day 1's input</param>
    void printDay1Solutions(const std::filesystem::path& filePath);
}
