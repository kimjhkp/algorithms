#include <iostream>

void insertion(int a[], int size){
    for (int j=1;j < size;++j){
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key){
            a[i + 1] = a[i];
            i--;
        };
        a[i + 1] = key;
    };

    for (int i = 0; i < size; ++i){
        std::cout << a[i] << "\n";
    }
};

int main(){
    int b[5] = {10, 4, 15, 6, 8};

    insertion(b, 5);
}