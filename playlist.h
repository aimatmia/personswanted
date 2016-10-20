#ifndef PLAYLIST
#define PLAYLIST
#include "mytunez.h"

//playlist is an array of linked lists
song_list** library(song_node** ptrs);
void add_song(song_node** library, char* name, char* artist);
song_node* search_song(song_node** library, char* name);

#endif
