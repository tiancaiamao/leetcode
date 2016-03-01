struct Stack {
    int *array;
    int pos;
    int cap;
};

static void
stack_init(struct Stack *s, int cap) {
    s->array = calloc(cap, sizeof(int));
    s->cap = cap;
    s->pos = 0;
}

static void
stack_destroy(struct Stack *s) {
    free(s->array);
    s->cap = 0;
    s->pos = 0;
}

static void
stack_push(struct Stack *s, int x) {
    s->array[s->pos] = x;
    s->pos++;
}

static int
stack_pop(struct Stack *s) {
    s->pos--;
    return s->array[s->pos];
}

static int
stack_top(struct Stack *s) {
    return s->array[s->pos-1];
}

static int
stack_empty(struct Stack *s) {
    return s->pos == 0;
}

typedef struct {
    struct Stack s;
    struct Stack m;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack_init(&stack->s, maxSize);
    stack_init(&stack->m, maxSize);
}

void minStackPush(MinStack *stack, int element) {
    stack_push(&stack->s, element);
    if (stack_empty(&stack->m)) {
        stack_push(&stack->m, element);
        return;
    }
    int top = stack_top(&stack->m);
    stack_push(&stack->m, element<top?element:top);
}

void minStackPop(MinStack *stack) {
    stack_pop(&stack->s);
    stack_pop(&stack->m);
}

int minStackTop(MinStack *stack) {
    return stack_top(&stack->s);
}

int minStackGetMin(MinStack *stack) {
    return stack_top(&stack->m);
}

void minStackDestroy(MinStack *stack) {
    stack_destroy(&stack->s);
    stack_destroy(&stack->m);
}
