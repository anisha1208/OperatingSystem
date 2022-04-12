#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

int nb,np;
cout<<"Enter number of blocks: ";
cin>>nb;
cout<<"Enter number of processes: ";
cin>>np;
int blocks[nb],processes[np],alloc[nb];
memset(alloc, -1,sizeof(alloc));

cout<<"Enter block sizes:\n";
for(int i=0;i<nb;i++){
    cin>>blocks[i];
}

cout<<"Enter processes sizes:\n";
for(int i=0;i<np;i++){
    cin>>processes[i];
}

for(int i=0;i<np;i++){
    int id=-1;
    for(int j=0;j<nb;j++){
        if(blocks[j]>=processes[i]){
            if(id==-1 or blocks[id]<blocks[j]){
                id=j;
            }
    }
    }

    if(id!=-1){
        alloc[i]=id;
        blocks[id]-=processes[i];
    }
}

cout<<"Allocation: \n";
cout<<"Process No.\tProcess Size\t\tBlock no.\n";
for (int i = 0; i < np; i++){
        cout << " " << i+1 << "    \t\t " << processes[i] << "\t\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout <<"\n";
    }

return 0;
}