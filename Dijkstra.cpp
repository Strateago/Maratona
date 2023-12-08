#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
const ll INF = LLONG_MAX;

pair <vector <ll>, vector <ll>> dijkstra (ll origin, vector <pll> *grafo){
    vector <ll> dist, prec;
    pll aux;
    dist.assign(n, INF);
    prec.assign(n, -1);
    dist[origin] = 0;
    priority_queue <pll> pq;
    pq.push({origin, 0});
    while(!pq.empty()){
        aux = pq.top();
        pq.pop();
        for(pll H : grafo[aux.first]){
            if(H.second + aux.second < dist[H.first]){
                dist[H.first] = H.second + aux.second;
                pq.push({H.first, dist[H.first]});
            }
        }
    }
    return {dist, prec};
}
