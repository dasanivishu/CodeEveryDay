/*Given a binary matrix of dimensions M * N. One can perform the given operation in the matrix.
Link:https://practice.geeksforgeeks.org/problems/7d7f73a59ddc3f9c8046af6bd66ea67311bf877e/1#

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to the directions right, down, left, and up respectively.
Initially you start from cell(0, 0), moving in right direction.

The task is to find the first cell of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) by performing the operations.

Example 1:

Input:
matrix[][] = {{0,1},
              {1,0}}

Output: (1,1)
Input: 
matrix[][] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 0, 1},
              {1, 1, 1, 0, 0}}

Output: (2,0) */
//Code:
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int N=matrix.size();
        int M=matrix[0].size();
        char curr_dirn='r';
        int index1=0,index2=0;
        int i=0,j=0;
        while((i>=0&&i<N)&&(j>=0&&j<M))
        {
            index1=i,index2=j;
            if(matrix[i][j]==1)
            {
                
                if(curr_dirn=='u')
                {
                    matrix[i][j]=0;
                    j++;
                    curr_dirn='r';
                    
                }
                else if(curr_dirn=='r')
               {
                  matrix[i][j]=0;
                  i++;
                  curr_dirn='d';
               }
               else if(curr_dirn=='d')
               {
                   matrix[i][j]=0;
                   j--;
                   curr_dirn='l';
               }
               else
               {
                   matrix[i][j]=0;
                   i--;
                   curr_dirn='u';
               }
            }
            else
            {
                if(curr_dirn=='u')
                {
                    i--;
                    
                }
                else if(curr_dirn=='r')
               {
                 j++;
               }
               else if(curr_dirn=='d')
               {
                   i++;
               }
               else
               {
                   j--;
               }
            }
            
        }
        return {index1,index2};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends
