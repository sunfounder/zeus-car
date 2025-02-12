.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

5. Control Remoto
======================

En este proyecto, aprenderás a controlar el Zeus Car con el control remoto.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/ir_control.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, primero debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``5_remote_control.ino`` en la ruta ``zeus-car-main\examples\5_remote_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, enciende el interruptor de alimentación para iniciar el Zeus Car.

#. Luego, usa los números 1~9 en el control remoto para mover el coche en 8 direcciones.

    .. image:: img/ar_remote_control.png
        :width: 600
        :align: center

#. Después de presionar una tecla, el Zeus Car seguirá en movimiento hasta que presiones |ir_power| o la tecla numérica 5.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center


#. Si presionas |ir_return| una vez, el coche girará en sentido antihorario con el cuerpo como centro y se detendrá hasta que presiones |ir_power| o la tecla numérica 5.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. De manera similar, al presionar |ir_usd| una vez, el coche girará en sentido horario y se detendrá hasta que presiones |ir_power| o la tecla numérica 5.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center  