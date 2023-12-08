#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
const ll INF = 2e15;

vector <vector <ll>> Floyd (vector <vector <ll>> dist, int n){
    for(int a = 0; a < n; a++){
        dist[a][a] = 0;
    }
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            for(int c = 0; c < n; c++){
                if(dist[b][a] + dist[c][a] > INF)
                    dist[b][c] = min(dist[b][c], INF);
                else
                    dist[b][c] = min(dist[b][c], dist[b][a] + dist[c][a]);
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <ll> aux;
    vector <vector <ll>> dist;
    cin >> n >> m >> q;
    aux.assign(n, INF);
    dist.assign(n, aux);
    for(int a = 0; a < m; a++){
        cin >> c1 >> c2 >> p;
        dist[c1-1][c2-1] = min(p, dist[c1-1][c2-1]);
        dist[c2-1][c1-1] = dist[c1-1][c2-1];
    }
    dist = Floyd(dist, n);
}
