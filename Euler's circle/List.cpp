#include "List.h"
Node* List::GetFirstUnusedEdge() //find edges which still did not inerted to the circle 
{
    Node* first = m_PosToCurrNeighbor;
    if (first != NULL)
    {
        while (first->IsPartOfUsedEdge())
        {
            m_PosToCurrNeighbor = m_PosToCurrNeighbor->GetNext();
            first = first->GetNext();
            if (first == NULL)
            {
                break;
            }
        }
    }
    return first;
}
int List::GetListLength()
{
    return m_ListLength;
}
void List::CreateEmptyList() //create a list out of nowhere. It shouldnt empty it, the empty will be done in the distructur
{
    m_Head = NULL;
    m_Tail = NULL;
    m_ListLength = 0;
    m_PosToCurrNeighbor = m_Head;
}
void List::PrintList()
{
    Node* temp = m_Head;
    while (temp != NULL) {
        cout << " " << temp->GetVertex();
        temp = temp->GetNext();
    }
    cout << "\n";
}
Node* List::GetTail()
{
    return m_Tail;
}
Node* List::GetHead()
{
    return m_Head;
}
void List::SetTail(Node* i_NewTail)
{
    m_Tail = i_NewTail;
}
void List::AddToEnd(int i_Data) //add a node to the end of list 
{
    Node* newNode = new Node(i_Data);
    if (m_Tail != NULL)
    {
        m_Tail->SetNext(newNode);
    }
    else
    {
        m_Head = newNode;
        m_PosToCurrNeighbor = newNode;
    }
    m_Tail = newNode;
    m_ListLength++;
}
void List::PasteList(List& tempList, Node* pos) //paste tempList in this List (after pos)
{
    tempList.m_Tail->SetNext(pos->GetNext());
    pos->SetNext(tempList.m_Head);
    tempList.m_Head = NULL;
}
