#pragma once
class Node {
private:
    int m_Vertex;
    Node* m_Next;
    bool m_IsPartOfUsedEdge;
    Node* m_CopyOfEdgeInUndirectedGraph; //this member is irrelevant when it comes to directed graph.
public:
    Node(int i_Data);
    void SetNext(Node* i_Next);
    void SetCopyEdge(Node* i_Copy);
    Node* GetNext();
    int GetVertex();
    bool IsPartOfUsedEdge();
    void MarkAsUsed();
    Node* GetCopyEdge(); //this method irrelevant when it comes to directed graph
};
