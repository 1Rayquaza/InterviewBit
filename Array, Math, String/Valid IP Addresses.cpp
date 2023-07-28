bool isValid(string s1, string s2, string s3, string s4){
    if(s1=="" || s2=="" || s3=="" || s4=="")
        return false;
    int n1=stoi(s1), n2=stoi(s2), n3=stoi(s3), n4=stoi(s4);
    if(n1<=255 && n2<=255 && n3<=255 && n4<=255)
    {

        if(to_string(n1).size()!=s1.size() || to_string(n2).size()!=s2.size() || to_string(n3).size()!=s3.size() || to_string(n4).size()!=s4.size())
            return false;   //0100/010/0001 exists :)
            //can also write this as if s1[0]!=0 and size
        return true;
    }
    return false;
}

vector<string> Solution::restoreIpAddresses(string A) {
    int n=A.size();
    vector<string> ans;
    for(int i=1;i<4;i++){
        for(int j=i;j<7;j++){
            for(int k=j;k<n;k++){
                string s1 = A.substr(0, i);
                string s2 = A.substr(i, j-i);
                string s3 = A.substr(j, k-j);
                string s4 = A.substr(k);
                int sizeee=s1.size()+s2.size()+s3.size()+s4.size();
                if(sizeee<4 || sizeee>12) continue;
                if(isValid(s1, s2, s3, s4))
                    ans.push_back(s1+"."+s2+"."+s3+"."+s4);
            }
        }
    }
    return ans;
}
    //int num=stoi(A);    //converted to int
    //place 3 dots acc. to rules
    //if(n1<=255 && n1>=0 && n2<=255 && n2>=0 && n3<=255 && n3>=0 && n4<=255 && n4>=0)
    //3 for loops is okay 'cause TC is 3*3*3*3
