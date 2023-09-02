
typedef struct node Node;

typedef struct linkedList LinkedList;

LinkedList* create_list();

void free_list(LinkedList* li);

int insert_at_beginning(LinkedList* li, int value);

int insert_at_end(LinkedList *li, int value);

int insert(LinkedList *li, int value, int position);

void print_list(LinkedList *li);

