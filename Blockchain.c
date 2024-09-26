
#include <stdio.h>
#include <stdlib.h>
#include <openssl/ssl.h>


// first step i took is to create a struct that defines what a Block comprises off onchain. 
typedef struct Block {
  
       int hash; 
       int  previousHash; 
       int timestamp;
} block;
















int main()
{
    
        printf("My Blockchain project!\n");
    return 0;
}




// }