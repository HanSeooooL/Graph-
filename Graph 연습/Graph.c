//
//  Graph.c
//  Graph 연습
//
//  Created by 한설 on 2023/03/30.
//

#include "Graph.h"

GraphPtr createGraph() {
    GraphPtr G = (GraphPtr)malloc(sizeof(Graph));   //동적 메모리 할당
    (*G).graph = NULL;
    G -> vertexCount = 0;
    
    return G;
}

VertexPtr createVertex(ElementType data) {
    
    VertexPtr nVertex = (VertexPtr)malloc(sizeof(Vertex));  //동적 메모리 할당
    nVertex -> data = data;
    nVertex->Next = NULL;
    nVertex->Edges = nVertex -> Next;
    nVertex -> visited = 0;
    nVertex -> index = -1;
    
    return nVertex;
}

void deleteVertex(VertexPtr V) {
    VertexPtr delV = V;
    EdgePtr edge = (*(*V).Edges).Next;  //V -> Edges -> Next V주소에 있는 구조체의 Edges주소에 있는 구조체의 Next주소
    while (edge) {
        deleteEdge(V -> Edges);
        V -> Edges = edge;
        edge = edge -> Next;
    }
    deleteEdge(V -> Edges);
    
    free(delV);
}

EdgePtr createEdge(VertexPtr start, VertexPtr end, int weight)
{
    EdgePtr edge = (EdgePtr)malloc(sizeof(Edge));
    edge -> start = start;
    edge -> end = end;
    edge -> Next = NULL;
    edge -> weight = weight;
    
    return edge;
}

void deleteEdge(EdgePtr E)
{
    free(E);
}


void deleteGraph(GraphPtr G)
{
    if(G -> graph) {
        VertexPtr V = G -> graph;
        while(V) {
            VertexPtr Next = V -> Next;
            deleteVertex(V);
            V = Next;
        }
    }
}

void addVertex(GraphPtr G, VertexPtr V) {
    V -> index = G -> vertexCount + 1;
    
    if(G -> graph) {
        VertexPtr buff = G -> graph;
        while (buff -> Next)
            buff = buff -> Next;
        buff -> Next = V;
    }
    else {
        G -> graph = V;
    }
}

void addEdge(VertexPtr V, EdgePtr E) {
    if(V -> Edges) {
        EdgePtr buff = V -> Edges;
        if(buff -> Next)
            buff = buff -> Next;
        buff -> Next = E;
    }
    else {
        V -> Edges = E;
    }
}

void printGraph(GraphPtr G)
{
    if (G -> graph) {
        VertexPtr V = G -> graph;
        while(V) {
            printf("[%c] : ", V -> data);
            EdgePtr E = V -> Edges;
            while(E) {
                printf("-> [%c] ", E -> end -> data);
                E = E -> Next;
            }
            printf("\n");
            V = V -> Next;
        }
    }
}
