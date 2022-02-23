//Shortest Seek Time First Disk Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void sstf(int n, ll arr[],int head){
    ll done[n]={0};
    int seekops=0,shortest,curr=head;
    for(int i=0;i<n;i++){
            int ind=0;
            shortest=INT_MAX;
            for(int j=0;j<n;j++){
                    if(abs(curr-arr[j])<shortest and done[j]!=1){
                            ind=j;
                            shortest=abs(curr-arr[j]);
                    }
            }
        done[ind]=1;
        seekops+=shortest;
        curr=arr[ind];
    }
    cout<<"Total no. of Seek operations : "<<seekops<<"\n";
}

int main(){
    int n,head;
    cout<<"Enter number of processes : ";
    cin>>n;
    ll arr[n];
    cout<<"Enter request queue : \n";
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }

    cout<<"Enter current position of head: ";
    cin>>head;

    cout<<"Request Queue is : ";
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
    } 
    cout<<"\n";
    sstf(n,arr,head);
    return 0;
}