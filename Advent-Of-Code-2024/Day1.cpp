#include "Day1.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>


void AOCDay1::readInputFile(const std::string& filePath, std::vector<int>& firstLocationList, std::vector<int>& secondLocationList)
{
	std::ifstream locationsFile(filePath);
	std::string num1Str;
	std::string num2Str;

	// Attempt to read in a value for the first list (left hand side of the file) until the file has been fully read
	while (std::getline(locationsFile, num1Str, ' ')) {
		// If we managed to read a first number we can read a second number as the two lists are expected to contain the same number of location IDs
		std::getline(locationsFile, num2Str);
		// Remove the whitespace from the second number
		num2Str.erase(std::remove(num2Str.begin(), num2Str.end(), ' '), num2Str.end());
		
		// Populate the two vectors with the location IDs
		firstLocationList.push_back(std::stoi(num1Str));
		secondLocationList.push_back(std::stoi(num2Str));
	}

	locationsFile.close();
}


int AOCDay1::calculateDistanceBetweenLocationLists(std::vector<int>& firstLocationList, std::vector<int>& secondLocationList)
{
	// TODO: Implement own version of merge sort for this - just for fun
	// Sort both vectors into ascending order
	std::sort(firstLocationList.begin(), firstLocationList.end(), [](const int& x, const int& y) { return x < y; });
	std::sort(secondLocationList.begin(), secondLocationList.end(), [](const int& x, const int& y) { return x < y; });

	// Calculate distance between elements of both vectors at the same index
	int totalDistance = 0;
	for (int i = 0; i < firstLocationList.size(); ++i) {
		totalDistance += abs(firstLocationList[i] - secondLocationList[i]);
	}

	return totalDistance;
}

int AOCDay1::calculateSimilarity(const std::vector<int>& firstLocationList, const std::vector<int>& secondLocationList) {
	// Loop through each location ID in list 2, storing the number of occurrences of each location ID in a map
	std::map<int, int> secondListOccurrences;
	for (int i = 0; i < secondLocationList.size(); ++i) {
		int num = secondLocationList[i];
		
		// If the key doesn't already exist, create it with a value of 1
		if (secondListOccurrences.count(num) == 0) {
			secondListOccurrences[num] = 1;
		}
		// Otherwise, increment the number of occurrences
		else {
			secondListOccurrences[num] += 1;
		}
	}

	// Calculate the similarity between the two lists by multiplying the location ID in the first list by the number of occurrences of that ID in the second list
	int similarity = 0;
	for (int i = 0; i < firstLocationList.size(); ++i) {
		int num = firstLocationList[i];

		// If the second list contained some number of occurrences of the ID in list 1 then add to the similarity score
		if (secondListOccurrences.count(num) == 1) {
			similarity += secondListOccurrences[num] * num;
		}
	}

	return similarity;
}

