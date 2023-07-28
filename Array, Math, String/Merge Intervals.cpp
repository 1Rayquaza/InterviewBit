/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool func(Interval A1, Interval A2)
{
    return A1.start < A2.start;
}
 
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    A.push_back(newInterval);
    sort( A.begin(), A.end(), func );
    int flag = 0;
    int cs, ce;
    vector<Interval> ans;
    int n = A.size();
    
    for(int i=0; i<n-1; i++){
        if(flag == 0){  //read after the next ones
            cs = A[i].start;
            ce = A[i].end;
            flag=1;
        }
        
        if(A[i+1].start <= ce){
            ce = max(ce, A[i+1].end);
        }
        else{
            flag = 0;  //start waala default tha, now update for next interval
            Interval tmp;
            tmp.start=cs;
            tmp.end=ce;
            ans.push_back(tmp);
        }       
    }
     
    if( flag == 0 ){
        ans.push_back(A[n-1]);
    }
    else{
        ce=max(ce,A[n-1].end);
        Interval tmp;
        tmp.start=cs;
        tmp.end=ce;
        ans.push_back(tmp);
    }
    
    return ans;
}