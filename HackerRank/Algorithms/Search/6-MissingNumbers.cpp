#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

int main() {
	// process the input
	int n, m;
	vector<int> firstList, secondList;
	set<int> numbers;
	int minimum = 0, maximum = 100000; // for cache
	cin >> n;
	firstList.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> firstList[i];
		minimum = min(firstList[i], minimum);
		maximum = max(firstList[i], maximum);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int currentNumber;
		cin >> currentNumber;
		secondList[i] = currentNumber;
		numbers.insert(currentNumber);
	}

	vector<int> cache(n);
	for (int i = 0)
	return 0;
}