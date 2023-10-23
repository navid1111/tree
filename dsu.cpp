#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
class DisjointSet
{	vector<int> rank, parent;

public:
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
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
	void unionByRank(int u, int v) {
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if (ulp_v == ulp_u)return;
		if (rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_u] > rank[ulp_v])
			parent[ulp_v] = ulp_u;
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}


	}


};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	DisjointSet ds(7);
	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(4, 5);
	ds.unionByRank(6, 7);
	ds.unionByRank(5, 6);
	// if 3 and 7 same or not
	if (ds.findParent(3) == ds.findParent(7)) {
		cout << "Same\n";
	}
	else cout << "Not same\n";

	ds.unionByRank(3, 7);

	if (ds.findParent(3) == ds.findParent(7)) {
		cout << "Same\n";
	}
	else cout << "Not same\n";


}