#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

struct node {
    int x,y;
    int f;
    int g;
    int h;
    int px,py;
    //int level;
    //a.f = g+h a.g = 0 a.h = distance(a,b) a.level = 0 
};
vector<node> open;
vector<node> close;
vector<node> path;
node a;
node b;
bool error;
int m,n;
node s[4];
char maze[2001][2001];
bool is_wall(node X){
    return maze[X.x][X.y] == '#';
}
bool is_valid(node X){
    return (X.x >= 0) && (X.x < m) && (X.y >=0) && (X.y < n) && (!is_wall(X));
}
int distance(node X,node Y){
    return abs(X.x - Y.x) + abs(X.y - Y.y);
}
bool is_desti(node X){
    
    //cout <<r <<endl;
    return X.x==b.x && X.y==b.y;
}
bool is_children(node C,node P){
    return (C.px == P.x) && (C.py==P.y);
}

void input(){
    error = false;
    scanf("%d %d\n",&m,&n);
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++){
            cin >>maze[i][j];
            if (maze[i][j]=='A') {
                a.x = i;
                a.y = j;
                a.g = 0;
                a.f = 0;
                a.px = a.x;
                a.py = a.y;
            }
            else if (maze[i][j]=='B'){
                b.x = i;
                b.y = j;
            }
        }
    }
    
}

void process(){
    if (error==true) return;
    path.push_back(a);
    open.push_back(a);
    while (!open.empty()){
        //sort(0,open.size()-1);
        //cout <<'a' <<endl;
        node d = open[0];
        int leastF = open[0].f;
        int index = 0;
        bool current_node_is_a_children = false;
        for (int i = 0;i<open.size();i++){
            if (open[i].f == leastF){
                if (is_children(open[i],path[path.size()-1])){
                    leastF = open[i].f;
                    index = i;
                    d = open[i];
                    current_node_is_a_children = true;
                }
            }
            else if (open[i].f < leastF){
                leastF = open[i].f;
                d = open[i];
                index = i;
            }
        }
        //cout <<'b' <<endl;
        open.erase(open.begin() + index);
        //cout <<'c' <<endl;
        if (current_node_is_a_children==true){
            path.push_back(d);
        }
        else {
            int bindex;
            for (int i = path.size()-1;i>=0;i--){
                if (is_children(d,path[i])==false){
                    bindex = i;
                }
            }
            path.erase(path.begin()+bindex,path.end());
            path.push_back(d);
        }
        for (int i = 0;i<4;i++){
            switch(i){
                case 0:
                    s[i].x = d.x-1;
                    s[i].y = d.y;
                    s[i].g = d.g + distance(s[i],d);
                    s[i].h = distance(b,s[i]);
                    s[i].f = s[i].g + s[i].h;
                    s[i].px = d.x;
                    s[i].py = d.y;
                    //s[i].level = d.level + 1;
                    break;
                case 1:
                    s[i].x = d.x;
                    s[i].y = d.y-1;
                    s[i].g = d.g + distance(s[i],d);
                    s[i].h = distance(b,s[i]);
                    s[i].f = s[i].g + s[i].h;
                    s[i].px = d.x;
                    s[i].py = d.y;
                    //s[i].level = d.level + 1;
                    break;
                case 2:
                    s[i].x = d.x+1;
                    s[i].y = d.y;
                    s[i].g = d.g + distance(s[i],d);
                    s[i].h = distance(b,s[i]);
                    s[i].f = s[i].g + s[i].h;
                    s[i].px = d.x;
                    s[i].py = d.y;
                    //s[i].level = d.level + 1;
                    break;
                case 3:
                    s[i].x = d.x;
                    s[i].y = d.y+1;
                    s[i].g = d.g + distance(s[i],d);
                    s[i].h = distance(b,s[i]);
                    s[i].f = s[i].g + s[i].h;
                    s[i].px = d.x;
                    s[i].py = d.y;
                    //s[i].level = d.level + 1;
                    break;
            }
        }
        //cout <<'d' <<endl;
        for (int i = 0;i<4;i++){
            bool can = true;
            if (!is_desti(s[i])){
                if (is_valid(s[i])){
                    //cout <<'e' <<endl;
                    for (int j = 0;j<open.size();j++){
                        if (distance(open[j],s[i])==0){
                            if (open[j].f < s[i].f){
                                can = false;
                                //cout <<"This is a break\n";
                                break;
                            }
                        }
                    }
                    //cout <<'f' <<endl;
                    if (can==true){
                        for (int j = 0;j<close.size();j++){
                        if (distance(close[j],s[i])==0){
                            if (close[j].f < s[i].f){
                                can = false;
                                //cout <<"This is a break\n";
                                break;
                            }
                        }
                    }
                    }
                    //cout <<'g' <<endl;
                }
                else can=false;
            }
            if (can==true){
                open.push_back(s[i]);
                //cout <<'h' <<endl;
            }
        }   
        if (is_desti(d)){
            return;
        }
        //cout <<d.x <<" " <<d.y <<endl;
        
        
        //cout <<'i' <<endl;
        close.push_back(d);
        //cout <<'k' <<endl;
    }
}

int main(){
    freopen("maze.inp","r",stdin);
    freopen("maze.out","w",stdout);
    input();
    process();
    if (error==true) return 0;
    cout <<"The path to solution is:\n";
    for (int i = 0;i<path.size();i++){
        if (distance(path[i],a)!=0 && distance(path[i],b)!=0){
            maze[path[i].x][path[i].y] = '+';
        }
        cout <<path[i].x <<" " <<path[i].y <<endl;
    }
    cout <<"The maze:\n";
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++){
            cout <<maze[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}