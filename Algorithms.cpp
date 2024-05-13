//209374487
#include <queue>
#include <vector>
#include <string>
#include "Algorithms.hpp"
#include <limits>

namespace Algorithms {

    int isConnected(Graph graphObj) {
        const std::vector<std::vector<int>> g = graphObj.getMat();
        int n=g.size();
        if(n==0)return 1;
        std::vector<bool> visited(n, false);std::queue<int> q;
        // Start BFS from vertex 0
        q.push(0);visited[0]=true;int counter=1;
        while (!q.empty()) {
            int current=q.front();q.pop();
            for(int i=0;i<n;i++){if(g[current][i]!=0 && !visited[i]){visited[i]=true;q.push(i);counter++;}}
        }
        if(counter==n)return 1;
        return 0;
    }

    bool isContainsCycle(Graph graphObj){
        const std::vector<std::vector<int>> g = graphObj.getMat();
        int n = g.size();
        if(n <= 1) return false;
        std::vector<bool> visited(n, false);
        std::queue<std::pair<int, int>> q; // Queue to store node and its parent

        for(int startVer = 0; startVer < n; startVer++){
            if(visited[startVer]) continue;
            q.push({startVer, -1});

            while (!q.empty()) {
                int current = q.front().first;
                int parent = q.front().second;
                q.pop();
                if(visited[current])continue;
                visited[current] = true;
                for(int i = 0; i < n; i++){
                    if(g[current][i] != 0) {
                        if(visited[i] && i != parent) {
                            return true; // Found a cycle
                        }
                        if(!visited[i]){
                            q.push({i, current}); // Push the node and its parent
                        }
                    }
                }
            }
        }
        return false;
    }


    std::string isBipartite(Graph graphObj){
        const std::vector<std::vector<int>> g = graphObj.getMat();
        int n=g.size();
        if(n==0)return "The graph is bipartite: A={}, B={}";
        if(n==1)return "The graph is bipartite: A={0}, B={}";
        if(n==2)return "The graph is bipartite: A={0}, B={1}";
        std::vector<int> side(n,0);std::queue<int> q;
        for(int startVertix=0;startVertix<n;startVertix++){//for each vertix make sure the while got it (if not connected)
            if(side[startVertix]==0){
                q.push(startVertix);side[startVertix]=1;
                while (!q.empty()) {//check for each connected vertix if not bipartite
                    int current = q.front();
                    q.pop();
                    for(int i=0;i<n;i++){
                        if (g[current][i]!=0 && i>current){
                            if(side[i]==side[current])return "0";
                            if(side[i]==0)q.push(i);
                            side[i]=side[current]*(-1);
                        }
                    }
                }
            }
        }
        std::string sideA = "";
        std::string sideB = "";
        for(int i=0;i<n;i++){
            std::string next = std::to_string(i);
            if(side[i]==1){
                if(!sideA.empty())sideA+=", ";
                sideA+=next;
            }
            else{
                if(!sideB.empty())sideB+=", ";
                sideB+=next;
            }
        }
        std::string ans = "The graph is bipartite: A={"+sideA+"}, B={"+sideB+"}";
        return ans;
    }

    std::string shortestPath(Graph graphObj, int startVer, int endVer) {
        const std::vector<std::vector<int>> g = graphObj.getMat();
        int n = g.size();
        if(startVer>=n || endVer>=n || startVer<0 || endVer<0)return "Input vertices doesn't match Graph size.";
        if(endVer==startVer)return std::to_string(startVer);
        if(n==2)return std::to_string(startVer) + "->" + std::to_string(endVer);

        std::vector<int> VerDist(n, std::numeric_limits<int>::max());
        std::queue<int> q;std::vector<int> reconstruct(n, -1);

        q.push(startVer);VerDist[startVer]=0; 
        while (!q.empty()) {
            int current=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(g[current][i]!=0 && VerDist[i]>VerDist[current]+g[current][i]){
                    VerDist[i]=VerDist[current]+g[current][i];
                    reconstruct[i]=current;
                    q.push(i);
                }
            }
        }

        if(VerDist[endVer]==std::numeric_limits<int>::max())return "-1";
        // Reconstruct the path from endVer back to startVer
        std::string ans=std::to_string(endVer);
        int step=endVer;
        while(step!=startVer){
            step=reconstruct[step];
            ans=std::to_string(step) + "->" + ans;
        }
        return ans;
    }

    std::string negativeCycle(Graph graphObj){
        const std::vector<std::vector<int>> g = graphObj.getMat();
        int n = g.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> predecessor(n, -1);

        int cycleStart = -1;
        dist[0] = 0;

        // detect with Belman Ford if there is a cycle and one vertex on it
        for(int step = 0; step < n; ++step){
            cycleStart = -1;
            for(int u = 0; u < n; ++u){
                for(int v = 0; v < n; ++v){
                    if(g[u][v] && dist[u]!=std::numeric_limits<int>::max() && dist[u] + g[u][v]<dist[v]){
                        dist[v] = dist[u] + g[u][v];
                        predecessor[v] = u;
                        if(step == n - 1){
                            cycleStart = v;
                        }
                    }
                }
            }
        }

        if(cycleStart == -1)return "No Negative Cycle";
        else {
            // Finding the cycle
            std::vector<int> cycle;
            int v = cycleStart;
            for (int i = 0; i < n; ++i) {
                v = predecessor[v];
            }

            // Store the cycle in reverse order
            int u = v;
            cycle.push_back(v);
            while (true) {
                v = predecessor[v];
                if (v == u) {
                    break;
                }
                cycle.push_back(v);
            }
            cycle.push_back(u); // Complete the cycle by returning to the start vertex

            // Convert cycle to string format
            std::string ans = "";
            for (size_t i = 0; i < cycle.size(); i++) {
                if (i > 0) ans = ans + "->";
                std::string next = std::to_string(cycle[i]);
                ans = ans + next;
            }
            return ans;
        }
    }
}