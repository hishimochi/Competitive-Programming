//UnionFind
struct UnionFind{
	vector<int> par;

    //x個の素集合を作成する
	UnionFind(int n):par(n,-1){}

    //xの根を求める
	int root(int x){
		if(par[x]<0)return x;
		else return par[x]=root(par[x]);
	}

    //xとyの属する集合が同じか求める
	bool issame(int x,int y){
		return root(x)==root(y);
	}

    //xの属する集合とyの属する集合をmergeする
    //既に同じ場合falseを返す
	bool merge(int x,int y){
		x=root(x);
        y=root(y);
		if(x==y)return false;
		if(par[x]>par[y])swap(x,y);
		par[x]+=par[y];
		par[y]=x;
		return true;
	}

    //xの属する集合の大きさを求める
	int size(int x){
		return -par[root(x)];
	}
};