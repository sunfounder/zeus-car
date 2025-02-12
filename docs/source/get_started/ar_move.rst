.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

1. Movimientos Básicos
========================

En este proyecto, aprenderás a hacer que el Zeus Car se mueva en todas las direcciones.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

   
#. Conecta el Zeus Car a tu computadora con el cable USB azul. Cuando enchufes la placa Arduino, la computadora la reconocerá automáticamente y le asignará un puerto COM, el cual puedes ver en el Administrador de dispositivos.

#. Abre el archivo ``1_basic_move.ino`` en la ruta ``zeus-car-main\examples\1_basic_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Puedes seleccionar rápidamente la placa y el puerto desde este lugar.

    .. image:: img/ar_board.png
    
    .. note::
        Si no aparece COMxx, abre el Administrador de Placas desde la barra lateral y asegúrate de que el núcleo "Arduino AVR Boards" está instalado.

        .. image:: img/ar_other_board.png

#. Ahora, haz clic en el botón **Upload** para cargar el código en la placa Arduino. Una vez finalizado, aparecerá una notificación en la esquina inferior derecha de la ventana del IDE. En caso de que surjan problemas durante la carga, los errores se mostrarán en esta sección.

    .. note::
        * Si aparece el error "Compilation error: SoftPWM.h: No such file or directory", significa que no tienes instalada la biblioteca ``SoftPWM``.
        * Consulta :ref:`ar_install_lib` para instalar las bibliotecas necesarias ``SoftPWM`` y ``IRLremote``.

    .. image:: img/ar_upload.png

#. Ahora, iniciemos el Zeus Car.

    * Si es la primera vez que se usa o si se desconectó el cable de la batería, el Zeus Car Shield activará su circuito de protección contra sobre-descarga.
    * Por lo tanto, deberás conectar el cable Type-C durante aproximadamente 5 segundos.

            .. image:: img/zeus_charge.jpg

    * Si el indicador de encendido se ilumina, significa que el estado de protección se ha liberado. En este punto, verifica los indicadores de batería. Si ambos están apagados, continúa cargando la batería con el cable Type-C.

        .. image:: img/zeus_power.jpg

#. Ahora verás cómo el Zeus Car se mueve durante un segundo en cada dirección.

    .. image:: img/zeus_move.jpg
        :width: 600

**¿Cómo funciona?**

Estos movimientos se logran gracias a la cooperación de las 4 ruedas Mecanum. Por ejemplo, si las cuatro ruedas avanzan o retroceden al mismo tiempo, el Zeus Car también se moverá en esas direcciones. Si dos ruedas avanzan y dos retroceden, el vehículo se desplazará lateralmente o girará hacia la izquierda o la derecha.

Veamos cómo se logran estos movimientos en detalle.

* Movimiento hacia adelante y hacia atrás, desplazamiento lateral.

    .. image:: img/ar_fwlr.jpg
        :width: 600

* Desplazamiento en diagonal.

    .. image:: img/ar_fblr.jpg
        :width: 600

* Rotación hacia la izquierda y la derecha.

    .. image:: img/ar_turn_lr.jpg
        :width: 600

