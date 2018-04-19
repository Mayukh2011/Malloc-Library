typedef struct Node{

  int size;
  int memory_size;
  int free_flag;
  void * startAddr;
  struct Node *next;
}Node;


extern Node *head=NULL;
extern void *struct_start_addr=NULL;
extern pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


Node* create_new_node(int,int);
void divide_node(Node * );
int findBuddies(Node *,Node *);
void merge_buddy_node();
void traversal();
void * malloc(size_t );
Node  * call_for_space();
int ceil(float );
void free(void *);
void *calloc(size_t, size_t );
void *realloc(void *, size_t);
void *reallocarray(void *, size_t, size_t);
void *memalign(size_t, size_t);
int posix_memalign(void **, size_t, size_t);
int isPowerOfTwo(int );
