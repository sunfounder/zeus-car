.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Módulo Omni Grayscale
============================

.. image:: img/omni_grayscale_front.png
    :width: 300

.. image:: img/omni_grayscale_back.png
    :width: 300

* **VREF**: Pin de entrada de voltaje de referencia. El valor de cada sensor se compara con este voltaje de referencia para determinar si la salida es alta o baja.
* **Q7**: Salida en serie de la última etapa.
* **PL**: Entrada de carga paralela asíncrona (activa en nivel bajo).
* **CP**: Entrada de reloj (activación en flanco de subida).
* **5V**: Entrada de alimentación DC de 3.3V a 5V.
* **GND**: Conexión a tierra.

Este es un módulo Omni Grayscale diseñado para seguimiento de líneas y detección de bordes. El término "Omni" se refiere a su capacidad omnidireccional, ya que el módulo cuenta con 8 sensores transmisores TCRT5000 distribuidos en círculo, permitiendo detectar líneas negras en cualquier dirección.

Esto permite que un robot móvil, como el Zeus Car con ruedas Mecanum, pueda seguir líneas en diferentes ángulos sin necesidad de mantener su frente alineado en una sola dirección.

La sensibilidad del módulo puede ajustarse según el entorno modificando el valor de VREF. En el Zeus Car Shield, el potenciómetro azul se usa para calibrar el valor del pin VREF.

**Principio de funcionamiento**

* |link_tcrt5000_datasheet|

El módulo integra ocho sensores TCRT5000, los cuales funcionan bajo el principio de reflexión óptica por infrarrojos. Cada sensor está compuesto por un diodo emisor de infrarrojos y un fototransistor, ambos protegidos por un material que bloquea la luz visible.

.. image:: img/tcrt5000_pin.jpg
    :width: 400
    :align: center

Durante el funcionamiento, el diodo emisor de infrarrojos del TCRT5000 emite luz infrarroja de 950nm de longitud de onda. Si la luz infrarroja no es reflejada por un objeto, o si la intensidad de la reflexión es insuficiente, el fototransistor permanece inactivo. Cuando la luz infrarroja es reflejada con suficiente intensidad y recibida por el fototransistor, este entra en funcionamiento y genera una salida de señal.

* |link_lm339_datasheet|

El módulo Omni Grayscale cuenta con dos chips LM339, cada uno con cuatro comparadores diferenciales, sumando un total de 8 comparadores. Estos comparadores se encargan de comparar el valor actual del sensor con el voltaje de referencia (VREF) para determinar si la salida es de nivel alto o bajo, lo que permite identificar la detección de una línea negra.

.. image:: img/lm339_chip.png

A continuación, se muestra un esquema del funcionamiento de uno de los canales:

.. image:: img/tcrt_lm339.png

* Se establece un voltaje de referencia en el pin VREF (configurado mediante el potenciómetro en el Zeus Car Shield) y se conecta a la entrada inversora (-) del comparador.
* La salida del fototransistor del sensor TCRT5000 se conecta a la entrada no inversora (+) del comparador.
* Si el rayo infrarrojo no se refleja o la intensidad reflejada es insuficiente, el fototransistor no conduce y su salida se mantiene en alto. En este caso, la entrada no inversora (+) del comparador es mayor que la inversora (-), lo que hace que la salida del comparador sea alta y el indicador LED permanezca apagado.
* Si el sensor detecta una superficie blanca (que refleja más luz infrarroja), el fototransistor conduce, reduciendo el voltaje en la entrada no inversora (+). En este caso, la salida del comparador es baja y el LED indicador se enciende.
* Como la superficie negra absorbe la luz infrarroja, refleja menos luz hacia el sensor, lo que hace que el comparador mantenga una salida alta y el indicador LED se mantenga apagado.

Estos 8 datos de los sensores se transmiten a la placa Arduino a través del 74HC165, un registro de desplazamiento de entrada paralela y salida en serie de 8 bits.

* |link_74hc165_datasheet|

El 74HC165 permite obtener salidas serie Q0 y Q7 desde su última etapa. Cuando la entrada de carga paralela (PL) está en bajo, los datos paralelos de D0 a D7 se leen de manera asíncrona en el registro. Cuando PL está en alto, los datos ingresan de forma serial desde la entrada DS, desplazándose un bit a la derecha en cada pulso de reloj.

Este mecanismo permite convertir datos de entrada paralela a serie, enlazando la salida Q7 a la entrada DS del siguiente registro de desplazamiento.

.. image:: img/74hc165_con.png

**Características**

* Voltaje de operación: 3.3 ~ 5V
* Salida: digital (alto/bajo)
* Carga paralela asíncrona de 8 bits
* Entrada serie síncrona
* Umbral de detección: ajustable mediante el pin VREF
* Tipo de sensor: TCRT5000
* Modelo de conector: ZH1.5-6P
* Temperatura de operación: -10 °C ~ +50 °C
* Dimensiones: 80mm x 80mm

**Calibración del módulo**

Dado que cada superficie tiene diferentes valores de escala de grises, el umbral de detección preconfigurado en fábrica puede no ser adecuado para todos los entornos. Por ello, es necesario calibrar el módulo antes de su uso. Se recomienda recalibrarlo cada vez que se produzcan cambios significativos en el color del suelo.

* Coloca el Zeus Car sobre una superficie blanca y ajusta el potenciómetro hasta que el LED del sensor de escala de grises se ilumine.

    .. image:: img/zeus_line_calibration.jpg

* Ahora, coloca los dos sensores laterales justo en el límite entre la línea negra y la superficie blanca, y ajusta lentamente el potenciómetro hasta que el LED de señal se apague.

    .. image:: img/zeus_line_calibration1.jpg

* Verifica moviendo el Zeus Car sobre la línea negra y la superficie blanca repetidamente. El sensor de escala de grises debe apagarse al estar sobre la línea negra y encenderse sobre la superficie blanca, lo que indicará que la calibración se ha realizado correctamente.
