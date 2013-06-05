force-brute
===========

### UBUNTU PREREQUISITES
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libboost1.40-dev libcpptest-dev

### To build:
make

### To build with unit tests
make TestSuite
./TestSuite --html > report.html


### Blender
blender -b water.blend -o // -F JPEG -x 1 -s 1 -e 80 -a


### cscope
cscope -R -b

### ctags
ctags -R
