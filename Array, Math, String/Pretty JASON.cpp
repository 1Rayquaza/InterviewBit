string insertTab(int tab){
    string ans;
    for(int i = 0; i < tab; ++i) ans += "\t";
    return ans;
}

vector<string> Solution::prettyJSON(string A) {
    if(A=="") return {};
    vector<string> ans;
    /* when will we push a string ??? 
    1. {, [, ], }
    2. ,(comma) comes 
    3. : followed by {, [  
     
    Indent: 1. {, [ - inc.
            2. }, ] - dec.  
            3. ith {, [ contains (i-1) indents */
            
    string k = "";
    int tab = 0;
    for(char c : A){    //to iterate for each character in a string
    // let's say we've a fn. which keeps track of how many tabs we need to add
        if(c=='{' || c=='['){
            if(k != "") ans.push_back(insertTab(tab) + k);  // pehle ke alawa open brackets, like C: before { in eg. 
            ans.push_back(insertTab(tab) + c); // { toh aayega hi, but iske pehle kuch tha toh woh bhi aajayega from above
            ++tab;
            k = "";
        }
        else if(c==','){
            k += c;
            ans.push_back(insertTab(tab) + k);
            k = "";
        }
        else if(c=='}' || c==']'){
            if(k != "") ans.push_back(insertTab(tab) + k);
            --tab;
            k = c;
        } 
        else{
            k += c;
        }
    }
    if(k!="")    ans.push_back(k);
    return ans;
}