#include<iostream>
#include<vector>
using namespace std;


#define v 6  // define the number of vertices in the graph
vector<float> averages; // vector to store average values

//finding minimum distance
int miniDist(int distance[], bool Tset[]){ 
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<v;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}


void DijkstraAlgo(int graph[v][v], int src) 
{
    float total = 0; //to calculate average time
    int distance[v];                            
    bool visited[v];   // bool array to store the visited and unvisited nodes
    
     
    //initializing procedure
    for(int k = 0; k<v; k++)
    {
        distance[k] = INT_MAX;  // setting the distance to all the vertices from source as zero
        visited[k] = false; // setting all vertices as unvisited
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    //
    for(int k = 0; k<v; k++)                           
    {
        int m=miniDist(distance, visited); 
        visited[m]=true;
        for(int k = 0; k<v; k++)                  
        {
            // updating the distance of neighbouring vertex
            //realization procedure
            if(!visited[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }

    cout << "Source Node is " << src << endl;
    for(int k = 0; k<v; k++)                      
    { 
        if (k == src){
            continue;
        }
        cout << "Average time taken to Node " << k << " = " << distance[k] << endl;  
        total += distance[k];
    }
    double average = total/(v-1);
    //cout << "Average Time = " << average << endl;
    averages.push_back(average);
}


void printAverages(vector<float> avg){    
    for (int j=0; j < v; j++){
        cout << "Average Time taken from Node " << j << " is " 
        << avg[j] << endl;
    }
}


void printmincity(vector<float> avg){
    float min = (float)INT_MAX;
    cout << "The City that have smallest average ";
    for (int k=0; k < v; k++){
        if (avg[k] <= min){
            min = avg[k];
            cout << k << " ";
        }
    }
}




int main(){
    int graph[v][v] = {{0, 10, 0, 0 ,15, 5}
    , {10, 0, 10, 30, 0, 0}
    , {0, 10, 0, 12, 5, 0}, 
    {0, 30, 12, 0, 0, 20},
    {15, 0, 5, 0, 0, 0}, 
    {5, 0, 0, 20, 0, 0}};

  
    
    for (int j=0; j < v; j++){
        DijkstraAlgo(graph, j);
        cout << endl;

    }

    // printAverages(averages);
    // printmincity(averages);
    

    
}
