#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;



static bool cmp(pair<int,node*> p, pair<int,node*> q) {
	return p.first < q.first;
}

vector<int> topView(Node *root) {
	int hd; // horizontal distance
	vector<pair<int,node*>> top_view;
	unordered_map<int,bool> visited;
	queue<pair<int,node*>> q;
	q.push(make_pair(0, root));
	while(q.size()) {
		root = q.front().second;
		hd = q.front().first;
		if(!visited[hd]) {
			top_view.push_back(q.front());
			visited[hd] = true;
		}
		q.pop();
		if(root -> left) q.push(make_pair(hd - 1, root -> left));
		if(root -> right) q.push(make_pair(hd + 1, root -> right));
	}
	sort(top_view.begin(), top_view.end(), cmp);
	vector<int> v;
	for(int i = 0; i < top_view.size(); i++)
		v.push_back(top_view[i].second -> data);
	return v;
}
