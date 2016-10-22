#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"
　
//Makes song_node with name and artist
//Places new song_node in front of rt
//Returns the new node
song_node* insert_front(song_node* rt, char name[], char artist[]){
  print_song(rt);
  song_node* new=(song_node *)malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = rt;
  return new;
}
　
//Printing all songs
void print_all(song_node* song){
  if (song==NULL) 
      return;
  print_song(song);
  if (song->next!=NULL){
    printf(", ");
    print_all(song->next);
  }
}
　
//Print a song
void print_song(song_node* song){
  if (song)
    printf("%s - %s\n", song->name, song->artist);
}
　
//Makes a new song node with the name and artist
//Places it in by alphabtical order by artist and then by name
//
//Checks if the song belongs before next and if not recursively finds the first
//song larger than it (linearly)
song_node* insert_order(song_node* next, char name[], char artist[]){
  if (!next) return insert_front(next, name, artist); 
  
  int a=strcmp(artist,next->artist);
  int b=strcmp(name,next->name);
  if ( a>0 || (a==0 && b>0) ) 
      next->next=insert_order(next->next, name, artist);
  else // a<0 or (a==0 && b<0)
      next=insert_front(next, name, artist);
}
　
　
//searches for song and returns a pointer to it
//If it is not found, null is returned.
 song_node* search_song(song_node* song, char name[]){
  while (song) {
    if (!strcmp(name, song->name))
      return song;
    song=song->next;
 }
  return NULL;
}
　
//returns the song with name
//if the song is not found, returns null
/*song_node* find_song(song_node* rt, char name[]){
  if (!rt) return rt;
  if (strcmp(rt->name,name)) //if not the song
    return find_song(rt->next,name); //move on
  else
    return rt; // if found the song
}
*/
　
//returns the first song with artist
//if the artist is not found, returns null
song_node* search_artist(song_node* rt, char artist[]){
  if (!rt) return rt;
  if (strcmp(rt->artist, artist)) //if not the artist
    return find_artist(rt->next, artist);//move on
  else
    return rt; //if found artist
}
　
int num_song(song_node* rt){
    int i = 0;
    while ((song_node*)(rt+i*(sizeof(song_node)) )){
        i++;
    }
    return i;
}
　
//
song_node* random_song(song_node* rt){
  if (!rt->next) return rt;
  int p = (int) rand()%num_song(rt); //# between 0 and num_songs
  return (song_node *)(rt+p*sizeof(song_node));
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
        pr#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"
　
//Makes song_node with name and artist
//Places new song_node in front of rt
//Returns the new node
song_node* insert_front(song_node* rt, char name[], char artist[]){
  print_song(rt);
  song_node* new=(song_node *)malloc(sizeof(song_node));
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = rt;
  return new;
}
　
//Printing all songs
void print_all(song_node* song){
  if (song==NULL) 
      return;
  print_song(song);
  if (song->next!=NULL){
    printf(", ");
    print_all(song->next);
  }
}
　
//Print a song
void print_song(song_node* song){
  if (song)
    printf("%s - %s\n", song->name, song->artist);
}
　
//Makes a new song node with the name and artist
//Places it in by alphabtical order by artist and then by name
//
//Checks if the song belongs before next and if not recursively finds the first
//song larger than it (linearly)
song_node* insert_order(song_node* next, char name[], char artist[]){
  if (!next) return insert_front(next, name, artist); 
  
  int a=strcmp(artist,next->artist);
  int b=strcmp(name,next->name);
  if ( a>0 || (a==0 && b>0) ) 
      next->next=insert_order(next->next, name, artist);
  else // a<0 or (a==0 && b<0)
      next=insert_front(next, name, artist);
}
　
　
//searches for song and returns a pointer to it
//If it is not found, null is returned.
 song_node* search_song(song_node* song, char name[]){
  while (song) {
    if (!strcmp(name, song->name))
      return song;
    song=song->next;
 }
  return NULL;
}
　
//returns the song with name
//if the song is not found, returns null
/*song_node* find_song(song_node* rt, char name[]){
  if (!rt) return rt;
  if (strcmp(rt->name,name)) //if not the song
    return find_song(rt->next,name); //move on
  else
    return rt; // if found the song
}
*/
　
//returns the first song with artist
//if the artist is not found, returns null
song_node* search_artist(song_node* rt, char artist[]){
  if (!rt) return rt;
  if (strcmp(rt->artist, artist)) //if not the artist
    return find_artist(rt->next, artist);//move on
  else
    return rt; //if found artist
}
　
int num_song(song_node* rt){
    int i = 0;
    while ((song_node*)(rt+i*(sizeof(song_node)) )){
        i++;
    }
    return i;
}
　
//
song_node* random_song(song_node* rt){
  if (!rt->next) return rt;
  int p = (int) rand()%num_song(rt); //# between 0 and num_songs
  return (song_node *)(rt+p*sizeof(song_node));
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
　
　
/*int main(){
　
  song_node* rt=NULL;
  song_node* new= insert_front(rt, "Bring Me To Life", "Evanescence");
  song_node* n2 = insert_order(new, "Cheap Thrills", "Sia");
  print_all(n2);
  song_node* n3 = search_song(n2, "Cheap Thrills");
  print_song(n3);
  
} */
　
ev=prev->next;
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
　
　
/*int main(){
　
  song_node* rt=NULL;
  song_node* new= insert_front(rt, "Bring Me To Life", "Evanescence");
  song_node* n2 = insert_order(new, "Cheap Thrills", "Sia");
  print_all(n2);
  song_node* n3 = search_song(n2, "Cheap Thrills");
  print_song(n3);
  
} */
　
