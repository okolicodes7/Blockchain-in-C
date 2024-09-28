
#include <stdio.h>
#include <stdlib.h>
#include <openssl/ssl.h>
#include <time.h>
#define constant MAX_NUMBER_OF_BLOCKS = 20;

// first step i took is to create a struct that defines what a Block comprises off onchain. 
// the componenets of a Block 
typedef struct {
  // an "unsigned char" in C holds non negative values and in this case we'd treat it as an integer 
       size_t index;      
       unsigned char  *hash; 
       unsigned char  *previousHash; 
       int timestamp;
       int nonce;
} Block;


//open ssl hash function
unsigned char *create_sha256(const unsigned char str[], unsigned char *buffer){
    SHA256(str, strlen((const char*)str), buffer);
    return buffer;
}


// third step was to generate a block 
Block generate_block(Block oldblock, int nonce){
// I iniitialized the newblock of Block type
    Block newblock;

    //Then I proceed to setting the elements of the newblock struct. Which is basically the componenets of a Block Struct
    newblock.index = oldblock.index + 1;
    // printf("the index is %ld\n", newblock.index);
  newblock.timestamp = 
  newblock.nonce = nonce;
  newblock.hash ;
  newblock.previousHash;
}


// second step as seen below is to be able to hash a block. 
unsigned char* Hash_block(Block newblock) {
    //what is going on here?  So.. basically I allocate a chunk of memory given as 1 * 1024 to the block_details variable which contains variables from the struct except from the hash variable.
    unsigned char* block_details = malloc(sizeof(char) * 1024);
// then i use sprintf() to store the block's information as a formatted string into the block_details.
      sprintf("%zu, %s, %d, %d,\n", (char*)block_details, newblock.index, newblock.previousHash, newblock.timestamp, newblock.nonce);
      // allocate another memory space to the buffer ( 1 * 256 bits(32 bytes))
      unsigned char* buffer = malloc(sizeof(char) * SHA256_DIGEST_LENGTH);
      // proceed to call the  create_sha256 function to create the blocks hash. Encountered a lot of issues down here as I did not cast the input parameters properly and my openssl create_sha256 function was not defined in the code so i had to define it properly above in line 20 (I initially only declared the function signature as is done with solidity)
     block_details = create_sha256((const unsigned char*) block_details, (unsigned char*) buffer);
  return buffer;
}










int main()
{
 // Block block1 =  generate_block(Block oldblock, int nonce +1);
    printf("My Blockchain project!\n");
    return 0;
}




// }