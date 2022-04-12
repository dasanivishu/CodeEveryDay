// Negative weight cycle:
// Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.
 

// Example 1:

// Input: n = 3, edges = {{0,1,-1},{1,2,-2},
// {2,0,-3}}
// Output: 1
// Explanation: The graph contains negative weight
// cycle as 0->1->2->0 with weight -1,-2,-3.
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	   // int dis[n]={0};//distance of every vertex from starting node
	   vector<int>dis(n, INT_MAX);
	    dis[0] = 0;
	    int len=edges.size();//No of edges
	   // for (int i=1;i<n;i++)
	   // {
	   //     dis[i]=2147483;
	   // }
	    for(int i=0;i<n-1;i++)//relax every node n-1 time to find shortest path
	    {
	        //relax every edge
	        for(int j=0;j<len;j++)
	        {
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int edge=edges[j][2];
	            if((dis[u]+edge)<dis[v])
	            dis[v]=dis[u]+edge;
	        }
	    }
	   //relax each edge one more time to check negative weight cycle
	    for(int j=0;j<len;j++)
	        {
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int edge=edges[j][2];
	            if((dis[u]+edge)<dis[v])
	            return 1;
	        }
	  return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
