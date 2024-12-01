#include "Reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>  // For sqrt and pow

bool Reader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return false;
    }

    std::string line;
    // Skip the header line if needed
    std::getline(file, line);  

    while (std::getline(file, line)) {
        auto fields = parseLine(line, ';');  // Using ';' delimiter
        if (fields.size() >= 10) {  // Make sure there are enough columns (e.g., 10)
            try {
                // Extract X, Y, Z coordinates from the appropriate columns (index 3, 4, 5)
                double x = std::stod(fields[3]);  // X coordinate
                double y = std::stod(fields[4]);  // Y coordinate
                double z = std::stod(fields[5]);  // Z coordinate

                coordinates.push_back({x, y, z});
                std::cout << "X: " << x << ", Y: " << y << ", Z: " << z << "\n";
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << " - " << e.what() << "\n";
            }
        }
    }
    file.close();
    return true;
}

std::vector<std::string> Reader::parseLine(const std::string& line, char delimiter) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, delimiter)) {
        fields.push_back(field);
    }
    return fields;
}

Coordinate Reader::calculateMean() {
    double sumX = 0, sumY = 0, sumZ = 0;
    for (const auto& coord : coordinates) {
        sumX += coord.x;
        sumY += coord.y;
        sumZ += coord.z;
    }
    int count = coordinates.size();
    return {sumX / count, sumY / count, sumZ / count};
}

double Reader::calculateJitter() {
    Coordinate mean = calculateMean();
    double sumSquareDistances = 0;
    for (const auto& coord : coordinates) {
        double dx = coord.x - mean.x;
        double dy = coord.y - mean.y;
        double dz = coord.z - mean.z;
        sumSquareDistances += dx * dx + dy * dy + dz * dz;
    }
    return std::sqrt(sumSquareDistances / coordinates.size());
}

double Reader::calculateDistance(const Coordinate& p1, const Coordinate& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2) + std::pow(p2.z - p1.z, 2));
}
