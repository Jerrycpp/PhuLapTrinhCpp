#include <iostream>
#include <string>
using namespace std;

string s;
int n,c;
void ghep(int start){
    string k = s;
    string add = "";
    for (int i = start;i<s.size();i++){
        add+=s[i];
    }
    s = add + k;
}
void XuLi(){
    
    scanf("%d %d\n",&n,&c);
    getline(cin,s);
    //cout <<s <<endl;
    for (int i = 1;i<=c;i++){
        ghep(n);
    }
    cout <<s;
}

int main(){
    freopen("cstring.inp","r",stdin);
    freopen("cstring.out","w",stdout);
    XuLi(); return 0;
}