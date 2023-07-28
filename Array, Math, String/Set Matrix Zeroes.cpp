// void Solution::setZeroes(vector<vector<int> > &A) {
//     int m=A.size();
//     int n=A[0].size();
//     set<int> r;
//     set<int> c;
    
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(A[i][j]==0){
//                 r.insert(i); //insertion mei TC is O(logN) so we can try ANOTHER WAY
//                 c.insert(j);
//             }
//         }
//     }
    
//     auto it=r.begin();
//     for(it=r.begin(); it!=r.end(); it++){
//         for(int j=0; j<n; j++){
//             A[*it][j]=0;
//         }
//     }
    
//     for(it=c.begin(); it!=c.end(); it++){
//         for(int i=0; i<m; i++){
//             A[i][*it]=0;
//         }
//     }
// }

void Solution::setZeroes(vector<vector<int>> &A){
    int m=A.size(); //row size
    int n=A[0].size();  //column size
    bool flag1=false;
    bool flag2=false;
    
    for(int i=0; i<m; i++){ //and j=0 i.e. 1st column
        if(A[i][0]==0){
            flag1=true;
            break;
        }
    }
    
    //performed these 2 loops so that 1st row and column mei 0 hone ki info store hojaaye
    for(int j=0; j<n; j++){ //and i=0 i.e. 1st row
        if(A[0][j]==0){
            flag2=true;
            break;
        }
    }
    
    for(int i=1; i<m; i++){     //first row and column mei store kr rhe so wo last mei dekhenge
        for(int j=1; j<n; j++){
            if(A[i][j]==0){
                A[i][0]=0;  //first row and first column mei info store kr rhe, to minimise space complexity
                A[0][j]=0;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][0]==0 || A[0][j]==0){
                A[i][j]=0;
            }
        }
    }
    
    if(flag1){
        for(int i=0; i<m; i++){
            A[i][0]==0;
        }
    }
    
    if(flag2){
        for(int j=0; j<n; j++){
            A[0][j]==0;
        }
    }
    
}
//   vector<int> r(1001, 0); //ek separate array mei sbb row and columns ki information store kra li
//   vector<int> c(1001, 0);
    
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(A[i][j]==0){
//                 r[i]=1; //updating 1 means wahan 0 tha
//                 c[j]=1;
//             }
//         }
//     }
    
//     for(int i=0; i<1001; i++){
//         if(r[i]==1){
//             for(int j=0; j<n; j++){
//                 A[i][j]=0;
//             }
//         }
//     }
    
//     for(int i=0; i<1001; i++){
//         if(c[i]==1){
//             for(int j=0; j<m; j++){
//                 A[j][i]=0;
//             }
//         }
//     }
// }
