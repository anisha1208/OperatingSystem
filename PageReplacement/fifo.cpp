// First In First Out Page Replacement Algo

#include <bits/stdc++.h>
using namespace std;

void fifo(int f,int p, int ps[]){
    queue<int> q;
    int faults=0, ref[p];
    for(int i=0;i<p;i++){
        if(ref[ps[i]]!=true){
            q.push(ps[i]);
            ref[ps[i]]=true;
            if(q.size()>f){
                int p=q.front();
                ref[p]=false;
                q.pop();
            }
            faults++;
        }
    }
    cout<<"No. of faults = "<<faults<<"\n";
    cout<< "No. of Hits = "<<p-faults<<"\n"; 
    return;
}

int main(){

int frames,pages;
cout<<"Enter number of frames: ";
cin>>frames;
cout<<"Enter number of pages: ";
cin>>pages;
int ps[pages];
cout<<"Enter page sequence:\n";
for(int i=0;i<pages;i++){
    cin>>ps[i];
}
fifo(frames,pages,ps);
return 0;
}