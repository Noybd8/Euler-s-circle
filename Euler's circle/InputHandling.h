#pragma once
#include "SimpleDirectedGraph.h"
#include "SimpleUnDirectedGraph.h"
void InitColorArr(char* io_ColorArr, int size);
bool AreInitialInputsValid(char isDirect, int n, int m);
bool IsVertexValid(int i_Vertex, int i_VertexesNum);
bool IsValidEdge(int i_Vertex1, int i_Vertex2, int i_VertexesNum);
bool GetInputAndBuild(int i_EdgesNum, int i_VertexesNum, Graph& o_G);
void ActivateMethods(int i_EdgesNum, int i_VertexesNum, char* io_ColorArr, Graph& graph);
