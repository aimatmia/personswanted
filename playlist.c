#include "stdio.h"
#include "stdlib.h"
#include "myTunez.h"


table* library(){
  song_node *table[26];
  int i;
  for (i=0;i<26;i++){
    table[i]=NULL;
  }
  return table;
}

//----------------+---------------------
void add_song(song_node** library, char* name, char* artist){
  char letter=*artist;
  int pos=letter-'A';
  insert_order(library[pos], name, artist);
}
 
 
//---------------SEARCH----------------- 
song_node* search_song(char name[]){
    int i;
    for (i=0;i<26<i++){
	    if (!search_song(table[i], name) return search_song(table[i], name);
    }
    return NULL;
}
 		
song_node* search_artist(char artist[]){
    int i;
    for (i=0;i<26<i++){
        if(!find_artist(table[i], artist)) return (find_artist(table[i], artist));
    }
  return NULL;
}


//---------------PRINT--------------
void print_letter(char letter){
    print_list(table[letter-'A']);
    printf("\n");
}

void print_artist(char artist[]){
    printf("songs for %s-- \n", artist);
    song_node* singer = find_artist(artist);
    while(singer && strcmp(artist, singer->artist)){
        if (strcmp(singer->artist, artist)) printf("%s  ->  %s\n", singer->artist, singer->name);
        singer=singer->next;
    }
}

void print_library(){
    printf("Mia & Stiven's playlist~ :) \n");
    int i;
    for (i=0;i<26;i++){
        print_all(table[i]);
    }
}

void shuffle(){
    printf("shuffle MS playlist up! \n");
}


//-------------DELETION-------------
void delete_song(char name[], char artist[]){
    printf("\n good-bye: *%s - %s*", artist, name);
    table[artist[0]-'A'] = remove_song(table[artist[0]-'A'], name, artist);
    print_library();
}

void delete_lib(){
    int i=0;
    for (i=0;i<26;i++){
        table[i] = free_all(table[i]);
    }
}
