string Solution::solve(string A) {
    int n=A.length();
    unordered_map<char, int> mp;
    queue<char> q;
    string B;
    for(int i=0; i<n; i++){
        mp[A[i]]++;
        q.push(A[i]);
        while(mp[q.front()]>1 && !q.empty()){
            q.pop();
        }
        if(q.empty()) B.push_back('#');
        else B.push_back(q.front());
    }
    return B;
}


// string Solution::solve(string A) {
//     int n=A.size();
//     string B="";
//     queue<char> q;
    
//     // to optimize TC use vectors instead of maps when dealing with multiple characters
//     vector<int> v(26,0);
//     // we need to mark that the character has already repeated
//     for(int i=0; i<n; i++){
//         if(q.size()==0 && v[A[i]-'a']==0){
//             v[A[i]-'a']=1;
//             B.push_back(A[i]);
//         }
//         else if(q.size()!=0 && A[i]!=q.front()){
//             v[A[i]-'a']=1;
//             B.push_back(q.front());
//         }
//         else if(q.size()!=0 && A[i]==q.front()){
//             q.pop();
//             if(q.size()==0) B.push_back('#');
//             else{
//                 while(v[q.front()-'a'] == 1){
//                     q.pop();
//                 }
//                 if(q.size()==0) B.push_back('#');
//                 else B.push_back(q.front());
//             }
//         }
//         q.push(A[i]);
//     }
//     return B;
// }

// jyhrcwuengcbnuchctluxjgtxqtfvrebveewgasluuwooupcyxwgl

