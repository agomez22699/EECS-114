/* Adrian Gomez
SID:20119988
EECS 114
Lab 9
3/4/2021
dfs.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//HELLOWORLD = 10
#define MAX 10

int vertexCount = 0;
int dfs_stack[MAX];
int topVar = -1;
// Build a structure Vertex to represent the vertices in graph
// Use adjacent list to store the graph

struct Vertex {
	char label;
	bool visited; 
};

// adjacency matrix
int adjMatrix[MAX][MAX];

// array of vertices
struct Vertex* lstVertices[MAX];

int popStack() { //implementing a stack 
	return dfs_stack[topVar--]; //returning the top int
}

int peekStack() {//top of the stack
	int temp;
	temp = dfs_stack[topVar];
	return temp; //return the top of the stack
}

void pushStack(int data) {//push data to the stack
	dfs_stack[++topVar] = data;//inputting data to the stack
}

bool isEmpty() {
	return topVar == -1;//return -1 if the stack is empty
}

// add vertex to the vertex list
void addVertex(char label) {
	struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
	vertex->label = label;
	vertex->visited = false;
	lstVertices[vertexCount++] = vertex;
}

// add edge to edge array
void addEdge(int start, int end) {
	adjMatrix[start][end] = 1;
	adjMatrix[end][start] = 1;
}

// display the vertex
void displayVertex(int vertexIndex) {
	printf("%c ", lstVertices[vertexIndex]->label);
}

// get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
	int i;
	for (i = 0; i < vertexCount; i++) {
		if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
			return i;
		}
	}
	return -1;
}

void dfs() {
	lstVertices[0]->visited = true; // this marks the node as visited
	displayVertex(0);//display the node
	pushStack(0);//push the first vertex

	while (!isEmpty()) {
		int uvVertex = getAdjUnvisitedVertex(peekStack()); //unvisited vertex int
															// this is at the top of the stack
		if (uvVertex == -1) {

			popStack(); //remove from the stack 

		}
		else {
			lstVertices[uvVertex]->visited = true;
			displayVertex(uvVertex);
			pushStack(uvVertex);
		}
	}

	for (int i = 0; i < vertexCount; i++) {

		lstVertices[i]->visited = false;//we want to reset the the visits

	}

}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			adjMatrix[i][j] = 0;
		}
	}

	
	addVertex('H'); // index = 0
	printf("Added Vertex H\n");
	addVertex('E'); //index = 1
	printf("Added Vertex E\n");
	addVertex('D');//index = 2
	printf("Added Vertex D\n");
	addVertex('W');//index = 3
	printf("Added Vertex W\n");
	addVertex('O');//index = 4
	printf("Added Vertex O\n");
	addVertex('R');//index = 5
	printf("Added Vertex R\n");
	addVertex('L');//index = 6
	printf("Added Vertex L\n");
	addVertex('L'); //index = 7
	printf("Added Vertex L\n");
	addVertex('L');//index = 8
	printf("Added Vertex L\n");
	addVertex('O');//index = 9
	printf("Added Vertex O\n\n");

	addEdge(0,1);//adding the edge 
	addEdge(1, 7);//adding the edge
	addEdge(7, 6);//adding the edge
	addEdge(6, 9);//adding the edge
	addEdge(9, 3);//adding the edge
	addEdge(3, 4);//adding the edge
	addEdge(4, 5);//adding the edge
	addEdge(5, 8);//adding the edge
	addEdge(8, 2);//adding the edge 
	
	printf("DFS: ");

	dfs();
}
