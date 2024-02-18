.. _ar_install_library:

Install the Required Libraries
===============================================

**What is library?**

A library, gathering some function definitions and header files, usually contains two files: .h (header file, including function statement, Macro definition, constructor definition, etc.) and .cpp (execution file, with function implementation, variable definition, and so on). 

When you need to use a function in some library, you just need to add a header file (e.g. #include <dht.h>), and then call that function. This can make your code more concise. 

If you don't want to use the library, you can also write that function definition directly. Though as a result, the code will be long and inconvenient to read.

Some libraries are already built in the Arduino IDE, when some others may need to be installed. So now let's see how to install one.

**How to install?**

.. note::

    I am using Arduino IDE 2.0, if you are using Arduino IDE 1.x, you can refer to |link_install_library|.

#. To install a new library into your Arduino IDE you can use the **Library Manager** which can open from the left column.

    .. image:: img/arduino/ar_libr_manager.jpg

#. A list will now appear of all available libraries, where we can also search for the library we want to use. Here, we are going to install the ``SoftPWM`` library. Click on the **INSTALL** button to install the library.

    .. image:: img/arduino/ar_softpwm.png

#. This process should not take too long, but allow up to a minute to install it. When it is finished, we can take a look at the library in the library manager column, where it should say **INSTALLED**.

    .. image:: img/arduino/ar_install_success.png

#. Install the ``IRLremote`` library in the same way, but be careful not to misspell the name.

    .. image:: img/arduino/ar_irlremote.png

#. Finally, install the ArduinoJson library.

    .. image:: img/arduino/ar_arduinojson.png