#include "World.h"
using namespace std;


World::World(double xSize, double ySize, double scale, unsigned int seed)
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
				entityMap[x][y] = EntityDisplayChar::passiveEntity;
				break;
			default:
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
			case EntityDisplayChar::passiveEntity:
				entityMap[x][y] = EntityDisplayChar::bothEntities;
				break;
			default:
				break;
			}	
		}
	}
	return entityMap;
}


void World::display(void)
{
	// Define color palette
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
	for (int i = 0; i < 256; i+=16)
		info.ColorTable[i/16] = RGB(i,i,i);
	SetConsoleScreenBufferInfoEx(hConsole, &info);


	// Get 2d heightMap of map
	vector<vector<unsigned int>> heightMap = m_Map->heightMap();
	unsigned int width = m_Map->width();
	unsigned int height = m_Map->height();

	vector<vector<EntityDisplayChar>> entityMap = this->entityMap();

	// display heightMap
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			SetConsoleTextAttribute(hConsole,heightMap[x][y] * 16);
			cout << (char) entityMap[x][y];
		}
		cout << endl;
	}
}