#include "World.h"
using namespace std;


World::World(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed)
{
	m_Map = new Graph();
	m_Map->generateRandomPerlin(xSize, ySize, scale, seed);
}


World::~World(void)
{
	delete m_Map;
	for(auto it = m_ActiveEntities.begin(); it != m_ActiveEntities.end(); ++it)
	{
		delete (*it);
	}
	for(auto it = m_PassiveEntities.begin(); it != m_PassiveEntities.end(); ++it)
	{
		delete (*it);
	}
}


void World::addPassiveEntity(PassiveEntity *entity)
{
	m_PassiveEntities.push_back(entity);
}
void World::addActiveEntity(ActiveEntity *entity)
{
	m_ActiveEntities.push_back(entity);
}


vector<vector<EntityDisplayChar>> World::entityMap(void)
{
	unsigned int width = m_Map->width();
	unsigned int height = m_Map->height();
	// Initialize entityMap
	vector<vector<EntityDisplayChar>> entityMap(width);
	for (unsigned int i = 0; i < width; ++i)
	{
		vector<EntityDisplayChar> vector(height);
		entityMap[i] = vector;
		for(unsigned int j = 0; j < height; ++j)
			entityMap[i][j] = EntityDisplayChar::empty;
	}

	// Get position of passive entities
	for (auto it = m_PassiveEntities.begin(); it != m_PassiveEntities.end(); ++it)
	{
		unsigned int x = (unsigned int) (*it)->x();
		unsigned int y = (unsigned int) (*it)->y();

		if (x >= 0 && x < width && y >= 0 && y < height) // Valid location
		{
			switch (entityMap[x][y])
			{
			case EntityDisplayChar::empty:
				switch((*it)->type())
				{
				case PassiveEntityType::ressource:
					switch(((Ressource *) (*it))->ressourceType())
					{
					// Food Ressource
					case RessourceType::food:
						entityMap[x][y] = EntityDisplayChar::ressourceFood;
						break;
					// Wood Ressource
					case RessourceType::wood:
						entityMap[x][y] = EntityDisplayChar::ressourceWood;
						break;
					// Gold Ressource
					case RessourceType::gold:
						entityMap[x][y] = EntityDisplayChar::ressourceGold;
						break;
					// Unknown Ressource
					default:
						entityMap[x][y] = EntityDisplayChar::passiveEntity;
						break;
					}
					break;
				// Unknown Passive Entity
				default:
					entityMap[x][y] = EntityDisplayChar::passiveEntity;
					break;
				}
				break;
			default:
				entityMap[x][y] = EntityDisplayChar::multipleEntities;
				break;
			}	
		}
	}

	// Get position of active entities
	for (auto it = m_ActiveEntities.begin(); it != m_ActiveEntities.end(); ++it)
	{
		unsigned int x = (unsigned int) (*it)->x();
		unsigned int y = (unsigned int) (*it)->y();

		if (x >= 0 && x < width && y >= 0 && y < height) // Valid location
		{
			switch (entityMap[x][y])
			{
			case EntityDisplayChar::empty:
				entityMap[x][y] = EntityDisplayChar::activeEntity;
				break;
			default:
				entityMap[x][y] = EntityDisplayChar::multipleEntities;
				break;
			}	
		}
	}
	return entityMap;
}


void World::display(void)
{
	// Clear console screen
	system("cls");


	// Change console attributes
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT size;
	CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
	// Change size of console windows
	size.Bottom = 768;
	size.Top = 0;
	size.Left = 0;
	size.Right = 768;
	info.srWindow = size;
	// Define greyscale color palette
	for (int i = 0; i < 256; i+=16)
		info.ColorTable[i/16] = RGB(i,i,i);
	SetConsoleScreenBufferInfoEx(hConsole, &info);


	// Get height map
	vector<vector<unsigned int>> heightMap = m_Map->heightMap();

	// Get entity map
	vector<vector<EntityDisplayChar>> entityMap = this->entityMap();

	// Display maps
	unsigned int width = m_Map->width();
	unsigned int height = m_Map->height();
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			SetConsoleTextAttribute(hConsole,heightMap[x][y] * 16 + 15);
			cout << (char) entityMap[x][y];
		}
		cout << endl;
	}
}