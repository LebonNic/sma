#include "Graph.h"
#include "PerlinNoise.h"

int main (int argc, char **argv)
{
	double x = 0.0;
	double y = 0.0;
	double xMax = 32.0;
	double yMax = 32.0;
	double xMin = -xMax;
	double yMin = -yMax;
	double xStep = 1.0;
	double yStep = 1.0;

	PerlinNoise noise(rand());
	Graph graph;

	for(x = xMin; x < xMax; x+=xStep)
	{
		for(y = yMin; y < xMax; y+=yStep)
		{
			double z = noise.noise(x,y,0.5);
			graph.addNode(x,y,z);
		}
	}

	return 0;
}