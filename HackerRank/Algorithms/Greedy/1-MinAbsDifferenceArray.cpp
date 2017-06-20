#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int minDifference = A[1] - A[0]; // n >= 2 so no bad access
	for (int i = 2; i <= n - 1; i++) {
		minDifference = min(A[i] - A[i - 1], minDifference);
	}
	cout << minDifference;

	return 0;
}