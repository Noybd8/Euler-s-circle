#include "SimpleDirectedGraph.h"
#include "InputHandling.h"
void SimpleDirectedGraph::AddEdge(int i_Vertex1, int i_Vertex2)
{
    m_AdjencyArr[i_Vertex1].AddToEnd(i_Vertex2);
}
void SimpleDirectedGraph::FindCircuit(int i_VertexV0, List& L, bool i_firstTime)
{
    int vertexV = i_VertexV0;
    int vertexU;
    L.CreateEmptyList();
    if (i_firstTime == true)
    {
        L.AddToEnd(i_VertexV0);
    }
    Node* firstUnusedEdge = m_AdjencyArr[vertexV].GetFirstUnusedEdge();
    while (firstUnusedEdge != NULL) {
        vertexU = firstUnusedEdge->GetVertex();
        firstUnusedEdge->MarkAsUsed();
        L.AddToEnd(vertexU);
        vertexV = vertexU;
        firstUnusedEdge = m_AdjencyArr[vertexV].GetFirstUnusedEdge();
    }
}
SimpleDirectedGraph SimpleDirectedGraph::createTransposeGraph()
{
    SimpleDirectedGraph G(m_VertexesNum);
    Node* currNeighbor;
    for (int i = 1; i < m_VertexesNum + 1; i++)
    {
        currNeighbor = m_AdjencyArr[i].GetHead();
        while (currNeighbor != NULL)
        {
            G.AddEdge(currNeighbor->GetVertex(), i);
            currNeighbor = currNeighbor->GetNext();
        }
    }
    return G;
}
bool SimpleDirectedGraph::IsStronglyConnected(char* io_ColorArr, SimpleDirectedGraph& io_TransposeGraph)
{
    Visit(1, io_ColorArr);
    bool returnValue = true;
    if (!AreAllVertexesVisited(io_ColorArr))
    {
        returnValue = false;
    }
    else
    {
        InitColorArr(io_ColorArr, m_VertexesNum);
        io_TransposeGraph.Visit(1, io_ColorArr);
        if (!AreAllVertexesVisited(io_ColorArr))
        {
            returnValue = false;
        }
    }
    return returnValue;

}
bool SimpleDirectedGraph::IsIndegreeEqualToOutdegree(int i_Vertex, SimpleDirectedGraph& io_TransposeGraph)
{
    bool returnValue = true;
    if (m_AdjencyArr[i_Vertex].GetListLength() != io_TransposeGraph.m_AdjencyArr[i_Vertex].GetListLength())
    {
        returnValue = false;
    }
    return returnValue;
}
bool SimpleDirectedGraph::AreALLIndegreeEqualToOutdegree(SimpleDirectedGraph& io_TransposeGraph) // help us to check on of the terms of Euler circle
{
    bool returnValue = true;
    for (int i = 1; i <= m_VertexesNum; i++)
    {
        if (!IsIndegreeEqualToOutdegree(i, io_TransposeGraph))
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}
bool SimpleDirectedGraph::IsAulerian(char* io_ColorArr)
{
    bool returnValue = true;
    SimpleDirectedGraph transposeGraph = createTransposeGraph();
    if (!IsStronglyConnected(io_ColorArr, transposeGraph))
    {
        returnValue = false;
    }
    else if (!AreALLIndegreeEqualToOutdegree(transposeGraph))
    {
        returnValue = false;
    }
    return returnValue;
}