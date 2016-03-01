struct node {
    int data;
    struct node *next;  
};
struct hash {
    struct node **array;
    int size;
};
void hash_init(struct hash* h, int size) {
    int s = sizeof(struct node*) * size;
    h->array = malloc(s);
    memset(h->array, 0, s);
    h->size = size;
}
void hash_insert(struct hash* h, int key) {
    struct node *n;
    int pos = (key * 31) % h->size;
    
    n = malloc(sizeof(struct node));
    n->data = key;
    n->next = h->array[pos];
    h->array[pos] = n;
}
bool hash_exist(struct hash* h, int key) {
    struct node *p;
    int pos = (key * 31) % h->size;

    for (p = h->array[pos]; p != NULL ; p = p->next) {
       if (p->data == key) {
           return true;
       }
    }
    return false;
}

int trans(int n) {
    int v, ret;
    ret = 0;
    while(n > 0) {
        v = n % 10;
        ret += v*v;
        n /= 10;
    } 
    return ret;
}

bool isHappy(int n) {
    struct hash h;
    int v, n1;
    
    hash_init(&h, 1133);
    while(n != 1) {
        if (hash_exist(&h, n)) return false;
        hash_insert(&h, n);
        n = trans(n);
    }
    return true;
}
