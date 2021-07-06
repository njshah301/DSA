class Solution {
public:
    bool subSetSum(vector<int>&nums,int target)
    {
        int n=nums.size();
        int m=target;
        bool t[n+1][m+1];
         for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0)
            t[0][j]=false;
            if(j==0)
            t[i][0]=true;
        }
         }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(j>=nums[i-1])
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
            
        }
        return t[n][m];
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum&1)
            return false;
        
        else
        {
            return subSetSum(nums,sum/2);
        }
    }
};