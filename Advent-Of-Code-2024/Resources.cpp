#include "Resources.h"
#include <string>
#include <fstream>
#include <filesystem>

std::string Resources::readFileInputToStr(const std::filesystem::path& filePath)
{
	std::string fileContent = std::string();

	std::ifstream fileInput = std::ifstream(filePath);
	std::string line;

	// Read each line and append it to the file string
	while (std::getline(fileInput, line)) {
		fileContent += line;
	}

	return fileContent;
}

std::vector<std::vector<char>> Resources::readFileInputTo2DVector(const std::filesystem::path& filePath)
{
	std::vector<std::vector<char>> fileContent;

	std::ifstream fileInput = std::ifstream(filePath);
	std::string line;

	// Read each line and append it to the file string
	while (std::getline(fileInput, line)) {
		std::vector<char> row;

		for (char c : line) {
			row.push_back(c);
		}

		fileContent.push_back(row);
	}

	return fileContent;
}
