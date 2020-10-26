//ダブリング
struct doubling{
    int logk,n;
    vector<vector<int>> Doubling;

    //N要素でk回進んだ先を求める
    doubling(long long k,int N):n(N),Doubling(N){
        logk=1;
        while((1LL<<logk)<k)logk++;
        for(int i=0;i<N;i++){
            Doubling[i].resize(logk);
        }
    }

    //1回進むとiからA[i]に進む配列
    //A[i]は0-indexedで各要素がn未満
    void setting(vector<int>& A){
        for(int i=0;i<n;i++){
            Doubling[i][0]=A[i];
        }
        for(int k=0;k<logk-1;k++){
            for(int i=0;i<n;i++){
                Doubling[i][k+1]=Doubling[Doubling[i][k]][k];
            }
        }
    }

    //K回進んだ先を求める
    int prod(long long K){
        int now=0;
        for(int k=0;K>0;k++){
            if(K&1)now=Doubling[now][k];
            K=K>>1;
        }
        return now;
    }
};