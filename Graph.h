//
//  Graph.h
//  Graph 연습
//
//  Created by 한설 on 2023/03/30.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct str_Graph {
    
    struct str_Vertex *graph;
    int vertexCount;
} Graph, *GraphPtr;

typedef struct str_Vertex {
    
    ElementType data;
    struct str_Vertex *Next;
    struct str_Edge *Edges;
    
    int index;
    int visited;
} Vertex, *VertexPtr;

typedef struct str_Edge {
    struct str_Vertex *start;
    struct str_Vertex *end;
    struct str_Edge *Next;
    int weight;
} Edge, *EdgePtr;

GraphPtr createGraph(void); //그래프 생성
void deleteGraph(GraphPtr G);   //그래프 제거

VertexPtr createVertex(ElementType data);   //정점 생성
void deleteVertex(VertexPtr V); //정점 제거

EdgePtr createEdge(VertexPtr start, VertexPtr end, int weight); //인접한 정점 생성
void deleteEdge(EdgePtr E); //인접한 정점 제거

void addVertex(GraphPtr G, VertexPtr V);
void addEdge(VertexPtr V, EdgePtr E);

void printGraph(GraphPtr G);
