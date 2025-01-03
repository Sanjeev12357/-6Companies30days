class Solution {
public:
    vector<int> dijkstra(int start,vector<pair<int,int>> adjList[],int n){
        vector<int> dist(n,INT_MAX);
        dist[start]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,start});

        while(!pq.empty()){
            auto top=pq.top();
            int dis=top.first;
            int node=top.second;
            pq.pop();

            for(auto nbr: adjList[node]){
                int nbrDist=nbr.second;
                int nbrNode=nbr.first;
                if(dis+ nbrDist< dist[nbrNode] ){
                    dist[nbrNode]=dis+nbrDist;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adjList[n];

        for(auto edge:edges){
            adjList[edge[0]].push_back({edge[1],edge[2]});
            adjList[edge[1]].push_back({edge[0],edge[2]});
        }

        int resultcity=-1;
        int minReachable=INT_MAX;

        for(int i=0;i<n;i++){
            vector<int> distances=dijkstra(i,adjList,n);
            int reachable=0;
            for(auto dist:distances){
                if(dist<=distanceThreshold){
                    ++reachable;
                }
            }

            if(reachable<minReachable || (minReachable == reachable && i> resultcity)){
                minReachable=reachable;
                resultcity=i;
            }
        }

        return resultcity;


    }
};