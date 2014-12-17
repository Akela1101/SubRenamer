subrenamer
==========
To rename subtitle files so they match video files, 
use terminal to execute subrenamer in directory with files.

Example
----------
```bash
\a$ ls -1
a.mkv
b.mkv
c.mkv
subrenamer.exe*
x.ssa
y.ssa
z.ssa

\a$ ./subrenamer.exe
Rename: "x.ssa" => a.ssa
Rename: "y.ssa" => b.ssa
Rename: "z.ssa" => c.ssa

Continue with it? (yes/no): y
```

BUILD
----------
```bash
mkdir build
cd build
cmake ..
# cmake -G "MSYS Makefiles" .. # for windows
make
sudo make install
```