// largest continuous sequence -> subarray
vector<int> Solution::lszero(vector<int> &A) {
    int n=A.size();
    unordered_map<int, int> m;
    m[0] = -1;  // very Imp. !! e.g. 5, -5 -> prefix array would be 5, 0 so yes 0 is there but how to compare
    int ans=0, sum=0, id=-1;
    
    for(int i=0; i<n; i++){
        sum += A[i];
        // if(m.count(sum) == 0){
        if(m.find(sum) == m.end()){
            m[sum] = i; // updated this value in unordered_map
        }
        else{
            // means another same sum exists so difference of these two indices would give a 
            // subarray with sum zero inbetween
            int len = i-m[sum]; // curr index - that pehle waale same sum ka index
            if(len > ans){
                ans = len;
                id = m[sum];
            }
        }
    }
    
    vector<int> answer;
    for(int i=0; i<ans; i++){
        answer.push_back(A[id+1]);
        id++;
    }
    return answer;
}


/*  - sum of elements from A[i] to A[j] = Sum[j] - Sum[i-1] which needs to be zero so,
    - find i and j s.t. sum[i]==sum[j] i.e. find two subarrays with equal sum so the subarray in-between has
    sum zero
    - if sum is present already then subtract indices to find length, else insert this in map
*/
  