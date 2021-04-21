#include <iostream>
using namespace std;

long long n;
long long m;
long long a[1000001];
long long mangdem[1000001];
void sort(int l,int r){
    long long x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j){
            long long t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
}
long long chatduoc(int i){
    long long docaomin = a[i-1];
    long long tong = mangdem[i]-(docaomin*(n-i+1));
    //cout <<i <<" " <<tong <<endl;
    
    if (tong==m) return docaomin;
    //cout <<(m-tong)/(n-i+1) <<" " <<endl;
    if (tong < m){
        docaomin -= (m-tong)/(n-i+1);
        return docaomin;
    }
    if (tong>m){
        docaomin += (tong-m)/(n-i+1);
        if (docaomin > a[i]) return -1;
        return docaomin;
    }
}
void XuLi(){
    scanf("%lld %lld\n",&n,&m);
    for (long long i = 1;i<=n;i++){
        scanf("%lld ",&a[i]);
        
    }
    sort(1,n);
    mangdem[n] = a[n];
    for (int i = n-1;i>=1;i--){
        mangdem[i] = mangdem[i+1] + a[i];
        //cout <<mangdem[i] <<" ";
    }
    /*for (int i = 1;i<=n;i++){
        cout <<mangdem[i] <<" ";
    }
    cout <<endl;
    for (int i = 1;i<=n;i++){
        cout <<a[i] <<" ";
    }
    cout <<endl; */
    a[0] = 0;
    mangdem[0] = 0;
    for (int i = 1;i<=n;i++){
        if (chatduoc(i)!=-1){
            cout <<chatduoc(i) <<endl;
            break;
        }
    }
    
    
}

int main(){
    freopen("chatgo.inp","r",stdin);
    freopen("chatgo.out","w",stdout);
    XuLi(); return 0;
}