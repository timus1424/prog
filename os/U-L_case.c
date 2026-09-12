#include <stdio.h>
#include<pthread.h>

void *uc (void *arg) [
char s[20] ="Hello my name is Ash";
printf ("\nThe UPPERCASE Characters are: \n"); for (int i=0; 1<20; i++) |
if (s [i]>="A" 88 s[1] <="Z")
printf ("%c,", s[il);
return NULL;
*Ic(void marg) [
char s[20]="Hello my name is Ash"; printf ("\nThe LOWERCASE Characters are: in");
for (int i=0; i<20; 1++) {
if (s [1]>="a"
&& s [i] <="z")
printf ("%c,", stil);
return NULL;
int main () f
pthread_t t1, t2:
pthread_create (&t1,
NULL,
pthread_create (&t2,
NULL, UC,
NULL);
1c,
NULL);
pthread_Join(t1, NULL);
pthread_Join(t2, NULL) ;
	return 0;
}
