#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "playlist.h"

//----------------+---------------------
void add_song(char name[], char artist[]){
  char letter=artist[0];
  int pos=letter-'A';
//  if (!table[pos])
//      table[pos]=(song_node*)malloc(sizeof(song_node*));
  table[pos]=insert_order(table[pos], name, artist);
}

//---------------SEARCH----------------- 
song_node* find_song(char name[]){
    int i;
    for (i=0;i<26;i++)
        if (search_song(table[i], name)) 
            return search_song(table[i], name);
        else
            continue;
    return NULL;
}
	
song_node* find_artist(char artist[]){
  char letter=artist[0];
  int pos=letter-'A';
  return search_artist(table[pos], artist);
}


//---------------PRINT--------------
void print_letter(char letter){
    print_all(table[letter-'A']);
    printf("\n");
}

void print_artist(char artist[]){
//    printf("songs by %s-- \n", artist);
    int bkt = artist[0]-'A';
    song_node* singer = table[bkt];
    while(singer){
        int len= strlen(artist);
        if (strncmp(singer->artist, artist, len)==0) print_song(singer);
        singer=singer->next;
    }
}

void print_library(){
    //Mia & Stiven's playlist~ :)
    int i;
    for (i=0;i<26;i++){
        if( table[i]) {
            printf("%c list\n", 'A'+i);
            print_all(table[i]);
        }
    }
}

void shuffle(int n){
    printf("shuffle MS playlist up! \n");
    //TODO: if (n>total_num_songs) n=tol_num_songs
    song_node* shuffle=NULL;
    while(n) { 
       int bkt=rand()%26;
       if(table[bkt]==NULL)
           continue;
       song_node* rand =random_song(table[bkt]);
       if(!search_song( shuffle, rand->name)) {
           shuffle = insert_order(shuffle, rand->name, rand->artist);
           n--;
       } 
    }
    print_all( shuffle);
}


//-------------DELETION-------------
void delete_song(char name[], char artist[]){
    printf("\n good-bye to : *%s - %s*", artist, name);
    int bkt = artist[0]-'A';
    table[bkt]=remove_song(table[bkt], name, artist);
    print_library();
}

void delete_lib(){
    int i=0;
    for (i=0;i<26;i++){
        free_all(table[i]);
    }
}


