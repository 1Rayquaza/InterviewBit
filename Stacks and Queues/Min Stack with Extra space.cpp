// with EXTRA space in constant time
stack<int> s;
stack<int> ss;
    
MinStack::MinStack() {
    while(s.size()!=0){
        s.pop();
    }
    while(ss.size()!=0){
        ss.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if((ss.size()==0) || ss.top()>=x){
        ss.push(x);
    }
}

void MinStack::pop() {
    if(s.size()==0) return;
    int x = s.top();
    s.pop();
    if(x == ss.top()) ss.pop();
}

int MinStack::top() {
    if(s.size()==0) return -1;
    else return s.top();
}

int MinStack::getMin() {
    if(s.size()==0) return -1;
    else return ss.top();
    
}
