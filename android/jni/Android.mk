# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#include $(call all-subdir-makefiles)\


LOCAL_MODULE    := force-brute
LOCAL_SRC_FILES := ballfield.cpp
# for native audio
LOCAL_LDLIBS    += -lOpenSLES
# for logging
LOCAL_LDLIBS    += -llog
# for native asset manager
LOCAL_LDLIBS    += -landroid -lsdl-1.2 -lsdl_image

#/home/larry/devel/force-brute/android/jni/libs/armeabi-v7a
LOCAL_LDFLAGS := -L/home/larry/devel/force-brute/android/jni/libs/armeabi-v7a

#LOCAL_C_INCLUDES += $(LOCAL_PATH)/sdl-1.2/include /home/larry/devel/force-brute
LOCAL_C_INCLUDES += /home/larry/devel/force-brute/android/jni/sdl-1.2/include /home/larry/devel/force-brute/android/jni/sdl_image/include /home/larry/devel/force-brute

#include $(LOCAL_PATH)/plasma/Android.mk
#include $(LOCAL_PATH)/sdl-1.2/Android.mk

include $(BUILD_SHARED_LIBRARY)
