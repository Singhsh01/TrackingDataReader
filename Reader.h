#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

// Define a simple structure to hold coordinates
struct Coordinate {
    double x, y, z;
};

class Reader {
public:
    bool readFile(const std::string& filename);   // Method to read CSV files
    std::vector<std::string> parseLine(const std::string& line, char delimiter = ',');  // Helper function to split a line
    Coordinate calculateMean();  // Method to calculate the mean position
    double calculateJitter();    // Method to calculate the jitter (standard deviation)
    double calculateDistance(const Coordinate& p1, const Coordinate& p2);  // Method to calculate Euclidean distance

private:
    std::vector<Coordinate> coordinates;  // Store the coordinates for processing
};

#endif // READER_H
