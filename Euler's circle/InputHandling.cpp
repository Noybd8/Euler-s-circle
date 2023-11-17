#include "InputHandling.h"
void InitColorArr(char* io_ColorArr, int size)
{
    for (int i = 1; i <= size; i++)
    {
        io_ColorArr[i] = WHITE;

    }
}
bool AreInitialInputsValid(char isDirect, int n, int m) //check some of the inputs
{
    bool returnValue = false;
    if ((isDirect == 'y' || isDirect == 'n') && n > 0 && m > 0)
    {
        returnValue = true;
    }
    return returnValue;
}
bool IsVertexValid(int i_Vertex, int i_VertexesNum) //check specificly vertex which inserted can be a part of an edge
{
    bool returnValue = false;
    if (i_Vertex >= 1 && i_Vertex <= i_VertexesNum)
    {
        returnValue = true;
    }
    return returnValue;
}
bool IsValidEdge(int i_Vertex1, int i_Vertex2, int i_VertexesNum)  //check the both vertixes if they can be an edge
{
    bool returnValue = false;
    if (IsVertexValid(i_Vertex1, i_VertexesNum) && IsVertexValid(i_Vertex2, i_VertexesNum))
    {
        returnValue = true;
    }
    return returnValue;
}
bool GetInputAndBuild(int i_EdgesNum, int i_VertexesNum, Graph& o_G) //build graph by inputs from user
{
    int countCurrentEdgeNum = 0;
    int vertex1, vertex2;
    while (countCurrentEdgeNum < i_EdgesNum)
    {
        cin >> vertex1;
        cin >> vertex2;
        if (IsValidEdge(vertex1, vertex2, i_VertexesNum))
        {
            o_G.AddEdge(vertex1, vertex2);
            countCurrentEdgeNum++;
        }
        else
        {
            cout << "Invalid input";
            return false;
        }
    }
    return true;
}
void ActivateMethods(int i_EdgesNum, int i_VertexesNum, char* io_ColorArr, Graph& graph) //a method which called for two types of Graph and prevent duplication of code
{
    if (!GetInputAndBuild(i_EdgesNum, i_VertexesNum, graph))
        return;
    if (graph.IsAulerian(io_ColorArr))
    {
        cout << "The graph is aulerian \n";
        List L;
        List tempList;
        graph.Eular(L, tempList);
        L.PrintList();
    }
    else
    {
        cout << "The graph is not aulerian";
    }
}