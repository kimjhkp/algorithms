#include <iostream>

void insertion(int a[], int size) {
    for (int j=1;j < size;++j) {
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        };
        a[i + 1] = key;
    };
};

// O(n^2) since there are 'for' and 'while' loops (triggered in avg/worst-case scenarios)

int main () {
    int ary[] = {45,3,1,123,5};

    insertion(ary, 5);

    for (int i = 0; i < 5; ++i) {
        std::cout << ary[i] << ",";
    };
}