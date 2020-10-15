#include<iostream>
#include<vector>

// This is an algorithm to find the minimum number operations needed to make two character arrays same
// It can be solved recursively as we can divide the original problem into multiple sub-problems

// In the end, we are computing the distance D(i,j) for all i = (0 < i < n) and j = (0 < j < m)
// The distance here is defined by number of operations (a.k.a costs) needed
// e.g) E, I -> minimum cost is 2
// e.g) E, IN -> minimum cost is 3
// e.g) E, INT -> minimum cost is 4

// There are three cost functions - substitution, deletion, and insertion
// Everytime we do a comparison, the minimum cost out of these three cost functions is selected

// We could also create a local cache to store already calculated costs

int recurse(std::vector<char>& s, int m, std::vector<char>& t, int n) {
	// Is is a recursive function that performs three operations
	//
	int result = 0;
	int subcost = 0;
	int delcost = 0;
	int inscost = 0;

	if (m == 0) {
		return n;
		}
	else if (n == 0) {
		return m;
		}
	else if (s[m - 1] == t[n - 1]) { // If the letters are same, move to next positions
		result = recurse(s, m - 1, t, n - 1);
		}
	else {
		subcost = 1 + recurse(s, m - 1, t, n - 1);
		delcost = 1 + recurse(s, m - 1, t, n);
		inscost = 1 + recurse(s, m, t, n - 1);
		
		result = std::min(std::min(subcost, delcost), inscost);
		}
	return result;
};

int computedistance(std::vector<char>& s, int m, std::vector<char>& t, int n) {
	
	return recurse(s, m, t, n);
};

int main(){

	std::vector<char> first = {'a',' ','c','a','t','!'};
	std::vector<char> second = {'t','h','e',' ','c','a','t','s','!'};

	int distance = 0;
	distance = computedistance(first, 3, second, 4);

	std::cout << distance << "\n";
}
