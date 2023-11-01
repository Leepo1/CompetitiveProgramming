#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
#include <fstream>

using namespace std;

int main(){
  ios::sync_with_studio(false);
  cin.tie(NULL);
  ifstream cin("destroyi.txt");
  ofstream cout("destroyo.txt");




  return 0;
}

























/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

bool visited[2005];


vector<int> calculate;
vector<int> Adj[2005];
int co=0;

void dfs(int c){
  visited[c]=true;
  co++;
  for(auto u : Adj[c]){
    if(!visited[u]){
      dfs(u);
    }
  }
}
void numbconnections(int n){
  for(int i=1; i<n; i++){
    if(!visited[i]){
      dfs(i);
    }
    calculate.push_back(co);
    co=0;
  }
}
int main(){
  ifstream cin("destroyi.txt");
  ofstream cout("destroyo.txt");
  int t;
  cin>> t;

    vector<pair<int,int>> v;
    long long answer=0;
    int n,m,d;
    cin>> n >> m >> d;

    for(int i=0; i<2005; i++){
      visited[i]=false;
    }

    pair<int,int> fc[m];

    vector<pair<int,int>> c;

    for(int i=0; i<m; i++){

      cin>> fc[i].first >> fc[i].second;

    }

    int destruction[d];
    for(int i=0; i<d; i++){
      cin>> destruction[i];
    }

    for(int i=0; i<m; i++){
        c.push_back(fc[i]);
    }
    for(int i=0; i<c.size(); i++){
      Adj[c[i].first].push_back(c[i].second);
      Adj[c[i].second].push_back(c[i].first);
    }


    numbconnections(n);
    for(int i=0; i<calculate.size(); i++){
      answer+=calculate[i]*calculate[i];
    }


    cout<< answer << '\n';

    answer=0;
    for(int i=0; i<2005; i++){
      Adj[i].clear();
      visited[i]=false;
    }

    int index=0;
    for(int i=0; i<d; i++){
      v.push_back(c[destruction[i]-1]);
    }

    for(int i=0; i<d; i++){

      for(int k=0; k<c.size(); k++){
        if(c[k]==v[index]){
          c.erase(c.begin()+k+1);
          index++;
          break;
        }
      }
      for()
      for(int k=0; k<c.size(); k++){

       Adj[c[k].first].push_back(c[k].second);
       Adj[c[k].second].push_back(c[k].first);

      }


      numbconnections(n);
      for(int k=0; k<calculate.size(); k++){
        answer+=calculate[k]*calculate[k];
      }


      cout<< answer << '\n';

      answer=0;
      for(int k=0; k<2005; k++){
        Adj[k].clear();
        visited[k]=false;
      }
      calculate.clear();

    }


  return 0;
}
*/





//----------------------------------------------------------------------------------






/*
#include <bits/stdc++.h>
using namespace std;
int MAXN=1e5;

vector<string> animals;

map<string, vector<string> > Adj;

map<string, vector<string> > NA;

map<string, bool> visited;

int groups=0;

void dfs(string c){
  visited[c]=true;
  for(auto u: Adj[c]){
    if(visited[u]==false){
      dfs(u);
    }
  }
}

void numbconnections(){
  for(auto u: animals){
    if(!visited[u]){
      dfs(u);
      groups++;
    }
  }
}

int main(){

  int N,C;
  cin>> N>>C;
  string p;
  for(int i=0; i<N; i++){
    cin>> p;
    animals.push_back(p);
  }
  string a,b;
  for(int i=0; i<C; i++){
    cin>> a >> b;
    Adj[a].push_back(b);
    Adj[b].push_back(a);
  }

  numbconnections();
  cout<< groups-1;





  return 0;
}
*/
