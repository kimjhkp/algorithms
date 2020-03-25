#include<iostream>

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // creating tmp arrays and copy elements
    int tmp1[n1];
    int tmp2[n2];

    for (int i=0; i < n1; ++i) {
        tmp1[i] = a[p + i];
    };
    for (int ii=0; ii < n2; ++ii) {
        tmp2[ii] = a[q + ii + 1];
    };

    int i = 0; 
    int j = 0; 
    int k = p; 

    while (i < n1 && j < n2) { 
        if (tmp1[i] <= tmp2[j]) { 
            a[k] = tmp1[i]; 
            i++; 
        } 
        else { 
            a[k] = tmp2[j]; 
            j++; 
        } 
        k++; 
    };

    // there can be left-overs, e.g. if left array index reaches maximum, this loop finishes leaving behind an element
    // in the right array without being copied
    while (i < n1) { 
        a[k] = tmp1[i]; 
        i++; 
        k++; 
    }; 

    while (j < n2) { 
        a[k] = tmp2[j]; 
        j++; 
        k++; 
    }; 
};

void mergesort(int a[], int p, int r) {

    if(p < r) {
        int q = p + (r - p) / 2;

        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    };
};

// n log(n) complexity
// merging step takes 'n' and there are log2(n) leaves 
int main() {
    int ary[] = {1,8,3,12,5,4};

    mergesort(ary, 0, 5);

    for (int i=0; i < 6; ++i) {
        std::cout << ary[i] << " " << ",";
    };
};
