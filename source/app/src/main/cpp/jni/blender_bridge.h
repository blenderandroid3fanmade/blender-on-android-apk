#ifndef BLENDER_BRIDGE_H
#define BLENDER_BRIDGE_H

#include <jni.h>
#include <string>
#include <vector>

// Forward declaration of Blender entry points
// Note: These must match the signatures in source/creator/creator.c
extern "C" {
    int main(int argc, const char **argv);
}

class BlenderBridge {
public:
    static jobject blender_call_init(JNIEnv *env, jobject p_instance, jobjectArray p_args);
    static jstring get_blender_version(JNIEnv *env);
};

#endif // BLENDER_BRIDGE_H

