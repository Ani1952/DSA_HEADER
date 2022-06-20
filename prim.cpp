#include<bits/stdc++.h>
using namespace std;

int extractmin(bool mst[] , int dist[] , int n){
    int k = INT_MAX;
    int mi;
    for(int i= 0 ; i<n ; i++){
        if(mst[i] == false && dist[i] <= k){
            k = dist[i] , mi = i;
        }
    }
    return mi;
}

void print(int parent[] , int v , int src){
    if(v < 0){
        return;
    }
    print(parent , parent[v] , src);
    if( v!= src){
        cout<<", ";
    }
   
    cout<<char(65+v);
}

void prims(int g[][100] , int src , int n){
    int dist[n];
    for(int i=0 ; i<n ;i++){
        dist[i] = INT_MAX;
    }
    bool mst[n];
    for(int i=0 ; i<n ;i++){
        mst[i] = false;
    }
    int parent[n];
    for(int i=0 ; i<n ; i++){
        parent[i] = -1;
    }
    dist[src] = 0;
    
    for(int i=0 ; i<n ; i++){
        int m = extractmin(mst , dist , n);
        mst[m] = true;
        for(int j = 0 ; j<n ; j++){
            if(g[m][j] != 0 && mst[j] == false &&  dist[m] + g[m][j] < dist[j]){
                dist[j] =  dist[m] + g[m][j];
                parent[j] = m;
            }
        }
        
    }

    for(int i=0 ; i<n ;i++){
        if(i == src)
            continue;
        print(parent,i,src);
        cout<<" --->  "<<dist[i];
        cout<<endl;
    }

}


int main(){
    fstream infile;
    infile.open("dijkstra.txt", ios::in);
    if(!(infile)){
        cout<<"Error to open file";
        exit(0);
    }
    int v;
    infile>>v;
    int graph[100][100];
    for(int i=0 ; i<v ; i++){
        for(int j=0 ; j<v ; j++){
            infile>>graph[i][j];
        }
    }
    prims(graph,0,v);
}