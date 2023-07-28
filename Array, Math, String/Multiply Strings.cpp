string addStrings(string &A, string &B) {
    //To counter MLE, copy create krne ki jageh saath saath fn. call krte add krte jao
    int i=A.size()-1;
    int j=B.size()-1;
    int c=0;
    string v="";
    while(i>=0 && j>=0){
        int d=0;
        d=(A[i]-'0')+(B[j]-'0')+c;
        
        if(d<=9){
            v.push_back((d+'0'));
            c=0;
        }
        else{
            d=d%10;
            v.push_back((d+'0'));
            c=1;
        }
        
        i--;
        j--;
    }
    
    while(i>=0){
        int d=0;
        d=(A[i]-'0')+c;
        
        if(d<=9){
            v.push_back((d+'0'));
            c=0;
        }
        else{
            d=d%10;
            v.push_back((d+'0'));
            c=1;
        }
        i--;
    }
    
    while(j>=0){
        int d=0;
        d=(B[j]-'0')+c;
        
        if(d<=9){
            v.push_back((d+'0'));
            c=0;
        }
        else{
            d=d%10;
            v.push_back((d+'0'));
            c=1;
        }
        j--;
    }
    
    //*************************
    if(c==1){
        v.push_back('1'); //incase carry reh jaaye, e.g. 925+98
    }
    
    reverse(v.begin(), v.end());
    return v;
}


string Solution::multiply(string A, string B) {
    //On paper multiplication
    //vectors for every digit
    //Add strings question
    
    int m=A.size();
    int n=B.size();
    int r=0;
    vector<string> nums;
    string temp="";
    string mul="";  //***
    
    for(int i=m-1; i>=0; i--){
        string ans="";
        for(int j=n-1; j>=0; j--){  // A ke ek digit se B ka har digit multiply and add
            int num = (A[i]-'0')*(B[j]-'0') + r;//add carry from previous
            ans += to_string((num%10));
            r = num/10;
        }
        if(r>0){    // agr last mei carry reh jaaye
            ans.push_back((r+'0'));   //push_back krna to vector bna kr krte
        }
        //string mei character pushback hota hai and string concatenate hoti hai, as string is array of characters
        reverse(ans.begin(), ans.end());
        ans+=temp;
        temp+="0";
        r=0;
        mul = addStrings(ans, mul);
        //Pehle hum vector mei pushback krke add kr rhe the so MLE, but ab yahin pr ho rha so OK :3
        // ************ nums.push_back(ans);
        //Rather than storing, yahin pr compute kr lete hain
        //cout << ans << endl;
    }
    
    // string mul=nums[0];  *************
    // for(int i=1; i<nums.size(); i++){
    //     mul = addStrings(nums[i], mul);
    // }
    
    reverse(mul.begin(), mul.end());
    while(mul[mul.size()-1]=='0' && mul.size()!=0){
        mul.pop_back();
        if(mul.empty()){
            return "0";
        }
    }
    reverse(mul.begin(), mul.end());
    return mul;
}
