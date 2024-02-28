class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
          int n = nums.size();
          vector<int> ans(n);
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
               ans[s.top()] = nums[i];
                s.pop();
            }
        }   
        
           while(!s.empty())
            {
               ans[s.top()] = -1;
                s.pop();
            }
        
        return ans;
    }
};