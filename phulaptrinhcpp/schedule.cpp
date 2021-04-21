#include <iostream>
using namespace std;

struct Xe {
    
    long long int tp;
    long long int tg;
   
};
int N;
Xe a[100001];
void Input(){
    scanf("%d\n",&N);
    for (int i = 1;i<=N;i++){
        scanf("%lld",&a[i].tp);
        
    }
    scanf("\n");
    for (int i = 1;i<=N;i++){
        scanf("%lld",&a[i].tg);
        
    }
    /*for (int i = 1;i<=N;i++){
        cout <<a[i].tp <<" " <<a[i].tg;
        cout <<endl;
    }*/
}
bool Comp(Xe a, Xe b){
    long long t1 = a.tg*b.tp;
    long long t2 = a.tp*b.tg;
    if (t1>t2) return true;
    else return false;
}
void sort(int l,int r){
    Xe x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (Comp(x,a[i])) i++;
        while (Comp(a[j],x)) j--;
        if (i<=j){
            Xe t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (j>l) sort(l,j);
}
void XuLi(){
    Input();
    long long int tong = 0;
    sort(1,N);
    long long int ngay = 0;
    //for (int i = 1;i<=N;i++){
      //  cout <<a[i].tg <<" " <<a[i].tp <<endl;
    //}
    for (int i = 1;i<=N;i++){
        ngay+=a[i].tg;
       // cout <<ngay <<endl;
        tong += a[i].tp*ngay;
       // cout <<tong <<endl;
    }
    cout <<tong;
}

int main(){
    freopen("schedule.inp","r",stdin);
    freopen("schedule.out","w",stdout);
    XuLi(); return 0;
}