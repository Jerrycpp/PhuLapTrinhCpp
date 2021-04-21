#include <iostream>
using namespace std;

string s;
void Input(){
    getline(cin,s);
}
bool DoiDuoc(string a){
    int mo = 0;
    int dong = 0;
    for (int i = 0;i<a.length();i++){
        if (a[i]=='(') mo++;
        else if (a[i]==')') dong++;
    }
    if (mo!=dong) return false;
    else return true;
}
int CanDoi(string a){
    int t = 0;
    for (int i = 0;i<a.length();i++){
        if (a[i]=='('&&a[i+1]!=')') t++;
    }
    return t;
}
void XuLi(){
    Input();
    if (DoiDuoc(s)==false) {
        cout <<-1;
        return;
    }
    cout <<CanDoi(s);
}

int main(){
    freopen("parentheses.inp","r",stdin);
    freopen("parentheses.out","w",stdout);;
    XuLi(); return 0;
}