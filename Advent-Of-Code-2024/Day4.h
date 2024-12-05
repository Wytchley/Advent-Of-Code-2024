#pragma once
#include <string>
#include <vector>

namespace AOCDay4
{
	bool checkForWordAtPos(const std::vector<std::vector<char>>& wordSearch, const std::string& word, const size_t startRow, const size_t startCol, const int rowDirection, const int colDirection);

	bool checkForXMas(const std::vector<std::vector<char>>& wordSearch, const size_t row, const size_t col);

	unsigned int countNumberOfXMasOccurrences(const std::vector<std::vector<char>>& wordSearch);

	unsigned int countNumberOfWordOccurrences(const std::vector<std::vector<char>>& wordSearch, const std::string& word);

	void printDay4Solutions(const std::string& filePath);
};

