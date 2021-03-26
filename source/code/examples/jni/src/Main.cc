#include <jni.h>
#include <stdio.h>
#include "Main.h"

JNIEXPORT jint JNICALL Java_Main_foo(JNIEnv *, jobject) {
   return 42;
}