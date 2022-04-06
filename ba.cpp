#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n,m,i,j,k;
    cout<<"Enter number of processses:";
    cin>>n;
    cout<<"Enter number of resources:";
    cin>>m;

    int all[n][m];
    int max[n][m];
    int avail[m];

    cout<<"Enter allocation:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>all[i][j];
        }
    }

    cout<<"Enter Max Needs:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    }

    cout<<"Enter Available:";
    for(int i=0;i<m;i++){
        cin>>avail[i];
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
        need[i][j] = max[i][j] - all[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
        if (f[i] == 0) {
    
            int flag = 0;
            for (j = 0; j < m; j++) {
            if (need[i][j] > avail[j]){
                flag = 1;
                break;
            }
            }
    
            if (flag == 0) {
            ans[ind++] = i;
            for (y = 0; y < m; y++)
                avail[y] += all[i][y];
                // cout<<"Available"<<avail[y]<<"\n";
            f[i] = 1;
            }
        }
        }
    }
    
    int flag = 1;
    
    //Safe Sequence check
    for(int i = 0;i<n;i++)
    {
            if(f[i]==0){
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }
    
    if(flag==1)
    {
        cout << "Following is a Safe Sequence" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] <<endl;
    }

    return 0;
}