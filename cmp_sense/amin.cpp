#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <fstream>
#include <array>
#include <list>
#include <functional>

#define mt make_tuple
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define rt return 0;
#define elif else if
#define len(v) ((int)v.size())


using namespace std;

char string_in_buffer[(int)260];


void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) { 
	scanf("%c", &x); 
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}

template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}

template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}

void fast_print(const int &x) { printf("%d", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const char &x) { printf("%c", x); };
void fast_print(const string &x) { printf("%s", x.c_str());}

template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}

template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(" ");
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print("\n");
		fast_print(v[i]);
	}
}



using namespace std;


namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;

	void precall_print() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
} //namespace smart_io


template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}

template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef vector<int> vi;
	typedef pair<int, int> pii;
	typedef vector<vector<pair<int, int>>> vvpii;
	typedef vector<vector<pair<bool, int>>> vvpbi;
}

namespace numbers_operation {
	template<class T>
	T floor_mod(T a, T b) {
		if (a % b == 0) return 0;
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;

#define print    \
smart_io::precall_print(); \
cout,

#define scan cin,

vector<vector<pii>> vertices;
vector<vector<int>> pref_min;
vector<vector<int>> prev2p;
vector<pii> pref;
vector<int> height;

void dfs_height(int v = 0, int h = 0) {
	height[v] = h;
	for (pii sub : vertices[v]) {
		dfs_height(sub.first, h + 1);
	}
}


void dfs_pref_min(int v = 0) {
	if (v == 0) {
		for (int k = 0; k < len(pref_min[v]); k++) {
			pref_min[v][k] = 1e7;
		}
	} else {
		pref_min[v][0] = pref[v].second;
		for (int k = 1; k < len(pref_min[v]); k++) {
			pref_min[v][k] = min(pref_min[v][k - 1], pref_min[prev2p[v][k - 1]][k - 1]);
		}
	}
}

void dfs_prev2p(int v = 0, int prev = 0) {
	prev2p[v][0] = prev;

	for (int k = 1; k < len(prev2p[v]); k++) {
		prev2p[v][k] = prev2p[prev2p[v][k - 1]][k - 1];
	}

	for (pii sub : vertices[v]) {
		dfs_prev2p(sub.first, v);
	}
}

int query(int v, int u) {

}




signed main(signed argc, char *argv[]) {
	int n;
	scan n;
	vertices.resize(n);
	pref_min.resize(n, vector<int>(25, 0));

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scan x, y;
		pref[i] = { x - 1, y };
		vertices[x - 1].pb({ i, y });
	}

	dfs_height();

	int cnt_q;
	scan cnt_q;



	for (int i = 0; i < cnt_q; i++) {
		
	}
}