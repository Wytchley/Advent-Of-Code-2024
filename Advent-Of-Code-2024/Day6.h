#pragma once
#include <vector>
#include <tuple>
#include <string>

namespace AOCDay6
{
	size_t calculateNumUniquePositions(std::vector<std::vector<char>> map, size_t rowPos, size_t colPos, int8_t rowDir, int8_t colDir);

	size_t countCharOccurrences(const std::vector<std::vector<char>>& map, char character);

	std::tuple<size_t, size_t> getGuardPosition(const std::vector<std::vector<char>>& map);

	std::tuple<int8_t, int8_t> getDirectionFromGuardChar(char guard);

	std::tuple<int8_t, int8_t> rotateDirection90Clockwise(int8_t rowDir, int8_t colDir);

	void printMap(const std::vector<std::vector<char>>& map);

	void printDay6Solutions(const std::string& filePath);
};

