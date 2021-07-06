
int subsetSum(vector<int>&A,int range)
{
    int n=A.size();
    int m=range;
    bool t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0)
            t[i][j]=false;
            if(j==0)
            t[i][j]=true;
          
        }
    }



    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(j>=A[i-1]){
                t[i][j]=t[i-1][j-A[i-1]] || t[i-1][j];
            }
            else
            t[i][j]=t[i-1][j];
        }
    }

    int i=A.size();
    int j;
    int ans=range;
    for(j=range/2;j>=0;j--)
    {
        if(t[i][j]==true){
            ans=(range-2*j);
            break;
        }
    }

    return ans;
}
int Solution::solve(vector<int> &A) {
    int range=0;
   for(int i=0;i<A.size();i++)
   {
       range+=A[i];
   }
   return subsetSum(A,range);
}