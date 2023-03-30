//
//  main.c
//  Graph 연습
//
//  Created by 한설 on 2023/03/30.
//

#include "Graph.h"


int main() {
    GraphPtr G = createGraph(); //G가 이름인 그래프 구조체 생성
    printf("!\n");
    
    VertexPtr V1 = createVertex('1');
    VertexPtr V2 = createVertex('2');
    VertexPtr V3 = createVertex('3');
    VertexPtr V4 = createVertex('4');
    
    addVertex(G, V1);
    addVertex(G, V2);
    addVertex(G, V3);
    addVertex(G, V4);
    
    addEdge(V1, createEdge(V1, V2, 0));
    addEdge(V1, createEdge(V1, V4, 0));
    addEdge(V2, createEdge(V2, V3, 0));
    addEdge(V3, createEdge(V3, V4, 0));
    addEdge(V4, createEdge(V4, V2, 0));
    
    printGraph(G);
    deleteGraph(G);
}
