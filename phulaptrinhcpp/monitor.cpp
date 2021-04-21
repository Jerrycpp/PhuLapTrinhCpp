#include <iostream>
using namespace std;


int n;
long long a[100001];

void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
}
void XuLi(){
    Input();
    int max = 0;
    long long int firstid = 0;
    for (int i = 1;i<=n;i++){
        for (int j = i+1;j<=n;j++){
            if (a[j]==a[i]){
                if (j-i+1>max) {max = j-i+1; firstid = a[i];}
            }
        }
    }
    cout <<firstid <<endl <<max;
}

int main(){
    freopen("monitor.inp","r",stdin);
    freopen("monitor.out","w",stdout);
    XuLi(); return 0;
}