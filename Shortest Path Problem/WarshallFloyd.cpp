//WarshallFloyd
//O(V^3)
template<class T>
struct WarshallFloyd{
    //頂点数
    int V;

    T tinf=numeric_limits<T>::max();
    vector<vector<T>> d;
    vector<vector<int>> to;

    WarshallFloyd(int v):V(v),d(v,vector<T>(v,tinf)),to(v,vector<int>(v)){
        for(int i=0;i<v;i++){
            d[i][i]=0;
            for(int j=0;j<v;j++){
                to[i][j]=j;
            }
        }
    }

    //xからyへコストcの辺を追加する
    void add(int x,int y,T c){
        assert(x>=0&&y>=0&&x<V&&y<V);
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
                    if(d[i][k]==tinf||d[k][j]==tinf){
                        continue;
                    }
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