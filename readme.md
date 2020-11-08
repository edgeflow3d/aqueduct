# Aqueduct Desktop App
The Aqueduct Desktop App is part of the **Aqueduct Project** it is a crossplatform 3D Asset Manager.
It is currently in alpha stage and has a very limited set of features.

![Aqueduct Desktop App Gui Screenshot on Linux (Gnome Desktop)](images/aqueduct_desktop_preview.png?raw=true "Aqueduct desktop app on linux (Gnome)")

For information on the Aqueduct Asset Manager visit the documentation at:  
[Read the Docs - Aqueduct Project](https://aqueduct-project.rtfd.io)

## How to Use
The Aqueduct Desktop app is best used in conjunction with the **Aqueduct Blender Addon**
that adds functionality to blender that makes it easier to work with 3D Asset blend-files
and improves blenders drag&drop context menu considerably.

Here's a video showing the two tools in action:  
[![Aqueduct Blender Addon Promo Video](http://img.youtube.com/vi/nV353pijQUo/0.jpg)](http://www.youtube.com/watch?v=nV353pijQUo)

## How to Install

### Binaries

#### Windows
We provide an experimental binary for windows, which can be downloaded on the [Releases Page](https://github.com/edgeflow3d/aqueduct/releases)

#### Linux
We are currently working on an AppImage release to support all Linux distributions.
If you want to try Aqueduct now you have to compile it from source.

### Building from source

#### Linux

##### Dependencies
* CMake (>= 3.1)
* Qt5

```sh
# installing dependencies on Ubuntu (Debian)
sudo apt-get install cmake
sudo apt-get install qtbase5-dev


# installing dependencies on CentOS or other RPM based distro
sudo dnf install cmake
sudo dnf install qt5-qtbase-devel
```

##### Compiling the source

```sh
# cloning the source and moving to its root folder
git clone https://github.com/edgeflow3d/aqueduct
cd aqueduct

# configuring build files
cmake -S ./source -B ./build

# building the binary (using all 12 threads on a 6 Core CPU)
cmake --build ./build -- -j12

# starting Aqueduct
./build/Aqueduct
```
