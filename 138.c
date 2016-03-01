struct KV {
  struct RandomListNode *key;
  struct RandomListNode *value;
};

const int HASH_SZ = 5000;
void hash_init(struct KV* hashdata) {
  int i;
  for (i=0; i<HASH_SZ; i++) {
    hashdata[i].key = NULL;
    hashdata[i].value = NULL;
  }
}

struct RandomListNode *hash_get(struct KV* hashdata, struct RandomListNode *key) {
  struct KV kv;
  intptr_t k = (intptr_t)key;
  int i;

  k = (k << 5) - k;
  for (i=0; i<5000; i++) {
    kv = hashdata[(( k+i) % HASH_SZ)];
    if (kv.key == key) {
      return kv.value;
    }
    if (kv.key == NULL) {
      return NULL;
    }
  }

  return NULL;
}

void hash_put(struct KV* hashdata, struct RandomListNode *key, struct RandomListNode *value) {
  struct KV* kv;
  intptr_t k = (intptr_t)key;
  int i;

  k = (k << 5) - k;
  for (i=0; i<5000; i++) {
    kv = &hashdata[(( k+i) % HASH_SZ)];
    if (kv->key == NULL || kv->key == key) {
      kv->key = key;
      kv->value = value;
      return;
    }
  }
}

struct RandomListNode *NewNode() {
  struct RandomListNode *ret;
  ret = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
  ret->label = 0;
  ret->random = NULL;
  ret->next = NULL;
  return ret;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
  struct RandomListNode *from, *to;
  struct RandomListNode *ret, *value;
  struct KV hashdata[HASH_SZ];

  if (head == NULL) {
    return NULL;
  } else {
    ret = NewNode();
    from = head;
    to = ret;
  }

  hash_init(hashdata);
  while(from) {
    to->label = from->label;

    if (from->random) {
      value = hash_get(hashdata, from->random);
      if (value == NULL) {
        value = NewNode();
        value->label = from->random->label;
        hash_put(hashdata, from->random, value);
      }
      to->random = value;
    } else {
      to->random = NULL;
    }

    if (from->next) {
      value = hash_get(hashdata, from->next);
      if (value == NULL) {
        value = NewNode();
        hash_put(hashdata, from->next, value);
      }
      to->next = value;
    } else {
      to->next = NULL;
    }

    from = from->next;
    to = to->next;
  }

  return ret;
}
