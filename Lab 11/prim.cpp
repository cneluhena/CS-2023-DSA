#include<bits/stdc++.h>
using namespace std;

#define V 6		//Number of vertices

int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];		
	vector<int> value(V, INT_MAX);	
	vector<bool> setMST(V,false);	

	parent[0] = -1;	
	value[0] = 0;	

	for(int i=0;i<V-1;++i)
	{
		
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	

    
		for(int j=0;j<V;++j)
		{
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}


	//Print MST
	for(int i=1;i<V;++i)
		cout<<parent[i]<<"->"<<i<<"  weight = "<<graph[parent[i]][i]<<"\n";
		}


int main()
{
	int graph[V][V] = { {0, 3, 0, 0, 0, 1},
						{3, 0, 2, 1, 10, 0},
						{0, 2, 0, 3, 0, 5},
						{0, 1, 3, 0, 5, 0},
						{0, 10, 0, 5, 0, 4},
						{1, 0, 5, 0, 4, 0} };

	findMST(graph);	
	return 0;
}
