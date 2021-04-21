#include <iostream>
using namespace std;

bool prime[20000001];
int p[2000001];
int SymP[2000001];
int m;
int n;
void Input(){
    scanf("%d\n",&n);
}
void TaoPrime(){
    for (int i = 0;i<=20000000;i++){
        prime[i] = true;
    }
    for (int i = 0;i<=20000000;i++){
        if (i==1||i==0) prime[i] = false;
        else if (prime[i]==true){
            for (int j = 2;j<=20000000/i;j++){
                prime[i*j] = false;
            }
        }
    }
}
void TaoSym(){
    int c = 0;
    for (int i = 2;i<=20000000-1;i++){
        if (prime[i]==true) {
            c++;
            p[c] = i;
        }
    }
    m = 0;
    for (int i = 2;i<=c-1;i++){
        if (p[i-1]+p[i+1]==2*p[i]){
            m++;
            SymP[m] = p[i];
        }
    }
}
bool tknp(int l,int r,int find){
    
    while (l<=r){
    int k = (l+r)/2;
    if (SymP[k]==find) return true;
    else if (SymP[k]<find) l = k+1;
    else if (SymP[k]>find) r = k-1;
    }
    return false;
}
void XuLi(){
    Input();
    TaoPrime();
    TaoSym();
    for (int i = 1;i<=n;i++){
        int a;
        cin >>a;
        if (prime[a]==false) cout <<"NO" <<endl;
        else {
            if (tknp(1,m,a)==true) cout <<"YES" <<endl;
            else cout <<"NO" <<endl;
        }
    }
}

int main(){
    freopen("symprime.inp","r",stdin);
    freopen("symprime.out","w",stdout);
    XuLi();
    return 0;

}