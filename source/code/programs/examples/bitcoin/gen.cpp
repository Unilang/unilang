#include <stdio.h>
#include "include/secp256k1.h"
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <string.h>

static secp256k1_context *ctx = NULL;
typedef unsigned char byte;


/* See https://en.wikipedia.org/wiki/Positional_notation#Base_conversion */
char* base58(byte *s, int s_size, char *out, int out_size) {
        static const char *tmpl = "123456789"
                "ABCDEFGHJKLMNPQRSTUVWXYZ"
                "abcdefghijkmnopqrstuvwxyz";

        int c, i, n;

        out[n = out_size] = 0;
        while (n--) {
                for (c = i = 0; i < s_size; i++) {
                        c = c * 256 + s[i];
                        s[i] = c / 58;
                        c %= 58;
                }
                out[n] = tmpl[c];
        }

        return out;
}




int main() {
    ctx = secp256k1_context_create(
    SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    /* Declare the private variable as a 32 byte unsigned char */
    unsigned char seckey[32];
    
    /* Load private key (seckey) from random bytes */
    FILE *frand = fopen("/dev/urandom", "r");
    
    /* Read 32 bytes from frand */
    fread(seckey, 32, 1, frand);
    
    /* Close the file */
    fclose(frand);

    /* Loop through and print each byte of the private key, */
    printf("Private Key: ");
    for(int i=0; i<32; i++) {
            printf("%02X", seckey[i]);
    }
    printf("\n");

    if (!secp256k1_ec_seckey_verify(ctx, seckey)) {
    printf("Invalid secret key\n");
    return 1;
    }



    secp256k1_pubkey pubkey;
    secp256k1_ec_pubkey_create(ctx, &pubkey, seckey);

    size_t pk_len = 65;
    char pk_bytes[34];

    /* Serialize Public Key */
    secp256k1_ec_pubkey_serialize(
    ctx,
    pk_bytes,
    &pk_len,
    &pubkey,
    SECP256K1_EC_UNCOMPRESSED
    );



    char pubaddress[34];
    byte s[65];
    byte rmd[5 + RIPEMD160_DIGEST_LENGTH];


    int j;  
    for (j = 0; j < 65; j++) {
    s[j] = pk_bytes[j];
    }


    /* Set 0x00 byte for main net */
    rmd[0] = 0;
    RIPEMD160(SHA256(s, 65, 0), SHA256_DIGEST_LENGTH, rmd + 1);


    memcpy(rmd + 21, SHA256(SHA256(rmd, 21, 0), SHA256_DIGEST_LENGTH, 0), 4);


    char address[34];
    base58(rmd, 25, address, 34);


    /* Count the number of 1s at the beginning of the address */
    int n = 0;
    for (n = 0; address[n] == '1'; n++);

    /* Do we need to remove any 1s? */
    if (n > 1) {
    /* Move the memory so that the address begins at the final 1 */
    memmove(address, address + (n-1), 34-(n-1));

    /* Force the address to finish at the correct length */
    pubaddress[34-(n-1)] = '\0';
    }

    printf("Address: %s\n\n", address);
}

