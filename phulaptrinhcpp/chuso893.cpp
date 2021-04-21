#include <iostream>
#include <string>
using namespace std;

string s;
int n;
long long m;
void Input(){
    getline(cin,s);
    scanf("%d %lld",&n,&m);
}
string Rev(string S){
    string a = S;
    string b = "";
    for (int i = a.length()-1;i>=0;i--){
        b+=a[i];
    }
    return b;
}
int pow(int a,int k){
    if (k==0) return 1;
    int res = 1;
    for (int i = 1;i<=k;i++){
        res*=a;
    }
    return res;
}
void XuLi(){
    Input();
    int ori = s.size();
    s+=Rev(s);
    int TheNum;
    if (m<s.size()) TheNum = m;
    else TheNum = m%s.size();
    //cout <<s.length() <<endl;
    
    //cout <<s <<endl;
    //cout <<TheNum <<endl;
    if (pow(ori,n)<m){
        cout <<-1;
    }
    else cout <<s[TheNum-1];
}

int main(){
    freopen("chuso893.inp","r",stdin);
    freopen("chuso893.out","w",stdout);
    XuLi(); return 0;
}