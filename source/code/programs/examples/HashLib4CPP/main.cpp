#include "HashLib4CPP.h"

int main()
{
    IHash hash = HashLib4CPP::Crypto::CreateMD5();
        
    IHash clone = hash->Clone();

    IHMAC hmac = HashLib4CPP::HMAC::CreateHMAC(hash);
    hmac->SetKey(Converters::ConvertStringToBytes("password"));

    IHashResult Result1 = hash->ComputeString("Hash");
    IHashResult Result2 = hmac->ComputeString("Hash");
    
    bool check = Result1->CompareTo(Result2);
    
    return 0;
}