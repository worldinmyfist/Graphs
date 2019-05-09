#include<bits/stdc++.h>
using namespace std;

const int sz = 1000;
priority_queue <pair <int,int> , vector < pair <int,int> > , greater<pair<int,int> > > pq;
vector < pair<int,int> > graph[sz];
vector <int> dist;

void djikstra(int src)
{
    dist[src] = 0;
    pq.push(make_pair(dist[src],src));

    while(!pq.empty()){
        
        int s = pq.top().second;
        pq.pop();
        auto itr = graph[s].begin();
        
        for(;itr!=graph[s].end();itr++)
        {
            if(dist[itr->first]>dist[s] + itr->second)
            {
                dist[itr->first] = dist[s] +itr->second;
                pq.push(make_pair(dist[itr->first],itr->first));
            }
        }
    }
}

int main()
{
    int n,e,i,x,y,v,j,ew;

    scanf("%d %d",&n,&e);
    dist.resize(n);

    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&x,&y,&ew);
        x--;
        y--;
        graph[x].push_back(make_pair(y,ew));
        graph[y].push_back(make_pair(x,ew));
    }


    for(i=0;i<n;i++)
    {
        dist[i] = sz;
    }

    djikstra(0);

    for(i=0;i<n;i++)
    {
        printf("%d %d\n",i+1,dist[i]);
    }
}
