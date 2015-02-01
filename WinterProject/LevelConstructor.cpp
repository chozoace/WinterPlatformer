#include "LevelConstructor.h"
#include "GameController.h"

LevelConstructor* LevelConstructor::instance = NULL;

LevelConstructor::LevelConstructor()
{
	instance = this;
	file<> xmlFile("TestLevel1.xml");
	doc.parse<0>(xmlFile.data());
	numberOfTiles = 0;

	xml_node<> *node = doc.first_node();
	//Gets all Attributes in map node
	for (xml_attribute<> *attr = node->first_attribute();
		attr; attr = attr->next_attribute())
	{
		string attributeName = attr->name();
		string attributeValue = attr->value();

		if (!attributeName.compare("width"))//why false
		{
			mapWidth = atoi(attributeValue.c_str());
		}
		else if (!attributeName.compare("height"))
		{
			mapHeight = atoi(attributeValue.c_str());
		}
		else if (!attributeName.compare("tilewidth"))
		{
			tileWidth = atoi(attributeValue.c_str());
		}
		else if (!attributeName.compare("tileheight"))
		{
			tileHeight = atoi(attributeValue.c_str());
		}
	}
	gidArray = new int[mapHeight * mapWidth];

	xml_node<> *iter = node->first_node("layer")->first_node()->first_node();
	//Get all gids into gid array
	for (xml_node<> *iter = node->first_node("layer")->first_node()->first_node(); iter; iter = iter->next_sibling())
	{
		xml_attribute<> *attr = iter->first_attribute();
		string value = attr->value();
		gidArray[numberOfTiles] = atoi(value.c_str());
		numberOfTiles++;
	}
	tileLoad();
}

list<Wall*>* LevelConstructor::getWallList()
{
	return &wallList;
}

void LevelConstructor::tileLoad()
{
	Wall* theWall = NULL;
	int playerPosX = 0;
	int playerPosY = 0;
	for (int spriteforX = 0; spriteforX < mapWidth; spriteforX++)
	{
		for (int spriteforY = 0; spriteforY < mapHeight; spriteforY++)
		{
			int destY = spriteforY * tileHeight;
			int destX = spriteforX * tileWidth;

			switch (getTileAt(spriteforX, spriteforY))
			{
				case 1:
					//wall
					theWall = new Wall((float)destX, (float)destY, tileWidth, tileHeight, 1);
					wallList.push_back(theWall);
					GameController::Instance()->addToGameObjectList(theWall);
					break;
				case 2:
					//player position
					playerPosX = destX;
					playerPosY = destY;
					break;
				case 3:
					//slope
					theWall = new Wall((float)destX, (float)destY, tileWidth, tileHeight, 3);
					wallList.push_back(theWall);
					GameController::Instance()->addToGameObjectList(theWall);
					break;
				case 4:
					theWall = new Wall((float)destX, (float)destY, tileWidth, tileHeight, 4);
					wallList.push_back(theWall);
					GameController::Instance()->addToGameObjectList(theWall);
					break;
				case 5:
					theWall = new Wall((float)destX, (float)destY, tileWidth, tileHeight, 5);
					wallList.push_back(theWall);
					GameController::Instance()->addToGameObjectList(theWall);
					break;
			}
		}
	}
	//create player
	GameController::Instance()->CreatePlayerAt(playerPosX, playerPosY);
}

int LevelConstructor::getTileAt(int x, int y)
{
	return gidArray[(x + (y * mapWidth))];
}

LevelConstructor::~LevelConstructor()
{
	printf("level constructor destructor\n");
	instance = NULL;
	delete[]gidArray;
	//while (!wallList.empty())
	//{
		//wallList.back() = NULL;
		//wallList.pop_back();
	//}
}