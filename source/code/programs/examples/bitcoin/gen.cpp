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
#include "code/utilities/crypto/bitcoin_wallet_generator.hpp"
#include "bitset2.hpp"



std::string urandom(){
    
    // Load private key (seckey) from random bytes
    FILE *frand = fopen("/dev/urandom", "r");
    
    // Read 32 bytes from frand
    unsigned char seckey[1231];
    fread(seckey, 32, 1, frand);
    
    // Close the file
    fclose(frand);
    
    std::string result((char*)seckey);
    return result;
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
    //code wallet generator: https://davanum.wordpress.com/2014/03/17/generating-a-bitcoin-private-key-and-address/
    //code: wallet generator: https://asecuritysite.com/encryption/bit_keys
    //code: wallet generator: https://github.com/Isaacdelly/Plutus/blob/master/plutus.py
    //code: wallet generator: https://github.com/matja/bitcoin-tool
    //code: wallet generator: https://github.com/nickfarrow/niceBit
    
    //lookup private keys: https://privatekeys.pw/
    
    //places to look:
    //https://ideone.com/ most recent
    
    //auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/Bitcoin_addresses_May_25_2021.txt");
    //auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/some_addresses.txt");
    
    //auto words = Scrabble_2019::Get();
    
    // while (true){
    //         auto str = urandom();
    //         auto x = Bitcoin_Wallet_Generator::Create(str);
    //         std::cout << x.wallet_address << std::endl;
    //         check_wallet(x,all_wallets);
    // }
    
    
    Bitset2::bitset2<256> bits;
    while (true){
        std::cout << bits.to_hex_string() << std::endl;
        ++bits;
    }


}

