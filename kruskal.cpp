#include<bits/stdc++.h>
using namespace std;

struct addme
{
    long long int u;
    long long int v;
    long long int weigh;
};

vector<struct addme> graph;
vector<long long int> parent;
long long int ct = 0;
long long int sum = 0;

long long int rootme(long long int x)
{
    while(parent[x]!=x)
    {
        x = parent[x];
    }

    return x;
}

void getunion(long long int a, long long int b)
{
    long long int root_a = rootme(a);
    long long int root_b = rootme(b);
    parent[root_a] = root_b;
    return;
}


long long int find(long long int x, long long int  y)
{
    if(rootme(x)==rootme(y))
    {
        return 0;
    }

    else
    {
        return 1;
    }
}

void kruskal(long long int e,long long int n)
{
    long long int i;
    for(i=0;i<e;i++)
    {
        if(ct==n-1)
        {
            return;
        }

        if(find(graph[i].u,graph[i].v) == 1)
        {
            getunion(graph[i].u,graph[i].v);
            sum = sum + graph[i].weigh;
            ct++;
        }

    }
}

bool comp(addme a,addme b)
{
    return a.weigh < b.weigh;
}

void sortme()
{
    sort(graph.begin(),graph.end(),comp);
}

int main()
{
    long long int n,e,i,x,y,w;
    scanf("%lld %lld",&n,&e);
    parent.resize(n);

    for(i=0;i<n;i++)
    {
        parent[i] = i;
    }

    for(i=0;i<e;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&w);
        x--;
        y--;

        addme node1;
        node1.u = x;
        node1.v = y;
        node1.weigh = w;
        graph.push_back(node1);
    }

    sortme();
    kruskal(e,n);

    printf("%lld",sum);
}

