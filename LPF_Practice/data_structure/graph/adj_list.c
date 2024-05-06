# include <stdio.h>
# include <stdlib.h>
//Define a graph data structure

//Think: 一個圖包含edge(與其他edge相連) 以及 vertex
struct node {
    int vertex;
    struct node* next;
};
typedef struct node Node;

struct Graph {
    int numvertices;
    Node** adjlist;
};

//Create a node 
struct node* createnode(int v){
    Node* newnode = malloc(sizeof(Node));
    newnode -> vertex = v;
    newnode -> next = NULL;
    return newnode;
};

//Create a graph
struct Graph* create_graph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> numvertices = vertices;
    graph -> adjlist = malloc(vertices * sizeof(struct node*));
    for (int i = 0; i < vertices; i++)
        graph -> adjlist[i] = NULL;
    return graph;
};

//Add edge
void addEdge(struct Graph* graph, int s, int d){
    //Add Edge from s to d
    struct node* newnode = createnode(d);
    newnode -> next = graph -> adjlist[s];
    graph -> adjlist[s] = newnode;

    //Add edge from d to s 
    newnode = createnode(s);
    newnode -> next = graph -> adjlist[d];
    graph -> adjlist[d] = newnode;
};

//Print the graph
void printgraph(struct Graph* graph){
    for (int v = 0; v < graph -> numvertices; v++){
        struct node* temp = graph -> adjlist[v];
        printf("\n Vertex %d \n ", v);
        while (temp){
            printf("%d -> ", temp -> vertex);
            temp = temp -> next;
        };
        printf("\n"); 
    };
};
int main(void){
    struct Graph* graph = create_graph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    printgraph(graph);
    return 0;
};