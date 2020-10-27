//FenwickTree
template<class T>
struct FenwickTree{
    int N;
    vector<T> seg;

    //0で初期化する
    FenwickTree(int n):N(n),seg(n+1,0){}

    //i番目の要素にxを加える
    void add(int i,T x){
        for(int idx=i;idx>0;idx+=(idx&-idx)){
            seg[idx]+=x;
        }
    }

    //[0,i)の和
    T sum1(int i){
        T s(0);
        for(int idx=i;idx>0;idx-=(idx&-idx)){
            s+=seg[idx];
        }
        return s;
    }

    //[a,b)の和
    T sum2(int a,int b){
        return sum1(b)-sum1(a);
    }
};