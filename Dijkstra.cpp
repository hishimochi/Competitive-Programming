//edge1
template<class T=long long>
struct edge1{
    int to;
    T cost;
    edge1(int t,T c):to(t),cost(c){}
};

//Dijkstra法
//前提 edge1
template<class T>
struct Dijkstra{
    int V;
    T tinf=numeric_limits<T>::max();
    vector<vector<edge1<T>>> G;
    vector<T> dist;
    vector<int> prev;

    //頂点数nのグラフを作成する
    Dijkstra(int n):V(n),G(n),dist(n),prev(n){}

    //xからyへコストcの辺を追加する
    void add(int x,int y,T c){
        edge1<T> e(y,c);
        G[x].emplace_back(e);
    }

    //頂点xから各頂点への最小コストをdistに格納する
    void Build(int x){
        for(int i=0;i<V;i++)dist[i]=tinf;
        for(int i=0;i<V;i++)prev[i]=-1;
        dist[x]=0;
        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> Q;
        Q.push(pair<T,int>(0,x));
        while(!Q.empty()){
            pair<T,int> p=Q.top();
            Q.pop();
            int f=p.second;
            if(dist[f]<p.first)continue;
            for(auto e:G[f]){
                if(dist[e.to]>dist[f]+e.cost){
                    dist[e.to]=dist[f]+e.cost;
                    Q.push(pair<T,int>(dist[e.to],e.to));
                    prev[e.to]=f;
                }
            }
        }
    }

    //始点からtへの経路を求める
    vector<int> route(int t){
        vector<int> res(V);
        int i=0;
        for(int cur=t;cur!=-1;cur=prev[cur]){
            res[V-1-i]=cur;
            i++;
        }
        return res;
    }
};