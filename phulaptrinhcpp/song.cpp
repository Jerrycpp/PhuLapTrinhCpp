#include <iostream>
using namespace std;
struct Song{
    int tt;
    long long repeat,time;
};

int n,m;
Song arr[100001];
long long Xet[100001];
long long mangdem[100001];
void Input(){
    scanf("%d %d\n",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%lld %lld\n",&arr[i].repeat,&arr[i].time);
        arr[i].tt = i;
    }
    for (int i = 1;i<=m;i++){
        scanf("%lld",&Xet[i]);
    }
    mangdem[0] = 0;
    for (int i = 1;i<=n;i++){
        mangdem[i] = mangdem[i-1]+(arr[i].repeat*arr[i].time);
    }
}
int search(long long t, int l,int r){
    int mid = (l+r)/2;
    //cout <<mangdem[mid] <<" " <<t <<endl;
    if (t>mangdem[mid-1]&&t<=mangdem[mid]) return mid;
    else if (t>mangdem[mid]) return search(t,mid+1,r);
    else if (t<mangdem[mid]) return search(t,l,mid-1);
    return -1;
}
void XuLi(){
    Input();
    for (int i = 1;i<=m;i++){
        cout <<search(Xet[i],1,n) <<endl;
    }
}

int main(){
    freopen("song.inp","r",stdin);
    freopen("song.out","w",stdout);
    XuLi(); return 0;
}