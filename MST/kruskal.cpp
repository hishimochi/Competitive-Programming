//edge2
template<class T=long long>
struct edge2{
    int from,to;
    T cost;
    edge2(int f,int t,T c):from(f),to(t),cost(c){}
};

//比較関数
template<class T>
bool CompEdge2(const edge2<T>& e1,const edge2<T>& e2){
    return e1.cost<e2.cost;
}

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

//kruskal法
//前提 edge2,UnionFind,CompEdge2
template<class T>
struct kruskal{
    vector<edge2<T>> AllEdge;
    int sz;

    //重みの総和が入る
    T cost;

    //頂点数vで初期化
    kruskal(int n):sz(n){}

    //fとtを重みcで結ぶ辺を追加
    void add(int f,int t,T c){
        AllEdge.emplace_back(f,t,c);
    }

    //MSTを構築する
    //構成する辺が入った配列を返す
    vector<edge2<T>> Build(){
        cost=0;
        vector<edge2<T>> Edges;
        sort(AllEdge.begin(),AllEdge.end(),CompEdge2<T>);
        UnionFind UF(sz);
        for(auto e:AllEdge){
            if(!UF.issame(e.from,e.to)){
                UF.merge(e.from,e.to);
                cost+=e.cost;
            }
        }
        return Edges;
    }
};