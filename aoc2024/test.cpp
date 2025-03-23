#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{4, 3, 4};

    v.erase(v.begin() + 1);

    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << endl;

    return 0;
}