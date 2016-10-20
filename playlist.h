#ifndef PLAYLIST
#define PLAYLIST
#include "mytunez.h"


song_list** playlist(song_node** ptrs);
void add_song(song_node** playlist, char* name, char* artist);
song_node* search_song(song_node** playlist, char* name);

#endif
