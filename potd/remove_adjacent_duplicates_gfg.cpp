// Given a string s, remove all its adjacent duplicate characters recursively. 

// Example 1:

// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation: 
// g(ee)ksforg(ee)k -> gksforgk


// Example 2:

// Input: 
// S = "abccbccba"
// Output: ""
// Explanation: 
// ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function remove() which takes the string S as input parameter and returns the resultant string.
// Note: For some test cases, the resultant string would be an empty string. For that case, the function should return the empty string only.


// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    // string duplicate(string s)
    
    string remove(string s){
        // code here
      int i=0,n=s.size();
      string temp;
      while(i<n)
      {
          int j=i+1;
          while(s[i]==s[j]&&j<n)
          j++;
          if(j==i+1)temp+=s[i];
          i=j;
      }
      if(s.size()==temp.size())
      return temp;
      else
      return remove(temp);
       
    
       
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends
