#ifndef PLAYLIST
#define PLAYLIST
#include "song_node.h"

//playlist is an array of linked lists

　
song_node* table[26];

void init_lib(){
  int i;
  for (i=0;i<26;i++){
    table[i]=NULL;
  }
}

void add_song(char* name, char* artist);
void delete_lib();
void delete_song(char name[], char artist[]);
void print_artist(char artist[]);
void print_letter(char letter);
void print_library();
song_node* find_artist(char artist[]);
song_node* find_song(char name[]);
void shuffle();

#endif
