class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
      
        vector<int> ans(n,0);
        int nn = bookings.size();
        for(int i=0;i<nn;i++)
        {
            for(int j=bookings[i][0];j<=bookings[i][1];j++)
            {
                if(j-1<n)
                 ans[j-1] = ans[j-1]+bookings[i][2];  
                else
                  break;
            }
        }
        
        return ans;
        
    }
};