//
// Created by 17hao on 2019-03-29.
//

//将指针t指向的字符串内容复制给s
void myStrCpy_V1(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

void myStrCpy_V2(char *s, char *t) {
    while(*t != '\0') {
        *s++ = *t++;
    }
}

void myStrCpy_V3(char *s, char *t) {
    while((*s++ = *t++))
        ;
}