.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

3. Movimiento y Rotación
==========================

En este proyecto, el Zeus Car puede aumentar los parámetros de rotación para girar sobre su propio eje o moverse en un arco.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``3_rotate_and_move.ino`` en la ruta ``zeus-car-main\examples\3_rotate_and_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/bf0dfe1b-18c1-4a45-bd38-a9a8e671d66a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.  
   Primero, el Zeus Car girará a la izquierda y luego a la derecha para regresar a su posición original. Luego, comenzará a moverse en un arco hacia afuera, con un ángulo de giro que disminuirá progresivamente hasta que finalmente gire sobre su propio eje.



**¿Cómo funciona?**

Aquí se agrega un parámetro de potencia de rotación ``rot`` a la función de movimiento del Zeus Car ``carMove()``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: La dirección en la que deseas que el Zeus Car se mueva. Usa la parte frontal del vehículo como referencia de 0 grados y aumenta el ángulo en sentido antihorario.
* ``power``: La potencia de movimiento, con un rango de -100% a 100%. Si ``power`` es positivo, el Zeus Car avanza; si es negativo, retrocede.
* ``rot``: La potencia de rotación, con un rango de -100% a 100%. Si ``rot`` es positivo, el Zeus Car girará en sentido antihorario; si es negativo, girará en sentido horario.

Si ``power`` es 0 y ``rot`` no es 0, el Zeus Car girará sobre su propio eje. Cuanto mayor sea el valor de ``rot``, mayor será la velocidad de rotación. Cuando ``rot`` es positivo, el giro será en sentido antihorario y, cuando es negativo, en sentido horario.

Si ``power`` no es 0, el Zeus Car se desplazará en un arco. El ángulo de giro aumentará a medida que ``rot`` aumente, y cuando el valor sea lo suficientemente grande, el Zeus Car girará sobre su propio eje.
