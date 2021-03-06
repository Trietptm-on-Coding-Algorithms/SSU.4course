#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


bool isTree(vector<int> &v) {
	return true;
}

bool cmpRev(int a, int b) {
	return a > b;
}

bool isGraph(vector<int> v) {
	int n = v.size();
	int sum = n * 2 - 2;
	while (sum != 0) {
		int to = 1 + v[0];
		sum -= v[0];
		v[0] = 0;
		if (to > n)
			return false;
		for (int j = 1; j < to; j++) {
			if (v[j] == 0)
				return false;
			sum--;
			v[j]--;
		}
		sort(v.begin(), v.end(), cmpRev);
	}
	return true;
}

/*set<vector<int> > generateVecDeg(int n) {
	set<vector<int> > result;
	int edges = n - 1;
	int sum = edges * 2;	//сумм чиселок в векторе
	vector<int> deg(n, 1);
	deg[0] = n - 1;	// [n-1, 1, 1, 1...] пример при n = 6: [5, 1, 1, 1, 1, 1]
	bool stop = false;
	while (!stop) {
		stop = true;
		if (isTree(deg) && isGraph(deg)) {
			result.insert(deg);
		}
		for (int i = n - 1; i >= 0 && stop; i--) {
			for (int j = i; j < n; j++) {
				if (deg[i] > deg[j] + 1) {
					deg[i]--;
					deg[j]++;
					stop = false;
					break;
				}
			}
		}
		sort(deg.begin(), deg.end(), cmpRev);
	}
	return result;
}*/
void generateVecDeg(int pos, vector<int> v, set<vector<int> > &result) {
	while (v[pos] != 1 && pos < v.size() - 1) {
		v[pos]--;
		v[pos + 1]++;
		vector<int> tmp = v;
		sort(tmp.begin(), tmp.end(), cmpRev);
		if (isTree(tmp) && isGraph(tmp)) {
			result.insert(tmp);
		}
		generateVecDeg(pos + 1, v, result);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> deg(n, 1);
	deg[0] = n - 1;
	set<vector<int> > v;

	generateVecDeg(0, deg, v);

	for (vector<int> item : v) {
		for (int num : item) {
			cout << num << " ";
		}
		cout << endl;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}