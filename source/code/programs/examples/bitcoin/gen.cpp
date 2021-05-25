#include <stdio.h>
#include "include/secp256k1.h"
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include "code/programs/examples/bitcoin/bitcoin_wallet.hpp"




/* See https://en.wikipedia.org/wiki/Positional_notation#Base_conversion */
char* base58(unsigned char *s, int s_size, char *out, int out_size) {
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

std::string to_caps_hex(unsigned char *s){
    std::stringstream ss;
    for(int i=0; i<32; ++i)
        ss << std::hex << std::uppercase << (int)s[i];
    std::string mystr = ss.str();
    return mystr;
}

void fill_private_key(Bitcoin_Wallet & wallet){
    
    
    /* Load private key (seckey) from random bytes */
    FILE *frand = fopen("/dev/urandom", "r");
    
    /* Read 32 bytes from frand */
    fread(wallet.secret_key, 32, 1, frand);
    
    /* Close the file */
    fclose(frand);
    
    wallet.secret_key_hex = to_caps_hex(wallet.secret_key);
}



int main() {
    
    Bitcoin_Wallet wallet;
    
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    
    
    
    fill_private_key(wallet);
    std::cout << "PRIVATE: " << wallet.secret_key_hex << std::endl;

    if (!secp256k1_ec_seckey_verify(ctx, wallet.secret_key)) {
        printf("Invalid secret key\n");
        return 1;
    }



    secp256k1_pubkey pubkey;
    secp256k1_ec_pubkey_create(ctx, &pubkey, wallet.secret_key);

    size_t pk_len = 65;
    unsigned char pk_bytes[34];

    /* Serialize Public Key */
    secp256k1_ec_pubkey_serialize(
    ctx,
    pk_bytes,
    &pk_len,
    &pubkey,
    SECP256K1_EC_UNCOMPRESSED
    );



    char pubaddress[34];
    unsigned char s[65];
    unsigned char rmd[5 + RIPEMD160_DIGEST_LENGTH];


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
    
    std::string public_address = pubaddress;
    std::string final_address = address;
    //std::cout << "Public: " << public_address << std::endl;
    std::cout << "WALLET: " << final_address << std::endl;
}

