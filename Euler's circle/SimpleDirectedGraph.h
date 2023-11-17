#pragma once
#include "Graph.h"
class SimpleDirectedGraph : public Graph
{
public:
    SimpleDirectedGraph(int i_VertexesNum) : Graph(i_VertexesNum) {}
    void AddEdge(int i_Vertex1, int i_Vertex2);
    void FindCircuit(int i_VertexV0, List& L, bool i_firstTime);
    SimpleDirectedGraph createTransposeGraph();
    bool IsStronglyConnected(char* io_ColorArr, SimpleDirectedGraph& io_TransposeGraph);
    bool IsIndegreeEqualToOutdegree(int i_Vertex, SimpleDirectedGraph& io_TransposeGraph);
    bool AreALLIndegreeEqualToOutdegree(SimpleDirectedGraph& io_TransposeGraph);
    bool IsAulerian(char* io_ColorArr);
};
