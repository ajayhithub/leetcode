class MyQueue {
    
     private:
     stack<int> in;
     stack<int> out;
    
public:
    MyQueue() {
                                                                  
                                                       
        
    }
     
    void push(int x) {
       
        in.push(x);
        return;
    }
    
    int pop() {
       
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        
        int t = out.top();
        out.pop();
        
         while(!out.empty())
        {
            in.push(out.top());
            out.pop();
        }
        
        return t;
        
    }
    
    int peek() {
        
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        
        int t = out.top();
      
         while(!out.empty())
        {
            in.push(out.top());
            out.pop();
        }
        
        return t;
        
    }
    
    bool empty() {
        
        if(in.empty())
            return true;
        else
            return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */