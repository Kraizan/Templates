class DSU {
    vector<int> par;
    vector<int> rank;

    int findPar(int x){
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    bool unionByRank(int x, int y){
        if(isConnected(x,y)) return false;
        int upx = par[x], upy = par[y];
        if(rank[upx] > rank[upy]){
            par[upy] = upx;
            rank[upx]++;
        }
        else{
            par[upx] = upy;
            rank[upy]++;
        }
        return true;
    }

public:
    DSU(int n){
        par.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = i;
        }
    }

    bool isConnected(int x, int y){
        return findPar(x) == findPar(y);
    }

    bool connect(int x, int y){
        return unionByRank(x,y);
    }
};
