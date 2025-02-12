.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

4. Derrape
======================

En este proyecto, aprenderás a hacer que el Zeus Car derrape.

.. image:: img/zeus_drift_left.jpg

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``4_drift.ino`` en la ruta ``zeus-car-main\examples\4_drift``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/9ca66dad-7258-4868-a8a4-3bd512bacd72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.
#. Ahora, el Zeus Car avanzará durante 0.5 segundos, luego derrapará 90 grados hacia la izquierda y repetirá el proceso. Puedes intentar cambiar el valor 45 (``rot``) por otro número o un número negativo para observar cómo cambian el ángulo y la dirección del derrape.


**¿Cómo funciona?**

El derrape del Zeus Car se logra agregando el parámetro de derrape ``drift`` a la función de movimiento ``carMove()``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot, bool drift)

* ``angle``: Dirección en la que deseas que se mueva el coche. Se toma como referencia la parte frontal del coche a 0 grados, aumentando en sentido antihorario.
* ``power``: Potencia de movimiento, con un rango de -100% a 100%. Cuando ``power`` es positivo, el coche avanza; si es negativo, retrocede.
* ``rot``: Potencia de rotación, con un rango de -100% a 100%. Si ``rot`` es positivo, el coche gira en sentido antihorario; si es negativo, gira en sentido horario.
* ``drift``: Por defecto es ``false``. Si es ``true``, se activa el modo derrape.

Diferentes valores de ``power`` y ``rot`` modificarán el ángulo y la dirección del derrape del Zeus Car.
