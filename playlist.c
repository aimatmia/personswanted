#include "stdio.h"
#include "stdlib.h"
#include "playlist.h"
	
//----------------+---------------------
void add_song(char* name, char* artist){
  char letter=*artist;
  int pos=letter-'A';
  insert_order(table[pos], name, artist);
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
    int i;
    for (i=0;i<26;i++){
        if(search_artist(table[i], artist)) return (song_node*)search_artist(table[i], artist);
    }
  return NULL;
}
	
	
//---------------PRINT--------------
void print_letter(char letter){
    print_all(table[letter-'A']);
    printf("\n");
}
　
void print_artist(char artist[]){
    printf("songs for %s-- \n", artist);
    song_node* singer = (song_node*) find_artist(artist);
    while(singer && strcmp(artist, singer->artist)){
        if (strcmp(singer->artist, artist)) print_song(singer);
        singer=singer->next;
    }
}
　
void print_library(){
    //Mia & Stiven's playlist~ :)
    int i;
    for (i=0;i<26;i++){
        print_all(table[i]);
    }
}
　
void shuffle(){
    printf("shuffle MS playlist up! \n");
    song_node* copy_node = NULL;
    int i;
    //copy all songs into flat 1-D nodes
    for (i=0;i<26;i++) {
        song_node* curr = table[i];
        while(curr) {
            copy_node = insert_front(copy_node, curr->name, curr->artist);
            curr=curr->next;
        }
    }
    while (copy_node) {
        song_node* rand_node = random_song(copy_node);
        print_song(rand_node);
        copy_node=remove_song(copy_node, rand_node->name, rand_node->artist );
    }
}
　
　
//-------------DELETION-------------
void delete_song(char name[], char artist[]){
    printf("\n attemping to delete-song: *%s - %s*", artist, name);
    int bkt = artist[0]-'A';
    table[bkt] = remove_song(table[bkt], name, artist);
    print_library();
}
　
void delete_lib(){
    int i=0;
    for (i=0;i<26;i++){
        free_all(table[i]);
    }
}
　
　
　
