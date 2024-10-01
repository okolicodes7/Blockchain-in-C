
#include <stdio.h>
#include <stdlib.h>
#include <openssl/ssl.h>
#include <time.h>
#include <stdbool.h>
#define MAX_NUMBER_OF_BLOCKCHAIN 20


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

// I iniitialized an array called "blockchain" of Block type and passed in the [MAX_NUMBER_OF_BLOCKCHAIN]
// Block blockchain[MAX_NUMBER_OF_BLOCKCHAIN];



//open ssl hash function
unsigned char *create_sha256(const unsigned char str[], unsigned char *buffer){
    SHA256(str, strlen((const char*)str), buffer);
    return buffer;
}



// second step as seen below is to be able to hash a block. 
// for some weird reason in C, the code refused to compile as I wrote this function after the generate_block function so i had to move it up
unsigned char* Hash_block(Block newblock) {
    //what is going on here?  So.. basically I allocate a chunk of memory given as 1 * 1024 to the block_details variable which contains variables from the struct except from the hash variable.
    unsigned char* block_details = malloc(sizeof(char) * 1024);

// then i use sprintf() to store the block's information as a formatted string into the block_details.
      sprintf((char*)block_details, "%zu, %s, %d, %d,\n", newblock.index, (char*)newblock.previousHash, newblock.timestamp, newblock.nonce);
      // allocate another memory space to the buffer ( 1 * 256 bits(32 bytes))
      unsigned char* buffer = malloc(sizeof(char) * SHA256_DIGEST_LENGTH);
      // proceed to call the  create_sha256 function to create the blocks hash. Encountered a lot of issues down here as I did not cast the input parameters properly and my openssl create_sha256 function was not defined in the code so i had to define it properly above in line 20 (I initially only declared the function signature as is done with solidity)
     block_details = create_sha256((const unsigned char*) block_details, (unsigned char*) buffer);
  return buffer;
}


// third step was to generate a block 
Block generate_block(Block oldblock, int nonce){
// I iniitialized the newblock of Block type
    Block newblock;

    //Then I proceed to setting the elements of the newblock struct. Which is basically the componenets of a Block Struct
     newblock.index = oldblock.index + 1;
     newblock.timestamp = time(NULL);
     newblock.nonce = nonce;
     newblock.hash = Hash_block(newblock); 
     newblock.previousHash = oldblock.hash;
     return newblock;
}

// fourth step 
 bool validate_block(Block newblock, Block oldblock){
    if(newblock.index != oldblock.index + 1){
        printf("INDEX NOT VALID\n");
        return false;
    }
    if(oldblock.hash != newblock.previousHash){
        printf("PREVIOUS HASH NOT VALID\n");
        return false;
    }

    char hash1[SHA256_DIGEST_LENGTH];
    char hash2[SHA256_DIGEST_LENGTH];

    strcpy(hash1, (char*)Hash_block(oldblock));
    strcpy(hash2, (char*)newblock.hash);

    if(memcmp(hash1, hash2, SHA_DIGEST_LENGTH) == 0){
        printf("NEW HASH NOT VALID\n");
        return false;
    }
return true;
 }

/*
// fifth step
 Block replacing_chain(Block newblockchain[MAX_NUMBER_OF_BLOCKCHAIN], Block oldblockchain[MAX_NUMBER_OF_BLOCKCHAIN]){
  int new_length;
   int old_length;
    
  if(newlength > oldlength){
     printf("VALID CHAIN\n");
     return newblockchain;
;
  }
  else {
     printf("VALID CHAIN\n");
    return oldblockchain;
   ;
  }
     
 }
 */
// step six (proceeds to create a print function that prints all the elements in the Block struct)
void printblock(Block newblock) {
    printf("INDEX: %zu\n", newblock.index);
    printf("TIMESTAMP: %d\n", newblock.timestamp);
    printf("NONCE: %d\n", newblock.nonce);
    if(newblock.previousHash == NULL){
    printf("PREV HASH: NULL\n");
} else {
    printf("PREV HASH: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        if(newblock.previousHash != NULL){
            printf("%02X", newblock.previousHash[i]);
        }
    }
    printf("\n");
}
 if(newblock.hash == NULL){
    printf("HASH: NULL\n");
} else { 
      printf("HASH: ");
   
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        if(newblock.hash != NULL){
            printf("%02X", newblock.hash[i]);
        }
}
  printf("\n");

}
}
   










int main()
{
   // Block blockchain[MAX_NUMBER_OF_BLOCKCHAIN];

   // initializing the different parameters passed in the block struct to form the GENESIS BLOCK
   Block genesisblock;
   genesisblock.index = 0;
   genesisblock.timestamp = time(NULL);
   genesisblock.nonce = 0;
   genesisblock.previousHash = NULL;
   genesisblock.hash = Hash_block(genesisblock);
   // call tp printblock is made passing the genesis block which was just initialized above.
   printblock(genesisblock);

  puts("\n\n");

// proceeds to generate the next block
 printblock(genesisblock);

   Block newblock = generate_block(genesisblock, genesisblock.nonce + 1);
   printblock(newblock);
   printf("IS VALID BLOCK: %d\n", validate_block(newblock, genesisblock));

   // printf("My Blockchain project!\n");
    return 0;

}




// }