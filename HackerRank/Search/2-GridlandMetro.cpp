#include <iostream>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;

struct Interval {
	Interval(int left, int right) : left(left), right(right) { }
	int left;
	int right;
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	// Keep a hashmap of linked lists
	// Each linked list stores intervals for train tracks for specific row
	unordered_map<int, list<Interval>> hashmap;
	// Keep a RBT storing identifiers of rows with at least one train track
	set<int> occupiedRowNumbers;

	for (int i = 0; i < k; i++) {
		int rowNumber, leftBound, rightBound;
		cin >> rowNumber >> leftBound >> rightBound;
		occupiedRowNumbers.insert(rowNumber);

		// Insert the current input to the hashmap and check for overlapping
		// intervals while doing so. If there exists an overlapping pair, merge them
		auto rowBucket = hashmap.find(rowNumber);
		if (rowBucket == hashmap.end()) {
			list<Interval> initialList;
			initialList.push_back(Interval(leftBound, rightBound));
			hashmap[rowNumber] = initialList;
		}
		else { // hashmap has stored a list in current bucket
			list<Interval> & currentList = rowBucket->second;
			auto listIter = currentList.begin();
			while (listIter != currentList.end() && (rightBound < listIter->left || leftBound > listIter->right)) {
				listIter++;
			}
			if (listIter != currentList.end()) { // we have overlapping intervals
				if (listIter->right < rightBound) {
					listIter->right = rightBound; // expand right bound
				}
				if (listIter->left > leftBound) {
					listIter->left = leftBound; // expand left bound
				}
			}
			else { // no overlap
				currentList.push_back(Interval(leftBound, rightBound));
			}
		}
	}

	// Now we have all disjoint intervals for each row. We can use basic math to obtain unoccupied cells
	long long freeCells = ((long long) n)*((long long) m); // initially
	while (!occupiedRowNumbers.empty()) {
		// we've kept the identifiers of occupied rows, hence we know for sure that find operation on
		// the hashmap will be successful for a given key provided from the set
		auto currentRowNumber = occupiedRowNumbers.begin();
		auto currentBucket = hashmap.find(*currentRowNumber);

		long long occupiedCells = 0;
		list<Interval> & currentList = currentBucket->second;
		auto iter = currentList.begin();
		while (iter != currentList.end()) {
			occupiedCells += (iter->right) - (iter->left) + 1;
			iter++;
		}
		freeCells -= occupiedCells;
		occupiedRowNumbers.erase(currentRowNumber);
	}
	cout << freeCells;

	return 0;
}