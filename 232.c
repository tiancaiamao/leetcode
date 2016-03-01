struct node {
  struct node *next;
  int val;
};

struct stack {
  struct node *top;
};

void push(struct stack *s, int v) {
  struct node *tmp;
  tmp = (struct node*)malloc(sizeof(struct node));
  tmp->val = v;
  tmp->next = s->top;
  s->top = tmp;
}

int pop(struct stack *s) {
  struct node *tmp;
  int ret;

  tmp = s->top;
  ret = tmp->val;
  s->top = s->top->next;
  free(tmp);
  return ret;
}

int peek(struct stack *s) {
  return s->top->val;
}

int empty(struct stack *s) {
  return s->top == NULL;
}

typedef struct {
  struct stack s1;
  struct stack s2;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
  queue->s1.top = NULL;
  queue->s2.top = NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
  push(&queue->s1, element);
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
  int v;
  if (empty(&queue->s2)) {
    while(!empty(&queue->s1)) {
      v = pop(&queue->s1);
      push(&queue->s2, v);
    }
  }

  pop(&queue->s2);
}

/* Get the front element */
int queuePeek(Queue *queue) {
  int v;
  if (empty(&queue->s2)) {
    while(!empty(&queue->s1)) {
      v = pop(&queue->s1);
      push(&queue->s2, v);
    }
  }

  return peek(&queue->s2);
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
  return empty(&queue->s1) && empty(&queue->s2);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
  struct node* tmp;
  while(queue->s1.top != NULL) {
    tmp = queue->s1.top;
    queue->s1.top = tmp->next;
    free(tmp);
  }
  while(queue->s2.top != NULL) {
    tmp = queue->s2.top;
    queue->s2.top = tmp->next;
    free(tmp);
  }
}
