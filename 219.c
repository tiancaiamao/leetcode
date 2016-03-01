struct Node {
  int key;
  int val;
  struct Node *next;
};

struct Hash {
  struct Node **table;
  int size;
};

static void
hash_init(struct Hash *h, int size) {
  h->size = size;
  h->table = calloc(size, sizeof(struct Node*));
}

static struct Node*
hash_get(struct Hash *h, int key) {
  struct Node *ptr = h->table[(unsigned int)(key) % h->size];
  while(ptr) {
    if (ptr->key == key) return ptr;
    ptr = ptr->next;
  }
  return NULL;
}

static void
hash_set(struct Hash *h, struct Node *n) {
  int pos = ((unsigned int)(n->key)) % h->size;
  struct Node *ptr = h->table[pos];
  n->next = h->table[pos];
  h->table[pos] = n;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct Hash h;
    
    hash_init(&h, 3000);
    
    for (int i=0; i<numsSize; i++) {
        struct Node *n = hash_get(&h, nums[i]);
        if (n) {
            if (i-n->val <= k) {
                return true;
            }
            n->val = i;
            continue;
        }
        
        struct Node *tmp = malloc(sizeof(*tmp));
        tmp->key = nums[i];
        tmp->val = i;
        hash_set(&h, tmp);
    }
    return false;
}
