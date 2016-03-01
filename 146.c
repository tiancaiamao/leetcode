struct Node {
  int key;
  int value;
  struct Node *hash_next;
  struct Node *list_next;
  struct Node *list_prev;
};


struct LRUCache {
  struct Node **array;
  int hash_size;
  int cap;
  int size;
  struct Node *list_head;
  struct Node *list_tail;
};

static struct Node*
node_new(int key, int value) {
  struct Node *ret = malloc(sizeof(struct Node));
  ret->key = key;
  ret->value = value;
  ret->hash_next = NULL;
  ret->list_next = NULL;
  ret->list_prev = NULL;
  return ret;
}

static void
move_to_list_front(struct LRUCache *cache, struct Node *n) {
  if (n == cache->list_head) return;
  if (n == cache->list_tail) cache->list_tail = n->list_prev;
  if (n->list_prev) n->list_prev->list_next = n->list_next;
  if (n->list_next) n->list_next->list_prev = n->list_prev;

  n->list_prev = NULL;
  n->list_next = cache->list_head;
  if (n->list_next) n->list_next->list_prev = n;
  cache->list_head = n;
  if (cache->list_tail == NULL)
    cache->list_tail = n;
}

// 不检查存在性，使用前用户需要自己先调hash_get
static void
hash_set(struct LRUCache *hash, struct Node *n) {
  int pos = n->key % hash->hash_size;
  n->hash_next = hash->array[pos];
  hash->array[pos] = n;
}

static struct Node*
hash_get(struct LRUCache *hash, int key) {
 int pos = key % hash->hash_size;
 for (struct Node *p = hash->array[pos]; p; p = p->hash_next) {
   if (p->key == key) return p;
 }
 return NULL;
}

static struct Node*
hash_del(struct LRUCache *hash, int key) {
  int pos = key % hash->hash_size;
  struct Node *prev = hash->array[pos];
  if (prev == NULL) return NULL;
  if (prev->key == key) {
    hash->array[pos] = prev->hash_next;
    return prev;
  }

  struct Node *p = prev->hash_next;
  while(p) {
    if (p->key == key) {
      prev->hash_next = p->hash_next;
      return p;
    }
    prev = p;
    p = p->hash_next;
  }
  return NULL;
}

void
lru_cache_init(struct LRUCache *cache, int cap) {
  cache->size = 0;
  cache->cap = cap;
  cache->hash_size = 2 * cap;
  cache->array = calloc(cache->hash_size, sizeof(struct Node*));
  cache->list_head = NULL;
  cache->list_tail = NULL;
}

int
lru_cache_get(struct LRUCache *cache, int key) {
  struct Node *n = hash_get(cache, key);
  if (n==NULL) return -1;
  move_to_list_front(cache, n);
  return n->value;
}

void
lru_cache_set(struct LRUCache *cache, int key, int value) {
  struct Node *n = hash_get(cache, key);
  if (n) {
    n->value = value;
    move_to_list_front(cache, n);
    return;
  }
  if (cache->size < cache->cap) {
    n = node_new(key, value);
    hash_set(cache, n);
    move_to_list_front(cache, n);
    cache->size ++;
    return;
  }
  n = cache->list_tail;
  hash_del(cache, n->key);
  n->key = key;
  n->value = value;
  hash_set(cache, n);
  move_to_list_front(cache, n);
}

void
lru_cache_free(struct LRUCache *cache) {
  free(cache->array);
  memset(cache, 0, sizeof(struct LRUCache));
}

static struct LRUCache global_cache;

void lruCacheInit(int capacity) {
  lru_cache_init(&global_cache, capacity);
}

void lruCacheFree() {
  lru_cache_free(&global_cache);
}

int lruCacheGet(int key) {
  return lru_cache_get(&global_cache, key);
}
    
void lruCacheSet(int key, int value) {
  return lru_cache_set(&global_cache, key, value);
}
