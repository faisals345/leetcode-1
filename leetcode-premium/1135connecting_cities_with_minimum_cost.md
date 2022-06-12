This problem is a standard minimum spanning tree problem. There are two solutions: Prim and Kruskal algorithms.

There are two general solutions to the MST (Minimum Spanning Tree) problem. Prim algorithm is one of them. It constructs an MST from the point of view. The general idea is: Let the set of vertices in the graph G be U, first Arbitrarily choose a point in the graph G as the starting point a, add this point to the set V, and then find another point b from the set UV to make the weight of any point from b to V the smallest, then add point b to the set V ; And so on, the current set V={a,b}, and then find another point c from the set UV so that the weight of any point from c to V is the smallest, at this time point c is added to the set V until all vertices All were added to V, and an MST was constructed at this time. Because there are N vertices, the MST has N-1 edges. Each time a point is added to the set V, it means that an MST edge is found.

The Kruskal algorithm is based on the idea of ​​greed. First, we arrange all edges from smallest to largest according to their weights, and then select each edge in order. If the two endpoints of this edge do not belong to the same set, then merge them until all the points belong to the same set Until the collection. As for how to merge into a collection, then here we can use a tool and search collection. In other words, the Kruskal algorithm is a greedy algorithm based on union search.

{
    #include <bits/stdc++.h>
using namespace std;

int primsAlgo(vector<pair<int,int>> g[],int n){

    bool vis[n];
    memset(vis,false,sizeof(vis));

    priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> Q;

    
    Q.push({0,0}); // weight,node


    int ans=0;

    while(Q.empty()==false){
        auto best = Q.top();
        Q.pop();
        int to = best.second;
        int weight = best.first;

        if(vis[to]){
            continue;
        }
        ans+=weight;
        vis[to]=true;

        for(auto child: g[to]){
            if(vis[child.first]==false){
                Q.push({child.second,child.first});
            }
        }

    }

    return ans;
}


int main(){

    int n;
    int e;
    cin>>n>>e;
    vector<pair<int,int>> g[n];

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    cout<<primsAlgo(g,n);



    return 0;
}

}
