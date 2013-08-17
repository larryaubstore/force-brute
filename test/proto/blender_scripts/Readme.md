sudo cmake -D CMAKE_INSTALL_PREFIX=../build -D CMAKE_BUILD_TYPE=Debug -D BUILD_NEW_PYTHON_SUPPORT=ON -D BUILD_PYTHON_SUPPORT=ON -D BUILD_EXAMPLES=OFF -D PYTHON_EXECUTABLE=/home/larry/.pythonbrew/venvs/Python-3.3.0/ubuntu/bin/python -D PYTHON_INCLUDE_DIR=/home/larry/.pythonbrew/venvs/Python-3.3.0/ubuntu/include/python3.3m/ -D WITH_CYCLES=OFF -D PYTHON_LIBRARY=/home/larry/.pythonbrew/pythons/Python-3.3.0/lib/libpython3.so ../blender/

export PYTHON_EXECUTABLE=/home/larry/.pythonbrew/venvs/Python-3.3.0/ubuntu/bin/python 
export PYTHON_INCLUDE_DIR=/home/larry/.pythonbrew/venvs/Python-3.3.0/ubuntu/include/python3.3m/ 
export PYTHON_LIBRARY=/home/larry/.pythonbrew/pythons/Python-3.3.0/lib/libpython3.3m.so
export LD_LIBRARY_PATH=/home/larry/.pythonbrew/pythons/Python-3.3.0/lib

pythonbrew venv use ubuntu

#export PYTHON_LIBRARY=/home/larry/.pythonbrew/pythons/Python-3.3.0/lib/libpython3.so
./blender/blenlib/intern/math_geom.c perspective_m4
math_geom.c:2864

re->viewmat
{{0.685880482, -0.317370087, 0.654861867, 0}, {0.727633715, 0.312468529, -0.61066556, 0}, {-0.0108167641, 0.895343125, 0.445245326, 0}, {-0.363019913, 0.922901273, -55.501564, 1}}


#0  RE_SetView (re=0xd75e3e0, mat=0xa6285c58) at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:655
#1  0x0978b77a in RE_Database_FromScene (re=0xd75e3e0, bmain=0xcd09ca8, scene=0xcd4b7e8, lay=19, use_camera_view=1) at /home/larry/devel/blender/source/blender/render/intern/source/convertblender.c:5268
#2  0x097a5d09 in do_render_3d (re=0xd75e3e0) at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:1138
#3  0x097a69e7 in do_render_fields_blur_3d (re=0xd75e3e0) at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:1438
#4  0x097a7dd3 in do_render_composite_fields_blur_3d (re=0xd75e3e0) at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:1911
#5  0x097a86ef in do_render_all_options (re=0xd75e3e0) at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:2120
#6  0x097a937e in RE_BlenderFrame (re=0xd75e3e0, bmain=0xcd09ca8, scene=0xcd4b7e8, srl=0x0, camera_override=0x0, lay=19, frame=45, write_still=0)
    at /home/larry/devel/blender/source/blender/render/intern/source/pipeline.c:2441
#7  0x096e72fb in render_startjob (rjv=0xc0d8ca0, stop=0xd75b8d8, do_update=0xd75b8d6, progress=0xd75b8dc) at /home/larry/devel/blender/source/blender/editors/render/render_internal.c:408
#8  0x092fad0b in do_job_thread (job_v=0xd75b890) at /home/larry/devel/blender/source/blender/windowmanager/intern/wm_jobs.c:273
#9  0x09e22ecc in tslot_thread_start (tslot_p=0xca1a3e0) at /home/larry/devel/blender/source/blender/blenlib/intern/threads.c:222
#10 0xb7885d4c in start_thread () from /lib/i386-linux-gnu/libpthread.so.0
#11 0xb7367dde in clone () from /lib/i386-linux-gnu/libc.so.6

re->winmat
{{5.14315796, 0, 0, 0}, {0, 9.14339256, 0, 0}, {0, 0, -1.002002, -1}, {0, 0, -0.2002002, 0}}
