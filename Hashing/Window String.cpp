string Solution::minWindow(string s, string t) {
    int n = s.size();
    int n2 = t.size();
    string ans = "";
    if(n2 > n) return ans;
    unordered_map<char, int> m;
    for(int i =0; i<n2; i++){
        m[t[i]]++;
    }
    int i=0, j=0;
    int count=m.size();
    int index=-1, ansLen=INT_MAX;

    while(j<n){
        if(m.find(s[j]) != m.end()){  // no && m[s[j]]>0 'cause inbetween occurance of char matter
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
            
        if(count > 0) j++;

        else if(count == 0){
            int idx = i;
            int len = j-i+1;
            if(len < ansLen){
                ansLen = len;
                index = i;
            }
			/* All characters required are in current window
            Now, try to minimize window by removing extra character at the start of window */

            /* if s[i] is present in map we need to check if that's the only occurance of i(so we find
            it again, or we can safely move to minimize the window) */
            while(count==0 && i<=j){
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(j-i+1 < ansLen){
                        ansLen = j-i+1;
                        index = i;
                    }
                    if(m[s[i]] > 0) count++;

                }
                i++;
            }
            j++;
        }
    }

    if(index==-1) return ans;
    for(int i=index; i<index+ansLen; i++){
        ans.push_back(s[i]);
    }
    return s.substr(index, ansLen);

}