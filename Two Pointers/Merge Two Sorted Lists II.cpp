void Solution::merge(vector<int> &A, vector<int> &B) {
    int n = A.size(); // Size of array A
    int m = B.size(); // Size of array B
    for (int i = 0; i < m; i++) {
        A.push_back(0); // Increase the size of A by appending m zeros at the end
    }
    int i = n - 1; // Index for array A
    int j = m - 1; // Index for array B
    int k = m + n - 1; // Index for the merged array
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[k] = A[i]; // Place the larger element from A at the end of the merged array
            i--; // Move to the previous element in A
        } else {
            A[k] = B[j]; // Place the larger element from B at the end of the merged array
            j--; // Move to the previous element in B
        }
        k--; // Move to the previous position in the merged array
    }
    while (j >= 0) {
        A[j] = B[j]; // Copy the remaining elements from B to the beginning of the merged array
        j--; // Move to the previous element in B
    }
}
