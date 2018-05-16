#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "2.09program2.6listlib.h"
#define TRAV_INIT_SIZE 8
typedef struct list_struct
{
     data_t item;  /* item.time for the timestamp, item.string for the text */
     struct list_struct *next;
} list_t;
/* next 5 variables are accessible only from within this file , due to static*/
static list_t endlist;
static list_t *headptr = NULL;
static list_t *tailptr = NULL;
static list_t **travptrs = NULL; /*beggining of a non-fixed-size array of pointers-to-list_t */
static int travptrs_size = 0;  /* setting the size of above array,initially to 0 */

int accessdata(void)
{              /* function returns a nonnegative key if successful */
   int i;
   list_t **newptrs;     /* an array of pointers-to-list_t objects */
   if (headptr == NULL)             /* refuse to access a completely empty list! */
     { errno = EINVAL; return -1; }
   if (travptrs_size == 0)                      /* is it the first traversal? */
   {    /* then allocate memory enough to hold 8 pointers of type list_t. */
      travptrs = (list_t **)calloc(TRAV_INIT_SIZE, sizeof(list_t *));
      if (travptrs == NULL)     /* couldn't allocate space for traversal keys? */
         return -1;
      travptrs[0] = headptr;
      travptrs_size = TRAV_INIT_SIZE;
      return 0;
    }   /*if not 1st traversal,then we got a travptrs_size of 8 or more */
   for (i = 0; i < travptrs_size; i++)     /* look for an empty slot for key */
   {
      if (travptrs[i] == NULL)
        { travptrs[i] = headptr; return i; }
   } /* if the previous loop did not found an empty slot, we expand the allocated memory, doubling it */
   newptrs = realloc(travptrs, 2*travptrs_size*sizeof(list_t *));
   if (newptrs == NULL)        /* couldn't double the array of traversal keys? */
      return -1;
   travptrs = newptrs;
   travptrs[travptrs_size] = headptr;
   travptrs_size *= 2;
   return travptrs_size/2;
}

int adddata(data_t data)    /* allocate node for data and add/append to end of list */
{
   list_t *newnode;
   int nodesize;
   nodesize = sizeof(list_t) + strlen(data.string) + 1;
   if ((newnode = (list_t *)(malloc(nodesize))) == NULL) /* couldn't add node? */
      return -1;
   newnode->item.time = data.time;
   newnode->item.string = (char *)newnode + sizeof(list_t);  /* ? WHY add sizeof ?*/
   strcpy(newnode->item.string, data.string);
   newnode->next = NULL;
   if (headptr == NULL)  /* was the newly added element , the 1st? */
      headptr = newnode;
   else      /* or was it the last of an existing list? */
      tailptr->next = newnode;
   tailptr = newnode;  /* in any case, update what is considered as a last element */
   return 0;
}

int getdata(int key, data_t *datap)  /* copy next item and set datap->string */
{
   list_t *t;
   if ( (key < 0) || (key >= travptrs_size) || (travptrs[key] == NULL) )
	  { errno = EINVAL; return -1; }
   if (travptrs[key] == &endlist)  /* reached end of list? */
   {
      datap->string = NULL;
      travptrs[key] = NULL;
      return 0;       /* reaching end of list natural condition, not an error */
    }
   t = travptrs[key];
   datap->string = (char *)malloc(strlen(t->item.string) + 1);
   if (datap->string == NULL) /* couldn't allocate space for returning string? */
      return -1;
   datap->time = t->item.time;
   strcpy(datap->string, t->item.string);
   if (t->next == NULL)
      travptrs[key] = &endlist;
   else
      travptrs[key] = t->next;
   return 0;
}

int freekey(int key)                /* free list entry corresponding to key */
{
   if ( (key < 0) || (key >= travptrs_size) )           /* key out of range? */
	   { errno = EINVAL; return -1; }
   travptrs[key] = NULL;
   return 0;
}

