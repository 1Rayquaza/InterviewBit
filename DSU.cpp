// code for DSU using Union by rank and Path Compression

#include <bits/stdc++.h>

using namespace std;

// void Union(int p1, int p2, vector<int> &parent){
//     parent[p1] = p2; // storing immediate parent
// }

// int find(int node, vector<int> &parent){ // returns ancestoral parent
//     if(node == parent[node]){
//         return node; // root node, indegree = 0
//     }
//     else return find(parent[node], parent);
// }

void Union(int p1, int p2, vector<int> &parent, vector<int> &rank){
    if(rank[p1] < rank[p2]){
        parent[p1] = p2;
    }
    else if(rank[p1] > rank[p2]){
        parent[p2] = p1;
    }
    else{
        parent[p1] = p2;
        rank[p2]++;
    }
}

int find(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node], parent);
    }
}

bool isCycle(vector<pair<int, int>> &edges, int V, int E){
    vector<int> parent(V);
    for(int i=0; i<V; i++){
        parent[i] = i;
    }
    
    vector<int> rank(V, 0);
    
    for(auto it: edges){
        int p1 = find(it.first, parent);
        int p2 = find(it.second, parent);   // ancestral parent
        
        if(p1 == p2) return 1;  // cycle present 
        
        else Union(p1, p2, parent, rank);
    }
}

int main() {
    int x=10;
    int y=25;
    int z=x+y;

    cout<<"Sum of x+y = " << z;
}