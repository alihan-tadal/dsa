typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

// make adt declaration
Queue *create_queue();
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int peek(Queue *queue);
int is_empty(Queue *queue);
void print_queue(Queue *queue);
void delete_queue(Queue *queue);
