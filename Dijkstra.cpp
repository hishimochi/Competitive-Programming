//edge1
template<class T=long long>
struct edge1{
    long long to;
    T cost;
    edge1(long long t,T c):to(t),cost(c){}
};

//Dijkstra
//前提 edge1
//O(ElogV)
template<class T>
struct Dijkstra{
    long long V;
    const T tinf=numeric_limits<T>::max()/(T)(3);
    vector<vector<edge1<T>>> G;
    vector<T> dist;
    vector<long long> prev;

    Dijkstra(long long n):V(n),G(n),dist(n),prev(n){}

    void add(long long x,long long y,T c){
        edge1<T> e(y,c);
        G[x].emplace_back(e);
    }

    void Build(long long x){
        for(long long i=0;i<V;i++)dist[i]=tinf;
        for(long long i=0;i<V;i++)prev[i]=-1;
        dist[x]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> Q;
        Q.push(pair<T,long long>(0,x));
        while(!Q.empty()){
            pair<T,long long> p=Q.top();
            Q.pop();
            long long f=p.second;
            if(dist[f]<p.first)continue;
            for(auto e:G[f]){
                if(dist[e.to]>dist[f]+e.cost){
                    dist[e.to]=dist[f]+e.cost;
                    Q.push(pair<T,long long>(dist[e.to],e.to));
                    prev[e.to]=f;
                }
            }
        }
    }

    vector<long long> route(long long t){
        vector<long long> res(V);
        long long i=0;
        for(long long cur=t;cur!=-1;cur=prev[cur]){
            res[V-1-i]=cur;
            i++;
        }
        return res;
    }
};