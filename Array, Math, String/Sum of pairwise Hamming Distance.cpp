//Similar to ***Single number || from Bits manipulation***
int Solution::hammingDistance(const vector<int> &A) {
    long long c0=0;
    long long c1=0;
    int m=1000000007;
    int n=A.size();
    long long ans=0;
    for(int i=0; i<32; i++){    
        for(int j=0; j<n; j++){    //32N is linear only
            if((A[j]&(1<<i))==0){   //sbka 0th bit fir 1st bit then 2nd bit... ith bit check krte jaa rhe 
                c0++;               //****** (A[j]&(1<<i)==0) BRACKETS IMPORTANT T_T 'cause '==' ki priority zyada h so 
            }
            else{
                c1++;
            }
        }
    ans = (ans+(c1*c0*2)%m)%m;
    c0=0;
    c1=0;
    }
    return ans;
}