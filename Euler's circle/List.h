#pragma once
#include "List.h"
#include "Node.h"
#include "tools.h"
class List {
private:
    Node* m_Head;
    Node* m_Tail;
    int m_ListLength;
    Node* m_PosToCurrNeighbor;
public:
    Node* GetTail();
    void SetTail(Node* i_NewTail);
    void AddToEnd(int i_Data);
    void PrintList();
    void CreateEmptyList();
    int GetListLength();
    Node* GetHead();
    Node* GetFirstUnusedEdge();
    void PasteList(List& tempList, Node* pos);
};

