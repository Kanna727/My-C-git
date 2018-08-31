#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> multiply(vector<vector<int>> F, vector<vector<int>> M){
    vector<vector<int>> t;
    int n = F.size();
    t.resize(n, vector<int>(n,0));
    for(int i=0; i<F.size();i++){
        for(int j=0; j<F.size();j++){
            t[i][j]= 0;
            for(int k=0;k<F.size();k++){
                t[i][j] += F[i][k] * M[k][j];
            }
        }
    }
    return t;
}

vector<vector<int>> kWalks(vector<vector<int>> adj, int k){
    if(k==0||k==1) return adj;
    vector<vector<int>> temp = adj;
    adj = kWalks(adj, k/2);
    //cout<<k<<" ";
    adj = multiply(adj, adj);
    if(k & 1) adj = multiply(adj, temp);
    return adj;
}

int main()
{
    std::cout << "Enter no of nodes in the graph: ";
    int n, s, d;
    cin>>n;
    vector<vector<int>> adj;
    adj.resize(n, vector<int>(n,0));
    //int adj[n][n] = {0};
    int maxEdges= n*(n-1);
    std::cout << "NOTE!!: Consider the nodes are labelled from 0 to n-1" << endl;
    while(maxEdges--){
        std::cout << "Enter edge(-1 -1 to exit): ";
        cin>>s>>d;
        if((s == -1) && (d == -1)) break;
        adj[s][d] = 1;
    }

    std::cout << "Enter the length of the walk: ";
    int k;
    cin>>k;
    std::cout << "Enter the source and destination: ";
    cin>>s>>d;

    vector<vector<int>> res = kWalks(adj, k);

    cout<<res[s][d]<<endl;
    
    system("pause");
    return 0;
}