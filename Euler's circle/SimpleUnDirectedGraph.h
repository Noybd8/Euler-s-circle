#pragma once
#include "Graph.h"
class SimpleUnDirectedGraph :public Graph
{
public:
    SimpleUnDirectedGraph(int i_VertexesNum) : Graph(i_VertexesNum) {}
    void AddEdge(int i_Vertex1, int i_Vertex2);
    bool IsConnected(char* io_ColorArr);
    bool AreAllDegreesEven();
    bool IsAulerian(char* io_ColorArr);
    void FindCircuit(int i_VertexV0, List& L, bool i_firstTime);

};
