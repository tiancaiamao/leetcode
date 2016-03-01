struct Queue {
    int *array;
    int cap;
    int head;
    int tail;
};

static void
queue_init(struct Queue* q, int cap) {
    cap++;
    q->cap = cap;
    q->array = calloc(cap, sizeof(int));
    q->head = 0;
    q->tail = 0;
}

static void
queue_push(struct Queue *q, int x) {
    q->array[q->tail] = x;
    q->tail = (q->tail+1) % q->cap;
}

static int
queue_pop(struct Queue *q) {
    int ret = q->array[q->head];
    q->head = (q->head+1) % q->cap;
    return ret;
}

static int
queue_peek(struct Queue *q) {
    return q->array[q->head];
}

static bool
queue_empty(struct Queue *q) {
    return q->head == q->tail;
}

static int
queue_size(struct Queue *q) {
    return (q->tail + q->cap - q->head) % q->cap;    
}

static void
queue_destroy(struct Queue *q) {
  free(q->array);
  q->array = NULL;
  q->head = 0;
  q->tail = 0;
}

typedef struct {
    struct Queue q[2];
    int cur;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    queue_init(&stack->q[0], maxSize);
    queue_init(&stack->q[1], maxSize);
    stack->cur = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    while(!queue_empty(&stack->q[stack->cur])) {
        int x = queue_pop(&stack->q[stack->cur]);
        queue_push(&stack->q[(stack->cur+1)%2], x);
    }
    queue_push(&stack->q[stack->cur], element);
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    queue_pop(&stack->q[stack->cur]);
    int another = (stack->cur+1) % 2;
    while(queue_size(&stack->q[another]) > 1) {
        int x = queue_pop(&stack->q[another]);
        queue_push(&stack->q[stack->cur], x);
    }
    stack->cur = another;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return queue_peek(&stack->q[stack->cur]);
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return queue_empty(&stack->q[stack->cur]);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    queue_destroy(&stack->q[0]);
    queue_destroy(&stack->q[1]);
}
