class Solution {
public:
    /* destination -> source  [a => 0, e=>1 , i=>2, o=>3, u=>4]
          a        -> e , i ,u
          
          e        -> a , i
          
          i        -> e, o
          
          o        -> i
          
          u        -> i, o
    
    */
    int countVowelPermutation(int n) {
        
        const int maxn=1e9+7;
        
        int dp[n+1][5]; // where, n length possible strings end with given char in column
        
        for(int i=0;i<5;i++)
        {
            dp[0][i]=0;
            dp[1][i]=1;
        }
        
        vector<vector<int>> source{{1,2,4},{0,2},{1,3},{2},{2,3}};
        
        for(int i=2;i<=n;i++)
        {
            for(int v=0;v<5;v++){
                dp[i][v]=0;
                for(int u:source[v])
                 dp[i][v]=(dp[i][v]+dp[i-1][u])%maxn;
        }
        }
        int ans=0;
        for(int u=0;u<5;u++)
        {
            ans=(ans+dp[n][u])%maxn;
        }
        return ans;
    }
};