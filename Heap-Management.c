/*write a program to implement heap management scheme. implement the 'allocate' and 'free' functions.*/

#include<stdio.h>
#include<stdlib.h>

int a = 0, b = 0;

struct free {
    int SNO;
    int size;
    struct free* link;
}* free_head = NULL, *prev_free = NULL;

struct alloc {
    int block_id;
    int SNO;
    int size;
    struct alloc* link;
}* alloc_head = NULL, *prev_alloc = NULL;


void create_free(int c)
{
    struct free* p = (struct free*)malloc(sizeof(struct free));
        
    p->size = c;
    p->SNO = a;
    p->link = NULL;
    if (free_head == NULL)
        free_head = p;
    else
        prev_free->link = p;
    prev_free = p;
    a++;
}


void print_free()
{
    struct free* p = free_head;
   printf("SNO\tSizefragment\n");
    while (p != NULL) {
      printf("%d /t %d \n",p->SNO,p->size);
        p = p->link;
    }
}


void print_alloc()
{
   struct alloc* p = alloc_head; 
   printf("SNO\tBlock ID\tSizefragment\n");
    while (p != NULL) {
      printf("%d \t %d \t %d \n",p->SNO,p->block_id,p->size);
        p = p->link;
    }
   
}

// fuction to create allocated memory according to first fit memory allocation.
void create_alloc(int c)
{
   
    struct alloc* q = (struct alloc*)malloc(sizeof(struct alloc));
        
    q->size = c;
    q->SNO = b;
    q->link = NULL;
    struct free* p = free_head;

    while (p != NULL) {
        if (q->size <= p->size)
            break;
        p = p->link;
	}
    if (p != NULL) {
        
        q->block_id = p->SNO;
        p->size = p->size-q->size;
        if (alloc_head == NULL)
            alloc_head = q;
        else {
            prev_alloc = alloc_head;
            while (prev_alloc->link != NULL)
                prev_alloc = prev_alloc->link;
            prev_alloc->link = q;
        }
        b++;
    }
    else
    {
    	printf("\nBlock of size %d can't be allocated\n\n", c);
	}
   
}


int main()
{
	
    int blockSize[3], RequestSize[4], BNo, RNo,i;
    
    printf("Enter no. of blocks:");
    scanf("%d",&BNo);
    printf("\n Enter size of each block:");
    for(i=1;i<=BNo;i++)
    	scanf("%d",&blockSize[i]);
    
    printf("Enter no. of Requests:");
    scanf("%d",&RNo);
    printf("\n Enter size of each Request:");
    for(i=1;i<=RNo;i++)
    	scanf("%d",&RequestSize[i]);
    
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(RequestSize) / sizeof(RequestSize[0]);

    for (i = 1; i <= m; i++){
	
        create_free(blockSize[i]);
	}
    for (i = 1; i <= n; i++){

        create_alloc(RequestSize[i]);
	}
    print_alloc();
    
return 0;
}


  
  
  
  
  
 
