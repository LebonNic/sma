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
	world.populateMap(0.05,0.10,0.05);

	world.display();
	cin.get();

	return 0;
}