.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _ar_grayscale:

13. Escala de Grises
==============================

En este proyecto, aprenderás a leer y calibrar el Módulo Omni Grayscale en la parte inferior del Zeus Car.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``13_hc165_and_grayscale.ino`` en la ruta ``zeus-car-main\examples\13_hc165_and_grayscale``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c34354c-dd61-4e86-9b99-eccc93e9293f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

    .. note::
        No desconectes el USB en este paso, ya que necesitarás verificar los datos del Módulo Omni Grayscale en tu computadora.

#. Abre el monitor serie y asegúrate de que la velocidad de transmisión actual esté configurada en 115200. Se recomienda hacer clic en el icono **Toggle Autoscroll** para visualizar los datos más recientes.

    .. image:: img/ar_grayscale.png

    * Voltea el coche y verás que el Monitor Serie imprime ``data: 11111111``.
    * Si cubres una de las sondas del módulo con la mano, verás que el valor en la posición correspondiente cambia a ``0``.
    * Por ejemplo, si cubres la sonda ``U11``, verás ``data: 01111111``.

#. Calibrar el Módulo Omni Grayscale.

    Dado que cada tipo de superficie tiene diferentes valores de escala de grises, el umbral preconfigurado de fábrica puede no ser adecuado para tu entorno actual. Por lo tanto, es necesario calibrar este módulo antes de usarlo. Se recomienda calibrarlo siempre que el color del suelo cambie significativamente.

    * Coloca el Zeus Car sobre una superficie blanca y gira el potenciómetro hasta que la luz del sensor de grises se ilumine justo en el punto de activación.

        .. image:: img/zeus_line_calibration.jpg

    * Luego, coloca los dos sensores de escala de grises en los extremos de la línea negra y la superficie blanca, y gira lentamente el potenciómetro hasta que el indicador de señal se apague.

        .. image:: img/zeus_line_calibration1.jpg

    * Puedes mover el coche repetidamente sobre la línea negra y la superficie blanca para asegurarte de que las luces del sensor de escala de grises se apaguen cuando estén entre la línea negra y la superficie blanca, y que se enciendan cuando estén sobre la superficie blanca, lo que indica que el módulo se ha calibrado con éxito.
