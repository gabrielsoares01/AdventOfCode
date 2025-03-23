#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

int sumSafeReports(vector<vector<int>> reports);
bool safeDistance(vector<int> levels);
bool pattern(vector<int> levels);
bool checkSafety(vector<int> levels);

int main() {
    ifstream file ("./input/data.txt");
    string inputs;
    vector<vector<int>> reports;

    if (!file.is_open()) {
        std::cerr << "Not able to open the file!" << std::endl;
        return 1;
    }

    while(getline(file, inputs)) {
        stringstream newStream(inputs);
        vector<int> levels;
        int num;

        while(newStream >> num)
            levels.push_back(num);
        reports.push_back(levels);
    }

    cout << "Safe reports: " << sumSafeReports(reports) << endl;
    
    file.close();
}

int sumSafeReports(vector<vector<int>> reports) {
    int count = 0;
    
    for(const auto levels : reports)
        if(checkSafety(levels)) {
            ++count;
        }

    return count;
}

bool checkSafety(vector<int> levels) {
    return pattern(levels) && safeDistance(levels);
}

bool pattern(vector<int> levels) {
    int a = levels[0], b = levels[1];

    return (is_sorted(levels.begin(), levels.end()) ||
            is_sorted(levels.begin(), levels.end(), greater<int>()));
}

bool safeDistance(vector<int> levels) {
    int distance;

    for(size_t i = 0; i < levels.size() - 1; ++i) {
        distance = abs(levels[i] - levels[i + 1]);
        if(distance > 3 || distance == 0)
            return false;
    }

    return true;
}