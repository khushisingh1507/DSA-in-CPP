class Solution {
public:

//   BINARY SEARCH 
   int lowerBound(vector<int>&nums,vector<int>&temp,int in){
    int low=0;
    int ans=temp.size()-1;
    int high=temp.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(temp[mid]>=nums[in]){
        ans=mid;
        high=mid-1;
    }
         if(temp[mid]<nums[in]){
             low=mid+1;}
       
    }
    return ans;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){temp.push_back(nums[i]);}
            else{
                int ind= lowerBound(nums,temp,i);
                temp[ind]=nums[i];
                }
               
            }
            return temp.size();
        }
        

};