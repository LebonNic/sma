#include "World.h"
#include "Ressource.h"
#include <ctime>
using namespace std;


int main (int argc, char **argv)
{
	srand((unsigned int) time(NULL));
	unsigned int width = 52;
	unsigned int height = 79;
	World world(width, height, 0.05, rand());

	for(unsigned int i = 0; i < 8; ++i)
	{
		double x = (double) (rand() % width);
		double y = (double) (rand() % height);
		double z = 0;
		Ressource *ressource = new Ressource(RessourceType::food, x, y, z);
		world.addPassiveEntity(ressource);
	}

	for(unsigned int i = 0; i < 64; ++i)
	{
		double x = (double) (rand() % width);
		double y = (double) (rand() % height);
		double z = 0;
		Ressource *ressource = new Ressource(RessourceType::wood, x, y, z);
		world.addPassiveEntity(ressource);
	}

		for(unsigned int i = 0; i < 32; ++i)
	{
		double x = (double) (rand() % width);
		double y = (double) (rand() % height);
		double z = 0;
		Ressource *ressource = new Ressource(RessourceType::gold, x, y, z);
		world.addPassiveEntity(ressource);
	}

	world.display();
	cin.get();

	return 0;
}