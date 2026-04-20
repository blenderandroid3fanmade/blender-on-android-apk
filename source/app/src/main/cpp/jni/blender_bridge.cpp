#include "blender_bridge.h"
#include <android/log.h>

#define LOG_TAG "BlenderNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jint JNICALL
Java_com_example_app_BlenderNative_initBlender(JNIEnv *env, jobject thiz, jobjectArray args) {
    LOGI("Initializing Blender Core...");

    // 1. Convert Java String array to C-style argc/argv
    int argc = env->GetArrayLength(args);
    const char **argv = new const char*[argc];

    for (int i = 0; i < argc; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(args, i);
        argv[i] = env->GetStringUTFChars(js, nullptr);
    }

    // 2. Call Blender's main entry point (from source/creator/creator.c)
    // In a real Android port, you might need to modify Blender's main() 
    // to not exit the process.
    int result = main(argc, argv);

    // 3. Cleanup
    for (int i = 0; i < argc; i++) {
        jstring js = (jstring)env->GetObjectArrayElement(args, i);
        env->ReleaseStringUTFChars(js, argv[i]);
    }
    delete[] argv;

    return result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_app_BlenderNative_getBlenderVersion(JNIEnv *env, jobject thiz) {
    // Return a dummy string for now to test the bridge
    return env->NewStringUTF("Blender 4.x Android Port");
}
