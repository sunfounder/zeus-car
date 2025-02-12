.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

6. Luces del Coche
==========================


En este proyecto, podrás utilizar el control remoto para gestionar las tiras de luces RGB en la parte inferior del coche, permitiéndoles mostrar diferentes colores.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/car_light.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``6_car_light.ino`` en la ruta ``zeus-car-main\examples\6_car_light``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

#. Ahora puedes usar los números del 1 al 9 en el control remoto para encender las luces del coche en diferentes colores. Presiona 0 para apagarlas y presiona |ir_return| para que el coche realice un ciclo de colores. Las teclas del 1 al 9 corresponden a los siguientes colores: rojo, naranja, amarillo, verde, cian, azul, morado, rosa y blanco.
