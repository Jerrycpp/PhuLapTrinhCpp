    #include <iostream>
    using namespace std;

    struct HS {
        string name;
        int toan;
        int tin;
        int tong;
        int tt;
    };
    int n;
    HS a[1000001];
    void Input(){
        scanf("%d\n",&n);
        for (int i = 1;i<=n;i++){
            getline(cin,a[i].name);
            scanf("%d %d\n",&a[i].toan,&a[i].tin);
            a[i].tong = a[i].toan+a[i].tin;
            a[i].tt = i;
        }
    }
    bool comp(HS a, HS b){
        if (a.tong>b.tong) return true;
        else if (a.tong<b.tong) return false;
        else if (a.tong == b.tong) {
            if (a.tin>b.tin) return true;
            else if (a.tin<b.tin) return false;
            else if (a.tin==b.tin){
                if (a.tt<b.tt) return true;
                else return false;
            }
        }
        
    }
    void sort(int l,int r){
        HS x = a[(l+r)/2];
        int i = l;
        int j = r;
        while (i<=j){
            while (comp(x,a[i])==true) i++;
            while (comp(a[j],x)==true) j--;
            if (i<=j){
                HS t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++;
                j--;
            }
        }
        while (i<r) sort(i,r);
        while (l<j) sort(l,j);
    }
    void XuLi(){
        Input();
        sort(1,n);
        for (int i = 1;i<=n;i++){
            cout <<a[i].tt <<endl <<a[i].name <<endl;
        }
        
    }

    int main(){
        freopen("chon.inp","r",stdin);
        freopen("chon.out","w",stdout);
        XuLi(); return 0;
    }