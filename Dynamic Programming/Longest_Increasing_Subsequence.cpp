class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
        int dp[n+1];
        dp[0]=0;
        for(int j=1;j<=n;j++)
        {
            int maxi=1;
            for(int i=1;i<j;i++)
            {
                
                if(nums[i-1]<nums[j-1])
                maxi=max(dp[i]+1,maxi);
            }
            dp[j]=maxi;
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};