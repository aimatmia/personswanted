#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

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
  if (!song) return song;
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
  if (!rt) return rt;
  if (strcmp(rt->name,name)) //if not the song
    return find_song(rt->next,name); //move on
  else
    return rt; // if found the song
}

//returns the first song with artist
//if the artist is not found, returns null
song_node* find_artist(song_node* rt, char artist[]){
  if (!rt) return rt;
  if (strcmp(rt->artist, artist)) //if not the artist
    return find_artist(rt->next, artist);//move on
  else
    return rt; //if found artist
}

int num_song(song_node* rt){
    int i = 0;
    while (*(rt+i*(sizeof(song_node)) )){
        i++;
    }
    return i;
}

//
song_node* random_song(song_node* rt){
  if (!rt->next) return rt;
  int p = rand()%num_song(rt); //# between 0 and num_songs
  return (rt+p*sizeof(song_node));
}

song_node* remove_song(song_node* rt, char name[], char artist[]){
    if (!rt) return rt;
    song_node* start = rt;
    song_node* prev = rt;
    //checking first node
    if (rt->name==name && rt->artist==artist) {
        song_node* next = rt->next; 
        free(rt);
        return next;  //if no next, return null
    }
    while (rt->next){
        rt= rt->next;
        if(rt->name==name && rt->artist==artist){
            prev->next=rt->next;
            free(rt);
            return start;
        }
        prev=prev->next;
    }
    return start; //song not found, nothing removed
}


void free_all(song_node* rt){
    while (rt){
        song_node* next = rt->next;
        free(rt);
        rt = next;
    }
}


int main(){

  song_node* rt=NULL;
  song_node* new= insert_front(rt, "Bring Me To Life", "Evanescence");
  insert_order(rt, "Cheap Thrills", "Sia");
  print_all(rt);
  
}
