#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

void print_list(song_node* sn) {
    if(sn==NULL)
        printf("No song found\n");
    else
        print_song(sn);
 
}

int main() {
  //initializes library nodes to null
	init_lib();

	//add fav beats to playlist

	add_song( "Bring Me To Life", "Evanescence");
	add_song("Surrender", "Evanescence");
	add_song( "Please, Please, Please Let Me Get What I Want", "The Smiths");
	add_song( "Locked Out of Heaven", "Bruno Mars");
	add_song( "Runaway Baby", "Bruno Mars");
	add_song( "Fireflies", "Owl City");
	add_song( "Tokyo", "Owl City");

	add_song( "Emperor's New Clothes", "Panic! at the Disco");
  
	add_song( "Death of a Bachelor", "Panic! at the Disco");
  
	add_song( "Counting Stars", "One Republic");
	add_song( "Contagious", "Night Riots");
	add_song( "Red Flag", "The Moth & The Flame");
	add_song("Crystals","Of Monsters and Men");
//	add_song( "For him.", "Troye Sivan");
	add_song( "Half Life", "Duncan Sheikh");
//	add_song( "Good Life", "Leslie Mills");
	add_song( "In The End", "LINKIN Park");
//	add_song( "CLoser", "Tegan and Sara");
	add_song( "Big Honkin Hole in My Heart", "Phineas and Ferb");
	add_song( "Sk8er Boi", "Avril Lavigne");

	//print the entire library to make sure everything was added correctly 
	printf("\n\n Mia & Steven's Playlist~ \n");
	print_library();

	//Search by artist/singer
	printf("\n Skimming for a song by Panic! at the Disco : \n");
	print_list(find_artist( "Panic! at the Disco"));
  
  printf("\n Skimming for a song by Phineas and Ferb : \n");
	print_list(find_artist( "Phineas and Ferb"));

	printf("\n Skimming for a song by No Doubt : \n");
	print_list(find_artist( "No Doubt"));


	//Print by letter
	printf("\n Printing songs that begin with the letter 'P': \n");
	char letter = 'P';
	print_letter( letter);


	//Printing by artist
	printf("\n Printing all songs by Evanescence: \n");
	print_artist( "Evanescence");

	//Shuffling playlist (with 9 random songs)
	printf("\n Shuffled playlist of 9 random songs : \n");
	shuffle(9);
  

	//Deleting songs from the library:
	printf("\n === Testing delete_song === : \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Original Playlist: \n");
	print_library();
  


	delete_song( "In The End", "LINKIN Park");
	print_library();


	delete_song( "Please, Please, Please Let Me Get What I Want", "The Smiths");
	print_library();



	printf("\n === Setting the Playlist Free === \n");
	printf("------------------------------------------------- \n");

	printf("Original M&S Playlist: \n");
	print_library();


	printf("\n Freed All the Songs \n");
	delete_lib();
  
	printf("\n Playlist empty, no songs left :( \n");
        printf("How 'bout you add some more songs?~\n"); 

        return 0;
}
