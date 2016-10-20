typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node* insert_front(song_node* rt, char name[], char artist[]);
song_node* insert_order(song_node* first, char name[], char artist[]);

void print_song(song_node* song);
void print_all(song_node* song);

song_node* find_song(song_node* rt, char name[]);
song_node* find_artist(song_node* rt, char artist[]);

song_node* random_song(song_node* rt);
song_node* remove_song(song_node* sacrifice);
  
  
