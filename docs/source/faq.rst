.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

FAQ
================

Cómo cambiar el canal de Wi-Fi
----------------------------------

La banda de Wi-Fi de 2.4GHz tiene canales del 1 al 13, y el ESP32 es compatible con los canales 1 al 11. Otros dispositivos operando en el mismo canal pueden causar interferencias, lo que podría generar problemas de conexión. Para minimizar esto, puedes probar cambiando el canal. Por defecto, el canal está configurado en 1. Se recomienda saltar de 1 a 2 canales a la vez. Por ejemplo, si el canal actual es 1, prueba con el canal 3, y si la señal sigue siendo deficiente, intenta con el canal 5.

.. note::

   Es necesario contar con la versión 1.4.1 o superior del firmware de la ESP32 CAM para cambiar el canal. Consulta :ref:`update_firmware` para más detalles.

#. Mantén la ESP32 CAM insertada en el adaptador y enciende el Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Para activar la ESP32 CAM, cambia el interruptor de modo a la posición **Run** y presiona el botón **Reset** para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. En tu dispositivo móvil (teléfono o tableta), busca la red "Zeus Car", introduce la contraseña ``12345678`` y conéctate.

   .. note::

        * La conexión actual es con el punto de acceso del Zeus Car, por lo que no habrá acceso a internet. Si el dispositivo sugiere cambiar de red, selecciona "Permanecer conectado".

   .. image:: img/app_wlan.png
        :width: 500

#. Abre un navegador en tu dispositivo móvil y accede a ``http://192.168.4.1`` para entrar a la página de actualización OTA de la ESP32 CAM.

   .. image:: img/faq_cam_ota_141.jpg
      :width: 400

#. En la sección **Wi-Fi AP Channel**, selecciona un canal diferente.

   * El canal predeterminado es 1. Al cambiar de canal, salta 1 o 2 posiciones a la vez (por ejemplo, de 1 a 3, y si es necesario, a 5).  
   * Haz clic en el botón **Confirm** para guardar los cambios.

   .. image:: img/faq_cam_ota_channel.png
      :width: 400

#. Aparecerá una ventana de confirmación pidiéndote que reinicies el dispositivo. Haz clic en **Confirm**.

   .. image:: img/faq_cam_ota_reset.jpg
      :width: 400
   
#. Presiona el botón **Reset** para reiniciar el dispositivo. Ahora, el Zeus Car está listo para su uso normal.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _update_firmware:

Cómo actualizar el firmware de la ESP32 CAM
--------------------------------------------

Sigue estos pasos detallados para actualizar el firmware de tu ESP32 CAM:

#. Mantén la ESP32 CAM insertada en el adaptador y enciende el Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Para activar la ESP32 CAM, cambia el interruptor de modo a la posición **Run** y presiona el botón **Reset** para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. En tu dispositivo móvil (teléfono o tableta), busca la red "Zeus Car", introduce la contraseña ``12345678`` y conéctate.

   .. note::

      * La conexión actual es con el punto de acceso del Zeus Car, por lo que no habrá acceso a internet. Si el dispositivo sugiere cambiar de red, selecciona "Permanecer conectado".

   .. image:: img/app_wlan.png
        :width: 500

#. Descarga el archivo de firmware ``ai-camera-firmware-v1.4.1-ota.bin`` y guárdalo en tu dispositivo móvil.

   * :download:`Firmware ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/download/1.4.1/ai-camera-firmware-v1.4.1-ota.bin>`

#. Abre un navegador en tu dispositivo móvil y accede a ``http://192.168.4.1`` para entrar a la página de actualización OTA de la ESP32 CAM.

   .. image:: img/faq_cam_ota.jpg
      :width: 400

#. En la página OTA, selecciona el archivo de firmware descargado.

   .. image:: img/faq_cam_ota_choose.png
      :width: 400

#. Selecciona el archivo ``ai-camera-firmware-v1.4.1-ota.bin`` de tu dispositivo y haz clic en **OK**.

   .. image:: img/faq_cam_ota_file.png
      :width: 400

#. Haz clic en el botón **Update** para iniciar el proceso de actualización del firmware.

   .. image:: img/faq_cam_ota_update.png
      :width: 400
   
#. Espera a que la actualización finalice. Cuando el número de versión mostrado cambie a ``1.4.1``, la actualización se habrá completado con éxito.

   .. image:: img/faq_cam_ota_finish.png
      :width: 400
   
#. Una vez terminada la actualización, puedes cerrar el navegador. Presiona el botón **Reset** para reiniciar el dispositivo. Ahora, la ESP32 CAM está lista para su funcionamiento normal.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _upload_zeus_code:

Cómo subir el código ``zeus-car.ino``
-----------------------------------------------

Por defecto, la placa Uno R3 del Zeus Car viene preinstalada con el firmware necesario, permitiéndote controlarlo a través de la aplicación. Si tu R3 board ha sido sobrescrita con otro código y deseas volver al firmware original para continuar con el proceso :ref:`quick_start`, sigue estos pasos para volver a cargar el código en tu placa R3:

#. Conecta el Arduino a tu computadora con un cable USB. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de cargar el código, desconecta la ESP32-CAM para evitar conflictos o problemas potenciales.
   
   .. image:: img/unplug_cam.png
        :width: 400

#. Descarga el firmware requerido desde el siguiente enlace:
        
   * :download:`Archivo de firmware de la R3 Board <https://github.com/sunfounder/zeus-car/releases/download/1.4.5/zeus-car-1.4.5.zip>`

#. Extrae el archivo zip descargado y haz doble clic en el archivo ``update-arduino-firmware.bat`` para ejecutarlo.

   .. image:: img/faq_firmware_file.png

#. Escribe el número correspondiente a la Arduino Uno de tu Zeus Car (por ejemplo, ``1``) y presiona **Enter** para iniciar la actualización.

   .. note::

     * Si no aparece el puerto COM correcto o si no estás seguro de cuál es, desconecta otros dispositivos USB de tu computadora, dejando solo el Zeus Car conectado.  
     * Si encuentras un error como ``avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX``, asegúrate de haber desconectado primero la ESP32-CAM.

   .. image:: img/faq_firmware_port.png

#. Tras unos momentos, el nuevo código se cargará exitosamente en la Uno R3 del Zeus Car. Si no logras subir el código después de varios intentos, ejecuta ``update-arduino-firmware-with-bootloader.bat``.

   .. image:: img/faq_firmware_finish.png


.. _ap_to_sta:

Cómo controlar el Zeus Car usando tu Wi-Fi doméstico
--------------------------------------------------------

Por defecto, la Uno R3 viene con un código preinstalado en modo APP, lo que significa que el Zeus Car emitirá un punto de acceso para que puedas conectarte y controlarlo con la aplicación SunFounder Controller.

Si prefieres controlar el Zeus Car mediante tu red Wi-Fi doméstica, sigue estos pasos para cargar el código modificado en la Uno R3:

#. Descarga los archivos necesarios desde el siguiente enlace:

   * :download:`Códigos de Zeus Car <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

#. Consulta la guía de instalación: :ref:`install_arduino_ide`.

#. Usa el **Library Manager** para instalar las bibliotecas ``SoftPWM`` y ``SunFounder AI Camera``. Para más detalles, revisa :ref:`ar_install_lib`.

#. Ve al directorio ``zeus-car-main\zeus-car`` y abre el archivo ``zeus-car.ino``.

   .. image:: img/faq_galaxy_code.png
      :width: 600

#. Comenta las líneas del modo AP, descomenta las líneas del modo STA y reemplaza ``SSID`` y ``PASSWORD`` con los datos de tu Wi-Fi doméstico.

   .. code-block:: arduino

      /** Configure Wifi mode, SSID, password*/
      // #define WIFI_MODE WIFI_MODE_AP
      // #define SSID "Zeus_Car"
      // #define PASSWORD "12345678"

      #define WIFI_MODE WIFI_MODE_STA
      #define SSID "xxxxxxxxxx"
      #define PASSWORD "xxxxxxxxxx"

#. Conecta la Arduino Uno a tu computadora con un cable USB. Como la ESP32-CAM y la Arduino comparten los mismos pines RX y TX, antes de cargar el código, desconéctala para evitar conflictos.

   .. image:: img/unplug_cam.png
        :width: 400

#. Haz clic en el botón **Upload** en Arduino IDE para subir el código modificado a la Uno R3.

   .. image:: img/faq_galaxy_upload.png
      :width: 600

#. Una vez que el código se haya cargado exitosamente, vuelve a conectar la ESP32-CAM y desliza el interruptor de encendido a ON para iniciar el Zeus Car.

   .. image:: img/plug_esp32_cam.jpg

#. Para activar la ESP32 CAM, cambia el interruptor de modo a **Run** y presiona el botón Reset para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Asegúrate de que tu dispositivo móvil (tableta o teléfono) esté conectado a tu red Wi-Fi doméstica.

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. Abre la aplicación SunFounder Controller, toca el ícono "+" para crear un nuevo controlador, selecciona el preset "Zeus Car", ingresa un nombre o simplemente presiona Confirmar.

   .. image:: img/app_preset.jpg
        :width: 600

#. La aplicación buscará automáticamente el Zeus Car. Después de unos segundos, verás un mensaje indicando "Conexión Exitosa".

   .. image:: img/app_edit.jpg
        :width: 600
    
#. Ahora, toca el botón |app_run| para ver la transmisión de video en vivo desde la cámara y controlar el Zeus Car con los widgets disponibles.

   .. image:: img/app_run123.png
        :width: 600 
    

Cómo invertir la cámara  
---------------------------

Si la transmisión de video de la cámara aparece invertida al usar la aplicación SunFounder Controller, puedes corregirla fácilmente desde la app. Sigue estos pasos:

1. Toca el botón |app_edit| en la esquina superior derecha.  

   .. image:: img/faq_edit.png  
        :width: 500 

2. Haz clic en el botón **Cámara** para abrir un menú emergente y activa el interruptor **Inverted**.

   .. image:: img/faq_inverted.png  
        :width: 500  

3. Guarda los cambios.

   .. image:: img/faq_save.png  
        :width: 500 

4. Vuelve a la interfaz de control y haz clic en el botón |app_run|.

   .. note::  

        Si la imagen de la cámara no aparece, pausa el controlador y vuelve a presionar el botón de ejecución.

   .. image:: img/faq_run.png  
        :width: 500  

Error de compilación: SoftPWM.h: No such file or directory?
--------------------------------------------------------------

Si aparece el mensaje "Compilation error: SoftPWM.h: No such file or directory", significa que no tienes instalada la biblioteca ``SoftPWM``.

Consulta la sección :ref:`ar_install_lib` para instalar las bibliotecas necesarias.


avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
---------------------------------------------------------------------------

Si después de hacer clic en el botón Upload, con la placa y el puerto correctamente seleccionados, sigues recibiendo el siguiente mensaje:

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

En este caso, debes asegurarte de que la ESP32-CAM esté desconectada.

La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de subir el código, desconéctala para evitar conflictos o posibles problemas.

.. image:: img/unplug_cam.png
    :width: 400
    :align: center


.. _stt_android:

¿Cómo usar la función STT en mi dispositivo Android?
------------------------------------------------------------------------

La función STT (Speech-to-Text) requiere que el dispositivo móvil Android esté conectado a Internet y tenga instalado el **Google service component**.

Sigue los pasos a continuación:

#. Modifica el modo AP en el archivo ``Zeus_Car.ino`` para cambiarlo a modo STA.

    * Abre el archivo ``Zeus_Car.ino`` ubicado en el directorio ``zeus-car-main/Zeus_Car``.
    * Comenta el código relacionado con el modo AP. Descomenta el código del modo STA y completa los valores de ``SSID`` y ``PASSWORD`` con los datos de tu red Wi-Fi doméstica.

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "Zeus_Car"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Guarda el código, selecciona la placa correcta (Arduino Uno) y el puerto, luego haz clic en el botón **Upload** para subirlo a la placa R3.

#. Busca ``google`` en Google Play, encuentra la aplicación mostrada a continuación e instálala.

    .. image:: img/google_voice.png

#. Conecta tu dispositivo móvil a la misma red Wi-Fi que configuraste en el código.

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. Abre el controlador previamente creado en la aplicación SunFounder Controller y conéctalo a Zeus_Car a través del botón |app_connect|.

    .. image:: img/app_connect.png
        :width: 500
        :align: center

#. Mantén presionado el widget |app_speech_m| después de hacer clic en el botón |app_run|. Aparecerá un mensaje indicando que está escuchando. Pronuncia los siguientes comandos para mover el Zeus Car:

    * ``stop``: Detiene todos los movimientos del coche.
    * ``pasue``: Funciona de manera similar a Stop, pero si la cabeza del coche no está orientada en la dirección establecida previamente, se moverá lentamente hasta esa dirección.
    * ``forward``: Avanzar.
    * ``backward``: Retroceder.
    * ``left forward``: Avanzar hacia la izquierda.
    * ``left backward``: Retroceder hacia la izquierda.
    * ``right forward``: Avanzar hacia la derecha.
    * ``right backward``: Retroceder hacia la derecha.
    * ``move left``: Desplazarse lateralmente a la izquierda.
    * ``move right``: Desplazarse lateralmente a la derecha.
