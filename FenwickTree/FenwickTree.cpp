//FenwickTree
//0-indexed
template<class T>
struct FenwickTree{
    //FenwickTreeの大きさ
    int N;

    vector<T> A;
    FenwickTree():N(0){}
    FenwickTree(int n):N(n),A(n,0){}

    //A[i]+=x
    //O(log n)
    void add(int i,T x){
        assert(0<=i&&i<N);
        i++;
        while(i<=N){
            A[i-1]+=x;
            i+=i&-i;
        }
    }

    //[a,b)の総和 O(log n)
    T sum(int a,int b){
        assert(0<=a&&a<=b&&b<=N);
        return sum(b)-sum(a);
    }

    //[0,i)の総和 O(log n)
    T sum(int i){
        T s=0;
        while(i>0){
            s+=A[i-1];
            i-=i&-i;
        }
        return s;
    }
};