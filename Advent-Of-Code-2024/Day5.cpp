#include "Day5.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>

void AOCDay5::readInputFile(const std::string& filePath, std::map<int, std::vector<int>>& rules, std::vector<std::vector<int>>& updates) {
	bool readingRules = true;

	std::ifstream inputFile = std::ifstream(filePath);
	std::string line;

	while (std::getline(inputFile, line)) {

		if (line == "") {
			readingRules = false;
			continue;
		}

		std::stringstream sStream = std::stringstream(line);

		if (readingRules) {
			std::string firstToUpdateStr;
			std::string secondToUpdateStr;
			

			std::getline(sStream, firstToUpdateStr, '|');
			std::getline(sStream, secondToUpdateStr, '|');

			int firstToUpdate = std::stoi(firstToUpdateStr);
			int secondToUpdate = std::stoi(secondToUpdateStr);

			if (rules.count(firstToUpdate) == 0) {
				rules[firstToUpdate] = std::vector<int>();
			}

			rules[firstToUpdate].push_back(secondToUpdate);

		}
		else {
			std::vector<int> update;

			std::string numStr;
			while (std::getline(sStream, numStr, ',')) {
				update.push_back(std::stoi(numStr));
			}

			updates.push_back(update);
		}
	}
}

bool AOCDay5::checkUpdateIsCorrect(const std::vector<int>& update, const std::map<int, std::vector<int>>& rules) {
	std::map<int, bool> seen;

	std::vector<int>::const_iterator it;

	for (it = update.begin(); it != update.end(); ++it) {

		int page = *it;
		seen[page] = true;
		
		if (rules.find(page) == rules.end()) {
			continue;
		}

		for (const int pagesAppearingAfter : rules.at(page)) {
			if (seen.count(pagesAppearingAfter) > 0) {
				return false;
			}
		}
	}

	return true;
}

void AOCDay5::fixUpdate(std::vector<int>& update, const std::map<int, std::vector<int>>& rules)
{

}

unsigned int AOCDay5::calculateSumOfCorrectUpdatesMiddlePages(std::vector<std::vector<int>>& updates, const std::map<int, std::vector<int>>& rules, bool fixIncorrectUpdates) {
	unsigned int total = 0;

	for (std::vector<int>& update : updates) {
		if (checkUpdateIsCorrect(update, rules)) {
			int midIndex = (update.size() - 1) / 2;
			total += update[midIndex];
		}
		else if (fixIncorrectUpdates) {
			fixUpdate(update, rules);
			int midIndex = (update.size() - 1) / 2;
			total += update[midIndex];
		}
	}

	return total;
}

void AOCDay5::printDay5Solutions(const std::string& filePath) {
	std::vector<std::vector<int>> updates;
	std::map<int, std::vector<int>> rules;
	
	readInputFile(filePath, rules, updates);
	unsigned int sumOfCorrectUpdates = calculateSumOfCorrectUpdatesMiddlePages(updates, rules);

	std::cout << "Sum of Correct Updates' Middle Pages: " << sumOfCorrectUpdates << "\n";
}
