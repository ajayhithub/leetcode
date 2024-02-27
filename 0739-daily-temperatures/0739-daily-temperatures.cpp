class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
         int n = temperatures.size();
          
          stack<int> s;
          s.push(0);
          vector<int> ans(n);
          for(int i=1;i<n;i++)
          {
              while(!s.empty() && temperatures[s.top()]<temperatures[i])
              {
                  ans[s.top()] = i-s.top();
                  s.pop();
              }
              s.push(i);
          }
        
            ans[n-1] = 0;
          return ans;
        
    }
};