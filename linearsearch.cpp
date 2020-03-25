#include <iostream>

int linearsearch(int a[], int size, int key) {  
    for(int i=0; i < size; ++i) {  
        if(a[i] == key) {
            return i;
        };
        if(a[i] != key && i == size) {
            return 0;
        };
    };
};

int main () {
    int ary[] = {45,3,1,123,5};

    linearsearch(ary, 5, 3);
}