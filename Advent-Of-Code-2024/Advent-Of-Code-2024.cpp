/*
     _       _                 _            __     ___          _                      
    /_\   __| |_   _____ _ __ | |_    ___  / _|   / __\___   __| | ___                 
   //_\\ / _` \ \ / / _ \ '_ \| __|  / _ \| |_   / /  / _ \ / _` |/ _ \                
  /  _  \ (_| |\ V /  __/ | | | |_  | (_) |  _| / /__| (_) | (_| |  __/                
  \_/ \_/\__,_| \_/ \___|_| |_|\__|  \___/|_|   \____/\___/ \__,_|\___|                
                                                                                     
                       ____   ___ ____  _  _                                                          
                      |___ \ / _ \___ \| || |                                                         
                        __) | | | |__) | || |_                                                        
                       / __/| |_| / __/|__   _|                                                       
                      |_____|\___/_____|  |_|       
*/

#include "Day1.h";
#include <iostream>
#include <vector>

void day1(std::string filePath);

int main() {
	std::cout << "-- Advent of Code 2024 --\n\n";
}


/// <summary>
/// Calls all necessary methods to calculate results for both questions in Advent of Code 2024: Day 1.
/// </summary>
/// <param name="filePath">The path to the file that contains day 1's input</param>
void day1(std::string filePath) {
	std::cout << "\t[Day 1]\n";

	std::vector<int> firstLocationList;
	std::vector<int> secondLocationList;

	AOCDay1::readInputFile(filePath, firstLocationList, secondLocationList);
	int diff = AOCDay1::calculateDistanceBetweenLocationLists(firstLocationList, secondLocationList);
	//std::cout << "Q1. Distance: " << diff << "\n";

	int similarity = AOCDay1::calculateSimilarity(firstLocationList, secondLocationList);
	//std::cout << "Q2. Similarity: " << similarity << "\n";
}