#include "Reader.h"
#include <iostream>

int main() {
    Reader reader1, reader2;

    // Read first file
    std::cout << "Reading NavigationDataTestData-Pos1.csv\n";
    if (!reader1.readFile("NavigationDataTestData-Pos1.csv")) {
        return 1;  // Error opening the file
    }

    // Calculate mean and jitter for first file
    auto mean1 = reader1.calculateMean();
    std::cout << "Mean Position for Pos1: X=" << mean1.x << ", Y=" << mean1.y << ", Z=" << mean1.z << "\n";
    double jitter1 = reader1.calculateJitter();
    std::cout << "Jitter for Pos1: " << jitter1 << "\n";

    // Read second file
    std::cout << "\nReading NavigationDataTestData-Pos2.csv\n";
    if (!reader2.readFile("NavigationDataTestData-Pos2.csv")) {
        return 1;  // Error opening the file
    }

    // Calculate mean and jitter for second file
    auto mean2 = reader2.calculateMean();
    std::cout << "Mean Position for Pos2: X=" << mean2.x << ", Y=" << mean2.y << ", Z=" << mean2.z << "\n";
    double jitter2 = reader2.calculateJitter();
    std::cout << "Jitter for Pos2: " << jitter2 << "\n";

    // Calculate Euclidean distance between Pos1 and Pos2
    double distance = reader1.calculateDistance(mean1, mean2);
    std::cout << "\nEuclidean Distance between Pos1 and Pos2: " << distance << " cm\n";

    return 0;
}
