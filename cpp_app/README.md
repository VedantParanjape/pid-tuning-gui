## Project Structure
```
.
├── cpp_app
│   ├── CMakeLists.txt                      // CMakeLists to build Makefiles
│   ├── data_handler.cpp                    // Socket Handling
│   ├── data_handler.h                      
│   ├── graph_renderer.cpp                  // Graph Handling
│   ├── graph_renderer.h
│   ├── main.cpp                            // Main file
│   ├── pid_message_config.h                // Message Structure
│   ├── pid_plotter_res.qrc                 // Qt Resource
│   ├── pid_tuning_gui_qt_en_IN.ts          // Translation
│   ├── pid_tuning_gui_qt.pro               // Project Configuration for qmake
│   ├── qcustomplot.cpp                     // QCustomplot
│   ├── qcustomplot.h
│   ├── README.md   
│   ├── sra.png                             // SRA Logo
│   ├── ui.cpp                              // UI Source File
│   └── ui.h
.
.
.
.

```

## Build From Source

```sh
mkdir build
cd build
cmake ../cpp_app/   -DCMAKE_PREFIX_PATH=$HOME/Qt/5.12.11/gcc_64/lib/cmake/Qt5 \
                    -DQt5_DIR=$HOME/Qt/5.12.11/gcc_64/lib/cmake/Qt5/Qt5Config.cmake
make --jobs=8 
```

### Dynamic Linking

```
 ~/Desktop/pid-tuning-gui/build  satacker/cpp_port ⇡3 !4 ?3  ldd ../cpp_app/bin/PID-Tuning-GUI                                                                  
	linux-vdso.so.1 (0x00007fff18535000)
	libQt5PrintSupport.so.5 => /home/satacker/Qt/5.12.11/gcc_64/lib/libQt5PrintSupport.so.5 (0x00007f138b4d9000)
	libboost_thread.so.1.71.0 => /lib/x86_64-linux-gnu/libboost_thread.so.1.71.0 (0x00007f138b493000)
	libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f138b470000)
	libQt5Widgets.so.5 => /home/satacker/Qt/5.12.11/gcc_64/lib/libQt5Widgets.so.5 (0x00007f138ac20000)
	libQt5Gui.so.5 => /home/satacker/Qt/5.12.11/gcc_64/lib/libQt5Gui.so.5 (0x00007f138a3d2000)
	libQt5Core.so.5 => /home/satacker/Qt/5.12.11/gcc_64/lib/libQt5Core.so.5 (0x00007f1389c35000)
	libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f1389a52000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f1389903000)
	libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f13898e8000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f13896f6000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f138b8e0000)
	libGL.so.1 => /lib/x86_64-linux-gnu/libGL.so.1 (0x00007f138966e000)
	libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f1389650000)
	libicui18n.so.56 => /home/satacker/Qt/5.12.11/gcc_64/lib/libicui18n.so.56 (0x00007f13891b7000)
	libicuuc.so.56 => /home/satacker/Qt/5.12.11/gcc_64/lib/libicuuc.so.56 (0x00007f1388dff000)
	libicudata.so.56 => /home/satacker/Qt/5.12.11/gcc_64/lib/libicudata.so.56 (0x00007f138741c000)
	libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f1387416000)
	libgthread-2.0.so.0 => /lib/x86_64-linux-gnu/libgthread-2.0.so.0 (0x00007f1387411000)
	libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f13872e8000)
	libGLdispatch.so.0 => /lib/x86_64-linux-gnu/libGLdispatch.so.0 (0x00007f138722e000)
	libGLX.so.0 => /lib/x86_64-linux-gnu/libGLX.so.0 (0x00007f13871fa000)
	libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f1387187000)
	libX11.so.6 => /lib/x86_64-linux-gnu/libX11.so.6 (0x00007f138704a000)
	libxcb.so.1 => /lib/x86_64-linux-gnu/libxcb.so.1 (0x00007f1387020000)
	libXau.so.6 => /lib/x86_64-linux-gnu/libXau.so.6 (0x00007f1387018000)
	libXdmcp.so.6 => /lib/x86_64-linux-gnu/libXdmcp.so.6 (0x00007f1387010000)
	libbsd.so.0 => /lib/x86_64-linux-gnu/libbsd.so.0 (0x00007f1386ff6000)
```