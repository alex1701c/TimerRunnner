## TimerRunner

This plugin is stil in development.  
TODO:
- Support specific time for timer (currently only durations like 5 minutes are supported) - Done
- Support 24/12 hour formats(am/pm) -Done
- Make timers editable
- Deb/Rpm build
- Documentation
- Publish on KRunner store

If you have any other feature ideas feel free to let me know :-).

This is a KRunner plugin written in C++ and Qt which uses the DBus API.
It is based on a test class of the official KRunner project: https://github.com/KDE/krunner/blob/master/autotests/testremoterunner.h  
For more information and the advantages of DBus visit: http://blog.davidedmundson.co.uk/blog/cross-process-runners/

### Required Dependencies

Debian/Ubuntu:  
`sudo apt install cmake extra-cmake-modules build-essential libkf5runner-dev`  

openSUSE:  
`sudo zypper install cmake extra-cmake-modules libQt5Core5 krunner-devel`  

Fedora:  
`sudo dnf install cmake extra-cmake-modules kf5-krunner-devel`  

Arch (Manjaro):  
`sudo pacman -S cmake extra-cmake-modules`  

### Build instructions  

```
cd /path/to/TimerRunner
mkdir build
cd build
cmake ..
make
make install
kquitapp5 krunner 2> /dev/null; kstart5 --windowclass krunner krunner > /dev/null 2>&1 &
```
The `make install` command installs the config file. You have to start the executable manually:  
`./build/bin/timerrunner`  
Or you can start the app using your IDE and for example a debugger.

If you want to install the app you have to configure your project differently:
`cmake -DCMAKE_BUILD_TYPE=Release ..`  
With this the `make install` command will place the executable in the ~/.config/autostart-scripts/ folder and the build is optimized.

