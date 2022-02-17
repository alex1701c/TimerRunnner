## TimerRunner

**Note**: This plugin is stil in development.

### TODO

- [x] Support specific time for timer (currently only durations like 5 minutes are supported)
- [x] Support 24/12 hour formats(am/pm)
- [ ] Make timers editable
- [ ] Deb/Rpm build
- [ ] Documentation
- [ ] Publish on KRunner store

If you have any other feature ideas feel free to let me know :-).

This is a KRunner plugin written in C++ and Qt which uses the DBus API.
It is based on a test class of the official [KRunner project](https://github.com/KDE/krunner/blob/master/autotests/testremoterunner.h).  
[More information and the advantages of DBus](http://blog.davidedmundson.co.uk/blog/cross-process-runners/).

## Installation

### Required Dependencies

<details>
<summary><b>Debian/Ubuntu</b></summary>

```bash
sudo apt install cmake extra-cmake-modules build-essential libkf5runner-dev
```

</details>


<details>
<summary><b>OpenSUSE</b></summary>

```bash
sudo zypper install cmake extra-cmake-modules libQt5Core5 krunner-devel
```

</details>


<details>
<summary><b>Fedora</b></summary>

```bash
sudo dnf install cmake extra-cmake-modules kf5-krunner-devel
```

</details>


<details>
<summary><b>Arch (Manjaro)</b></summary>

```bash
sudo pacman -S cmake extra-cmake-modules
```

</details> 

### Build instructions  

```bash
cd /path/to/TimerRunner
mkdir build
cd build
cmake ..
make
make install
kquitapp5 krunner 2> /dev/null; kstart5 --windowclass krunner krunner > /dev/null 2>&1 &
```

The `make install` command installs the config file. You have to start the executable manually:  
`./build/bin/timerrunner` or you can start the app using your IDE and for example a debugger.

If you want to install the app you have to configure your project differently (`cmake -DCMAKE_BUILD_TYPE=Release ..`).
With this the `make install` command will place the executable in the `~/.config/autostart-scripts/` folder and the build is optimized.

