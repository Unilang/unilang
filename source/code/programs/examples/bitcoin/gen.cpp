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
#include <thread>



std::string urandom(){
    
    // Load private key (seckey) from random bytes
    FILE *frand = fopen("/dev/urandom", "r");
    
    // Read 32 bytes from frand
    unsigned char seckey[32];
    fread(seckey, 32, 1, frand);
    
    // Close the file
    fclose(frand);
    
    std::string result((char*)seckey);
    return result;
}

void check_wallet(Bitcoin_Wallet const& x, std::unordered_set<std::string> const& all_wallets){

    if (Exists_In_Set(all_wallets,x.wallet_address)){
        std::cout << "FOUND: " << x.private_key << std::endl;
        auto path = Full_Path_For_Desktop_File(x.wallet_address);
        Write_To_File(path,x.private_key);
        
    }
}


int main() {
    
    // Imagine a universe in which storing money is not guarded by metal but left out in the open.
    // An open field so large it's a statistical improbability that you can guess where I hid it.
    // A bitcoin address is a number.
    // It's a number between 0 - 115792089237316195423570985008687907853269984665640564039457584007913129639936
    // 78 digits.
    // The number is expressed through 256 bits.
    // That is to say, 2^256.
    // The number has a name.  115 quattuorvigintillion.
    // If you guess the right number you gain access to an infeasible amount of wealth.
    // So much wealth that if you tried to spent it the sheer supply would devalue the universe it exists in.
    // Even if you moved a small amount, it would scare everyone that ownership is alive.
    // The best course of action will be to burn the coins into an invalid address and ciphen only a little out.
    
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
    
    // std::string current_number = "1010011111000001110000011010111100101101010001110001000011010001110111010000100011110001001001010100101101110000100111101010011110110101100011101110011011110000100000000000101111101010000110101000110111101010100100110000101111001000111010000011001001010111";
    
    // std::thread searcher([&](){
        
    //     Bitset2::bitset2<256> bits(current_number);
    //     while (true){
    //         //std::cout << bits.to_hex_string() << std::endl;
    //         --bits;
    //     }
    // });
    
    // std::thread saver([&](){
    //     while (true){
    //         std::cout << urandom() << std::endl;
    //     }
    // });
    
    
    // searcher.join();
    // saver.join();
    
    //auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/Bitcoin_addresses_May_25_2021.txt");
    //auto all_wallets = Read_Each_Line_Of_File_Into_USet("/home/luxe/Desktop/some_addresses.txt");
    
    //auto words = Scrabble_2019::Get();
    
    while (true){
            auto str = urandom();
            auto x = Bitcoin_Wallet_Generator::Create(str);
            std::cout << x.wallet_address << std::endl;
            //check_wallet(x,all_wallets);
    }


}

