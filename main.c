#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define abs(a) a > 0 ? a : -1 * a

struct Location
{
    char name[30];
    float latitude;
    float longitude;
    struct Location *next;
};

bool equal(const struct Location *a, const struct Location *b)
{
	return strcmp(a->name, b->name) == 0 && 
		   a->latitude == b->latitude &&
		   a->longitude == b->longitude;
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
    while (l)
    {
        printLocation(l);
        printf("\n");

        l = l->next;
    }
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

struct Location *remove(struct Location *l, struct Location *a)
{
	struct Location *head = l;
	if (equal(l, a))
	{
		head = head->next;
		free(l);
		
		return head;
	}
	
	if (a == NULL)
	{
		return head;
	}
	
	while (l->next)
	{
		if (equal(l->next, a))
		{
			struct Location *temp = l->next;
			l->next = l->next->next; 
			free(temp);
			
			break;
		}
	}
	
	return head;
}

int main()
{
    srand(time(NULL));
    struct Location *list = makeLocation("America", 37.0902, 95.7129);
    list = insert_front(list, "Russia", 61.5240, -103.3188);
    list = insert_front(list, "China", 35.8617, -104.1954);
    list = insert_front(list, "Madeupland", (((float)rand() / (float)(RAND_MAX)) * 360) - 180, (((float)rand() / (float)(RAND_MAX)) * 360) - 180);

    print_list(list);
    free_list(list);
}
