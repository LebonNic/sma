#include "World.h"
#include "Ressource.h"
#include <ctime>
using namespace std;


int main (int argc, char **argv)
{
	srand((unsigned int) time(NULL));
	unsigned int width = 32;
	unsigned int height = 48;
	World world((double) width,(double) height, 0.1, rand());

	for(unsigned int i = 0; i < 8; ++i)
	{
		double x = (double) (rand() % width);
		double y = (double) (rand() % height);
		double z = 0;
		Ressource *ressource = new Ressource(x, y, z);
		world.addPassiveEntity(ressource);
	}

	world.display();
	cin.get();

	return 0;
}