#ifndef LIST_H
#define LIST_H

struct Location
{
    char name[30];
    float latitude;
    float longitude;
    struct Location *next;
};

int equal(const struct Location *, char *, float, float);
struct Location *makeLocation(char *, float, float);
void printLocation(const struct Location *);
void print_list(const struct Location *);
struct Location *insert_front(struct Location *, char *, float, float);
struct Location *free_list(struct Location *);
struct Location *remove_node(struct Location *, char *, float, float);

#endif