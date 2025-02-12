.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Placa Adaptadora de Cámara
================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Se utiliza para reiniciar la ESP32-CAM.
* **SCL**: Pin de datos en serie del QMC6310.
* **SDA**: Pin de reloj en serie del QMC6310.
* **RXD**: RXD de la ESP32-CAM. Se requiere para cargar código en la ESP32-CAM mediante los pines de comunicación serie RXD y TXD.
* **TXD**: TXD de la ESP32-CAM.
* **5V**: Entrada de alimentación de 5V DC.
* **GND**: Conexión a tierra.

La Placa Adaptadora de Cámara, como su nombre indica, es una placa de expansión diseñada para la ESP32-CAM, permitiendo fijarla al robot de manera segura y facilitando su cableado.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Además, debido a que el chip geomagnético QMC6310 es sensible a las interferencias de los motores, lo hemos colocado en esta placa adaptadora de cámara para mantenerlo lo más alejado posible de ellos.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Características**

* Voltaje de operación: 5V
* Modelo de interfaz: ZH1.5, 7P
* Dimensiones: 40mm x 27mm x 15mm
* Protocolos de comunicación: UART e I2C

**Documentos**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Esquemático

.. image:: img/cam_adapter_sche.png


**Acerca del QMC6310**

El QMC6310 es un sensor magnético triaxial que integra sensores magnéticos y un ASIC de acondicionamiento de señal en un solo chip de silicio. Este paquete Land Grid Array (LGA) está diseñado para aplicaciones como brújulas electrónicas, rotación de mapas, videojuegos y navegación personal en dispositivos móviles y wearables.

El QMC6310 utiliza tecnología magnetorresistiva de alta resolución de última generación. Junto con un ASIC de conversión analógico-digital (ADC) de 16 bits diseñado a medida, ofrece ventajas como bajo nivel de ruido, alta precisión, bajo consumo de energía, cancelación de offset y compensación de temperatura. El QMC6310 permite una precisión de orientación de brújula de 1° a 2°. Su interfaz de comunicación I²C facilita la integración con otros dispositivos.

El QMC6310 se presenta en un paquete de montaje superficial LGA de 8 pines con dimensiones de **1.2 x 1.2 x 0.53 mm³**.

* |link_qmc6310_datasheet|