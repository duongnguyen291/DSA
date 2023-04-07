#include <stdio.h>
#include <string.h>

#define n 1000

int check(const char *a, const char *b, const char *c, int start) {
    if (start + strlen(a) > strlen(c)) {
        return 0;
    }
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != c[start + i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char a[n], b[n], c[n];
    scanf("%[^\n]%*c", a);
    scanf("%[^\n]%*c", b);
    scanf("%[^\n]%*c", c);

    printf("%s\n%s\n%s\n", a, b, c);

    char temp[2*n];
    memset(temp, 0, sizeof(temp));
    char *p = temp;

    for (int i = 0; i < strlen(c); i++) {
        if (check(a, b, c, i)) {
            strcpy(p, b);
            p += strlen(b);
            i += strlen(a) - 1;
                printf("1:%s\n", temp);

        } else {
            *p++ = c[i];
                printf("2:%s\n", temp);

        }
    }

    printf("%s\n", temp);

    return 0;
}
