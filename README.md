<h1>
<img alt="WakBox logo" src="https://raw.github.com/KevinSupertramp/WakBox/master/doc/img/logo.png" title="WakBox"/>
</h1>

Wakfu sandbox written in C++/Qt

**Special Thanks : Boredom, Velocity, scalexm, nightwolf93, Smarken, Crystal**

## Documentation

+ [Core] (https://github.com/KevinSupertramp/WakBox/blob/master/doc/core/index.md)
+ [Databases] (https://github.com/KevinSupertramp/WakBox/blob/master/doc/database/index.md)

## Precompiled Cryptopp Library

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

## Enable MySQL or MariaDB support for QT

When you have this kind of error : "QMYSQL driver not loaded", you should compile QT with MariaDB support.

**on Windows :**

+ Download QT source code. If you have already QT installed, just launch MaintenanceTool.exe
+ Download MariaDB(x32) and tick **Client C API Library (Shared)**
+ Open a qt command prompt at **"C:\Qt\YOUR_QT_VERSION\Src\qtbase\src\plugins\sqldrivers\mysql"**
+ Launch the following command line (dir /x  => the directory without spaces)

   ```sh
   qmake "INCLUDEPATH+=C:\\PROGRA~2\\MARIAD~1.0\\include\\mysql" "LIBS+=C:\\PROGRA~2\\MARIAD~1.0\\lib\\libmysql.lib" mysql.pro
   make
   ```
   change make for nmake if you use MSVC<br>
   if nmake doesn't work lauch the following command line :
   
   ```sh
   "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86
   # or
   "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x64
   ```

+ Copy all files from **C:\Qt\YOUR_QT_VERSION\Src\qtbase\plugins\sqldrivers** except **libmysql.dll** to **C:\Qt\YOUR_QT_VERSION\YOUR_COMPILER_NAME\plugins\sqldrivers**

+ Copy **libmysql.dll** to Windows directory

**on Unix :**

+ Just following the [QT 5 Documentation for SQL Driver](http://doc.qt.io/qt-5/sql-driver.html)

**Help link :**

[QT 5 Documentation for SQL Driver](http://doc.qt.io/qt-5/sql-driver.html)

  
