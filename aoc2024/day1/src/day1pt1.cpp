#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void readLists (int list1[], int list2[]);

int main() {
    int var1, var2, sum = 0, sizeList1 = 1000, sizeList2 = 1000;
    int list1 [sizeList1], list2 [sizeList2];

    readLists(list1, list2);
    
    sort(list1, list1 + sizeList1); 
    sort(list2, list2 + sizeList2);

    for(size_t j = 0; j < sizeList1; ++j) {
    sum += abs(list1[j] - list2[j]);
    }

    cout << "\nThe sum of the distances is: " << sum << endl;
    return 0;
}

void readLists (int list1[], int list2[]) {
    cout << "Please insert the two lists: " << endl;

    for(size_t i = 0; !cin.eof(); ++i) {
    cin >> list1[i] >> list2[i];
    }
}