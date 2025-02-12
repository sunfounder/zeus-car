.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

El ESP32-CAM es un módulo de cámara compacto basado en el chip ESP32-S, con un costo aproximado de $10. Además de integrar la cámara OV2640 y múltiples GPIOs para conectar periféricos, cuenta con una ranura para tarjetas microSD, ideal para almacenar imágenes capturadas o archivos para servir a clientes.

Este módulo puede operar de forma independiente como un sistema de tamaño reducido, con dimensiones de 27 x 40.5 x 4.5 mm y un consumo en modo de suspensión profunda de tan solo 6mA.

El ESP32-CAM se puede utilizar en una amplia variedad de aplicaciones IoT, incluyendo dispositivos inteligentes para el hogar, control inalámbrico industrial, monitoreo remoto, identificación inalámbrica mediante códigos QR, sistemas de posicionamiento y muchas otras aplicaciones de IoT. Es una solución versátil y eficiente para proyectos de Internet de las Cosas.

**Especificaciones Técnicas**

.. list-table::
    :widths: 25 50

    * - Modelo del módulo
      - ESP32-CAM
    * - Paquete
      - DIP-16
    * - Dimensiones
      - 27 x 40.5 x 4.5 (±0.2) mm
    * - Memoria Flash SPI
      - 32Mbit por defecto
    * - RAM
      - 520KB interna + 8MB PSRAM externa
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR y BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces soportadas
      - UART, SPI, I2C, PWM
    * - Soporte para tarjeta TF
      - Hasta 4GB
    * - Pines de I/O
      - 9
    * - Velocidad del puerto serie
      - 115200 bps por defecto
    * - Formato de salida de imagen
      - JPEG (solo compatible con OV2640), BMP, GRAYSCALE
    * - Rango de frecuencia
      - 2400 ~ 2483.5MHz
    * - Tipo de antena
      - Antena PCB integrada, ganancia de 2dBi
    * - Potencia de transmisión
      - 802.11b: 17±2 dBm (@11Mbps) 
    * - 
      - 802.11g: 14±2 dBm (@54Mbps) 
    * - 
      - 802.11n: 13±2 dBm (@MCS7)
    * - Sensibilidad de recepción
      - CCK, 1 Mbps: -90 dBm
    * - 
      - CCK, 11 Mbps: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK): -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM): -70 dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps): -67 dBm
    * - Consumo de energía
      - Flash apagado: 180mA @5V
    * - 
      - Flash encendido al máximo brillo: 310mA @5V
    * - 
      - Deep-sleep: mínimo 6mA @5V
    * - 
      - Moderm-sleep: mínimo 20mA @5V
    * - 
      - Light-sleep: mínimo 6.7mA @5V
    * - Seguridad
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Rango de alimentación
      - 4.75 - 5.25V
    * - Temperatura de operación
      - -20 ℃ ~ 70 ℃
    * - Condiciones de almacenamiento
      - -40 ℃ ~ 125 ℃, < 90%RH


**Diagrama de pines del ESP32-CAM**

La siguiente imagen muestra el diagrama de pines del módulo ESP32-CAM AI-Thinker.

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Dispone de tres **GND** y tres pines de alimentación: 3.3V, 5V y un pin configurable en 3.3V o 5V.
* **GPIO 1** y **GPIO 3** son los pines de comunicación serie (RXD y TXD). Se requieren para cargar código en la placa.
* **GPIO 0** es clave, ya que define si el ESP32 entra en modo de carga de firmware. Si **GPIO 0** está conectado a **GND**, el ESP32-CAM entra en modo de carga.

Los siguientes pines están conectados internamente al lector de tarjetas microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (también conectado al LED integrado)
* GPIO 12: Data 2
* GPIO 13: Data 3

**Notas Importantes**

* Asegúrate de que la alimentación del módulo sea de al menos 5V 2A, de lo contrario, la imagen podría mostrar líneas de interferencia.
* El GPIO32 controla la alimentación de la cámara. Para que la cámara funcione correctamente, GPIO32 debe estar en bajo.
* GPIO0 está conectado a la señal XCLK de la cámara. Déjalo desconectado (flotante) cuando uses la cámara, no lo conectes a nivel alto o bajo.
* El firmware predeterminado ya está preinstalado en fábrica. Si necesitas cargar otro firmware, hazlo con precaución.

**Documentación**

* Diagrama esquemático: |link_esp32cam_schematic|
* Especificación de la cámara (versión en inglés): |link_cam_ov2640|

.. note::
    Toda la información anterior proviene de |link_aithiner|
