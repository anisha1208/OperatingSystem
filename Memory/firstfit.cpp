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
    for(int j=0;j<nb;j++){
        if(blocks[j]>=processes[i]){
            alloc[i]=j;
            blocks[j]-=processes[i];
            break;
        }
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