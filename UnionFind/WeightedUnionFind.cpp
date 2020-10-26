//重み付きUnionFind
template<class T>
struct WeightedUnionFind{
    vector<int> par;
    vector<T> diff_weight;

    //n個の素集合で初期化する
    WeightedUnionFind(int n):par(n,-1),diff_weight(n,0){}

    //xの根を求める
    int root(int x){
        if(par[x]<0){
            return x;
        }else{
            int r=root(par[x]);
            diff_weight[x]+=diff_weight[par[x]];
            return par[x]=r;
        }
    }

    //xの根からの距離を求める
    T weight(int x){
        root(x);
        return diff_weight[x];
    }

    //xとyが同じ集合に属するかを返す
    bool issame(int x,int y){
        return root(x)==root(y);
    }

    //y = x + w となるようにmergeする
    bool merge(int x,int y,T w){
        w+=weight(x);
        w-=weight(y);
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(par[x]>par[y]){
            swap(x,y);
            w*=-1;
        }
        par[x]+=par[y];
        par[y]=x;
        diff_weight[y]=w;
        return true;
    }

    //y - x を求める
    T diff(int x,int y){
        return weight(y)-weight(x);
    }
};