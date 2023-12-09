#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
const ll INF = LLONG_MAX;

ll MST (ll origin, ll n, vector <pll> *grafo){
    ll weight = 0;
    pll aux;
    vector <bool> visited;
    priority_queue <pll, vector <pll>, greater <pll>> pq;
    visited.assign(n, false);
    pq.push({0, origin});
    while(!pq.empty()){
        aux = pq.top();
        pq.pop();
        if(visited[aux.second]) continue;
        visited[aux.second] = true;
        weight += aux.first;
        for(pll H : grafo[aux.second]){
            if(!visited[H.first]){
                pq.push({H.second, H.first});
            }
        }
    }
    for(int a = 0; a < n; a++){
        if(!visited[a]){
            return -1;
        }
    }
    return weight;
}
