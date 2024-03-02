class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int ans = INT_MIN;
        int sum1 = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum1 += nums[i]; 
            sum += nums[i]*i;
        }
   
        ans = max(ans,sum);
        for(int i=0;i<n;i++)
        {
            cout<<sum<<" ";
            ans = max(ans,sum+sum1-n*nums[n-1-i]);
            sum = sum+sum1-n*nums[n-1-i];
        }
         
        return ans;
        
    }
};