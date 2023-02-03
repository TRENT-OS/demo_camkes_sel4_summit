/*
 * Server
 *
 * Copyright (C) 2022, HENSOLDT Cyber GmbH
 */

#include <camkes.h>
#include <camkes/dataport.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int length = strlen(s);
    int temp, i, j;
    for(i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void if_server_reverse(dataport_ptr_t *ptr) {
    char *olleh;

    olleh = (char *) dataport_unwrap_ptr(*ptr);

    printf("Server: Receiving String '%s' from Client.\n", olleh);
    printf("Server: Reversing String.\n");

    reverse(olleh);

    printf("Server: Sending reversed String '%s' to Client.\n", olleh);

    strcpy((char *)buf_server, olleh);
    *ptr = dataport_wrap_ptr((void *)buf_server);
}