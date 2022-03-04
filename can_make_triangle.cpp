/*Given an array A[] of N elements, You'd like to know how many triangles can be formed with side lengths equal to adjacent elements from A[].
Construct an array of integers of length N - 2 where ith element is equal to 1 if it is possible to form a triangle with side lengths A[i], A[i+1], and A[i+2]. otherwise 0.
Note: A triangle can be formed with side lengths a, b and c if a+b>c and a+c>b and b+c>a.
Example 1:
Input:
N = 4
A[] = {1, 2, 2, 4}
Output:
1 0
Explanation:
output[0] = 1 because we can form a 
triangle with side lengths 1,2 and 2.
output[1] = 0 because 2+2<4 so, we cannot 
form a triangle with side lengths 2,2 and 4.
Input: 
N = 5
A[] = {2, 10, 2, 10, 2}
Output:
0 1 0
Explanation:
output[0] = 0 because 2+2<10 so, we cannot
form a triangle with side lengths 2, 10 and 2. 
output[1] = 1 we can form a triangle with 
side lengths 10,2 and 10. 
output[1] = 0 because 2+2<10 so, we can
form a triangle with side lengths 2, 10 and 2. 
*/
//code:
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        vector<int>res;
        int maximum;
        int sum=0;
        for(int i=0;i<3;i++)
        {
         sum+=A[i];
         maximum=max(A[0],max(A[1],A[2]));
          
        }
        if((sum-maximum)>maximum)
            res.push_back(1);
            else
            res.push_back(0);
        for(int i=1;i<N-2;i++)
        {
            maximum=max(A[i],max(A[i+1],A[i+2]));
            sum+=A[i+2]-A[i-1];
            if(sum-maximum>maximum)
            res.push_back(1);
            else
            res.push_back(0);
        }
        return res;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends
