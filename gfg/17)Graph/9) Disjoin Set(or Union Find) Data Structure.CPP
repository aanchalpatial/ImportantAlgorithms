// https://leetcode.com/explore/featured/card/graph/618/disjoint-set/3843/

class UnionFind {
    int *root, *rank;
public:
    UnionFind(int n) {      // O(n)
        root = new int[n];
        rank = new int[n];
        for(int i=0;i<n;++i) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {           // O(α(N)) ~ O(1) on average
        if(x == root[x]) return x;
        // path compression optimisation
        root[x] = find(root[x]);
        return root[x];
    }

    void unionSet(int x, int y) {   // O(α(N)) ~ O(1) on average
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY) {
            // union by rank(height) optimisation
            if(rank[rootX]<rank[rootY]) {
                root[rootX] = rootY;
            } else if(rank[rootX]>rank[rootY]) {
                root[rootY] = rootX;
            } else {
                root[rootX] = rootY;
                rank[rootY] += 1;
            }
        }
    }

    bool connected(int x, int y) {  // O(α(N)) ~ O(1) on average
        return find(x) == find(y); 
    }
};


// APPLICATION: https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
int earliestAcq(vector<vector<int>>& logs, int n) {
    
    // method: union-find algorithm
    // step 1: sort logs in increasing order of timestamp
    sort(logs.begin(), logs.end(), customComp);

    // step 2: initialise disjoin set data structure
    UnionFind uf(n); 
    int groupCount = n;

    for(auto l: logs) {
        int x = l[1], y = l[2];

        if(uf.connected(x, y)==false) {
            uf.unionSet(x, y);
            --groupCount;
        }
        
        if(groupCount==1) {
            int timestamp = l[0];
            return timestamp;
        }
    }
    return -1;

    // time: O(mlogm + n + m*α(N)) & space: O(n)
}