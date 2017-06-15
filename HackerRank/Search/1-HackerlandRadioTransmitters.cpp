#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getNextUncoveredHouse(const vector<int> houses, int low, int k) {
	// houses[low] is an uncovered house, we'll find the farmost
	// house that'll cover house[low] and return its the index of that house if it exists
	// otherwise return -1 to indicate the list is exhausted

	// Two scenarios:
	//      1) There exists a house other than <low> that can reach out to <low>
	//      2) Such a house does not exist -> transmitter on <low> is a must
	int candidate = low;
	int max_position = houses[low] + k;
	int arraySize = houses.size();
	while ((candidate + 1) < arraySize && houses[candidate + 1] <= max_position) {
		candidate++;
	}
	// we've found the house to put the transmitter on, now we have to find 
	// the house such that the transmitter doesn't cover beyond it
	int lastCoveredHouse = candidate;
	int lastCoveredPosition = houses[candidate] + k;
	while (((lastCoveredHouse + 1) < arraySize && houses[lastCoveredHouse + 1] <= lastCoveredPosition)) {
		lastCoveredHouse++;
	}
	if (lastCoveredHouse == arraySize - 1) { // the list is exhausted
		return -1;
	}
	else {
		return (lastCoveredHouse + 1); // return the next uncovered house
	}
}

int main() {
	int n, k;
	vector<int> houses;
	cin >> n >> k;
	houses.resize(n); // keep array of size n to keep location of houses
	auto iterator = houses.begin(); // could've written iterator = houses as well;
	for (int i = 0; i < n; i++) {
		cin >> *iterator;
		iterator++;
	}
	sort(houses.begin(), houses.end()); // O(nlog(n)) -> dominates

										// we have the location of houses
										// using a greedy approach, let's put a transmitter on top of a house
										// such that the first house in the array is covered, then we'll perform the
										// same for the remaining houses (we'll have a sub-problem)
	int transmitter_count = 0;
	int firstUncoveredHouse = 0;
	while (firstUncoveredHouse != -1) { // O(n)
		firstUncoveredHouse = getNextUncoveredHouse(houses, firstUncoveredHouse, k);
		transmitter_count++;
	}
	cout << transmitter_count;
}