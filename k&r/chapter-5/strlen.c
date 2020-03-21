int strlen(char *s) {
    int i;
    for (i = 0; *s != '\0'; s++) {
        i++;
    }
    return i;
}

int main() {
    char s[] = "hello, world";
    int len = strlen(s);
    printf("len is: %d\n", len);
}