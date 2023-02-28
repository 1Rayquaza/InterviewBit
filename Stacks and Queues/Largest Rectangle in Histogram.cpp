int Solution::largestRectangleArea(vector<int> &A) {
// Max Area Histogram
// >= height towers will work so we need to find the next smaller on both sides to break the loop
// Prefer index over storing length
    int n=A.size();
	vector<int> vL;
	stack<pair<int, int>> s1;
 
	for(int i=0; i<n; i++){
		if(s1.size()==0){
			vL.push_back(1);
		}
		else if(s1.size()!=0 && s1.top().first<A[i]){
			vL.push_back(1);
		}
		else if(s1.size()!=0 && s1.top().first>=A[i]){
			while(s1.size()!=0 && s1.top().first>=A[i]){
				s1.pop();
			}
			if(s1.size()==0) vL.push_back(i+1);
			else vL.push_back((i-s1.top().second));
		}
		s1.push({A[i], i});
	}
 
	vector<int> vR;
	stack<pair<int, int>> s2;
 
	for(int i=n-1; i>=0; i--){
		if(s2.size()==0){
			vR.push_back(1);
		}
		else if(s2.size()!=0 && s2.top().first<A[i]){
			vR.push_back(1);
		}
		else if(s2.size()!=0 && s2.top().first>=A[i]){
			while(s2.size()!=0 && s2.top().first>=A[i]){
				s2.pop();
			}
			if(s2.size()==0) vR.push_back(n-i);
			else vR.push_back((s2.top().second-i));
		}
		s2.push({A[i], i});
	}
	reverse(vR.begin(), vR.end());
 
	int area = A[0]*vL[0]*vR[0];
	int mx = area;
 
	for(int i=1; i<n; i++){
		area = A[i]*(vL[i]+vR[i]-1);
		mx = max(mx, area);
	}
	return mx;
}