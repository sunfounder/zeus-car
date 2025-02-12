.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _ar_line_track:

14. Seguimiento de Línea
===========================

En este proyecto, aprenderás a utilizar el Módulo Omni Grayscale para el seguimiento de líneas.

Antes de comenzar, necesitarás usar cinta aislante negra para trazar una línea de pista, la cual puede ser un círculo, una línea recta o una forma irregular.

Pero hay dos puntos a tener en cuenta:

1. La línea debe tener un ancho de 3 cm (el grosor de una cinta aislante es de 1.5 cm).
2. El ángulo de la curva no debe ser menor de 90°.

.. image:: img/map.png

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``14_line_track.ino`` en la ruta ``zeus-car-main\examples\14_line_track``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/f1bfb9ad-8bfa-417e-a4c0-10dbdcdc4298/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

#. A continuación, tu Zeus Car se moverá siguiendo la línea. Si se desvía, es posible que necesites recalibrar el :ref:`ar_grayscale` o reducir su velocidad.
