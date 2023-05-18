#pragma once
#include <vector>
using namespace std;
struct datas
{
    vector<pair<int, int>> x;
};
struct edge
{
    int source, end, cost;
};

class u_graph
{
private:
    vector<datas> adjacency_list;
    int verticescount;
public:
    u_graph(int s);
    int getvertices_count();
    void setverticescount(int s);
    vector<vector<pair<int, int>>> setadjacency_list(vector<datas>temp);
    vector<datas> getlist();
    void add(edge temp);
};
