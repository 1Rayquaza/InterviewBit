/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
// https://www.interviewbit.com/problems/copy-list/
// Similar to this ques, we'd do one traversal to create hash of all nodes
// then another to assign neighbours to the deep copy nodes

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    queue<UndirectedGraphNode* > q;
    q.push(node);
    
    UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    mp[node] = head; 
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        for(auto i : it->neighbors){
            if(mp.find(i) == mp.end()){
                UndirectedGraphNode* tmp = new UndirectedGraphNode(i->label);
                q.push(i);
                mp[i] = tmp;
            }
        }
    }
    
    q.push(node);
    unordered_map<UndirectedGraphNode*, int> vis;
    vis[node] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        for(auto i : it->neighbors){
            if(vis.find(i) == vis.end()){
                q.push(i);
                vis[i] = 1;
            }
            mp[it]->neighbors.push_back(mp[i]);
        }
    }
    
    return head;
}