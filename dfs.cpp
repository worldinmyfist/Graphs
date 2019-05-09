#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > graph;
vector<int> visit;

void dfs(int s)
{
    int j;
    visit[s] = 1;
    for(j=0;j<graph[s].size();j++)
    {
        if(visit[graph[s][j]] == 0)
        {
            dfs(graph[s][j]);
        }
    }
    
    visit[s] = 2;
}

int main()
{
    int e,i,n,x,y,j;
    scanf("%d %d",&n,&e);
    graph.resize(n);
    visit.resize(n);
    
    for(i=0;i<n;i++)
    {
        visit[i] = 0;
    }

    for(i=0;i<e;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
    }
    
    for(i=0;i<n;i++)
    {
        if(visit[i] == 0)
        {
            dfs(i);
        }
    }
}
