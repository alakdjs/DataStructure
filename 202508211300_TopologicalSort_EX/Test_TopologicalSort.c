#include "Graph.h"
#include "TopologicalSort.h"

int main( void )
{
    Node* SortedList  = NULL;
    Node* CurrentNode = NULL;

    //  그래프 생성     
    Graph* graph = CreateGraph();
    
    //  정점 생성 
    Vertex* A = CreateVertex( "C" );
    Vertex* B = CreateVertex( "C++" );
    Vertex* C = CreateVertex( "C#" );
    Vertex* D = CreateVertex( "자료구조" );
    Vertex* E = CreateVertex( "알고리즘" );
    Vertex* F = CreateVertex( "Unity" );
    Vertex* G = CreateVertex( "Unreal" );
    Vertex* H = CreateVertex( "게임개발" );
    Vertex* I = CreateVertex( "취업" );

    //  그래프에 정점을 추가 
    AddVertex( graph, A );
    AddVertex( graph, B );
    AddVertex( graph, C );
    AddVertex( graph, D );
    AddVertex( graph, E );
    AddVertex( graph, F );
    AddVertex( graph, G );
    AddVertex( graph, H );
    AddVertex( graph, I );

    //  정점과 정점을 간선으로 잇기 
    AddEdge( A, CreateEdge( A, B, 0 ) );
    AddEdge( A, CreateEdge( A, D, 0 ) );

    AddEdge( B, CreateEdge( B, F, 0 ) );
    AddEdge( B, CreateEdge( B, G, 0 ) );

    AddEdge( C, CreateEdge( C, F, 0 ) );
    
    AddEdge( D, CreateEdge( D, E, 0 ) );

    AddEdge( E, CreateEdge( E, F, 0 ) );
    AddEdge( E, CreateEdge( E, G, 0 ) );

    AddEdge( F, CreateEdge( F, H, 0 ) );
    
    AddEdge( G, CreateEdge( G, H, 0 ) );

    AddEdge( H, CreateEdge( H, I, 0 ) );

    //  위상 정렬 
    TopologicalSort( graph->Vertices, &SortedList );

 
    printf("Topological Sort Result : ");

    CurrentNode = SortedList;

    while ( CurrentNode != NULL )
    {
        printf("%s-> ", CurrentNode->Data->Data );
        CurrentNode = CurrentNode->NextNode;
    }
    printf("\n");
    

    //  그래프 소멸 
    DestroyGraph( graph );

    return 0;
}
