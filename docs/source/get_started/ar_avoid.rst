.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

11. Evitación de obstáculos
================================

En este proyecto, el Zeus Car avanzará automáticamente y utilizará dos módulos de evitación de obstáculos junto con un módulo ultrasónico para evitar colisiones.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Abre el archivo ``11_obstacle_avoid.ino`` en la ruta ``zeus-car-main\examples\11_obstacle_avoid``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

    * El Zeus Car avanzará automáticamente.
    * Un módulo ultrasónico detectará los obstáculos al frente; si detecta uno, el coche girará a la izquierda.
    * Cuando el módulo de evitación de obstáculos izquierdo detecte un obstáculo, el coche girará a la derecha, y cuando el módulo de evitación de obstáculos derecho detecte un obstáculo, el coche girará a la izquierda.

.. note::
    Antes de usarlo, es necesario ajustar la distancia de detección de los dos módulos de evitación de obstáculos a 15 cm. Los pasos son los siguientes:
    
    * Primero, ajusta el módulo de evitación de obstáculos derecho. Durante el transporte, los golpes pueden hacer que el transmisor y el receptor del módulo infrarrojo se inclinen. Por lo tanto, debes alinearlos manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Coloca un obstáculo a unos 15 cm del módulo de evitación de obstáculos por infrarrojos.
    * En el módulo hay dos potenciómetros: uno para ajustar la potencia de emisión y otro para ajustar la frecuencia de emisión. Ajustando estos potenciómetros, puedes configurar la distancia de detección.
    * Luego, ajusta un potenciómetro y, si a 15 cm la luz de señal en el módulo se enciende, la calibración será exitosa; si no, ajusta el otro potenciómetro.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibra el otro módulo de evitación de obstáculos de la misma manera.
