#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int*
getPwdInfo() {
    int num_pwd, len_pwd;
    int* pwd_info[2];

    printf("Input number of passwords: ");
    scanf("%d", &num_pwd);
    printf("Input length of passwords: ");
    scanf("%d", &len_pwd);

    pwd_info[0] = num_pwd;
    pwd_info[1] = len_pwd;

    return pwd_info;
}

void
generatePwd(int* pwd_info) {
    int rand_int;
    char pwd_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";

    srand(time(NULL));

    for (int i = 0; i < pwd_info[0]; i++) {
        printf("%d. ", i+1);

        for (int j = 0; j < pwd_info[1]; j++) {
            rand_int = rand() % 72 + 1;
            printf("%c", pwd_chars[rand_int]);
        }

        printf("\n");
    }
}
