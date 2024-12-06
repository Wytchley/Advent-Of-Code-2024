#pragma once
#include <string>
#include <map>
#include <vector>

namespace AOCDay5
{
	void readInputFile(const std::string& filePath, std::map<int, std::vector<int>>& rules, std::vector<std::vector<int>>& updates);

	bool checkUpdateIsCorrect(const std::vector<int>& update, const std::map<int, std::vector<int>>& rules);

	unsigned int calculateSumOfCorrectUpdatesMiddlePages(const std::vector<std::vector<int>>& updates, const std::map<int, std::vector<int>>& rules);

	void printDay5Solutions(const std::string& filePath);
};

