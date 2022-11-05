#include<stdio.h>

int rank[];
int parent[];
int c[];


void makeSet(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
}

void DisjointUnionSets(int n)
{
    rank[n];
    parent[n];
    c[n];
    makeSet(n);
}

int find(int x)
{
    if(parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void union(int x, int y)
{
    xRoot = find(x);
    yRoot = find(y);
    
    if(xRoot == yRoot)
        return;
    
    if(rank[xRoot] > rank[yRoot])
    {
        parent[yRoot] = xRoot;
        // rank[xRoot]++;
    }
    else if(rank[xRoot] < rank[yRoot])
    {
        parent[xRoot] = yRoot;
        // rank[yRoot]++;
    }
    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}


int countIslands(int a[][])
{
    int n = 5;
    int m = 5;
    DisjointUnionSets(n*m);
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<m; k++)
        {
            if(a[j][k] == 0)
                continue;
            
            if(j+1 < n && a[j+1][k] == 1)
                union(j*m + k, (j+1)*m + k);
                
            if(j-1 >= 0 && a[j-1][k] == 1)
                union(j*m + k, (j-1)*m + k);
                
            if(k+1 < m && a[j][k+1] == 1)
                union(j*m + k, j*m + k+1);
                
            if(k-1 >= 0 && a[j][k-1] == 1)
                union(j*m + k, j*m + k-1);
                
            if(j-1 >= 0 && k+1 < m && a[j-1][k+1] == 1)
                union(j*m + k, (j-1*)m + k+1);
                
            if(j+1 < n  && k+1 < m && a[j+1][k+1] == 1)
                union(j*m + k, (j+1*)m + k+1);
                
            if(j-1 >= 0 && k-1 >= 0 && a[j-1][k-1] == 1)
                union(j*m + k, (j-1*)m + k-1);
                
            if(j+1 < n  && k-1 >= 0 && a[j+1][k-1] == 1)
                union(j*m + k, (j+1*)m + k-1);
        }
    }
    
    int number_of_Islands = 0;
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<m; k++)
        {
            if(a[j][k] == 1)
            {
                int x = find(j*m + k);
                
                if(c[x] == 0)
                {
                    number_of_Islands++;
                    c[x]++;
                }
                else
                    c[x]++;
            }
        }
    }
    return number_of_Islands;
}


void main()
{
    for(int i=0; i<n)
    {
        rank[i] = 0;
        c[i] = 0;
    }
    
    int a[][] ={{1, 1, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {1, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 0, 1, 0, 1}};
            
    print(countIslands(a));
}
