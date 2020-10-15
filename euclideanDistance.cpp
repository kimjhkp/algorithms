#include<iostream>
#include<vector>
#include<math.h>

double distsum = 0;

struct cache {
    int x;
    int y;
};

std::vector<cache> vault;

//std::map -> key - value pair

double dist(std::vector<double>& s, int m, std::vector<double>& t, int n) {

    if (m == 0 && n == 0) {
        distsum += (std::pow(s[m] - t[n],2));
        return distsum;
    }
    else {
        distsum += (std::pow(s[m] - t[n],2));
        return dist(s, m - 1, t, n - 1);
    }
};

double euclidean(std::vector<double>&s, int m, std::vector<double>&t, int n) {
    if (m == n) {
        dist(s, m, t, n);
    }
    else {
        std::cerr << "Lengths differ between two vectors" << "\n";
    }
}

int main () {



}