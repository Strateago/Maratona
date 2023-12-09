#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
const ll INF = LLONG_MAX;

vector <ll> dijkstra (ll origin, vector <pll> *grafo, int n){
    vector <ll> dist;
    pll aux;
    dist.assign(n, INF);
    dist[origin] = 0;
    priority_queue <pll, vector <pll>, greater<pll>> pq;
    pq.push({0, origin});
    while(!pq.empty()){
        aux = pq.top();
        pq.pop();
        if(aux.first > dist[aux.second]) continue;
        for(pll H: grafo[aux.second]){
            if(H.second + aux.first < dist[H.first]){
                dist[H.first] = H.second + aux.first;
                pq.push({dist[H.first], H.first});
            }
        }
    }
    return dist;
}
