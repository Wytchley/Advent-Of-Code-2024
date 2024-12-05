#include "Day4.h"
#include "Resources.h"
#include <vector>
#include <string>
#include <iostream>

bool AOCDay4::checkForWordAtPos(const std::vector<std::vector<char>>& wordSearch, const std::string& word, const size_t startRow, const size_t startCol, const int rowDirection, const int colDirection)
{
	for (int i = 0; i < word.length(); ++i) {
		int colToCheck = startCol + (colDirection * i);
		int rowToCheck = startRow + (rowDirection * i);

		// Check if the indexes to check are outside of the wordsearch bounds. If so, return false, the word cannot be found
		if (rowToCheck > wordSearch.size() - 1 || rowToCheck < 0 || colToCheck > wordSearch[0].size() - 1 || colToCheck < 0) {
			return false;
		}

		// Check if the word search location does not contain the expected next character from the word, if so return false as the word cannot be matched
		if (wordSearch[rowToCheck][colToCheck] != word[i]) {
			return false;
		}
	}

	// If no issues were found, then we must have found the word
	return true;
}

unsigned int AOCDay4::countNumberOfWordOccurrences(const std::vector<std::vector<char>>& wordSearch, const std::string& word)
{
	unsigned int total = 0;

	// Loop through each character in the word search
	for (int row = 0; row < wordSearch.size(); ++row) {
		for (int col = 0; col < wordSearch[row].size(); ++col) {

			// For each character look in all combinations of directions (e.g. up [1,0], down [-1,0], right [0,1], diagonalLeftUp [-1,-1] ... etc.)
			for (int rowDir = -1; rowDir <= 1; rowDir++) {
				for (int colDir = -1; colDir <= 1; colDir++) {

					// We can skip a direction of [0,0] as it will just check the same position word.length() number of times
					if (colDir == 0 && rowDir == 0) {
						continue;
					}

					// If the word was found, we'll add a 1 to the total, otherwise we'll add a 0
					total += checkForWordAtPos(wordSearch, word, row, col, rowDir, colDir) ? 1 : 0;
				}
			}
		}
	}

	return total;
}

void AOCDay4::printDay4Solutions(const std::string& filePath)
{
	std::vector<std::vector<char>> wordSearch = Resources::readFileInputTo2DVector(filePath);
	unsigned int occurrences = countNumberOfWordOccurrences(wordSearch, "XMAS");

	std::cout << "XMAS Occurrences: " << occurrences << "\n";
}
