#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct yearPrice {
	int year;
	long price;

	bool operator < (const yearPrice & rhs) {
		return this->price < rhs.price;
	}
};

int main() {
	// Get inputs
	int n;
	cin >> n;
	vector<yearPrice> prices(n);
	for (int i = 0; i < n; i++) {
		yearPrice input;
		cin >> input.price;
		input.year = i;
		prices[i] = input;
	}

	// Sort the array
	sort(prices.begin(), prices.end());

	// For each adjacent pair, search the minimum loss
	long minLoss = prices[1].price - prices[0].price;
	for (int i = 2; i < n; i++) {
		yearPrice earlier, later;
		if (prices[i].year < prices[i - 1].year) {
			earlier = prices[i];
			later = prices[i - 1];
		}
		else {
			earlier = prices[i - 1];
			later = prices[i];
		}

		if (earlier.price - later.price > 0) {
			minLoss = min(minLoss, earlier.price - later.price);
		}
	}

	cout << minLoss;

	return 0;
}