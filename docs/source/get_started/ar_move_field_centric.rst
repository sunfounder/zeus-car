.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

8. Movimiento Centrado en el Campo
======================================

Este proyecto se basa en el proyecto anterior para combinar la función de la brújula con el movimiento del Zeus Car.  
Mientras controlas el movimiento del Zeus Car con el control remoto, si es desviado por una fuerza externa (por ejemplo, una patada de un perro), automáticamente corregirá su dirección original.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``8_move_field_centric.ino`` en la ruta ``zeus-car-main\examples\8_move_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

#. Luego, usa los números del 1 al 9 en el control remoto para mover el Zeus Car en 8 direcciones. Una vez que presiones una tecla, el Zeus Car seguirá moviéndose hasta que presiones |ir_power| o la tecla número 5.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. Al presionar |ir_return| una vez, el Zeus Car girará en sentido antihorario con su cuerpo como centro y se detendrá cuando presiones |ir_power| o la tecla número 5.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. De manera similar, al presionar |ir_usd| una vez, el Zeus Car girará en sentido horario y se detendrá hasta que presiones |ir_power| o la tecla número 5.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center

#. Presiona la tecla |ir_minus| para hacer que el Zeus Car derrape hacia la izquierda.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. Presiona la tecla |ir_plus| para hacer que el Zeus Car derrape hacia la derecha.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


.. note::

    * Si el Zeus Car no se mueve correctamente, es posible que la brújula no esté bien calibrada. Debes presionar |ir_mute| para calibrarla.
    * Si levantas el Zeus Car del suelo a una mesa, el campo magnético cambiará y será necesario recalibrarlo.
