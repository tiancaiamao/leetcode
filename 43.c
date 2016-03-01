static void
mul(char *str, char c, char *dest) {
    int i;
    int b = c-'0';
    int high = 0;
    for (i=0; str[i]!='\0'; i++) {
        int v = (str[i]-'0') * b + high;
        dest[i] = (v % 10) + '0';
        high = v / 10;
    }
    if (high > 0) dest[i] = high + '0';
}

static void
add(char *s1, char *s2, int offset) {
    int i;
    int high = 0;
    for (i=0; s2[i]!='\0'; i++) {
        int v = s1[offset+i]-'0' + s2[i]-'0' + high;
        s1[offset+i] = (v % 10) + '0';
        high = v / 10;
    }
    if (high > 0) s1[offset+i] = high + '0';
}

static void
reverse(char *s, int i, int j) {
    char tmp;
    while(i<j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int cap = len1+len2;
    
    char *ret = malloc(cap+1);
    memset(ret, '0', cap);
    ret[cap] = '\0';
    char *tmp = malloc(cap+1);

    reverse(num1, 0, len1-1);
    reverse(num2, 0, len2-1);
    printf("%s\n", num1);
    printf("%s\n", num2);
    int i;
    for (i=0; i<len2; i++) {
        memset(tmp, 0, cap+1);
        mul(num1, num2[i], tmp);
        add(ret, tmp, i);
    }
    int pos = strlen(ret);
    while(ret[pos]=='\0' || ret[pos]=='0') {
        ret[pos] = '\0';
        pos--;
    }
    reverse(ret, 0, pos);
    if (strcmp(ret, "")==0) {
        ret[0] = '0';
    }
    return ret;
}
