# CXX Idl compiler for CycloneDDS

This project provides an idl compiler to compile datatypes that can be used in the CXX API for [CycloneDDS](https://github.com/eclipse-cyclonedds/cyclonedds/) 

## Requirements for the CXX Idl compiler

In order to build the Idl compiler you need a Linux, Mac or Windows 10 machine with the following
installed on your host:
  
  * Git
  * [CMake](https://cmake.org/download/), version 3.7 or later.  (Version 3.6 should work but you
    will have to edit the ``cmake_minimum_required`` version.)
  * Java JDK, version 8 or later, e.g., [OpenJDK 11](http://jdk.java.net/11/).
  * [Apache Maven](http://maven.apache.org/download.cgi), version 3.5 or later.


## Building

Building the Idl compiler, requires only a few simple steps. There are some small differences
between Linux and macOS on the one hand, and Windows on the other. For Linux or macOS:

    $ git clone https://github.com/ADLINK-IST/idlpp-cxx.git
    $ cd idlpp-cxx
    $ mkdir build
    $ cd build
    $ cmake <cmake-config_options> ..
    $ cmake --build .

and for Windows:

    $ git clone https://github.com/ADLINK-IST/idlpp-cxx.git
    $ cd idlpp-cxx
    $ mkdir build
    $ cd build
    $ cmake -G "<generator-name>" <cmake-config_options> ..
    $ cmake --build .

where you replace ``<generator-name>`` by one of the ways
CMake [generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) offer for
generating build files.  For example, "Visual Studio 15 2017 Win64" would target a 64-bit build
using Visual Studio 2017.

The ``<cmake-config_options>`` can be ignored or replaced. A few of the most common options are:
-DCMAKE_INSTALL_PREFIX=``<install-location>``
-DCMAKE_BUILD_TYPE=Debug

    $ cmake -DCMAKE_BUILD_TYPE=Debug ..


## Packaging

If you want to package the product, the config step and build step are slightly different compared
to how it is normally build.

The -DCMAKE_INSTALL_PREFIX=``<install-location>`` option should be added to the configuration,
where the ``<install-location>`` is replaced by the directory under which you would like to
install the Idl compiler.

During the build step, you have to specify that you want to build the install target as well.


This would make the build look like

    $ mkdir build
    $ cd build
    $ cmake -DCMAKE_INSTALL_PREFIX=<install-location>  ..
    $ cmake --build . --target install

Don't forget the generator when building on Windows.

After the build, required files are copied to:

  * ``<install-location>/lib``
  * ``<install-location>/share``

The ``<install-location>`` directory is will be used to create the package(s).

    $ cpack

Depending on the target, you now have packages.

