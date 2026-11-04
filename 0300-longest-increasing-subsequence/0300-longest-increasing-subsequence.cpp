class Solution {
public:
/*     RECURSION
  int fn(int i, vector<int>& nums) {
        if (i == 0)
            return 1;
        if (nums[i] > nums[i - 1]) {
            return 1 + fn(i - 1, nums);
        } else
            return fn(i - 1, nums);
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans = max(ans, fn(i, nums));
        }
        return ans;
    }
};
*/

//   MEMORIZATION
/*int fn(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
if(i==nums.size())return 0;
if(dp[i][prev+1]!=-1)return dp[i][prev+1];
int select=INT_MIN;
 int skip=fn(i+1,prev,nums,dp);
if(prev==-1||nums[i]>nums[prev]){
      select=1+fn(i+1,i,nums,dp);
}

return dp[i][prev+1]= max(select,skip);
}
int lengthOfLIS(vector<int>& nums){
 int n=nums.size();
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return fn(0,-1,nums,dp);
}
};
*/

//       TABULATION
int lengthOfLIS(vector<int>& nums){
int n=nums.size();
vector<vector<int>>dp(n+1,vector<int>(n+1,0));
for(int j=0;j<n+1;j++){
    dp[n][j]=0;
}
for(int i=n-1;i>=0;i--){
   for( int prev=-1;prev<n;prev++){
    int skip=dp[i+1][prev+1];
    int select=INT_MIN;
    if(prev==-1||nums[i]>nums[prev])
    select=1+dp[i+1][i+1];
   
   dp[i][prev+1]=max(skip,select);
}
}
return dp[0][0];


}
};