// Circular Scan


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Here 200 tracks is considered as the disk size

void cscan(int n,int arr[],int head,int dir){
    int curr,seekops=0,complete=0,temp,end;
    vector<int> seq;
    seq.push_back(head);
    vector<int> left,right,first, second;

    if(dir==0){
        left.push_back(0);
    }
    else if(dir==1){
        right.push_back(199);
    }

    for(int i=0;i<n;i++){
        if(arr[i]<head){
            left.push_back(arr[i]);
        }
        if (arr[i]>head){
            right.push_back(arr[i]);
        }
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    
    if(dir==0){
        sort(left.begin(), left.end(), greater<int>());
        sort(right.begin(), right.end(), greater<int>());
        first=left;
        second=right;
        end=199;
    }
    else if(dir==1){
        first=right;
        second=left;
        end=0;
    }

    for(int i=0;i<first.size();i++){
        curr=first[i];
        seq.push_back(curr);
        seekops+=abs(curr-head);
        head=curr;
    }

    head=end;
    seekops+=199;
    seq.push_back(head);

    for(int i=0;i<second.size();i++){
        curr=second[i];
        seq.push_back(curr);
        seekops+=abs(curr-head);
        head=curr;
    }

    cout<<"Sequence : ";
    for(int i=0;i<seq.size()-1;i++){
        cout<<seq[i]<<" -> ";
    }
    cout<<seq[seq.size()-1]<<"\n";

    cout<<"Total Seek Operations: "<<seekops<<"\n";

}

int main(){
    int n,head,dir;
    cout<<"Enter number of processes : ";
    cin>>n;
    int arr[n];
    cout<<"Enter request queue : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter direction, 1 for Right, 0 for Left: ";
    cin>>dir;
    cout<<"Enter current position of head: ";
    cin>>head;

    cout<<"Request Queue is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<"\n\n";
    cscan(n,arr,head,dir);
    return 0;
}