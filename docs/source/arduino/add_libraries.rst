.. _ar_install_library:

Install the Required Libraries
===============================================

**What is a Library?**

A library is a collection of predefined functions and headers that make programming easier and more efficient. Libraries typically consist of two main files:

* **.h (Header File)**: Contains function declarations, macro definitions, and constructor definitions.
* **.cpp (Source File)**: Includes function implementations, variable definitions, and other executable components.

By including a library in your project, you can directly call the functions it provides (e.g., ``#include <dht.h>``) instead of writing your own definitions from scratch. This keeps your code concise and easier to read. 

While it's possible to write the function definitions yourself, using a library saves time and reduces complexity.

Some libraries are pre-installed with the Arduino IDE, while others need to be installed manually. Here's how to install the required libraries for this project.

**How to Install a Library**

.. note::

    The following instructions are for **Arduino IDE 2.0**. If you are using Arduino IDE 1.x, refer to |link_install_library|.

Here are steps to install a library:

1. Click on the **Library Manager** icon in the left column of the Arduino IDE.

   .. image:: img/arduino/ar_libr_manager.jpg

2. Search for the library:

   * A list of available libraries will appear. Use the search bar to find the library you want to install.
   * For example, to install the ``SoftPWM`` library, type the library name and click the **INSTALL** button.

   .. image:: img/arduino/ar_softpwm.png

3. The installation process usually takes less than a minute. Once completed, the library will display **INSTALLED** in the Library Manager.
   
   .. image:: img/arduino/ar_install_success.png

4. Follow the same steps as above to install the ``IRLremote`` Library, ensuring you spell the library name correctly.
   
   .. image:: img/arduino/ar_irlremote.png

5. Then, install the ``ArduinoJson`` library.

   .. image:: img/arduino/ar_arduinojson.png

6. Search for and install the ``SunFounder AI Camera`` library, the final library needed for this project.

   .. image:: img/arduino/ar_aicamera.png

By following these steps, you'll have all the necessary libraries installed and ready to use for your project.
