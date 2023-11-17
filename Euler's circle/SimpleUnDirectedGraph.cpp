#include "SimpleUnDirectedGraph.h"
void SimpleUnDirectedGraph::AddEdge(int i_Vertex1, int i_Vertex2)
{
    m_AdjencyArr[i_Vertex1].AddToEnd(i_Vertex2);
    m_AdjencyArr[i_Vertex2].AddToEnd(i_Vertex1);
    Node* copy1 = m_AdjencyArr[i_Vertex1].GetTail();
    Node* copy2 = m_AdjencyArr[i_Vertex2].GetTail();
    m_AdjencyArr[i_Vertex1].GetTail()->SetCopyEdge(copy2);
    m_AdjencyArr[i_Vertex2].GetTail()->SetCopyEdge(copy1);
}
bool SimpleUnDirectedGraph::IsConnected(char* io_ColorArr)
{
    int vartexU = 1;
    Visit(vartexU, io_ColorArr);
    return AreAllVertexesVisited(io_ColorArr);
}
bool SimpleUnDirectedGraph::AreAllDegreesEven() //one of the terms of Euler Circle
{
    bool returnValue = true;
    int neighborsNum;
    for (int i = 1; i <= m_VertexesNum; i++)
    {
        neighborsNum = m_AdjencyArr[i].GetListLength();
        if ((neighborsNum % 2) != 0)
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}
bool SimpleUnDirectedGraph::IsAulerian(char* io_ColorArr)
{
    bool returnValue = true;
    if (!IsConnected(io_ColorArr))
    {
        returnValue = false;
    }
    else if (!AreAllDegreesEven())
    {
        returnValue = false;
    }
    return returnValue;

}
void SimpleUnDirectedGraph::FindCircuit(int i_VertexV0, List& L, bool i_firstTime)
{
    int vertexV = i_VertexV0;
    int vertexU;
    L.CreateEmptyList();
    if (i_firstTime == true)
    {
        L.AddToEnd(i_VertexV0);
    }
    Node* firstUnusedEdge = m_AdjencyArr[vertexV].GetFirstUnusedEdge();
    while (firstUnusedEdge != NULL)
    {
        vertexU = firstUnusedEdge->GetVertex();
        firstUnusedEdge->MarkAsUsed();
        firstUnusedEdge->GetCopyEdge()->MarkAsUsed();
        L.AddToEnd(vertexU);
        vertexV = vertexU;
        firstUnusedEdge = m_AdjencyArr[vertexV].GetFirstUnusedEdge();
    }
}