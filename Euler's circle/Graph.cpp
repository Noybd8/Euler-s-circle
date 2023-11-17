#include "Graph.h"
Graph::Graph(int i_VertexesNum)
{
    m_VertexesNum = i_VertexesNum;
    m_AdjencyArr = new List[i_VertexesNum + 1];
    for (int i = 1; i < i_VertexesNum + 1; i++)
    {
        m_AdjencyArr[i].CreateEmptyList();
    }
}
Graph:: ~Graph()
{
    delete[] m_AdjencyArr;
}
List* Graph::GetAdjencyArr()
{
    return m_AdjencyArr;
}
void Graph::Visit(int i_VartexU, char* io_ColorArr) // visit the vertixes in a depth first serarch
{
    io_ColorArr[i_VartexU] = GRAY;
    Node* vartexV = m_AdjencyArr[i_VartexU].GetHead();
    while (vartexV != NULL) {
        if (io_ColorArr[vartexV->GetVertex()] == WHITE)
        {
            Visit(vartexV->GetVertex(), io_ColorArr);
        }
        vartexV = vartexV->GetNext();
    }
    io_ColorArr[i_VartexU] = BLACK;
}
bool Graph::AreAllVertexesVisited(char* io_ColorArr) //useful to us inter alia to test if connected/strongly connected
{
    bool returnValue = true;
    for (int i = 1; i <= m_VertexesNum; i++)
    {
        if (io_ColorArr[i] != BLACK)
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}
void Graph::Eular(List& L, List& tempList) //Find Euler circle (In the End it stores the whole circle in L)
{
    FindCircuit(1, L, true);
    int vertexV;
    Node* pos = L.GetHead();
    Node* firstUnusedEdge;
    while (pos != NULL)
    {
        firstUnusedEdge = m_AdjencyArr[pos->GetVertex()].GetFirstUnusedEdge();
        if (firstUnusedEdge == NULL)
        {
            pos = pos->GetNext();
        }
        else
        {
            FindCircuit(pos->GetVertex(), tempList, false);
            L.PasteList(tempList, pos);
        }
    }
}