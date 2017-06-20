#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> //std::abs
#include <utility> // std::pair
#include <list>

using namespace std;

bool comparePair(const pair<int, int> & left, const pair<int, int> & right) {
	return left.second < right.first;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());
	int minDiff = abs(A[0] - A[1]);
	list< pair<int, int> > pairs;
	for (int i = 0; i <= (N - 2); i++) {
		pair<int, int> currentPair(A[i], A[i + 1]);
		int currentDiff = abs(currentPair.first - currentPair.second);
		if (currentDiff < minDiff) {
			minDiff = currentDiff;
			pairs.clear();
			pairs.push_back(currentPair);
		}
		else if (currentDiff == minDiff) {
			pairs.push_back(currentPair);
		}
	}

	pairs.sort(comparePair);
	while (!pairs.empty()) {
		cout << pairs.front().first << " " << pairs.front().second << " ";
		pairs.pop_front();
	}

	return 0;
}