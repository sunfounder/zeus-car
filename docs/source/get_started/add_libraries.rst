.. note:: 

    ¡Hola y bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Únete a otros apasionados para profundizar en Raspberry Pi, Arduino y ESP32.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos productos y adelantos especiales.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _ar_install_lib:

Instalar las bibliotecas requeridas
===============================================

**¿Qué es una biblioteca?**

Una biblioteca es un conjunto de funciones y encabezados predefinidos que facilitan la programación y la hacen más eficiente. Generalmente, las bibliotecas constan de dos archivos principales:

* **.h (Header File)**: Contiene declaraciones de funciones, definiciones de macros y constructores.
* **.cpp (Source File)**: Incluye implementaciones de funciones, definiciones de variables y otros componentes ejecutables.

Al incluir una biblioteca en tu proyecto, puedes llamar directamente a las funciones que proporciona (por ejemplo, ``#include <dht.h>``) en lugar de escribir tus propias definiciones desde cero. Esto mantiene el código más conciso y fácil de leer.  

Si bien es posible definir las funciones manualmente, el uso de una biblioteca ahorra tiempo y reduce la complejidad.

Algunas bibliotecas vienen preinstaladas en el Arduino IDE, mientras que otras deben instalarse manualmente. A continuación, se explica cómo instalar las bibliotecas necesarias para este proyecto.

**Cómo instalar una biblioteca**

.. note::

    Las siguientes instrucciones son para **Arduino IDE 2.0**. Si utilizas Arduino IDE 1.x, consulta |link_install_library|.

Sigue estos pasos para instalar una biblioteca:

1. Haz clic en el ícono del **Library Manager** en la columna izquierda del Arduino IDE.

   .. image:: img/arduino/ar_libr_manager.jpg

2. Busca la biblioteca:

   * Aparecerá una lista de bibliotecas disponibles. Usa la barra de búsqueda para encontrar la que deseas instalar.
   * Por ejemplo, para instalar la biblioteca ``SoftPWM``, escribe su nombre y haz clic en el botón **INSTALL**.

   .. image:: img/arduino/ar_softpwm.png

3. El proceso de instalación suele tardar menos de un minuto. Una vez finalizado, la biblioteca mostrará el estado **INSTALLED** en el Administrador de Bibliotecas.

   .. image:: img/arduino/ar_install_success.png

4. Repite los pasos anteriores para instalar la biblioteca ``IRLremote``, asegurándote de escribir correctamente el nombre.

   .. image:: img/arduino/ar_irlremote.png

5. Luego, instala la biblioteca ``ArduinoJson``.

   .. image:: img/arduino/ar_arduinojson.png

6. Finalmente, busca e instala la biblioteca ``SunFounder AI Camera``, la última biblioteca necesaria para este proyecto.

   .. image:: img/arduino/ar_aicamera.png

Siguiendo estos pasos, tendrás todas las bibliotecas necesarias instaladas y listas para usar en tu proyecto.
