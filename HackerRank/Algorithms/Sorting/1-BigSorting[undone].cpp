#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compareStrings(const string & s1, const string & s2) {
	// returns true if s1 <= s2

	if (s1.length() > s2.length()) return false;
	else if (s1.length() < s2.length()) return true;

	// lengths are equal
	for (int i = 0; i < s1.length(); i++) {
		// lexicographic order matches numeric order
		if (s1[i] > s2[i]) return false;
	}
	return true;
}

void sortStrings(vector<string> & arr) {
	// Insertion sort
	for (int i = 1; i < arr.size(); i++) {
		int j = i;
		while (j >= 1 && !compareStrings(arr[j - 1], arr[j])) { // while arr[j - 1] > arr[j]
			swap(arr[j - 1], arr[j]);
			j--;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sortStrings(arr);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}