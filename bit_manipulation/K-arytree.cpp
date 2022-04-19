// Find the number of leaf nodes in a full k-ary tree of height m.
// Note: You have to return the answer module 109+7.

 

// Example 1:

// Input:
// k = 2, m = 2
// Output:
// 4
// Explanation:
// A full Binary tree of height 2 has 4 leaf nodes. 

// Example 2:

// Input:
// k = 2, m = 1
// Output:
// 2
// Explanation:
// A full Binary tree of height 1 has 2 leaf nodes
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long power(int x,int y,long long p)
    {
        long long res=1;
         x=x%p;
        if(x==0)return 0;
        while(y>0)
        {
            if(y&1)//y->0dd
            {
                res=(res%p*x%p)%p;
                
            }
            // y miust be even now
            y=(y>>1);//y=y/2;
            x=(x%p*x%p)%p;
        }
        return res;
    }
    long long karyTree(int k, int m) {
        // code here
        long long p=1e9+7;
        return power(k,m,p);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends
