#include "Node.h"
#include "tools.h"
Node::Node(int i_Data)
{
    m_Vertex = i_Data;
    m_Next = NULL;
    m_IsPartOfUsedEdge = false;
    m_CopyOfEdgeInUndirectedGraph = NULL;
}
Node* Node::GetCopyEdge()
{
    return m_CopyOfEdgeInUndirectedGraph;
}
void Node::MarkAsUsed() //help us to mark if the edge is/ isnt in the circle
{
    m_IsPartOfUsedEdge = true;
}
bool Node::IsPartOfUsedEdge() //help us to know if the edge is/isnt in the circle
{
    return m_IsPartOfUsedEdge;
}
Node* Node::GetNext()
{
    return m_Next;
}
int Node::GetVertex()
{
    return m_Vertex;
}
void Node::SetNext(Node* i_Next)
{
    m_Next = i_Next;
}
void Node::SetCopyEdge(Node* i_Copy)
{
    m_CopyOfEdgeInUndirectedGraph = i_Copy;
}