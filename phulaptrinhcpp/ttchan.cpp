#include <iostream>
using namespace std;

int main(){
freopen("ttchan.inp","r",stdin);
freopen("ttchan.out","w",stdout);
int sl;
scanf("%d",&sl);
int a[sl];
for (int i = 0;i<sl;i++) scanf("%d",&a[i]);
for (int i = 0;i<sl;i++){
if ((i+1)%2==0) printf("%d ",a[i]);

}
return 0;
}
