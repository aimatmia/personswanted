typedef struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
} song_node;

song_node* insert_front(song_node* rt, char name[], char artist[]);
song_node* insert_order(song_node* next, char name[], char artist[]);

void print_all(song_node* song);
void print_song(song_node* song);

//song_node* find_song(song_node* rt, char name[]);
song_node* search_artist(song_node* rt, char artist[]);
song_node* search_song(song_node* song, char name[]);

int num_song(song_node* rt);
song_node* random_song(song_node* rt);

song_node* remove_song(song_node* rt, char name[], char artist[]);
void free_all(song_node* rt); 
