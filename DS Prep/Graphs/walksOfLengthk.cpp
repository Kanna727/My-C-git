/*
    PROBLEM STATEMENT: Print the no of all possible walks of length k between some s and d
*/

#include <bits/stdc++.h>
using namespace std;

int commonNeighbours(vector<vector<int>> &adj, int s, int d){
    int n = adj.size();
    int count = 0;
    for(int i=0;i<n;i++){
        if(adj[s][i] == 1 && adj[i][d] == 1){
                count++;
        }
    }
    return count;
}

void multiply(vector<vector<int> > &F, vector<vector<int> > &M){
    vector<vector<int> > t;
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

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            F[i][j] = t[i][j];            
        }
        cout<<endl;
    }
    //return t;
}

void kWalks(vector<vector<int> > &adj, int k){
    if(k==0||k==1) return;
    vector<vector<int> > &temp = adj;
    kWalks(adj, k/2);
    //cout<<k<<" ";
    multiply(adj, adj);
    if(k & 1) multiply(adj, temp);
    //return adj;
}

/*  NOTE!!! THE MATRIX EXPONENTIATION METHOD IS RECOMMENDED WHEN k>2.
    FOR k=2, this question can be solved in O(V), whereas matrix exponentiation takes O((V^4)logk).
    When k=2, this question is equivalent to finding number of common neighbours between given source and destination
    which can be done in O(V)*/

int main()
{
    std::cout << "Enter no of nodes in the graph: ";
    int n, s, d;
    cin>>n;
    vector<vector<int> > adj;
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

    if(k!=2) { 
        kWalks(adj, k);
        cout<<adj[s][d]<<endl; 
    } else{
        std::cout << commonNeighbours(adj, s, d) << endl;
    }
    
    system("pause");
    return 0;
}
