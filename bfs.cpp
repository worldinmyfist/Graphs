#include<bits/stdc++.h>
using namespace std;

int n = 200010;
queue<int> q;
vector< vector<int> > graph;
vector<bool>visit(n,false);

void bfs(int s)
{
    q.push(s);

    while(!q.empty())
    {
        int i;
        int node = q.front();
        printf("%d ",q.front());
        q.pop();
        visit[node] = true;

        for( i=0; i<graph[node].size(); i++)
        {
            if(visit[graph[node][i]] == false)
            {
                visit[graph[node][i]] = true;
                q.push(graph[node][i]);
            }
        }
    }
}


int main()
{
    int e,n,i,x,y;

    scanf("%d %d",&n,&e);
    graph.resize(n);

    for(i=0;i<e;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
    }

    for(i=0;i<n;i++)
    {
        if(visit[i] == false)
        {
            bfs(i);
        }
    }
}
