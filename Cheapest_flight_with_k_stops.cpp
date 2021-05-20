/*

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

#include <iostream>


using namespace std;


class Solution {
	public:
		int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
			vector<pair<int, int>> adj[n];
			for(int i= 0; i< flights.size(); i++) {
				adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
			}

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > minHeap;
        minHeap.push({0, {src,0}});

        set<string> visited;       // must mark visited to solve the TLE issue

        while(!minHeap.empty()) {
            int cost= minHeap.top().first;
            int ver= minHeap.top().second.first;
            int stops= minHeap.top().second.second;
            minHeap.pop();

            visited.insert(to_string(ver)+"&"+to_string(stops));

            if(ver == dst)
                return cost;
            if(stops <= k) {
                for(auto nbr: adj[ver]) {
                    int nbrVer= nbr.first;
                    int nbrWt= nbr.second;
                    if(visited.find(to_string(nbrVer)+"&"+to_string(stops+1)) == visited.end())
                        minHeap.push({cost+nbrWt, {nbrVer, stops+1}});
                }
            }
        }

        return -1;
    }
};


