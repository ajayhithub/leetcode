class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        vector<int> ans;
        ans.push_back(asteroids[0]);
        for(int i=1;i<n;i++)
        {
             int t=0;
             while(ans.size()!=0 &&  (ans.back()>=0 && asteroids[i]<0))
             {
                 if(abs(ans.back())<=abs(asteroids[i])) 
                 {
                      if(abs(ans.back())==abs(asteroids[i]))
                      {
                        t =  1;  
                        ans.pop_back();
                          break;
                      }
                      
                     
                     ans.pop_back();
                 }
                 else
                 {
                     t = 1;
                     break;
                 }    
                    
             }
            
             if(t==0)
             ans.push_back(asteroids[i]);   
             
            
        }
        
        return ans;
        
    }
};