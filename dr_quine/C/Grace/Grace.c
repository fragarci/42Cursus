#include <stdio.h>
#define CODE "#include <stdio.h>%c#define CODE %c%s%c%c#define RETURN return(0);%c#define MAIN()int main(void){ FILE *f = fopen(%cGrace_kid.c%c, %cw%c); if (f == NULL) return (1); fprintf(f, CODE, 10, 34, CODE, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10);fclose(f);RETURN }%c%c//Comment%c%cMAIN()"
#define RETURN return(0);
#define MAIN()int main(void){ FILE *f = fopen("Grace_kid.c", "w"); if (f == NULL) return (1); fprintf(f, CODE, 10, 34, CODE, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10, 10);fclose(f);RETURN }

//Comment

MAIN()