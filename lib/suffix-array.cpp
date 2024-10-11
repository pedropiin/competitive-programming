#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> sort_cyclic_shifts(string &s) {
	int n = s.size();
	int ascii_size = 256;

	vector<int> p(n);
	vector<int> c(n);
	vector<int> count(max(ascii_size, n), 0);

	for (int i = 0; i < n; i++) {
		count[s[i]]++;
	}
	for (int i = 1; i < ascii_size; i++) {
		count[i] += count[i - 1];
	}
	for (int i = 0; i < n; i++) {
		p[--count[s[i]]] = i;
	}
	
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]]) {
			classes++;
		}
		c[p[i]] = classes - 1;
	}

	vector<int> pn(n);
	vector<int> cn(n);
	for (int h = 0; (1 << h) < n; ++h) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0) {
				pn[i] += n;
			}
		}
		
		fill(count.begin(), count.begin() + classes, 0);
		for (int i = 0; i < n;i++) {
			count[c[pn[i]]]++;
		}
		for (int i = 1; i < classes; i++) {
			count[i] += count[i - 1];
		}
		for (int i = (n - 1); i >= 0; i--) {
			p[--count[c[pn[i]]]] = pn[i];
		}

		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
			if (cur != prev) {
				++classes;
			}
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}
			
vector<int> suffix_array(string &s) {
	s += "$";
	vector<int> sorted_shifts = sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	return 0;
}
