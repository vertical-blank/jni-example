#include <jni.h>

/*
 * Class:     vblank_Native
 * Method:    calc
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_vblank_Native_calc
  (JNIEnv *env, jclass class, jint i, jint j) {
    return i + j;
  }
