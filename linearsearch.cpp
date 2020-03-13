#include <iostream>

int linearsearch(int a[], int size, int key){
    for(int i=0; i < size; ++i){
        if(a[i] == key){
            return i;
        };
        if(a[i] != key && i == size){
            return 0;
        };
    };
};

int main(){
    int b[5] = {1,2,3,4,5};

    std::cout << linearsearch(b, 5, 2) << "\n";
}