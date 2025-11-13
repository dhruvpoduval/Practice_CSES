#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

const ll INF  = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#endif

static void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(){
    fastio();

    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        movies[i] = {a, b};
    }
    
    //Sort based on ending times of movies.
    sort(movies.begin(), movies.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    int count = 0;
    int last_end_time = 0;

    //If end time of current movie is less than or equal to start time of next, a full movie can be added to count. 
    for(int i=0; i<n; i++){
        if(movies[i].first >= last_end_time){
            count++;
            last_end_time = movies[i].second;
        }
    }
    cout << count << endl;

    return 0;
}