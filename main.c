#include <stdio.h> #include <stdlib.h>
#include <string.h>
#include "song_node.h"
　
　
int main() {
  //initializes library nodes to null
	init_lib();
　
	//add fav beats to playlist
	char name[40] = "Bring Me To Life";
	char artist[40] = "Evanescence";
	add_song( name, artist);
　
	strcpy(name, "Surrender");
	strcpy(artist, "Evanescence");
	add_song( name, artist);
　
	strcpy(name, "Locked Out of Heaven");
	strcpy(artist, "Bruno Mars");
	add_song( name, artist);
　
	strcpy(name, "Runaway Baby");
	strcpy(artist, "Bruno Mars");
	add_song( name, artist);
　
	strcpy(name, "Fireflies");
	strcpy(artist, "Owl City");
	add_song( name, artist);
　
	strcpy(name, "Tokyo");
	strcpy(artist, "Owl City");
	add_song( name, artist);
　
	strcpy(name, "Emperor's New Clothes");
	strcpy(artist, "Panic! at the Disco");
	add_song( name, artist);
  
  strcpy(name, "Death of a Bachelor");
	strcpy(artist, "Panic! at the Disco");
	add_song( name, artist);
  
  strcpy(name, "Counting Stars");
	strcpy(artist, "One Republic");
	add_song( name, artist);
　
	strcpy(name, "Please, Please, Please Let Me Get What I Want");
	strcpy(artist, "The Smiths");
	add_song( name, artist);
　
	strcpy(name, "Contagious");
	strcpy(artist, "Night Riots");
	add_song( name, artist);
  
  strcpy(name, "Red Flag");
	strcpy(artist, "The Moth & The Flame");
	add_song( name, artist);
  
	strcpy(name, "Crystals");
	strcpy(artist, "Of Monsters and Men");
	add_song( name, artist);
  
  strcpy(name, "For him.");
	strcpy(artist, "Troye Sivan");
	add_song( name, artist);
  
	strcpy(name, "Half Life");
	strcpy(artist, "Duncan Sheikh");
	add_song( name, artist);
  
  strcpy(name, "Good Life");
	strcpy(artist, "Leslie Mills");
	add_song( name, artist);
　
	strcpy(name, "In The End");
	strcpy(artist, "LINKIN Park");
	add_song( name, artist);
　
	strcpy(name, "Closer");
	strcpy(artist, "Tegan and Sara");
	add_song( name, artist);
  
  strcpy(name, "Big Honkin Hole in My Heart");
	strcpy(artist, "Phineas and Ferb");
	add_song( name, artist);
  
  strcpy(name, "Sk8er Boi");
	strcpy(artist, "Avril Lavigne");
	add_song( name, artist);
　
	//print the entire library to make sure everything was added correctly 
	printf("\n\n Mia & Steven's Playlist~ \n");
	print_library();
  printf("\n");
　
	//Search by artist/singer
	printf("\n Skimming for a song by Panic! at the Disco : \n");
	strcpy(artist, "Panic! at the Disco");
	find_artist(artist);
  
  printf("\n Skimming for a song by Phineas and Ferb : \n");
	strcpy(artist, "Phineas and Ferb");
	find_artist( artist);
　
	printf("\n Skimming for a song by No Doubt : \n");
	strcpy(artist, "No Doubt");
	find_artist( artist);
　
　
　
	//Print by letter
	printf("\n Printing songs that begin with the letter 'C': \n");
	char letter = 'C';
	print_letter( letter);
　
　
	//Printing by artist
	printf("\n Printing all songs by Evanescence: \n");
	strcpy(artist, "Evanescence");
	print_artist( artist);
　
　
	//Shuffling playlist (with 9 random songs)
	printf("\n Shuffled playlist of 9 random songs : \n");
	shuffle( 9);
  
　
	//Deleting songs from the library:
	printf("\n === Testing delete_song === : \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Original Playlist: \n");
	print_library();
  
　
	printf("\n good-bye to: 'In The End' \n");
	strcpy(name, "In The End");
	delete_song( name);
	print_library();
　
　
	printf("\n good-bye to: 'Please, Please, Please Let Me Get What I Want' \n");
	strcpy(name, "Please, Please, Please Let Me Get What I Want");
	delete_song( name);
	print_library();
　
　
　
	printf("\n === Setting the Playlist Free === \n");
	printf("------------------------------------------------- \n");
　
	printf("Original M&S Playlist: \n");
	print_library();
　
　
	printf("\n Freed All the Songs \n");
	delete_lib();
	print_library(); //printing an empty playlist
  
	printf("\n Playlist empty, no songs left :( \n");
  printf("How 'bout you add some more songs?~"); 
　
        return 0;
}
　
