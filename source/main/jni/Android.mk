LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libdobby
LOCAL_SRC_FILES := libraries/$(TARGET_ARCH_ABI)/libdobby.a
#for aide users do this LOCAL_SRC_FILES := libraries/$(TARGET_ARCH_ABI)/libdobby.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
APP_PLATFORM := android-21

# Here is the name of your lib.
# When you change the lib name, change also on System.loadLibrary("") under OnCreate method on StaticActivity.java
# Both must have same name
LOCAL_MODULE    := arm64-v8a

# -std=c++17 is required to support AIDE app with NDK
LOCAL_CFLAGS := -w -s -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions
LOCAL_CPPFLAGS := -w -s -Wno-error=format-security -fvisibility=hidden -Werror -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fpermissive -Wall -fexceptions
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all,-llog
LOCAL_LDLIBS                            := -llog -landroid -lEGL -lGLESv2 -lGLESv1_CM -lz -fno-asm
LOCAL_ARM_MODE := arm

LOCAL_STATIC_LIBRARIES := libdobby

LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ImGui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ImGui/backends

# Here you add the cpp file to compile
# BY IMDARIUSYW!!
LOCAL_SRC_FILES := Plthook.cpp \
	Substrate/hde64.c \
	Substrate/SubstrateDebug.cpp \
	Substrate/SubstrateHook.cpp \
	Substrate/SubstratePosixMemory.cpp \
	Substrate/SymbolFinder.cpp \
	KittyMemory/KittyMemory.cpp \
	KittyMemory/MemoryPatch.cpp \
    KittyMemory/MemoryBackup.cpp \
    KittyMemory/KittyUtils.cpp \
	ImGui/imgui.cpp \
	ImGui/imgui_draw.cpp \
	ImGui/imgui_demo.cpp \
	ImGui/imgui_widgets.cpp \
	ImGui/imgui_tables.cpp \
	ImGui/backends/imgui_impl_opengl3.cpp \
	ImGui/backends/imgui_impl_android.cpp \
    Plthook/plthook_elf.c
    
include $(BUILD_SHARED_LIBRARY)
LOCAL_SRC_FILES += MenuCustom.cpp \
                   другие_файлы.cpp
