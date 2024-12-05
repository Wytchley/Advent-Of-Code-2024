#pragma once
#include <string>
#include <vector>

/// <summary>
/// More generic implementations of things are held in the resources namespace.
/// This might include generically loading files data etc.
/// More task-specific implementations belong in their respective AOCDay namespace
/// </summary>
namespace Resources
{
	/// <summary>
	/// Reads the contents of the input file for this question into a string
	/// </summary>
	/// <param name="filePath">The path to the file that contains an input</param>
	/// <returns>A string of containing the contents of the file at the given path</returns>
	std::string readFileInputToStr(const std::string& filePath);

	std::vector<std::vector<char>> readFileInputTo2DVector(const std::string& filePath);
};

