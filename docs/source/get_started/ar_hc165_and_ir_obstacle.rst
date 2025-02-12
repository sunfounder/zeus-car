.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

9. Sensor de Obstáculos Infrarrojo
======================================

En este proyecto, aprenderás a utilizar los módulos de evitación de obstáculos por infrarrojos en ambos lados del Zeus Car.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``9_hc165_and_ir_obstacle.ino`` en la ruta ``zeus-car-main\examples\9_hc165_and_ir_obstacle``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3486be01-6b0e-4e84-86f6-9bdadafa1f48/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

    .. note::
        No desconectes el USB en este paso, ya que necesitarás verificar los datos de los dos módulos de evitación de obstáculos en tu computadora.

#. Abre el monitor serie y asegúrate de que la velocidad de transmisión actual esté configurada en 115200, luego podrás visualizar los datos impresos.

   * Si ninguno de los módulos de evitación de obstáculos detecta un obstáculo, el monitor serie imprimirá ``0, 0``.
   * Si colocas tu mano frente a uno de los módulos, imprimirá ``1, 0`` o ``0, 1``.

    .. image:: img/ar_serial.png

#. Calibrar el módulo de evitación de obstáculos por infrarrojos.

    * Comienza ajustando el módulo de evitación de obstáculos derecho. Durante el transporte, los golpes pueden causar que el transmisor y el receptor del módulo de infrarrojos se inclinen. Por lo tanto, es necesario enderezarlos manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Coloca un obstáculo aproximadamente a 15 cm del módulo de evitación de obstáculos por infrarrojos.
    * En el módulo hay dos potenciómetros, uno para ajustar la potencia de transmisión y otro para ajustar la frecuencia de transmisión. Ajustando estos potenciómetros, puedes modificar la distancia de detección.
    * Ajusta uno de los potenciómetros y, si a 15 cm la luz de señal en el módulo se ilumina, la calibración ha sido exitosa. Si no, ajusta el otro potenciómetro.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibra el otro módulo de evitación de obstáculos de la misma manera.
