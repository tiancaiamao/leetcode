struct TrieNode {
  bool word;
  struct TrieNode* array[26];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
  struct TrieNode *ret;
  int i;

  ret = (struct TrieNode*)malloc(sizeof(struct TrieNode));
  memset(ret, 0, sizeof(*ret));
  return ret;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
  struct TrieNode *p;
  char c;

  p = root;
  while(*word != '\0' ) {
    c = *word;
    if (p->array[c - 'a'] == NULL) {
      p->array[c-'a'] = trieCreate();
    }
    p = p->array[c - 'a'];
    
    word++;
  }
  p->word = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
  struct TrieNode *p;
  char c;

  p = root;
  while(*word != '\0') {
    c = *word;
    if (p->array[c-'a'] == NULL) {
      return false;
    }
    p = p->array[c-'a'];
    word++;
  }  

  return p->word;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
  struct TrieNode *p;
  char c;

  p = root;
  while(*prefix != '\0') {
    c = *prefix;
    if (p->array[c-'a'] == NULL) {
      return false;
    }
    p = p->array[c-'a'];
    prefix++;
  }  

  return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
  int i;
  if (root == NULL) {
    return;
  }

  for (i=0; i<26; i++) {
    trieFree(root->array[i]);
  }

  free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
