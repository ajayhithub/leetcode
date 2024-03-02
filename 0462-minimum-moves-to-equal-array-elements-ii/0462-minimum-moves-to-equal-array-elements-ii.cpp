class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
     
            int t = n/2;
            int ans = 0;
            for(int i=0;i<n;i++)
            {
               ans += abs(nums[t]-nums[i]);    
            }
            
           if(n%2 != 0)
            return ans;
        
          int ans1 = ans;
          ans = 0;
          t--;
          for(int i=0;i<n;i++)
          {
               ans += abs(nums[t]-nums[i]);    
          }
          
           ans1 = min(ans1,ans);
        
          return ans1;
      
        
    }
};