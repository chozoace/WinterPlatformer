#ifndef LEVELCONSTRUCTOR_H
#define LEVELCONSTRUCTOR_H

#include <string>
#include <list>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <objbase.h>
#include "Wall.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

class LevelConstructor
{
	public:
		LevelConstructor();
		~LevelConstructor();
		static LevelConstructor* Instance(){ return instance; }
		void loadLevel(string level);
		list<Wall*>* getWallList();
	private:
		static LevelConstructor* instance;
		list<Wall*> wallList;
		xml_document<> doc;
		string currentLevel;
		int mapWidth;
		int mapHeight;
		int tileWidth;
		int tileHeight;
		int numberOfTiles;
		int *gidArray;
		list<int> gidList;
		int getTileAt(int x, int y);
		void tileLoad();
};

#endif LEVELCONSTRUCTOR_H