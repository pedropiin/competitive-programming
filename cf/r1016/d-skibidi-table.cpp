#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> powers(62);

typedef struct {
	ll row;
	ll col;
} coord;

void solve_first_query(coord query_coord, pair<ll, ll> interval, pair<coord, coord> coord_interval) {
	cout << "entered with query_coord == (" << query_coord.row << ", " << query_coord.col << ") AND coord_interval == [(" << coord_interval.first.row << ", " << coord_interval.first.col << "), (" << coord_interval.second.row << ", " << coord_interval.second.col << ")]" << endl;
	if (interval.second - interval.first == 3) {
		if (query_coord.row == coord_interval.first.row && query_coord.col == coord_interval.first.col) {
			cout << interval.first << endl;
			return;
		} else if (query_coord.row == coord_interval.second.row && query_coord.col == coord_interval.second.col) {
			cout << interval.first + 1 << endl;
			return;
		} else if (query_coord.row == coord_interval.first.row && query_coord.col == coord_interval.second.col) {
			cout << interval.first + 2 << endl;
			return;
		} else if (query_coord.row == coord_interval.second.row && query_coord.col == coord_interval.first.col) {
			cout << interval.second << endl;
			return;
		}
	}

	ll mid_row = coord_interval.first.row + (coord_interval.second.row - coord_interval.first.row)/2;
	ll mid_row_plus = mid_row + 1;
	ll mid_col = coord_interval.first.col + (coord_interval.second.col - coord_interval.first.col)/2;
	ll mid_col_plus = mid_col+1;

	coord t1, t2;
	t1 = coord_interval.first;
	t2 = {mid_row, mid_col};
	pair<coord, coord> top_left_coord = make_pair(t1, t2);

	t1 = {mid_row_plus, mid_col_plus};
	t2 = coord_interval.second;
	pair<coord, coord> bot_right_coord = make_pair(t1, t2);

	t1 = {mid_row_plus, coord_interval.first.col};
	t2 = {coord_interval.second.row, mid_col};
	pair<coord, coord> bot_left_coord = make_pair(t1, t2);

	t1 = {coord_interval.first.row, mid_col_plus};
	t2 = {mid_row, coord_interval.second.col};
	pair<coord, coord> top_right_coord = make_pair(t1, t2);

	ll sub_window_size = (interval.second - interval.first + 1)/4;
	if (query_coord.row >= top_left_coord.first.row && query_coord.row <= top_left_coord.second.row
		&& query_coord.col >= top_left_coord.first.col && query_coord.col <= top_left_coord.second.col) {
		
		pair<ll, ll> new_interval = {interval.first, interval.first + sub_window_size - 1};
		solve_first_query(query_coord, new_interval, top_left_coord);
	} else if (query_coord.row >= bot_right_coord.first.row && query_coord.row <= bot_right_coord.second.row 
		&& query_coord.col >= bot_right_coord.first.col && query_coord.col <= bot_right_coord.second.col) {
		
		pair<ll, ll> new_interval = {interval.first + sub_window_size, interval.first + 2*sub_window_size - 1};
		solve_first_query(query_coord, new_interval, bot_right_coord);
	} else if (query_coord.row >= bot_left_coord.first.row && query_coord.row <= bot_left_coord.second.row 
		&& query_coord.col >= bot_left_coord.first.col && query_coord.col <= bot_left_coord.second.col) {
		
		pair<ll, ll> new_interval = {interval.second - 2*sub_window_size + 1, interval.second - sub_window_size};
		solve_first_query(query_coord, new_interval, top_right_coord);
	} else if (query_coord.row >= top_right_coord.first.row && query_coord.row <= top_right_coord.second.row 
		&& query_coord.col >= top_right_coord.first.col && query_coord.col <= top_right_coord.second.col) {
		
		pair<ll, ll> new_interval = {interval.second - sub_window_size + 1, interval.second};
		solve_first_query(query_coord, new_interval, top_right_coord);
	}
	cout << "leaving with interval over analysis == (" << interval.first << ", " << interval.second << ")" << endl;
}

void solve_second_query(ll d, pair<ll, ll> interval, pair<coord, coord> coord_interval) {
	if (interval.second - interval.first == 3) {
		int mod = d % 4;
		int x = coord_interval.first.row;
		int y = coord_interval.first.col;
		switch (mod) {
			case 1:
				cout << x << " " << y << endl;
				return;
			case 2:
				cout << x+1 << " " << y+1 << endl;
				return;
			case 3:
				cout << x+1 << " " << y << endl;
				return;
			case 0:
				cout << x << " " << y+1 << endl;
				return;
		}
	}

	ll n_minus_two = (interval.second - interval.first + 1) >> 2;
	ll n_minus_one = (interval.second - interval.first + 1) >> 1;

	ll mid_row = coord_interval.first.row + (coord_interval.second.row - coord_interval.first.row)/2;
	ll mid_row_plus = mid_row + 1;
	ll mid_col = coord_interval.first.col + (coord_interval.second.col - coord_interval.first.col)/2;
	ll mid_col_plus = mid_col+1;
	
	pair<ll, ll> top_left = make_pair(interval.first, interval.first + n_minus_two - 1);
	pair<ll, ll> bot_right = make_pair(interval.first + n_minus_two, interval.first + n_minus_one - 1);
	pair<ll, ll> bot_left = make_pair(interval.first + n_minus_one, interval.first + n_minus_one + n_minus_two -1);
	pair<ll, ll> top_right = make_pair(interval.first + n_minus_one + n_minus_two, interval.second);
	
	coord t1, t2;
	if (d >= top_left.first && d <= top_left.second) {
		t1 = coord_interval.first;
		t2 = {mid_row, mid_col};
		pair<coord, coord> top_left_coord = make_pair(t1, t2);
		solve_second_query(d, top_left, top_left_coord);
	} else if (d >= bot_right.first && d <= bot_right.second) {
		t1 = {mid_row_plus, mid_col_plus};
		t2 = coord_interval.second;
		pair<coord, coord> bot_right_coord = make_pair(t1, t2);
		solve_second_query(d, bot_right, bot_right_coord);
	} else if (d >= bot_left.first && d <= bot_left.second) {
		t1 = {mid_row_plus, coord_interval.first.col};
		t2 = {coord_interval.second.row, mid_col};
		pair<coord, coord> bot_left_coord = make_pair(t1, t2);
		solve_second_query(d, bot_left, bot_left_coord);
	} else {
		t1 = {coord_interval.first.row, mid_col_plus};
		t2 = {mid_row, coord_interval.second.col};
		pair<coord, coord> top_right_coord = make_pair(t1, t2);
		solve_second_query(d, top_right, top_right_coord);
	}
}

void solve() {
	int n; cin >> n;
	int q; cin >> q;

	pair<ll, ll> default_interval = make_pair(1, powers[2*n]);
	coord t = {1, 1}; coord t2 = {powers[n], powers[n]};
	pair<coord, coord> default_coord = make_pair(t, t2);
	while(q--) {
		string s; cin >> s;
		if (s == "->") {
			ll x, y; cin >> x >> y;
			coord query_coord = {x, y};
			solve_first_query(query_coord, default_interval, default_coord);
		} else if (s == "<-") {
			ll d; cin >> d;
			solve_second_query(d, default_interval, default_coord);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	powers[0] = 1;
	for (int i = 1; i < 62; i++) 
		powers[i] = (ll)(powers[i-1] << 1);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
