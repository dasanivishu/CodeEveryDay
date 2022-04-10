// Minimum increment/decrement to make array non-Increasing
// Given an array a of length n, find the minimum number of operations required to make it non-increasing. You can select any one of the following operations and preform it any number of times on an array element.

//     increment the array element by 1.
//     decrement the array element by 1. 

// Example 1:

// Input:
// N = 4 
// array = {3, 1, 2, 1}
// Output: 1
// Explanation: 
// Decrement array[2] by 1. 
// New array becomes {3,1,1,1} which is non-increasing. 
// Therefore, only 1 step is required. 


// Example 2:

// Input:
// N = 4 
// array = {3, 1, 5, 1}
// Output: 4
// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
public:
    int minOperations(int *a,int n)
    {
       int steps=0;  
       priority_queue<int,vector<int>,greater<int>>pq;//min_heap
       for(int i=0;i<n;i++)
       {
           if(!pq.empty()&&pq.top()<a[i])
           {
               steps+=a[i]-pq.top();
               pq.push(a[i]);
               pq.pop();
           }
           pq.push(a[i]);
       }
       return steps;
    }
    
};

// { Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
public:
    int minOperations(int *a,int n)
    {
       int steps=0;  
       priority_queue<int,vector<int>,greater<int>>pq;//min_heap
       for(int i=0;i<n;i++)
       {
           if(!pq.empty()&&pq.top()<a[i])
           {
               steps+=a[i]-pq.top();
               pq.push(a[i]);
               pq.pop();
           }
           pq.push(a[i]);
       }
       return steps;
    }
    
};

// { Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
