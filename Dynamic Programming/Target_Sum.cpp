class Solution {
    
    /*
    -> Given nums: [1,1,1,1]
    -> Target=3 
    =>Do '+' and '-' to the elements to make Target
     
     Example: Target=3  +1+1+1-1 = S1 -S2 , where S1=[1,1,1] and S2=1;
     ___________________________________________________
    |~>| S1-S2=Target    =>  S1=Target+S2               |
    |~>| We can write S2 =>  Sum of all elements - S1   |
    |~>| Thus,          S1=> (Target+Sum)/2;            |
    |__|________________________________________________|
     *****************************************************************************************Here, set sum can be zero also so we need to keep 0th column into consideration.
*****************************************************************************************
    */
public:
    int subCount(vector<int>&nums,int target)
    {
        int n=nums.size();
        int m=target;
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(j>=nums[i-1])
                {
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][m];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto nj:nums)
            sum+=nj;
        if((sum+target)&1)
            return 0;
        
        return subCount(nums,(sum+target)/2);
    }
};