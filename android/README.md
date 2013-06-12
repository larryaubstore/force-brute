force-brute
===========

### create android project
android create project --name androidforcebrute --target 18 --path . --activity MainActivity --package com.forcebrute


### start avd manager
android avd

### install apk
adb install package.apk

### build native librairies
ndk-build

### log
adb logcat
