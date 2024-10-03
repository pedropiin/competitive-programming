#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXDIGITS 7
#define INF 1e9

vector<int> digits;

int get_digits(int n) {
	digits.clear();

	int num_digits = 0;
	while (n > 9) {
		int temp = n / 10;
		digits.push_back(n - (temp * 10));
		num_digits++;
		n /= 10;
	}

	digits[num_digits] = n;
	num_digits++;
	
	return num_digits;
}
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll count = 0;
	while (n > 9) {
		int num_digits = get_digits(n);
		int max_digit = digits[0];
		for (int i = 1; i < num_digits; i++) {
			if (digits[i] > max_digit) {
				max_digit = digits[i];
			}
		}
		n -= max_digit;
		count++;
	}
	
	count++;
	cout << count << endl;
	return 0;
}
