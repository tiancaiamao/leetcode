struct Node {
  int val;
  struct Node *next;
};

bool containsDuplicate(int* nums, int numsSize) {
  int pos, i;
  struct Node *tmp;
  struct Node* table[50000];
  
  memset(table, 0, sizeof(struct Node*)*50000);
  for (i=0; i<numsSize; i++) {
    pos = (nums[i] * 31) % 50000;
    for (tmp = table[pos]; tmp != NULL; tmp = tmp->next) {
      if (tmp->val == nums[i]) return true;
    }

    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->val = nums[i];
    tmp->next = table[pos];
    table[pos] = tmp;    
  }

  return false;
}
