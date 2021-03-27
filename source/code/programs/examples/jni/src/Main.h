#include <jni.h>
/* Header for class Main */

#ifndef _Included_Main
#define _Included_Main
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Main
 * Method:    foo
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_Main_foo(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif