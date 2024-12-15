#pragma once
#include <string>
#include <map>
#include <vector>
#include <filesystem>

namespace AOCDay5
{
	void readInputFile(const std::filesystem::path& filePath, std::map<int, std::vector<int>>& rules, std::vector<std::vector<int>>& updates);

	bool checkUpdateIsCorrect(const std::vector<int>& update, const std::map<int, std::vector<int>>& rules);

	void fixUpdate(std::vector<int>& update, const std::map<int, std::vector<int>>& rules);

	unsigned int calculateSumOfCorrectUpdatesMiddlePages(std::vector<std::vector<int>>& updates, const std::map<int, std::vector<int>>& rules, bool fixIncorrectUpdates = false);

	void printDay5Solutions(const std::filesystem::path& filePath);
};

