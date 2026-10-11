
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long type;
    char text[100];
};

int main() {
    int id;
    struct message msg;

    id = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (id == -1) {
        perror("msgget");
        return 1;
    }

    msg.type = 1;
    strcpy(msg.text, "Hello through message queue");

    if (msgsnd(id, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        msgctl(id, IPC_RMID, NULL);
        return 1;
    }

    if (msgrcv(id, &msg, sizeof(msg.text), 1, 0) == -1) {
        perror("msgrcv");
        msgctl(id, IPC_RMID, NULL);
        return 1;
    }

    printf("Message received: %s\n", msg.text);

    msgctl(id, IPC_RMID, NULL);

    return 0;
}
