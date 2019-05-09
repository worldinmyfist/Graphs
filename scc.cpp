#include<bits/stdc++.h>
using namespace std;

int flag = 0;
vector< vector<int> > graph;
vector< vector<int> > rev;
vector<int> visit;
stack<int> st;

void revdfs(int s ,int n)
{
    int j;
    visit[s] = 1;

    for(j=0;j<rev[s].size();j++)
    {
        if(visit[rev[s][j]] == 0)
        {
            revdfs(rev[s][j],n);
        }
    }
    
    visit[s] = 2;
    printf("%d ",s);
    return ;
}

void dfs(int s ,int n)
{
    int j;
    visit[s] = 1;
    
    for(j=0;j<graph[s].size();j++)
    {
        if(visit[graph[s][j]] == 0)
        {
            dfs(graph[s][j],n);
        }
    }
    
    visit[s] = 2;
    st.push(s);
    return ;
}

int main()
{
    int e,i,n,x,y,j;

    scanf("%d %d",&n,&e);
    graph.resize(n);
    visit.resize(n);
    rev.resize(n);
    for(i=0;i<n;i++)
    {
        visit[i] = 0;
    }

    for(i=0;i<e;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        rev[y].push_back(x);
    }

    for(i = 0; i < n; i++)
    {
        if(visit[i] == 0)
        {
            dfs(i,n);
        }
    }

    for(i=0;i<n;i++)
    {
        visit[i] = 0;
    }

    while(!st.empty())
    {
        if(visit[st.top()]==0)
        {
            revdfs(st.top(),n);
            printf("\n");
        }
        st.pop();
    }
}
