#include <jni.h>
#include <stdio.h>
#include <stdlib.h>

jint nativeCallback(JNIEnv *env, jclass class, jint i, jint j) {
    return i * j;
}

int main(int argc, char* args[])
{

  JNIEnv *env;
  JavaVM *jvm;
  JNIEnv jni;
  JavaVM vmi;
  JavaVMInitArgs vm_args;
  JavaVMOption options[4];

  options[0].optionString = (char *) "-Djava.class.path=build/classes/main";
  options[1].optionString = (char *) "-Djava.compiler=NONE";
  vm_args.version = JNI_VERSION_1_8;
  vm_args.options = options;
  vm_args.nOptions = 2;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  JNI_CreateJavaVM(&jvm,(void **)&env,&vm_args);
  jni = *env;
  vmi = *jvm;

  jclass cls = jni->FindClass(env, "vblank/HelloJni");
  if (cls == 0) {
    printf("cannot found HelloJni\n");
    exit(1);
  }

  jmethodID mid = jni->GetStaticMethodID(env, cls, "fromC", "()V");
  if (mid == 0) {
    printf("Could not locate method testmthod with signature ()V");
    exit(1);
  }

  jclass inject = jni->FindClass(env, "vblank/Native");
  if (inject == 0) {
    printf("cannot found Native\n");
    exit(1);
  }

  JNINativeMethod native_method = {"calc", "(II)I", nativeCallback}; 
  
  jni->RegisterNatives(env, inject, &native_method, 1);

  jni->CallStaticVoidMethod(env, cls, mid, NULL);

  vmi->DestroyJavaVM(jvm);

  return 0;
}

