//Count Queen Solutions with some specified queens
#include <bits/stdc++.h>
using namespace std;
int fix[30],n,k,out;
vector< pair<int,int> > ngu;

void zui(int p){
    if(p==n+1){
//        for(int i=0;i<ngu.size();i++){
//            printf("%d %d\n",ngu[i].first,ngu[i].second);
//        }
        out++;
//        printf("\n");
        return;
    }
    if(fix[p]!=0){
        zui(p+1);
        return;
    }
    for(int i=1;i<=n;i++){
        int cut=0;
        for(int j=0;j<ngu.size();j++){
            int x=ngu[j].first,y=ngu[j].second;
            if(y==i||abs(x-p)==abs(y-i)){
                cut=1;
                break;
            }
        }
        if(cut)continue;
        ngu.push_back({p,i});
        zui(p+1);
        ngu.pop_back();
    }
}

int main(){
    int a,b;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        fix[a]=b;
        ngu.push_back({a,b});
    }
    if(n==k){
        printf("1");
        return 0;
    }
    zui(1);
    printf("%d",out);
}#include <bits/stdc++.h>
using namespace std;
int fix[30],n,k,out;
vector< pair<int,int> > ngu;

void zui(int p){
    if(p==n+1){
//        for(int i=0;i<ngu.size();i++){
//            printf("%d %d\n",ngu[i].first,ngu[i].second);
//        }
        out++;
//        printf("\n");
        return;
    }
    if(fix[p]!=0){
        zui(p+1);
        return;
    }
    for(int i=1;i<=n;i++){
        int cut=0;
        for(int j=0;j<ngu.size();j++){
            int x=ngu[j].first,y=ngu[j].second;
            if(y==i||abs(x-p)==abs(y-i)){
                cut=1;
                break;
            }
        }
        if(cut)continue;
        ngu.push_back({p,i});
        zui(p+1);
        ngu.pop_back();
    }
}

int main(){
    int a,b;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        fix[a]=b;
        ngu.push_back({a,b});
    }
    if(n==k){
        printf("1");
        return 0;
    }
    zui(1);
    printf("%d",out);
}