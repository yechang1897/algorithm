#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;
vector<int> res;

void dfs(int u) {
    visited[u] = 1;
    res.push_back(u);
    for (int v: edges[u]) {
        if (visited[v] == 0) {
            dfs(v);
        }
        else if (visited[v] == 1) {
            return;
        }
    }
    visited[u] = 2;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto& info: prerequisites) {
        edges[info[1]].push_back(info[0]);
    }
    for (int i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    if((int)res.size() == numCourses) {
        return res;
    } else {
        res.clear();
        return res;
    }
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<int> ans = findOrder(numCourses, prerequisites);
    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}