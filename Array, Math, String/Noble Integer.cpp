int Solution::solve(vector<int> &v) {
    sort(v.begin(), v.end());
    //auto it;
    for(int i=0; i<v.size(); i++){  //upper/lower bound will ONLY  work for sorted arrays 'cause it's implemented using binary search
        auto it=upper_bound(v.begin(), v.end(), v[i]);  //v.begin and end are at ANY position in the memory block
        int x = it - v.begin(); //so array ke indexing ke according ho jaaye
        if((v.size()-x)==v[i])
            return 1;
    }
    return -1;
}
//cout << *it; will give the value of the element jiski posn. upar pta lgi

/* upper_bound() is a standard library function in C++ defined in the header . 
It returns an iterator pointing to the first element in the range [first, last) that is greater than value, 
or last if no such element is found. The elements in the range shall already be sorted or at least 
partitioned with respect to val.