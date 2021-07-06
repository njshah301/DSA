int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int m=B;
    bool t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++)
        {
         if(i==0){
             t[i][j]=false;
         }
         if(j==0){
             t[i][j]=true;
         }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
         if(j>=A[i-1]){
             t[i][j]=t[i-1][j-A[i-1]] || t[i-1][j];
         }
         else{
             t[i][j]=t[i-1][j];
         }
        }
    }
    if(t[n][m]==true)
    return 1;
    else{
        return 0;
    }
}
