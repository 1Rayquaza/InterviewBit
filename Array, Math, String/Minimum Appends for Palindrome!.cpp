int Solution::solve(string A) {
    //Here, we need to find the longest suffix which is a palindrome
    //we'll use lps but how ? ... ! We'll reverse A + ***(some random characters to differenciate) + A
    //And calculate the lps for this
    // e.g. A=abede; A(inv.)=edeba -> s = edeba$$$abede; lps of the string is ede, from this we can calculate the min. appends
    
    string temp = A;
    int m=A.size();
    reverse(temp.begin(), temp.end());
    string rev = temp;  // A inverse
    //to differenciate and avoid overlapping, we'll add special characters in middle 
    string s = rev+"$"+A;
    int n=s.size();
    //now we've to find the lps for this entire string hehe
    vector<int> lps(n);
    lps[0]=0;
    int j=0;
    int len=0;
    for(int i=1; i<n; ){
        if(s[i]==s[j]){
            len++;
            lps[i]=len;
            i++;
            j++;
        }
        else{
            if(j==0){
                lps[i]=0;
                len=0;
                i++;
            }
            else{
                len=lps[j-1];
                j=len;
            }
        }
    }
    
    int ans = m-lps[n-1];
    return ans;
}

































// int Solution::solve(string A) {
//     int n=A.size();
//     int i=0;
//     int j=n-1;
//     int k,l;
//     while(i<j){
//         if(A[i]==A[j]){
//             k=i;
//             l=j;
//             while(k<l && A[k]==A[l]){
//                 k++;
//                 l--;
//             }
//             if(k>=l){
//                 return i;   //starting mei jitna unequal utna return
//             }
//             //i = k;  //i ka jump ho rha hai, so no repeated checks
//             //starting se same matching isliye won't work
//         }else{
//             i++;
//         }
//     }
// }

// bool isPalindrome(string &s){
//     int n=s.size();
//     for(int i=0; i<n/2; i++){
//         if(s[i] != s[n-i-1]){
//             return false;
//         }
//     }
//     return true;
// }

// int Solution::solve(string A) {
//     //minimum characters to be appended (insertion at end) to make the string A a palindrome
//     //brute force approach
//     //longest palindromic suffix
//     int n=A.size();
//     int c=0;
//     int i=0;
//     int j=n-1;
    
//     while(i<j){
//         string check = A.substr(i, j-i+1);
//         if(isPalindrome(check)){
//             break;
//         }
//         i++;
//         c++;
//         }
//     return c;
// }
