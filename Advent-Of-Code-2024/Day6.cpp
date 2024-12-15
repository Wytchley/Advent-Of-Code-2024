#include "Day6.h"
#include "Resources.h"
#include <stdexcept>
#include <tuple>
#include <vector>
#include <iostream>
#include <filesystem>

size_t AOCDay6::calculateNumUniquePositions(std::vector<std::vector<char>> map, size_t rowPos, size_t colPos, int8_t rowDir, int8_t colDir) {

    size_t nextRowPos = rowPos + rowDir;
    size_t nextColPos = colPos + colDir;

    // Mark the initial position as visited
    map[rowPos][colPos] = 'X';

    // While moving will still result in an in-range position
    while (nextRowPos >= 0 && nextRowPos < map.size() && nextColPos >= 0 && nextColPos < map[nextRowPos].size()) {
        // If the next position is obstructed, rotate 90 degrees clockwise
        if (map[nextRowPos][nextColPos] == '#') {
            std::tuple<int8_t, int8_t> newDir = rotateDirection90Clockwise(rowDir, colDir);
            rowDir = std::get<0>(newDir);
            colDir = std::get<1>(newDir);
        }
        else {
            rowPos += rowDir;
            colPos += colDir;
        }

        // Mark the current position as visited
        map[rowPos][colPos] = 'X';

        nextRowPos = rowPos + rowDir;
        nextColPos = colPos + colDir;
    }

    return countCharOccurrences(map, 'X');
}

size_t AOCDay6::countCharOccurrences(const std::vector<std::vector<char>>& map, char character)
{
    size_t count = 0;

    for (int row = 0; row < map.size(); ++row) {
        for (int col = 0; col < map[row].size(); ++col) {
            if (map[row][col] == character) {
                count++;
            }
        }
    }
    
    return count;
}

std::tuple<size_t, size_t> AOCDay6::getGuardPosition(const std::vector<std::vector<char>>& map) {
    // Stores the location of the guard
    size_t guardRow = 0;
    size_t guardCol = 0;

    // Find the location of the guard
    while (map[guardRow][guardCol] != '^' && map[guardRow][guardCol] != 'v' && map[guardRow][guardCol] != '>' && map[guardRow][guardCol] != '<') {
        if (guardCol < map[guardRow].size() - 1) {
            guardCol++;
        }
        else if (guardRow < map.size()) {
            guardCol = 0;
            guardRow++;
        }
        else {
            // If the guard hasn't been found and we've run out of cells in the grid to search, then the map is invalid as the guard doesn't exist
            throw std::invalid_argument("Invalid map, no initial guard location found.");
        }
    }

    return std::tuple<size_t, size_t>(guardRow, guardCol);
}

std::tuple<int8_t, int8_t> AOCDay6::getDirectionFromGuardChar(char guard) {
    switch (guard) {
        case '^':
            return std::tuple<int8_t, int8_t>(-1, 0);
        case '>':
            return std::tuple<int8_t, int8_t>(0, 1);
        case 'v':
            return std::tuple<int8_t, int8_t>(1, 0);
        case '<':
            return std::tuple<int8_t, int8_t>(0, -1);
    }

    return std::tuple<int8_t, int8_t>(0, 0);
}

std::tuple<int8_t, int8_t> AOCDay6::rotateDirection90Clockwise(int8_t rowDir, int8_t colDir) {
    if (colDir == 0 && rowDir == 1) {
        colDir -= 1;
        rowDir -= 1;
    }
    else if (colDir == 0 && rowDir == -1) {
        colDir += 1;
        rowDir += 1;
    }
    else if (rowDir == 0 && colDir == 1) {
        rowDir += 1;
        colDir -= 1;
    }
    else if (rowDir == 0 && colDir == -1) {
        rowDir -= 1;
        colDir += 1;
    }

    return std::tuple<int8_t, int8_t>(rowDir, colDir);
}

void AOCDay6::printMap(const std::vector<std::vector<char>>& map)
{
    for (int row = 0; row < map.size(); ++row) {
        for (int col = 0; col < map[row].size(); ++col) {
            std::cout << map[row][col];
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void AOCDay6::printDay6Solutions(const std::filesystem::path& filePath) {
    std::vector<std::vector<char>> map = Resources::readFileInputTo2DVector(filePath);
    std::tuple<size_t, size_t> startPos = getGuardPosition(map);
    std::tuple<int8_t, int8_t> startDir = getDirectionFromGuardChar(map[std::get<0>(startPos)][std::get<1>(startPos)]);

    size_t numUniquePositions = calculateNumUniquePositions(map, std::get<0>(startPos), std::get<1>(startPos), std::get<0>(startDir), std::get<1>(startDir));
    std::cout << "Q1. Number of Unique Positions Visited: " << numUniquePositions << "\n";
}
