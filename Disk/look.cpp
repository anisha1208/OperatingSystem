//Look Disk Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Here 200 tracks is considered as the disk size

void look(int n,int arr[],int head,int dir){

int curr,seekops=0,complete=0,temp;
    vector<int> seq;
    seq.push_back(head);
    vector<int> left,right;

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
    
    
    for(int r=0;r<2;r++){
        if(dir==0){
            for(int i=left.size()-1; i>=0;i--){
                curr=left[i];
                seq.push_back(curr);
                seekops+=abs(curr - head);
                head=curr;
            }
            dir=1;
        }

        else if(dir==1){
            for(int i=0; i<right.size();i++){
                curr=right[i];
                seq.push_back(curr);
                seekops+=abs(curr - head);
                head=curr;
            }
            dir=0;
        }
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
    look(n,arr,head,dir);
    return 0;
}