.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.


Módulo Ultrasónico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Entrada de pulso de disparo.
* **ECHO**: Salida de pulso de eco.
* **GND**: Conexión a tierra.
* **VCC**: Alimentación de 5V.

Este es el sensor de distancia ultrasónico HC-SR04, que proporciona mediciones sin contacto en un rango de 2 cm a 400 cm, con una precisión de hasta 3 mm. El módulo incluye un transmisor ultrasónico, un receptor y un circuito de control.

Solo necesitas conectar 4 pines: VCC (alimentación), Trig (disparo), Echo (recepción) y GND (tierra) para comenzar a usarlo en tus proyectos de medición.

**Características**

* Voltaje de operación: DC 5V
* Corriente de operación: 16mA
* Frecuencia de trabajo: 40kHz
* Rango máximo: 500 cm
* Rango mínimo: 2 cm
* Señal de entrada del disparo: Pulso TTL de 10μs
* Señal de salida del eco: Señal TTL proporcional a la distancia
* Conector: XH2.54-4P
* Dimensiones: 46 x 20.5 x 15 mm

**Principio de Funcionamiento**

El sensor ultrasónico funciona bajo los siguientes principios:

* Usa un disparo IO con una señal en nivel alto de al menos 10μs.
* El módulo emite una ráfaga de 8 ciclos de ultrasonido a 40 kHz y detecta si se recibe una señal de eco.
* El pin Echo generará una señal en alto si el pulso es reflejado por un objeto. La duración de este pulso en alto corresponde al tiempo que tarda la señal en viajar hasta el objeto y regresar.
* Distancia = (Tiempo en alto x Velocidad del sonido (340 m/s)) / 2.


    .. image:: img/ultrasonic_prin.jpg
        :width: 800

Fórmulas de conversión:

* Microsegundos / 58 = Distancia en centímetros.
* Microsegundos / 148 = Distancia en pulgadas.
* Distancia = (Tiempo en alto x Velocidad del sonido (340m/s)) / 2.

**Notas de Aplicación**

* No conectes el módulo a la alimentación antes de conectar GND, ya que podría afectar su funcionamiento.
* La superficie del objeto a medir debe ser de al menos 0.5 m² y lo más plana posible para obtener mediciones precisas.
