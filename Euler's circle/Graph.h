#pragma once
#include "List.h"
class Graph {
protected:
    List* m_AdjencyArr;
    int m_VertexesNum;
public:
    Graph(int i_VertexesNum);
    ~Graph();
    List* GetAdjencyArr();
    void Visit(int i_VartexU, char* io_ColorArr);
    virtual void FindCircuit(int i_VertexV0, List& L, bool i_firstTime) = 0;
    bool AreAllVertexesVisited(char* io_ColorArr);
    virtual bool IsAulerian(char* io_ColorArr) = 0;
    void Eular(List& L, List& tempList);
    virtual void AddEdge(int i_Vertex1, int i_Vertex2) = 0;
};
