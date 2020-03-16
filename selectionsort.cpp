#include <iostream>

void selectionsort(int a[], int size){
    for (int j=0; j < size - 1; ++j){
        for (int i=j+1; i < size; ++i){
            if (a[j] > a[i]){
                int smaller = a[i];
                a[i] = a[j];
                a[j] = smaller;
            }; 
        };
    };
    
    for (int s=0; s < size; ++s){
        std::cout << a[s] << "\n";
    }
};

int main (){
    int b[] = {3,67,32,1,2}; // {1,67,32,3,2}

    selectionsort(b, 5);
}

