
# Performance

## Build

```bash
mkdir build
cd build
cmake ..

# If needed, you can specify a compiler as follows
# cmake .. -DCMAKE_CXX_COMPILER=g++-11

make function_timer
make peach_snail
```

## Profile on Linux gprof

```bash
mkdir build
cd build
cmake ..

# If needed, you can specify a compiler as follows
# cmake .. -DCMAKE_CXX_COMPILER=g++-11

make gprof.svg
```

## Profile On MacOS Xcode Instruments

```bash
mkdir build.xcode
cd build.xcode
cmake .. -G Xcode

open Performance.xcodeproj

# Open the desired target at the top of the window
# Product -> Profile (⌘I)
# Choose Time Profiler
# Record
```

## Installing gprof2dot on Linux

<https://pypi.org/project/gprof2dot/>

```bash
sudo apt install python3 graphviz
pip3 install gprof2dot
```
# cse111
