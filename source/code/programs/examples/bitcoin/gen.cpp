#include <stdio.h>
#include <algorithm>
#include <cstdint>
#include "include/secp256k1.h"
#include "libbase58.h"
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <openssl/evp.h>
#include "code/programs/examples/bitcoin/bitcoin_wallet.hpp"
#include "code/utilities/formats/encryption/SHA256/sha256_hasher.hpp"
#include "code/utilities/formats/encryption/RIPEMD160/ripemd160_hasher.hpp"
#include "boost/algorithm/hex.hpp"
#include "boost/range/begin.hpp"
#include "boost/range/end.hpp"
#include "fmt/format.h"
#include "fmt/printf.h"




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
        ss << std::hex << std::uppercase << (unsigned int)s[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::uppercase << (unsigned int)str[i];
    std::string mystr = ss.str();
    return mystr;
}

std::string to_caps_hex_p2(std::string const& str){
    std::stringstream ss;
    for(int i=0; i<str.size(); ++i)
        ss << std::hex << std::setfill('0') << std::setw(2)  << static_cast<unsigned int>(static_cast<unsigned char>(str[i]));
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

void fill_private_key(Bitcoin_Wallet & wallet, std::string phrase){
}


std::string unhex(std::string const& str){
    std::string new_str;
    boost::algorithm::unhex ( str, std::back_inserter (new_str));
    return new_str;
}

std::string base58(std::string str){
    char p2[256];
    size_t new_size = 256;
    std::string stage2_unhex = unhex(str);
    if (b58enc(p2, &new_size, stage2_unhex.c_str(), stage2_unhex.size()) == 0){
        printf("b58enc\n");
        exit(1);
    }
    std::string base58_address(p2);
    return base58_address;
}


Bitcoin_Wallet create_wallet(std::string const& phrase){
    
    //Demo this was written off of:
    //https://royalforkblog.github.io/2014/08/11/graphical-address-generator/
    
    //Private key parts
    
    
    //hash a word
    auto sha256 = Sha256_Hasher::std_sha256(phrase);
    std::cout << sha256 << std::endl;
    
    
    //extend hash with bitcoin information
    std::string stage1;
    stage1 += "80"; //mainnet
    stage1 += sha256;
    stage1 += "01"; //compression
    std::cout << stage1 << std::endl;
    
    //add checksum
    auto checksum = Sha256_Hasher::std_sha256(unhex(Sha256_Hasher::std_sha256(unhex(stage1))));
    auto stage2 = stage1 + checksum.substr(0,8);
    std::cout << stage2 << std::endl;
    
    
    //convert to base52 private key
    std::string base58_address = base58(stage2);
    std::cout << base58_address << std::endl;
    
    //Public key parts
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    
    
    

    std::string sha256_unhex = unhex(sha256);
    unsigned char m_Test[32];
    strcpy( (char*) m_Test, sha256_unhex.c_str() );
    
    
    
    //std::cout << sha256_unhex << std::endl;
    if (!secp256k1_ec_seckey_verify(ctx, m_Test)) {
        printf("Invalid secret key\n");
        exit(1);
    }



    secp256k1_pubkey pubkey;
    if (secp256k1_ec_pubkey_create(ctx, &pubkey, m_Test) == 0){
        printf("secp256k1_ec_pubkey_create\n");
        exit(1);
    }

    unsigned char pk_bytes[33];
    size_t pk_len = 33;

    /* Serialize Public Key */
    secp256k1_ec_pubkey_serialize(
    ctx,
    pk_bytes,
    &pk_len,
    &pubkey,
     //SECP256K1_EC_UNCOMPRESSED
    SECP256K1_EC_COMPRESSED
    );
    
  secp256k1_pubkey pubkey2;
  if (secp256k1_ec_pubkey_parse(ctx, &pubkey2, pk_bytes, 33) == 0) {
    printf("error re-parsing public key!\n");
    exit(1);
  }
  
for (int i = 0; i < 33; i++) {
    printf("%.2x", pk_bytes[i]);
}
std::cout << std::endl;

std::string pub;
for (int i = 0; i < 33; i++) {
    pub += fmt::sprintf( "%.2x", pk_bytes[i]);
}
std::cout << pub << std::endl;
    
auto pub_hashed1 = Ripemd160_Hasher::ripemd160(unhex(Sha256_Hasher::std_sha256(unhex(pub))));
std::string pub_hashed2;
pub_hashed2 += "00";
pub_hashed2 += pub_hashed1;
std::cout << pub_hashed2 << std::endl;
auto pub_checksum = Sha256_Hasher::std_sha256(unhex(Sha256_Hasher::std_sha256(unhex(pub_hashed2))));
std::cout << pub_checksum << std::endl;

auto pub_hashed3 = pub_hashed2 + pub_checksum.substr(0,8);
std::cout << pub_hashed3 << std::endl;

    std::string wallet_address = base58(pub_hashed3);
    std::cout << wallet_address << std::endl;
    
    //create wallet
    Bitcoin_Wallet x;
    x.private_key = base58_address;
    x.wallet_address = wallet_address;
    return x;
}


int main() {
    
    auto x = create_wallet("bitcoin");
    std::cout << x.wallet_address << std::endl;


}

