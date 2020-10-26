//要素の削除
template<class T>
void del(vector<T> &v,long long pos){
    swap(v[pos],v[v.size()-1]);
    v.pop_back();
}