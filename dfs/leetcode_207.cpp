#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;
bool valid = true;

void dfs(int u) {
    visited[u] = 1;
    for (int v: edges[u]) {
        if (visited[v] == 0) {
            dfs(v);
            if (!valid) {
                return;
            }
        }
        else if (visited[v] == 1) {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto& info: prerequisites) {
        edges[info[1]].push_back(info[0]);
    }
    for(auto x : edges) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return valid;
}

void dfs_2(int u) {
    visited[u] = 1;
    for(int v : edges[u]) {
        if(visited[v] == 0) {
            dfs_2(v);
            if(!valid) {
                return;
            }
        } else if(visited[v] == 1){
            valid = false;
            return;
        }
    }
    visited[u] = 2;
}

bool canFinish_2(int numCourses, vector<vector<int>>& prerequisites) {
   edges.resize(numCourses);
   visited.resize(numCourses);
   for(const auto& info: prerequisites) {
       edges[info[1]].push_back(info[0]);
   } 
    for(int i = 0; i < numCourses && valid; i++) {
        if(!visited[i]) {
            dfs_2(i);
        }
    }
    return valid;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << canFinish_2(numCourses, prerequisites) << endl; 
}