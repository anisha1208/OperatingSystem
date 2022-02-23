//First Come First Serve Disk Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void fcfs(int n, ll arr[],int head){
    int curr=head,seekops=0;
    for(int i=0;i<n;i++){
            seekops+=abs(arr[i]-curr);
            curr=arr[i];
    }

    cout<<"Total No. of seek operations : "<<seekops<<"\n";      
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
    fcfs(n,arr,head);
    return 0;
}