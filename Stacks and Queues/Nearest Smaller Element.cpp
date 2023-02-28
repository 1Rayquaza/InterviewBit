vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n=arr.size();
    vector<int> v;
	stack<int> s;
 
	for(int i=0; i<n; i++){
		if(s.size()==0){
			v.push_back(-1);
		}
		else if(s.size()!=0 && s.top()<arr[i]){
			v.push_back(s.top());
		}
		else if(s.size()!=0 && s.top()>=arr[i]){
			while(s.size()!=0 && s.top()>=arr[i]){
				s.pop();
			}
			if(s.size()==0) v.push_back(-1);
			else v.push_back(s.top());
		}
		s.push(arr[i]);
	}
    return v;
}
