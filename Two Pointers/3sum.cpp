int Solution::threeSumClosest(vector<int> &A, int B) {
    //Notice the constraints
    //O(N2) 
    //Brute force approach would be by O(N3) where looping i, j, k over the array 
    //then returning when the difference with B is min., now to do this in O(N2) ...
    int n=A.size();
    if(n<3) return -1;
    sort(A.begin(), A.end());
    long sum=0;
    long closestSum = INT_MIN; //(A[0]+A[1]+A[2]);
    for(int i=0; i<n-2; i++){
        int s=i+1, e=n-1;
        while(s<e){
            sum=(long)(A[i]+A[s]+A[e]);
            if(sum==B) return sum;
            if (abs(B-sum) < abs(B-closestSum)) {
              closestSum = sum;
            }
            // if(abs(B-sum)==abs(B-closestSum))
            //     closestSum=max(sum,closestSum);
            else if(sum>B) e--;
            else s++; 
        }
    }
    return closestSum;
}

// int sum=0;
//     unordered_map<int, int> m;
//     for(int i=0; i<n; i++){
//         m[A[i]]++;
//     }
    
//     unordered_map<int, int> ms;
//     for(int i=0; i<n; i++){
//         sum=0;
//         for(int j=i+1; j<n; j++){
//             sum = A[i]+A[j];
//             ms[sum]++;
//         }
//     }
//     if()