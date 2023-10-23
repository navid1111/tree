#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
class DisjointSet
{	vector<int> size, parent;

public:
	DisjointSet(int n) {
		size.resize(n + 1, 1);
		parent.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;

		}
	}
	int findParent(int node) {
		if (node == parent[node])
			return node;
		return parent[node] = findParent(parent[node]);

	}
	void UnionByRank(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if (ulp_v == ulp_u)return;
		if (size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else if (size[ulp_u] > size[ulp_v]) {
			parent[ulp_v] = ulp_u;

			size[ulp_u] += size[ulp_v];
		}
		else {
			parent[ulp_v] = ulp_u;
			size[ulp_u] = size[ulp_u] + size[ulp_v];
		}


	}


};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	DisjointSet ds(7);
	ds.UnionByRank(1, 2);
	ds.UnionByRank(2, 3);
	ds.UnionByRank(4, 5);
	ds.UnionByRank(6, 7);
	ds.UnionByRank(5, 6);
	// if 3 and 7 same or not
	if (ds.findParent(3) == ds.findParent(7)) {
		cout << "Same\n";
	}
	else cout << "Not same\n";

	ds.UnionByRank(3, 7);

	if (ds.findParent(3) == ds.findParent(7)) {
		cout << "Same\n";
	}
	else cout << "Not same\n";


}