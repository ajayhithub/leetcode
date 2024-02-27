class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
       long long n = arr.size();
       long long mod = 1e9+7;
       vector<long long> l(n),r(n);
       stack<pair<long long,long long>> s;
       for(long long i=0;i<n;i++)
       {
          long long cnt = 1;
          while(!s.empty() && s.top().first > arr[i])
          {
              cnt += s.top().second;
              s.pop();
          }
          s.push({arr[i],cnt});
          l[i] = cnt;
       } 

         while(!s.empty())
         s.pop();

        for(long long i=n-1;i>=0;i--)
       {
          long long cnt = 1;
          while(!s.empty() && s.top().first >= arr[i])
          {
              cnt = (cnt%mod + s.top().second%mod)%mod;
              s.pop();
          }
          s.push({arr[i],cnt});
          r[i] = cnt;
       } 

        long long ans = 0;
        for(long long i=0;i<n;i++)
        {
            long long aa = arr[i]%mod;
            long long bb = l[i]%mod;
            long long cc = r[i]%mod;
            ans =  (ans%mod + (((aa*bb)%mod)*cc)%mod)%mod;
        }  

         return ans%mod;
     
    }
};