vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // words in L are of the SAME LENGTH
    int n = A.size();
    int n2 = B.size();
    int l = B[0].size();    // size of one word
    unordered_map<string, int> m;
    for(int i=0; i<n2; i++){
        m[B[i]]++;
    }
    unordered_map<string, int> p;
    int len = n2*l;
    vector<int> ans;
    //cout<<"h"<<" ";
    
    for(int i=0; i<n-len+1; i++){
        //cout << i << " " ;
        // string str = A.substr(i,len);
        p = m;
        for(int j=i; j<i+len-l+1; j+=l){    // constraints are written according to string A
            string tmp = A.substr(j, l);    
            //cout << tmp << " " ;
            
            if(p.find(tmp) == p.end()) break;
            else if(p.find(tmp) != p.end()){
                p[tmp]--;
                if(p[tmp]==0) p.erase(tmp);
            }
            if(p.size()==0){
                ans.push_back(i);
            }
        }
    }
    return ans;
}