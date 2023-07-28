string Solution::convertToTitle(int A) {
    //(i%26) + 'A'; something something
    int n=A;
    string ans="";
    char c;
    while(n!=0){
        int x=(n%26);
        if(x==0){
            c='Z';
        }
        else{
            c='A'+x-1;
        }
        
        ans=c+ans;
        n--;    //whyyy ??? to avoid repeatation when single digit no. comes !!
        n=n/26; //bade numbers ke liye unaffected hi rhega so no chage
    }           
    return ans;
}
/* 1434 BCD */