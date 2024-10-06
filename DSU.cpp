class DSU {
    vector<int> par, rank, size;

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

    bool unionBySize(int x, int y){
        if(isConnected(x,y)) return false;
        int upx = par[x], upy = par[y];
        if(size[upx] > size[upy]){
            par[upy] = upx;
            size[upx] += size[upy];
        }
        else{
            par[upx] = upy;
            size[upy] += size[upx];
        }
        return true;
    }

public:
    DSU(int n){
        par.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = i;
        }
    }

    bool isConnected(int x, int y){
        return findPar(x) == findPar(y);
    }

    bool connect(int x, int y, bool bySize = false){
        return bySize ? unionBySize(x,y) : unionByRank(x,y);
    }

    int getSize(int x){
        int upx = findPar(x);
        return size[upx];
    }
};
