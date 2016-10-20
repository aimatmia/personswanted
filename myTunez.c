 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTunez.h"

//Makes song_node with name and artist
//Places new song_node in front of rt
//Returns the new node
song_node* insert_front(song_node* rt, char name[], char artist[]){
  printf("inserting ");
  print_song(rt);
  song_node* new=(song_node *)malloc(sizeof(song_node));
  strncpy(new->name, name, 256);
  strncpy(new->artist, artist, 256);
  return new;
}

//Makes a new song node with the name and artist
//Places it in by alphabtical order by artist and then by name
//
//Checks if the song belongs before next and if not recursively finds the first
//song larger than it (linearly)
song_node* insert_order(song_node* next, char name[], char artist[]){
  int a=(strcmp(artist,next->artist)<0);
  int b=(strcmp(name,next->name)<0);
  if ( a>0 || (a==0 && b>0) ) 
      insert_order(next->next, name, artist);
  else // a<0 or (a==0 && b<0)
      insert_front(next, name, artist);

}

//Print a song
void print_song(song_node* song){
  if (song==NULL)
    printf("no song found.\n");
  else
    printf("%s - %s\n", song->name, song->artist);
}

//Printing all songs
void print_all(song_node* song){
  if (!song) return;
  print_song(song);
  if (song->next){
    printf(", ");
    print_all(song->next);
  }
}

//searches for song and returns a pointer to it
//If it is not found, null is returned.
song_node* search_song(song_node* song, char name[]){
  while (song)
    if (strcmp(name, song->name)==0)
      return song;
  return 0;
}

//returns the song with name
//if the song is not found, returns null
song_node* find_song(song_node* rt, char name[]){
  if (!rt) return 0;
  if (strcmp(rt->name,name))
    return rt;
  else
    return find_song(rt->next,name);
}

//returns the first song with artist
//if the artist is not found, returns null
song_node* find_artist(song_node* rt, char artist[]){
  if (!rt) return 0;
  if (strcmp(rt->artist, artist))
    return rt;
  else
    return find_artist(rt->next, artist);
}

//returns rt with probability p
// else moves on
song_node* random_song(song_node* rt){
  float p=0.5; //Probability rt is returned
  if (!rt->next) return rt;
  float q=1.0*rand()/RAND_MAX;
  if (q<p) return rt;
  else return random_song(rt->next);
}

int main(){

  song_node* rt=NULL;
  song_node* new= insert_front(rt, "22", "tswift");
  print_song(new);
  
}
