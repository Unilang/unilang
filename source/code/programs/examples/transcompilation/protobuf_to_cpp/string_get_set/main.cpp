
#include <iostream>
#include "code/programs/examples/transcompilation/protobuf_to_cpp/string_get_set/example.pb.h"
int main(){

    // I would have just a set "hello world" as the default
    // in the proto message, but proto3 doesn't support default values like that.
    // so I'll just test it here with a get and set.
    // The other problem I noticed, is that when I did try to give a default string value,
    // the compiler error, was not very helpful at all.  I think it just said that the protobuf compiler or something
    // just crashed.  It didn't give me line numbers into the proto message at all.
    // That might be something we try to improve later if needed
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    demo::Message message;
    message.set_foo("hello world");
    std::cout << message.foo() << std::endl;

        return 0;
}
