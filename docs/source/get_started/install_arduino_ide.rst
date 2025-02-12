.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _install_arduino_ide:

Descargar e Instalar Arduino IDE 2.0
========================================

El Arduino IDE, conocido como Entorno de Desarrollo Integrado de Arduino, proporciona todas las herramientas necesarias para desarrollar proyectos con Arduino. Es un software de programación diseñado específicamente para Arduino y desarrollado por el equipo de Arduino, permitiendo escribir programas y cargarlos en la placa Arduino.

Arduino IDE 2.0 es un proyecto de código abierto y representa un gran avance respecto a su predecesor, Arduino IDE 1.x. Viene con una interfaz rediseñada, un mejorado gestor de placas y bibliotecas, depurador, función de autocompletado y muchas otras mejoras.

En este tutorial, explicaremos cómo descargar e instalar Arduino IDE 2.0 en sistemas Windows, Mac o Linux.

Requisitos
-------------------

* Windows - Windows 10 o posterior, 64 bits
* Linux - 64 bits
* Mac OS X - Versión 10.14 ("Mojave") o posterior, 64 bits

Descargar Arduino IDE 2.0
-------------------------------

#. Visita |link_download_arduino|.
#. Descarga la versión del IDE correspondiente a tu sistema operativo.

    .. image:: img/arduino/sp_001.png

Instalación
------------------------------

* :ref:`ide_windows`
* :ref:`ide_macos`
* :ref:`ide_linux`

.. _ide_windows:

Windows
^^^^^^^^^^^^^

#. Haz doble clic en el archivo ``arduino-ide_xxxx.exe`` para ejecutarlo.

#. Lee y acepta el Acuerdo de Licencia.

    .. image:: img/arduino/sp_002.png

#. Configura las opciones de instalación.

    .. image:: img/arduino/sp_003.png

#. Selecciona la ubicación de instalación. Se recomienda instalar el software en un disco distinto al del sistema.

    .. image:: img/arduino/sp_004.png

#. Finaliza la instalación.

    .. image:: img/arduino/sp_005.png

.. _ide_macos:

macOS
^^^^^^^^^^^^^^^^

Haz doble clic en el archivo ``arduino_ide_xxxx.dmg`` descargado y sigue las instrucciones para copiar **Arduino IDE.app** a la carpeta **Applications**. En unos segundos, el Arduino IDE estará instalado correctamente.

.. image:: img/arduino/macos_install_ide.png
    :width: 800

.. _ide_linux:

Linux
^^^^^^^^^^^^

Para conocer los pasos de instalación de Arduino IDE 2.0 en Linux, consulta la documentación oficial en:  
https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux


Abrir el IDE
---------------

#. La primera vez que abras Arduino IDE 2.0, el software instalará automáticamente las placas AVR de Arduino, bibliotecas preinstaladas y otros archivos necesarios.

    .. image:: img/arduino/sp_901.png

#. Es posible que tu firewall o centro de seguridad muestre mensajes emergentes pidiéndote permiso para instalar ciertos controladores. Asegúrate de permitir todas las instalaciones.

    .. image:: img/arduino/sp_104.png

#. ¡Listo! Tu Arduino IDE está preparado para usarse.

    .. note::
        Si por problemas de conexión u otras razones alguna instalación no se completa, puedes volver a abrir Arduino IDE y continuará con el proceso pendiente. La ventana de salida no se abrirá automáticamente tras completar la instalación, a menos que hagas clic en "Verificar" o "Subir".
