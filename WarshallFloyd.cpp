//WarshallFloyd法
template<class T>
struct WarshallFloyd{
    int V;
    T tinf=numeric_limits<T>::max();
    vector<vector<T>> d;
    vector<vector<int>> to;

    //頂点数nのグラフを作成する
    WarshallFloyd(int n):V(n),d(n,vector<T>(n,tinf)),to(n,vector<int>(n)){
        for(int i=0;i<n;i++){
            d[i][i]=0;
            for(int j=0;j<n;j++){
                to[i][j]=j;
            }
        }
    }

    //頂点xから頂点yへコストcの辺を追加する
    void add(int x,int y,T c){
        d[x][y]=c;
    }

    //最短経路を計算する
    void build(){
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(d[i][k]==tinf||d[k][j]==tinf)continue;
                    if(d[i][j]>d[i][k]+d[k][j]){
                        d[i][j]=d[i][k]+d[k][j];
                        to[i][j]=to[i][k];
                    }
                }
            }
        }
    }

    //負閉路があるか判定する
    bool checknegative(){
        for(int i=0;i<V;i++){
            if(d[i][i]<0){
                return true;
            }
        }
        return false;
    }

    //無限にコストを下げられるなら-tinfになる
    void negativebuild(){
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(d[i][k]==tinf||d[k][j]==tinf)continue;
                    if(d[i][k]==-tinf||d[k][j]==-tinf){
                        d[i][j]=-tinf;
                        to[i][j]=to[i][k];
                        continue;
                    }
                    if(d[i][j]>d[i][k]+d[k][j]){
                        d[i][j]=-tinf;
                        to[i][j]=to[i][k];
                    }
                }
            }
        }
    }

    //xからyへのコストを求める
    //-tinfの時、無限にコストを下げられる
    T dist(int x,int y){
        return d[x][y];
    }

    //xからyへの経路を求める
    vector<int> route(int x,int y){
        vector<int> path;
        for(int i=x;i!=y;i=to[i][y]){
            path.emplace_back(i);
        }
        path.emplace_back(y);
        return path;
    }
};