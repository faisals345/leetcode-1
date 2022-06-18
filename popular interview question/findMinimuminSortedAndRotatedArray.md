Version 1-> 
This question wants you to find the minimum in rotated and sorted array , containing  all unique elements . 


Find Minimum in Rotated Sorted Array[https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/]

Approach -> 
Binary Search 

    int findMin(vector<int>& num) {
        
        int start=0,end=num.size()-1;
        
        while (start<end) {
            
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];    
    }


// 

Now the second question consist of duplicates . 
How do we modify this algo ? 

link[https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/]

int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1) return nums[0];
        
        int left = 0;
        int right = n-1;
        int mid;
        
        if(nums[0]<nums[n-1]) return nums[0];
        

        while(left<right)
        {   
           
            
            mid = (left+right)/2;
            
            
             if(nums[left]<nums[right]) return nums[left];
           
             if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

            else if(nums[mid]>=nums[left])
            {
                  left = mid+1;
            }
            else
            {   
                right = mid;

            }
        }
        return nums[left];  
    }
