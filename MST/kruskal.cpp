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