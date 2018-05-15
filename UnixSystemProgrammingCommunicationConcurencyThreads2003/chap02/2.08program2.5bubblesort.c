static int count = 0;  /* variable not accessible from outside files (internal linkage) */

static int onepass(int a[], int n) /* function not accessible from other files */
{
   int i;
   int interchanges = 0;
   int temp;

   for (i = 0; i < n - 1; i++)
      if (a[i] > a[i+1])
      {
         temp = a[i];
         a[i] = a[i+1];
         a[i+1] = temp;
         interchanges = 1;
         count++;
      }
   return interchanges;   /* return true if interchanges are made */
}
/* next functions are accessible from other files */
void clearcount(void) { count = 0; }

int getcount(void) { return count; }

void bubblesort(int a[], int n)
{               /* sort a in ascending order */
   int i;
   for (i = 0; i < n - 1; i++)
      if (!onepass(a, n - i))
         break;
}
