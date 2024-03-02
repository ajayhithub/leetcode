class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        
        int n =  arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
           if(arr[i]==1)
             cnt++;   
        }
    
           if(cnt == 0)
             return {0,n-1};  
        
        if(cnt%3 != 0)
         return {-1,-1};
        
        int cnt2 = cnt/3;
        int nnn = 0;
          for(int i=n-1;i>=0;i--)
        {
             nnn++;
           if(arr[i]==1)
           {
               cnt2--;
           }
             if(cnt2==0)
             {  
              break;
             }
            
        }
        // cout<<nnn<<" ";
        vector<int> aa(nnn);
        int cnt1 = cnt/3;
        int tt = 0;
         for(int i=n-1;i>=0;i--)
        {
            aa.push_back(arr[i]); 
           if(arr[i]==1)
           {
               cnt1--;
           }
             if(cnt1==0)
             {
              tt = i;   
              break;
             }
             
                    
        }
        
        reverse(aa.begin(),aa.end());
         int it = 0;
        int t = 0;
        int l = 0;
      
      //  cout<<aa[0]<<" ";
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0 && t==0)
            {
              continue;
            } 
            else
            {
                t = 1;
                if(arr[i]!=aa[it])
                 return {-1,-1};
                
                it++;
            }
            
            if(it==nnn)
            {
              l = i;  
              break;
            }
        }
        
        
        
         if(l>=tt)
         return {-1,-1};
    
    //    cout<<l<<" "<<tt<<" ";
         it = 0;
         t = 0;
        int r = 0;
     
        for(int i=l+1;i<tt;i++)
        {
         
             if(arr[i]==0 && t==0)
            {
              continue;
            } 
            else
            {
                t = 1;
                if(arr[i]!=aa[it])
                 return {-1,-1};
                
                it++;
            }
            
             r = i; 
            if(it==nnn)
            { 
               break;
            }
        }
        
        cout<<r<<" "<<nnn<<" "<<tt<<" "<<l<<" ";
        
        if(r>=tt || it!=nnn)
         return {-1,-1};
        
        
        return {l,r+1};
    }     
       
};