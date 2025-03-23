#include <iostream>
using namespace std;

void readLists (int list1[], int list2[]);
int findSimilarity(int list1[], int list2[], int sizeList);

int main() {
    int sizeList = 1000;
    int list1[sizeList], list2[sizeList];

    readLists(list1, list2);

    cout << "The similarity value is: " << 
        findSimilarity(list1, list2, sizeList) << endl;

    return 0;
}

void readLists (int list1[], int list2[]) {
    cout << "Please insert the two lists: " << endl;

    for(size_t i = 0; !cin.eof(); ++i) 
        cin >> list1[i] >> list2[i];
}

int findSimilarity(int list1[], int list2[], int sizeList) {
    int similarity = 0;

    for (size_t i = 0; i < sizeList; ++i) {
        int count = 0;
        for (size_t j = 0; j < sizeList; ++j)
            if(list1[i] == list2[j])
                ++count;

        similarity += list1[i] * count;
    }

    return similarity;
}