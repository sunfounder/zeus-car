.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

7. Brújula
==============

En este proyecto, el Zeus Car se convertirá en una brújula.  
Deberás establecer una dirección de referencia, y sin importar cómo lo gires, siempre se orientará hacia esa dirección.

.. note::
    Si hay cables eléctricos cerca del Zeus Car, el campo electromagnético interferirá con el funcionamiento del módulo qmc6310, lo que podría alterar la dirección establecida.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``7_compass.ino`` en la ruta ``zeus-car-main\examples\7_compass``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/672af146-1b45-46f6-b1d9-8ad9ecdcf8c0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.



#. Primero, calibremos el módulo qmc6310.

    * Coloca el coche en el suelo (asegúrate de que esté lejos de superficies con cables eléctricos densos).
    * Presiona |ir_mute| y el coche girará sobre su propio eje.
    * Se detendrá cuando haya registrado completamente el campo magnético en ese lugar.  
    * Si no se detiene después de más de 2 minutos, puedes presionar |ir_power| para detenerlo y continuar la calibración en otro lugar.

#. Gira el coche en la dirección en la que deseas que se mantenga orientado y presiona |ir_play|. A partir de ese momento, sin importar cómo lo gires, el coche girará lentamente hasta volver a la dirección establecida.

#. Los campos magnéticos en el suelo y en una mesa pueden ser diferentes, por lo que es necesario recalibrarlo según la superficie en la que se utilice.
