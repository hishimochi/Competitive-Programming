//Dijkstra法
//O
template<class T>
struct Dijkstra{
    template<class U>
    struct edge{
        int to;
        U cost;
        edge(int t,U c):to(t),cost(c){}
    };
    //頂点数
    int V;

    T tinf=numeric_limits<T>::max();
    vector<vector<edge<T>>> G;
    vector<T> d;
    vector<int> prev;

    Dijkstra(int v):V(v),G(v),d(v),prev(v){}

    //xからyへコストcの辺を追加する
    void add(int x,int y,T c){
        assert(x>=0&&x<V&&y>=0&&y<V);
        edge<T> e(y,c);
        G[x].emplace_back(e);
    }

    //頂点xから各頂点への最小コスト
    void Build(int x){
        for(int i=0;i<V;i++)d[i]=tinf;
        for(int i=0;i<V;i++)prev[i]=-1;
        d[x]=0;
        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> Q;
        Q.push(pair<T,int>(0,x));
        while(!Q.empty()){
            pair<T,int> p=Q.top();
            Q.pop();
            int f=p.second;
            if(d[f]<p.first)continue;
            for(auto e:G[f]){
                if(d[e.to]>d[f]+e.cost){
                    d[e.to]=d[f]+e.cost;
                    Q.push(pair<T,int>(d[e.to],e.to));
                    prev[e.to]=f;
                }
            }
        }
    }

    //頂点tの最小コスト
    T dist(int t){
        return d[t];
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