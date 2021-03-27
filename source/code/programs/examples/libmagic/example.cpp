#include <stdio.h>
#include <string>
#include "magic.h"

int main(void)
{
    //std::string actual_file = "/bin/cp";
    std::string actual_file = "/home/thickey/Desktop/test.o";
    const char *magic_full;
    magic_t magic_cookie;
    
    // you can specify different things on open
    
    // MAGIC_NONE
    // MAGIC_DEBUG
    // MAGIC_SYMLINK
    // MAGIC_COMPRESS
    // MAGIC_DEVICES
    // MAGIC_MIME_TYPE
    // MAGIC_MIME_ENCODING
    // MAGIC_CONTINUE
    // MAGIC_CHECK
    // MAGIC_PRESERVE_ATIME
    // MAGIC_RAW
    // MAGIC_ERROR
    // MAGIC_NO_CHECK_APPTYPE
    // MAGIC_NO_CHECK_ASCII
    // MAGIC_NO_CHECK_COMPRESS
    // MAGIC_NO_CHECK_ELF
    // MAGIC_NO_CHECK_FORTRAN
    // MAGIC_NO_CHECK_SOFT
    // MAGIC_NO_CHECK_TAR
    // MAGIC_NO_CHECK_TOKENS
    // MAGIC_NO_CHECK_TROFF
    
    
        auto flags = MAGIC_NONE;
        flags |= MAGIC_MIME;
        flags |= MAGIC_MIME_ENCODING;
        flags |= MAGIC_CONTINUE;
        flags |= MAGIC_COMPRESS;
        flags |= MAGIC_RAW;

    magic_cookie = magic_open(flags);
    
    if (magic_cookie == NULL) {
        printf("unable to initialize magic library\n");
        return 1;
    }
    
    printf("Loading default magic database\n");
    
    if (magic_load(magic_cookie, NULL) != 0) {
        printf("cannot load magic database - %s\n", magic_error(magic_cookie));
        magic_close(magic_cookie);
        return 1;
    }
    
    magic_full = magic_file(magic_cookie, actual_file.c_str());
    printf("%s\n", magic_full);
    magic_close(magic_cookie);
    return 0;
}