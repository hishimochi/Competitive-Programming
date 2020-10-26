//edge2
template<class T=long long>
struct edge2{
    int from,to;
    T cost;
    edge2(int f,int t,T c):from(f),to(t),cost(c){}
};

//BellmanFord法
//前提 edge2
template<class T>
struct BellmanFord{
    int V;
    vector<T> d;
    vector<int> prev;
    vector<edge2<T>> Es;
    T tinf=numeric_limits<T>::max();

    //頂点数vのグラフを作成
    BellmanFord(int v):V(v),d(v),prev(v){}

    //fからtへコストcの辺を追加する
    void add(int f,int t,T c){
        edge2<T> E(f,t,c);
        Es.emplace_back(E);
    }

    //頂点sから各頂点への最小コストをdに格納する
    //最短距離が-tinfの場合、負閉路を用いて無限にコストを下げられる
    //trueを返す場合に負閉路が存在する
    bool build(int s){
        bool c=false;
        for(int i=0;i<V;i++)d[i]=tinf;
        for(int i=0;i<V;i++)prev[i]=-1;
        d[s]=0;
        for(int i=0;i<V-1;i++){
            for(auto &e:Es){
                if(d[e.from]==tinf)continue;
                if(d[e.from]+e.cost<d[e.to]){
                    d[e.to]=d[e.from]+e.cost;
                    prev[e.to]=e.from;
                }
            }
        }
        for(int i=0;i<V;i++){
            for(auto &e:Es){
                if(d[e.from]==tinf)continue;
                if(d[e.from]==-tinf){
                    d[e.to]=-tinf;
                    continue;
                }
                if(d[e.from]+e.cost<d[e.to]){
                    c=true;
                    d[e.to]=-tinf;
                }
            }
        }
        return c;
    }

    //始点から頂点tへの経路を求める
    vector<int> route(int t){
        vector<int> res;
        for(int cur=t;cur!=-1;cur=prev[cur]){
            res.emplace_back(cur);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};