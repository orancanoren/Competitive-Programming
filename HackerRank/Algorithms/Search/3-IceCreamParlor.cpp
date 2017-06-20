#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n;
		cin >> m >> n;

		unordered_map<int, int> previousPrices; // key: price | value: ID
		for (int id = 1; id <= n; id++) {
			int price_i;
			cin >> price_i;

			const int complement = m - price_i;
			auto findResult = previousPrices.find(complement);
			if (findResult == previousPrices.end()) {
				previousPrices[price_i] = id;
			}
			else {
				const int otherID = findResult->second;
				const int otherPrice = findResult->first;
				if (otherID > id) {
					cout << id << " " << otherID << endl;
				}
				else {
					cout << otherID << " " << id << endl;
				}
			}
		}
	}
	return 0;
}