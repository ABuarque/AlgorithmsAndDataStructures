#ifndef STATICLIST_H
#define STATICLIST_H

struct staticList {
	int index;
	int size;
	int* v;
};

typedef struct staticList StaticList;

StaticList newStaticList(const int size);

void destroyStaticList(StaticList* list);

void addAtEnd(StaticList* list, int value);

int getLast(const StaticList* list);

int getAt(const StaticList* list, const int index);

void addAt(StaticList* list, const int index, const int value);

void removeFrom(StaticList* list, int index);

void printStaticList(const StaticList* list);

#endif
