#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    void makeset(int *father, int *rank, int x) {
        father[x] = x;
        rank[x] = 0;
    }

    int find(int *father, int x) {
        int parent = father[x];
        if (parent == x) {
            return x;
        } else {
            father[x] = find(father, parent);
            return father[x];
        }
    }

    inline void unionset(int *father, int *rank, int x, int y) {
        int parent1 = find(father, x);
        int parent2 = find(father, y);
        int rank1 = rank[parent1];
        int rank2 = rank[parent2];

        if (rank1 < rank2) {
            father[parent1] = parent2;
        } else if (rank1 > rank2) {
            father[parent2] = parent1;
        } else {
            father[parent2] = parent1;
            ++rank[parent1];
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if (n > connections.size() + 1) return -1;

        int father[n];
        int rank[n];
        memset(rank, 0, sizeof(rank));

        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }

        for (auto& data: connections) {
            unionset(father, rank, data[0], data[1]);
        }

        unordered_set<int> fathers;
        for (int i = 0; i < n; ++i) {
            int parent = find(father, i);
            fathers.insert(parent);
        }

        return fathers.size() - 1;
    }
};

int main() {
    vector<vector<int>> nums = {
        {1,4},{0,3},{1,3},{3,7},{2,7},{0,1},{2,4},{3,6},{5,6},{6,7},{4,7},{0,7},{5,7}
    };
    Solution solu;
    solu.makeConnected(11, nums);
}
