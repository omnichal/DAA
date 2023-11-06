#include<iostream>
using namespace std;

struct node{
  int s;
  int e;
  int w;
};

node val[20];

void input(int n){
  for(int i=0;i<n;i++){
    cout<<"\n"<<"Enter the starting vertex:"<<"\n";
    cin>>val[i].s;
    cout<<"\n"<<"Enter the ending vertex:"<<"\n";
    cin>>val[i].e;
    cout<<"\n"<<"Enter the weight of the edge:"<<"\n";
    cin>>val[i].w;  
  }
}

void display(int n){
  cout<<"\n";
  cout<<"S"<<"\t"<<"E"<<"\t"<<"W"<<"\n";
  for(int i=0;i<n;i++){
    cout<<val[i].s<<"\t"<<val[i].e<<"\t"<<val[i].w<<"\n";
  }
}

void bellmanFord(int n, int cost[],int source){
  for(int i=0;i<n;i++){
    if(i==source){
      cost[i]=0;
    }
    else{
      cost[i]=999;
    }
  }

  cout<<"\n"<<"Relaxation iterations:"<<"\n";
  // Relax edges repeatedly
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      int u = val[j].s;
      int v = val[j].e;
      int weight = val[j].w;
      if (cost[u] + weight < cost[v]) {
        cost[v] = cost[u] + weight;
      }
    }
    // cout<<"\n"<<"Iteration "<<i+1<<": "<<"\n";
    // for(int i=0;i<n;i++){
    //   cout<<cost[i]<<"\t";
    // }
  }
}

int main(){
  int n,source;
  cout<<"\n"<<"Enter the number of edges:"<<"\n";
  cin>>n;
  int cost[n];
  input(n);
  display(n);
  cout<<"\n"<<"Enter the source vertex:"<<"\n";
  cin>>source;

  bellmanFord(n, cost, source);

  cout << "Shortest distances from source " << source << " to other     vertices:" << endl;
  cout << "Vertex\tDistance" << endl;
  for (int i = 0; i < n; i++) {
    cout << i << "\t" << cost[i] << endl;
  }
  
  return 0;
}