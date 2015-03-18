<h1>
<img alt="WakBox logo" src="https://raw.github.com/KevinSupertramp/WakBox/master/doc/img/logo.png" title="WakBox"/>
</h1>

Wakfu sandbox written in C++/Qt

### Supported Compilator

You should extract Cryptopp library for your compilator.
Check /dep/cryptopp/x32 and /dep/cryptopp/x64

#### Windows :
* MSVC2013 x32
* MSVC2013 x64
* MSVC2012 x32
* MSVC2012 x64
* MinGW x32

#### Unix :

* @TODO : Not yet tested

#### Mac :

* @TODO : Not yet tested

### Special Thanks :

Boredom, Velocity, scalexm, nightwolf93, Smarken, Crystal


### Enable ~~MySQL~~ :heart: MariaDB :heart: support for QT :

When you have this kind of error : "QMYSQL driver not loaded", you should compile QT with MariaDB support
**MariaDB is a fork of MySQL Rather use.**

#### on Windows (IN PROGRESS) :

1. Download QT source code - **if you have already QT installed, just launch MaintenanceTool.exe**
2. Download MariaDB and tick **Client C API Library (Shared)**
3. Open a command prompt at **"C:\Qt\{YOUR_QT_VERSION}\Src\qtbase\src\plugins\sqldrivers\mysql"**
4. Launch the following command line

```
qmake "INCLUDEPATH+=C:\PROGRA~1\MARIAD~1.0\include\mysql" "LIBS+= -LC:\PROGRA~1\MARIAD~1.0\lib" mysql.pro
nmake
```

use "C:/PROGRA~1/MARIAD~1.0/" is short name path, use dir /x for find

MinGW : **MariaDB libraries are compiled with Visual Studio for use with MinGW you should convert them**

##### nmake doesn't work :

Lauch the following command line :

```
"C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86
or
"C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x64
```

##### Help link : 

[QT 5 Documentation](http://doc.qt.io/qt-5/sql-driver.html)

  
