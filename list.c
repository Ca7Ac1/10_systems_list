#include "list.h"

#define abs(a) a > 0 ? a : -1 * a

struct Location
{
    char name[30];
    float latitude;
    float longitude;
    struct Location *next;
};

int equal(const struct Location *a, char *name, float latitude, float longitude)
{
	return strcmp(a->name, name) == 0 && 
		   a->latitude == latitude &&
		   a->longitude == longitude;
}

struct Location *makeLocation(char *name, float latitude, float longitude)
{
    struct Location *l = malloc(sizeof(struct Location));

    strcpy(l->name, name);
    l->latitude = latitude;
    l->longitude = longitude;
    l->next = 0;

    return l;
}

void printLocation(const struct Location *l)
{
    char lat = l->latitude >= 0 ? 'N' : 'S';
    char lon = l->longitude >= 0 ? 'W' : 'E';

    printf("%s is located at %.2f %c, %.2f %c", l->name, abs(l->latitude), lat, abs(l->longitude), lon);
}

void print_list(const struct Location *l)
{
    printf("[ \n");
    while (l)
    {
        printLocation(l);
        printf("\n");

        l = l->next;
    }
    printf("]\n");
}

struct Location *insert_front(struct Location *front, char *name, float latitude, float longitude)
{
    struct Location *l = makeLocation(name, latitude, longitude);
    l->next = front;

    return l;
}

struct Location *free_list(struct Location *l)
{
    struct Location *front = l;

    while (l)
    {
        struct Location *prev = l;
        l = l->next;

        free(prev);
    }

    return front;
}

struct Location *remove_node(struct Location *l, char *name, float latitude, float longitude)
{
	struct Location *head = l;
	if (equal(l, name, latitude, longitude))
	{
		head = head->next;
		free(l);
		
		return head;
	}
	
	while (l->next)
	{
		if (equal(l, name, latitude, longitude))
		{
			struct Location *temp = l->next;
			l->next = l->next->next; 
			free(temp);
			
			break;
		}
	}
	
	return head;
}