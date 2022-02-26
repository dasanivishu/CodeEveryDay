/*Given an array of integers nums, sort the array in ascending order.
Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]*/

class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right)
    {
        int i=left,j=mid,k=0;
        int temp[(right-left+1)];
        while((i<=(mid-1))&&(j<=right))
        {
            if(nums[i]<=nums[j])
                temp[k++]=nums[i++];
            else 
                temp[k++]=nums[j++];
        }
        while(i<=(mid-1))
            temp[k++]=nums[i++];
        while(j<=right)
            temp[k++]=nums[j++];
         
        for(int i=left,k=0;i<=right;i++,k++)
        {
            nums[i]=temp[k];
        }
            
        return;
    }
    void merge_sort(vector<int>& nums,int left,int right)
    {
        int mid;
        if(left<right)
        {
            mid=(left+right)/2;
            merge_sort(nums,left,mid);
            merge_sort(nums,mid+1,right);
            merge(nums,left,mid+1,right);
        }
        return;
    }
    
    
    
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        merge_sort(nums,0,n-1);
        return nums;
    }
};
