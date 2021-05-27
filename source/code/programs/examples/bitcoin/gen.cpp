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
#include "code/utilities/formats/encryption/BASE58/base58_hasher.hpp"
#include "boost/algorithm/hex.hpp"
#include "boost/range/begin.hpp"
#include "boost/range/end.hpp"
#include "fmt/format.h"
#include "fmt/printf.h"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"
#include "code/utilities/types/unordered_set/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/linguistics/dictionary/scrabble_2019.hpp"
#include "code/utilities/types/strings/observers/hex/lib.hpp"



std::string urandom(){
    
    
    // /* Load private key (seckey) from random bytes */
    // FILE *frand = fopen("/dev/urandom", "r");
    
    // // /* Read 32 bytes from frand */
    // fread(wallet.secret_key, 32, 1, frand);
    
    // // /* Close the file */
    // fclose(frand);
    return "";
}


Bitcoin_Wallet create_wallet(std::string const& phrase){
    
    //Demo this was written off of:
    //https://royalforkblog.github.io/2014/08/11/graphical-address-generator/
    
    //Private key parts
    
    
    //hash a word
    auto sha256 = Sha256_Hasher::std_sha256(phrase);
    
    
    //extend hash with bitcoin information
    std::string stage1;
    stage1 += "80"; //mainnet
    stage1 += sha256;
    stage1 += "01"; //compression
    //std::cout << stage1 << std::endl;
    
    //add checksum
    auto checksum = Sha256_Hasher::std_sha256(unhex(Sha256_Hasher::std_sha256(unhex(stage1))));
    auto stage2 = stage1 + checksum.substr(0,8);
    //std::cout << stage2 << std::endl;
    
    
    //convert to base52 private key
    std::string base58_address = Base58_Hasher::base58(stage2);
    //std::cout << base58_address << std::endl;
    
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
    //printf("%.2x", pk_bytes[i]);
}
//std::cout << std::endl;

std::string pub;
for (int i = 0; i < 33; i++) {
    pub += fmt::sprintf( "%.2x", pk_bytes[i]);
}
//std::cout << pub << std::endl;
    
auto pub_hashed1 = Ripemd160_Hasher::ripemd160(unhex(Sha256_Hasher::std_sha256(unhex(pub))));
std::string pub_hashed2;
pub_hashed2 += "00";
pub_hashed2 += pub_hashed1;
//std::cout << pub_hashed2 << std::endl;
auto pub_checksum = Sha256_Hasher::std_sha256(unhex(Sha256_Hasher::std_sha256(unhex(pub_hashed2))));
//std::cout << pub_checksum << std::endl;

auto pub_hashed3 = pub_hashed2 + pub_checksum.substr(0,8);
//std::cout << pub_hashed3 << std::endl;

    std::string wallet_address = Base58_Hasher::base58(pub_hashed3);
    //std::cout << wallet_address << std::endl;
    
    //create wallet
    Bitcoin_Wallet x;
    x.private_key = base58_address;
    x.wallet_address = wallet_address;
    return x;
}

void check_wallet(Bitcoin_Wallet const& x, std::unordered_set<std::string> const& all_wallets){

    if (Exists_In_Set(all_wallets,x.wallet_address)){
        std::cout << x.private_key << std::endl;
        auto path = Full_Path_For_Desktop_File(x.wallet_address);
        Write_To_File(path,x.private_key);
        
    }
}


int main() {
    
    //wiki: https://en.bitcoin.it/wiki/Main_Page
    //glossary: https://academy.binance.com/en/glossary
    //https://bitcoin.stackexchange.com/
    //https://ethereum.stackexchange.com/
    //wallet data: http://addresses.loyce.club/
    //wallet data: https://gz.blockchair.com/bitcoin/addresses/
    //other information about private keys: https://allprivatekeys.com/
    //WIF key generator: https://allprivatekeys.com/generate-address
    //app: wallet generator: https://github.com/JeanLucPons/VanitySearch
    //app: wallet generator: https://btckeygen.com/##
    //app: https://learnmeabitcoin.com/technical/checksum
    //code wallet generator: https://www.netburner.com/learn/bitcoin-hash-functions-and-printer-drivers/
    //code: wallet generator: https://asecuritysite.com/encryption/bit_keys
    //code: wallet generator: https://github.com/Isaacdelly/Plutus/blob/master/plutus.py
    //code: wallet generator: https://github.com/matja/bitcoin-tool
    //code: wallet generator: https://github.com/nickfarrow/niceBit
    
    //lookup private keys: https://privatekeys.pw/
    
    //places to look:
    //https://ideone.com/ most recent
    
    //auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/Bitcoin_addresses_May_25_2021.txt");
    auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/some_addresses.txt");
    
    auto words = Scrabble_2019::Get();
    while (true){
        for (auto const& word: words){
            //try{
                auto x = create_wallet(word);
                std::cout << x.wallet_address << std::endl;
                check_wallet(x,all_wallets);
            //}
            //catch(...){}
        }
    }


}

