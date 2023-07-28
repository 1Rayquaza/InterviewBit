string Solution::fractionToDecimal(int A, int B) {
    #define int long long
    // since the data after decimal point is needed, we'll do long division(like hand written)
    // by checking denominator AFTER SIMPLIFICATION, we can tell whether the fractional part is recurring or non-recurring
    // if denominator is in form pow(2, a)*pow(5, b) then alright else need to do smth
    // int part can be calculated directly, now need to deal with frac part
    // 56/48 = 7/6 = 1.1(6) 
    if(A==INT_MIN && B==-1) return "2147483648";
    if(A==0) return "0";

    int flag = 0;
    if((A<0 && B>0) || (A>0 && B<0)){   // make both absolute, add sign in the end
        A = abs(A);
        B = abs(B);
        flag = 1;
    }

    int n1 = A/B; // integer part
    int n2 = A%B;
    if(n2==0) return to_string(n1); 
    // if remainder becomes same as dividend, the frac part starts repeating
    int den = B;
    int num = n2*10;

    string ans = "";
    unordered_map<int, int> m;
    int i=0;
    int dividend = num;  // remainder will become num in every iteration
    m[dividend] = 0;

    while(1){
        int q = dividend / B; // we also need to store quotient infor to return as ans
        ans += to_string(q);
        int r = dividend % B;
        if(r==0) break;
        r = r*10;
        i++;
        if(m.find(r) == m.end()) m[r] = i;
        else{
            ans.insert(m[r], "(");
            ans += ")";
            break;
        }
        dividend = r;
    }
    string finall = to_string(n1)+"."+ans;
    if(flag==1) finall = "-" + anss;
    return finall;
}

// whatever the remainder, multiply by 10 until zero or same as previous so repeatingnow        
// need to check if this r, now the new dividend has came earlier, use map