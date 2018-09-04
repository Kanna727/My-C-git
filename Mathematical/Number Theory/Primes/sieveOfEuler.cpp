#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main()
{
    long long int n;
    cin>>n;
    struct Node* head =  NULL;
    Node* v[n+1];
    for(long long int i=0;i<=n;i++) {
        v[i] = new Node;
        v[i]->data = i;
        v[i]->next = NULL;
        if(i==0){
            v[i]->prev = NULL;
        }
        else {
            v[i-1]->next = v[i];
            v[i]->prev = v[i-1];
        }
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(long long int i=4;i<=n;i+=2) {
        v[i]->data == -1;
        if(v[i]->prev!=NULL)v[i]->prev->next = v[i]->next;
        if(v[i]->next!=NULL)v[i]->next->prev = v[i]->prev;
    }
    for(long long int i=9;i<=n;i+=6) {
        v[i]->data == -1;
        if(v[i]->prev!=NULL)v[i]->prev->next = v[i]->next;
        if(v[i]->next!=NULL)v[i]->next->prev = v[i]->prev;
    }
    long long int p=5;
    while(p*p<=n){
        long long int i=p;
        long long int k=p;
         while(k<=(n/p)&&(v[k]->next!=NULL)){
            
             v[i*k]->data = -1;
             if(v[i*k]->prev!=NULL)v[i*k]->prev->next = v[i*k]->next;
             if(v[i*k]->next!=NULL)v[i*k]->next->prev = v[i*k]->prev;
             long long int t = k;
             while(i*t*i<=n){
                 v[i*t*i]->data = -1;
                 if(v[i*t*i]->prev!=NULL)v[i*t*i]->prev->next = v[i*t*i]->next;
                if(v[i*t*i]->next!=NULL)v[i*t*i]->next->prev = v[i*t*i]->prev;
                t = i*t;
             }
             k = v[k]->next->data;
        }
         p=v[p]->next->data;
     }
    long long int i=2;
    //long long int c=1;
    while(v[i]->next!=NULL){
        cout<<v[i]->data<<" ";
        i=v[i]->next->data;
        
        //c++;
    }
    cout<<v[i]->data<<endl;
    //cout<<c<<endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    std::cout << "time elapsed: " << duration << endl;
    
    system("pause");
    return 0;
}