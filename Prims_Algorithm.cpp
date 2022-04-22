#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define n 6

// minkey()

int minkey(int key[], bool mstset[]){

int min = INT_MAX, min_index;

for(int i=0; i<n; i++)

 if(mstset[i] == false && key[i] < min)
   min = key[i], min_index = i;
  
  return min_index;

}

//print()

void print(int parent[],int  graph[n][n]){
int sum = 0;    
cout<<"\n----------------PRIMS ALGORITHM----------------\n";
cout<<"Edges"<<"\t"<<"weight"<<endl;

for(int i=1; i<n; i++)
{
cout<<char(parent[i] + 65)<<"<--->"<<char(i + 65)<<"   "<<graph[i][parent[i]]<<endl;
sum += graph[i][parent[i]];
}

cout<<"\nMINIMUM COST::"<<sum<<endl;
}




void prims(int graph[n][n]){

int parent[n];
int key[n];
bool mstset[n];

for(int i=0;i<n;i++)
  key[i] = INT_MAX, mstset[i] = false;
  key[0] = 0;
  parent[0] = -1;

// minkey function

  for (int i = 0; i < n-1; i++)
  {
    int u = minkey(key,mstset);
    mstset[u] = true;   
   
    

    for (int v = 0; v < n; v++)
    {
        if(graph[u][v] && mstset[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];

    }
    

  }
   // print the graph with minimum weights  
   print(parent , graph);

}





int main()
{
  int v;
  fstream fin;
  fin.open("sample.txt",ios::in | ios::out);
if(!fin){

   cout<<"Unable to open the file!!"<<endl;

}
else{

  int graph[n][n];
   for(int i=0; i<n; i++){
       
       for(int j=0 ; j<n; j++){

           fin>> graph[i][j];
       }
   }
  
  prims(graph);

 
}
     return 0;

}