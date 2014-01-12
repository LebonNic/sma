#include "Graph.h"
using namespace std;

int main (int argc, char **argv)
{
	Graph graph;

	graph.generateRandomPerlin(32.0,48.0,0.1);
	graph.display();
	cin.get();

	return 0;
}