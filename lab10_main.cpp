#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "u_graphs.h"
    u_graph::u_graph(int s)
    {
        verticescount = s;
        adjacency_list.resize(s);
        for (int i = 0; i < s; i++)
        {
            adjacency_list.at(i).x.resize(s);
        }
    }
    int u_graph:: getvertices_count()
    {
        return verticescount;
    }
    void u_graph::setverticescount(int s)
    {
        verticescount = s;
    }
    vector<vector<pair<int, int>>> u_graph:: setadjacency_list(vector<datas>temp)
    {
        adjacency_list = temp;
    }
    vector<datas>  u_graph:: getlist()
    {
        return adjacency_list;
    }
    void u_graph:: add(edge temp)
    {
        adjacency_list.at(temp.source).x.at(temp.end) = pair<int, int>(temp.cost, temp.end);
        adjacency_list.at(temp.end).x.at(temp.source) = pair<int, int>(temp.cost, temp.source);
    }






int main() {
    vector<string> lines;
    string temp;
    ifstream trial_files;
    trial_files.open("trial.txt");
    while (getline(trial_files, temp))
    {
        lines.push_back(temp);
    }
    u_graph trial(lines.size());
    for (int i = 0; i < lines.size(); i++) {
        temp = lines.at(i);
        for (int j = 0; j < lines.size(); j++) {
            if (temp[j * 3] != '-') {
                edge tempedge;
                tempedge.cost = stoi(temp.substr(j * 3 + 1, 2));
                tempedge.source = i;
                tempedge.end = j;
                trial.add(tempedge);
            }
        }
    }
    cout << "output:" << endl;
    for (int i = 0; i < trial.getlist().size(); i++)
    {
        for (int j = 0; j < trial.getlist().at(i).x.size(); j++)
        {
            cout << trial.getlist().at(i).x.at(j).first << '\t';

        }
        cout << endl;
    }

    return 0;
}
