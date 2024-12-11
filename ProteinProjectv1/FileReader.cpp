#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Coordinate {
    double x, y, z;
};

int main() {
    ifstream inputFile("coordinates.txt");
    if (!inputFile) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<Coordinate> coordinates;
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Coordinate coord;
        if (iss >> coord.x >> coord.y >> coord.z) {
            coordinates.push_back(coord);
        }
    }

    inputFile.close();
    for (size_t i = 0; i < coordinates.size() - 1; ++i) {
        cout << fixed << setprecision(3);
        cout << "(" << coordinates[i].x << ", " << coordinates[i].y << ", " << coordinates[i].z << ") - ";
        cout << "(" << coordinates[i + 1].x << ", " << coordinates[i + 1].y << ", " << coordinates[i + 1].z << ")" << endl;
    }

    return 0;
}
