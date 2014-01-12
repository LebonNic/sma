#include "World.h"
#include <ctime>
using namespace std;


int main (int argc, char **argv)
{
	srand((unsigned int) time(NULL));
	World world(32.0,48.0,0.1,rand());
	world.display();
	cin.get();

	return 0;
}