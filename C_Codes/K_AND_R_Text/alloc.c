#define ALLOCSIZE 100000 /* SIZE OF AVAILABLE SPACE */

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        /* IT FITS */
        allocp += n;
        return allocp -n; /* OLD P */
    } else{
        return 0;
    }
}

void afree(char *p){
    if(p>=allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
