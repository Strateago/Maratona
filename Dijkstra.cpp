#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
const ll INF = LLONG_MAX;
int v, e;

pair <vector <ll>, vector <ll>> dijkstra (ll origin, vector <vector <pll>> grafo){
    int no, peso;
    vector <ll> dist, prec;
    vector <pll> e;
    pll aux;
    dist.assign(grafo.size(), INF);
    prec.assign(grafo.size(), -1);
    dist[origin] = 0;
    priority_queue <pll> pq;
    pq.push({origin, 0});
    while(!pq.empty()){
        aux = pq.top();
        pq.pop();
        e = grafo[aux.first];
        for(int a = 0; a < e.size(); a++){
            no = e[a].first;
            peso = e[a].second;
            if(peso + aux.second < dist[no]){
                dist[no] = peso + aux.second;
                prec[no] = aux.first;
                pq.push({no, dist[no]});
            }
        }
        return {dist, prec};
    }
}
