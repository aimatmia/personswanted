#include "stdio.h"
#include "stdlib.h"
#include "myTunez.h"

song_list** playlist(song_node** ptrs){ 
  int i=0;
  while(i<26){
    ptrs[i]=NULL;
    i++;
  }
}

void add_song(song_node** playlist, char* name, char* artist){
  song_node* start;
  while(playlist) continue;
  if (start==playlist) playlist=insert_front(playlist, name, artist);
  else playlist=insert_order(playlist, name, artist);
}
  
song_node* search_song(song_node** playlist, char* name){
  while(playlist){
    if (playlist->name==name) return playlist;
  }
  return NULL;
}
