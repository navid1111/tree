#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
class DisjointSet
{
public:
	vector<int> size, parent;

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
	void UnionBySize(int u, int v) {
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
int numProvinces(vector<vector<int>>adj, int V) {
	DisjointSet ds(V);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (adj[i][j] == 1)
				ds.UnionBySize(i, j);
		}
	}
	int cnt = 0;
	for (int i = 0; i < V; i++) {
		if (ds.parent[i] == i)cnt++;
	}
	return cnt;
}

int main() {

	int V = 3;
	vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};


	int ans = numProvinces(adj, V);
	cout << "The number of provinces is: " << ans << endl;
	return 0;
}
