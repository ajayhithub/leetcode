class Solution {
public:
    
    vector<int> fun(int n)
    {
        vector<int> ans(10,0);
        
        while(n)
        {
            ans[n%10]++;
             n = n/10;
        }
        
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> a = fun(n);
        
         for(int i=0;i<31;i++)
         {
              vector<int> b = fun(1<<i);
             if(a==b)
              return true;  
             
         }
        
        return false;
       
        
    }
};