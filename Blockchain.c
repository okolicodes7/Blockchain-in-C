
#include <stdio.h>
#include <stdlib.h>
#include <openssl/ssl.h>
#include <time.h>


// first step i took is to create a struct that defines what a Block comprises off onchain. 
typedef struct {
  // an "unsigned char" in C holds non negative values and in this case we'd treat it as an integer 
       size_t index;      
       unsigned char  *hash; 
       unsigned char  *previousHash; 
       int timestamp;
       int nonce;
} Block;
//open ssl hash function
unsigned char *create_sha256(const unsigned char str[], unsigned char *buffer);



Block generate_block(Block oldblock, int nonce){

    Block newblock;
    newblock.index = oldblock.index + 1;
    // printf("the index is %ld\n", newblock.index);
  newblock.timestamp = 
  newblock.nonce = nonce;
  newblock.hash ;
  newblock.previousHash;
}

unsigned char* Hash_block(const unsigned char str[SHA256_DIGEST_LENGTH], unsigned char* buffer[50]) {


}










int main()
{
 // Block block1 =  generate_block(Block oldblock, int nonce +1);
    printf("My Blockchain project!\n");
    return 0;
}




// }