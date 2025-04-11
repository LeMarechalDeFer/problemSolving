#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct HashEntry {
    char* key ;  
    int value ; 
    struct HashEntry* next ; 
} HashEntry ;


typedef struct HashMap{
    HashEntry** entries ;
    size_t size;
} *HashMap;

unsigned long hash(const char* str);
HashMap createHashMap(size_t size);
void insert(HashMap table, const char* key, int value);
void get_element(HashMap table, const char* key);
void delete_element(HashMap table, const char* key);
void free_table(HashMap table);


#endif


/*
To do list : 
- Insert (Create Update)
- Get (Read)
- Delete
- Rezise 
- Collision Handling
- Loop Through a Map
- Elements with Equal Keys

Definitions
- hash function
    - performance
    - uniformity
    - simplicity
    - djb2, next MurmurHash, CRC32, FNV-1a
- load factor
- collision
    - Chaining
    - Open addressing memory (robin hood est une des strategies)
- dynamic resizing


Link: 
https://en.wikipedia.org/wiki/Hash_table#Robin_Hood_hashing
https://www.w3schools.com/cpp/cpp_maps.asp
https://www.youtube.com/watch?v=FsfRsGFHuv4
https://github.com/tidwall/hashmap.c
https://visualgo.net/en/hashtable
*/
