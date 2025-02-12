.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

2. Movimiento Omnidireccional
================================

En este proyecto, aprenderás a mover el Zeus Car en direcciones de 0, 45, 90, 135, 180, 225, 270 y 315 grados.

Si ignoramos la fricción con el suelo y las tolerancias estructurales, su trayectoria debería formar un octágono y eventualmente regresar a su punto de origen.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``2_omni_move.ino`` ubicado en la ruta ``zeus-car-main\examples\2_omni_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/2425f280-5bd4-4e49-bb2e-220d1f4f867b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Selecciona la placa y el puerto correctos, luego haz clic en el botón **Upload**.

    .. note::
        * Si aparece el error "Compilation error: SoftPWM.h: No such file or directory", significa que no tienes instalada la biblioteca ``SoftPWM``.
        * Consulta :ref:`ar_install_lib` para instalar las dos bibliotecas necesarias ``SoftPWM`` y ``IRLremote``.

    .. image:: img/ar_board_upload.png

#. Enciende el interruptor de encendido para iniciar el Zeus Car.

    .. image:: img/zeus_power.jpg

#. En este punto, el Zeus Car se moverá en las direcciones de 0, 45, 90, 135, 180, 225, 270 y 315 grados.


**¿Cómo funciona?**

El movimiento del Zeus Car se implementa principalmente mediante esta función:

.. code-block::

    void carMove(int16_t angle, int8_t power)

* ``angle``: La dirección en la que deseas mover el coche. Usa la parte frontal del coche como 0 grados y aumenta el ángulo en dirección antihoraria.
* ``power``: La potencia de movimiento, con un rango de -100% a 100%. Cuando ``power`` es positivo, el coche avanza; si es negativo, retrocede.
