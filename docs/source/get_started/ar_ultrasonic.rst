.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

10. Ultrasonido
==============================

En este proyecto, aprenderás a leer la distancia detectada por el módulo ultrasónico.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, primero debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``10_ultrasonic.ino`` en la ruta ``zeus-car-main\examples\10_ultrasonic``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b3c702d7-2d4e-48fe-8d8d-7d20f70c9e45/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, enciende el interruptor de alimentación para iniciar el Zeus Car.

    .. note::
        No desconectes el USB en este paso, ya que necesitas verificar los datos del módulo ultrasónico en tu computadora.

#. Abre el monitor serie y asegúrate de que la velocidad de baudios actual esté configurada en 115200. Se recomienda hacer clic en el icono **Toggle Autoscroll** para ver los datos más recientes.

   * Podrás visualizar los datos impresos como ``distance: 21.11  is_obstacle: 0``.
   * Si la distancia del obstáculo frente al sensor es inferior a 20 cm, ``is_obstacle: 0`` cambiará a ``is_obstacle: 1``.

    .. image:: img/ar_ultrasonic.png

