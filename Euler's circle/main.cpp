// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "InputHandling.h"

int main()
{
    char isDirect;
    int n, m;
    int v1, v2;
    cout << "Is the graph directed: y/n \n";
    cin >> isDirect;
    cin >> n;
    cin >> m;
    if (!AreInitialInputsValid(isDirect, n, m))
    {
        cout << "Invalid input";
    }
    else
    {
        char* colorArr = new char[n + 1];
        InitColorArr(colorArr, n);
        List L;
        List tempList;
        if (isDirect == 'y')
        {
            SimpleDirectedGraph graph(n);
            ActivateMethods(m, n, colorArr, graph);

        }
        else
        {
            SimpleUnDirectedGraph graph(n);
            ActivateMethods(m, n, colorArr, graph);
        }
        delete[] colorArr;

    }
}

