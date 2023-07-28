// for O(1) space, only variables are there sooo, use as many variables but space would be O(1)
// if we store and update the variable the previous information will be lost hence, 
// we'll store corrupted values in the stack to flag mark the element which changed the min. element 
// instead of pushing x(new min) we'll push 2*x-minEle
stack<int> s;
int minEle;

MinStack::MinStack() {
    while(s.size()!=0){
        s.pop();
    }
}

void MinStack::push(int x) {
    if(s.size()==0){
        s.push(x);
        minEle=x;
    }
    else{ // implies minEle needs to be changed but we need to store previous minEle
        if(x < minEle){
            s.push(2*x - minEle);
            minEle = x;
        }
        else s.push(x);
    }
}

void MinStack::pop() {
    if(s.size()==0){
        return;
    }
    else{
        if(s.top() >= minEle) s.pop();
        else{
            minEle = 2*minEle - s.top();    // ****** i.e. the previous element since s.top() is 2*ME - prev_ME
            s.pop();
        }
    }
}

int MinStack::top() {
    if(s.size()!=0){
        if(s.top() < minEle){   // means flag so iss point pr current ME aaya
            return minEle;    // not 2*minEle - s.top() 
        }
        else return s.top();
    }
    else return -1;
}

int MinStack::getMin() {
    if(s.size()!=0){
        return minEle;
    }
    else return -1;
}



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

