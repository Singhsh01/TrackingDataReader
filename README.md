# TrackingDataReader
This repository contains a C++ program designed to read, process, and analyze 3D tracking data stored in CSV files. The primary functionality includes extracting positional data from CSV files, calculating statistical metrics such as the mean position and jitter, and computing the Euclidean distance between two sets of tracking coordinates.


Key Features:
CSV Parsing: The program reads tracking data stored in CSV format, where each row represents a timestamped set of 3D coordinates (X, Y, Z) along with other metadata.
Statistical Analysis: The program calculates:
Mean Position: Computes the average X, Y, and Z coordinates across all recorded points.
Jitter Calculation: Measures the variance in positional data by computing the average deviation from the mean position, providing insights into the stability of the tracking data.


Euclidean Distance Calculation: The program calculates the Euclidean distance between two sets of tracking data, providing a quantitative measure of the spatial relationship between the two datasets.

Extensibility: This project can be extended to support additional analyses, such as velocity or acceleration calculations, or to handle more complex CSV formats.
Use Case: This tool is ideal for applications involving motion tracking, such as robotics, virtual reality (VR), augmented reality (AR), and other fields where precise positional data is crucial. It provides a foundation for analyzing and comparing movement data across different timeframes or experimental conditions.



# TrackingDataReader

This project reads and processes tracking data from CSV files. The program calculates the mean and jitter for each set of tracking data and computes the Euclidean distance between two sets of data.

## How to Use

1. Clone the repository:
git clone https://github.com/your-username/TrackingDataReader.git


2. Build the project:
cmake .. cmake --build .


3. Run the program:
./build/TrackingDataReader


## Files

- `NavigationDataTestData-Pos1.csv` and `NavigationDataTestData-Pos2.csv`: CSV files containing tracking data.

