#include<iostream>
#include<vector>
using namespace std;

class Edges
{
    public:
        int u;
        int v;

        Edges(int u, int v)
        {
            this->u = u;
            this->v = v;
        }
};

class Graph
{
    public:
        vector<vector<int>> neighbors;

        Graph(int numberOfVertices, const vector<Edges>& edges)
        {
            neighbors.resize(numberOfVertices);
            for(int i = 0; i < edges.size(); i++)
            {
                neighbors[edges[i].u].push_back(edges[i].v);
                neighbors[edges[i].v].push_back(edges[i].u);
            }
        }

        int getSize()
        {
            return this->neighbors.size();
        }

        int getDegree() //Degree means the number of vertices
        {
            int degree = 0;
            for(int i = 0; i < this->neighbors.size(); i++)
            {
                degree += this->neighbors[i].size();
            }

            return degree;
        }

       void printEdges()
       {
         for(int i = 0; i < neighbors.size(); i++)
         {
            for(int j = 0; j < neighbors[i].size(); j++)
            {
                if(i >= j)
                {
                    cout << i << j << endl;
                }
            }
         }
       }

       vector<int>getNeighbors(int u)
       {
         vector<int> result;
         for(int i = 0; i < this->neighbors[u].size(); i++)
         {
            result.push_back(i);
         }

         return result;
       }



       vector<int> printAdjacencyMatrix() 
       {
         vector<vector<int>> adjacencyMatrix(getSize());

         for(int i = 0; i < getSize(); i++)
         {
            adjacencyMatrix[i] = vector<int>(getSize());
         }

         for(int i = 0; i < neighbors.size(); i++)
         {
            for(int j = 0; j < neighbors.size(); j++)
            {
                if(i == j)
                {
                    adjacencyMatrix[i][j] = 1;
                }

                else 
                {
                    adjacencyMatrix[i][j] = 0;
                }
            }
         }
       }

};
