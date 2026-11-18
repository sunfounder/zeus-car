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

   Para cambiar el canal Wi-Fi se requiere la versión de firmware de la ESP32 CAM **1.4.1 o superior**. Consulta :ref:`update_firmware` para más detalles.

#. Mantén la ESP32 CAM insertada en el adaptador y enciende el Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Para activar la ESP32 CAM, cambia el interruptor de modo a **Run** y pulsa el botón **Reset** para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Busca ``Zeus_Car-XXXXXX`` en la lista de redes disponibles de tu dispositivo móvil (tableta o teléfono), introduce la contraseña ``12345678`` y conéctate. ``XXXXXX`` son los últimos seis caracteres de la dirección MAC del ESP32 CAM, por lo que el nombre del punto de acceso es distinto en cada coche.

   .. note::

        * La conexión actual es al punto de acceso del Zeus Car, así que no hay acceso a Internet. Si se te pide cambiar de red, elige "Mantener la conexión".

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Abre un navegador web en tu dispositivo móvil y ve a ``http://192.168.4.1`` para abrir la página de ajustes de la ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: La página de ajustes es distinta según la versión de firmware de la ESP32 CAM. La Versión A (firmware 1.4.x) es una sola página que reúne las opciones de Wi-Fi y OTA, mientras que la Versión B (firmware 1.5.x y posteriores) tiene las pestañas **Base**, **AP**, **WIFI**, **Camera** y **OTA**. Sigue los pasos que correspondan a la interfaz que veas.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Versión A** (firmware 1.4.x)

   5. En la sección **Wi-Fi AP Channel**, selecciona otro canal y haz clic en el botón **Confirm**.

      * El canal por defecto es 1. Al cambiar de canal, salta 1-2 canales a la vez (por ejemplo, del canal 1 al 3 y, si es necesario, al 5).

      .. image:: img/faq_cam_ota_channel.png
         :width: 400

   #. Aparecerá una ventana de confirmación que te pedirá reiniciar el dispositivo. Haz clic en **Confirm**.

      .. image:: img/faq_cam_ota_reset.jpg
         :width: 400

   #. Pulsa el botón **Reset** de la placa R3 para reiniciar la ESP32 CAM. El Zeus Car ya está listo para funcionar con normalidad.

      .. image:: img/zeus_run123.jpg
         :width: 600

**Versión B** (firmware 1.5.x y posteriores)

   5. Haz clic en **AP** en el menú lateral (o toca la pestaña **AP** en la parte inferior de la pantalla) y selecciona otro canal en la lista **AP Channel**.

      * El canal por defecto es 1. Al cambiar de canal, salta 1-2 canales a la vez (por ejemplo, del canal 1 al 3 y, si es necesario, al 5).

      .. image:: img/faq_change_channel.jpg
         :width: 400

   #. Cuando aparezca el aviso "Reboot to take effect." en la parte superior de la página, haz clic en **REBOOT**. El Zeus Car ya está listo para funcionar con normalidad.

.. _update_firmware:

Cómo actualizar el firmware de la ESP32 CAM
--------------------------------------------

Sigue estos pasos detallados para actualizar el firmware de tu ESP32 CAM:

#. Mantén la ESP32 CAM insertada en el adaptador y enciende el Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Para activar la ESP32 CAM, cambia el interruptor de modo a **Run** y pulsa el botón **Reset** para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Descarga el archivo de firmware.

   * Abre `la última versión del firmware de la ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/latest>`_ — el número de versión del firmware actual aparece en la parte superior de la página.
   * En la lista **Assets**, descarga el archivo ``ai-camera-firmware.vX.X.X-ota.bin``. El archivo ``-factory.bin`` de esa misma lista sirve para grabar el módulo con un programador y no se utiliza en esta actualización.

   .. image:: img/faq_firm_download.png
      :width: 600

#. Conecta tu dispositivo móvil a la red Wi-Fi del Zeus Car.

   * El nombre de la red (SSID) es ``Zeus_Car-XXXXXX``, donde ``XXXXXX`` son los últimos seis caracteres de la dirección MAC del ESP32 CAM, y la contraseña es ``12345678``.
   * Si aparece el aviso "Sin acceso a Internet", elige la opción **"Mantener la conexión"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Abre un navegador web en tu dispositivo móvil y ve a ``http://192.168.4.1`` para abrir la página de ajustes de la ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: En esta página verás las opciones de actualización OTA en una de dos interfaces. La Versión A (la primera) y la Versión B (la segunda) aparecen según la versión de firmware. Sigue los pasos que correspondan a la interfaz que veas.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Versión A** (firmware 1.4.x)

   6. En la página OTA, selecciona el archivo de firmware e inicia la actualización:

      * Elige el archivo ``ai-camera-firmware.vX.X.X-ota.bin`` que descargaste antes y haz clic en **Add**.
      * Haz clic en el botón **Update** para iniciar la actualización y espera a que termine.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Cuando termine la actualización, el punto de acceso del Zeus Car pasará a llamarse ``AI Camera-XXXXXX`` y la contraseña seguirá siendo ``12345678``. Pulsa el botón **Reset** de la placa R3 para que el coche vuelva a registrar su nombre; entonces el punto de acceso será de nuevo ``Zeus_Car-XXXXXX``.

**Versión B** (firmware 1.5.x y posteriores)

   6. En la página **OTA**, comprueba la versión de firmware actual que se muestra.

      .. image:: img/faq_upgrade.jpg
         :width: 400
         :align: center

   #. Toca **Upgrade Firmware**, selecciona el archivo de firmware y espera a que termine la actualización:

      * Toca el botón **Upgrade Firmware** y elige el archivo ``ai-camera-firmware.vX.X.X-ota.bin`` que descargaste antes.
      * La actualización comienza de inmediato y suele tardar 1-2 minutos. Cuando termine, selecciona **CONFIRM** para reiniciar el Zeus Car.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Cuando termine la actualización, el punto de acceso del Zeus Car pasará a llamarse ``AI Camera-XXXXXX`` y la contraseña seguirá siendo ``12345678``. Pulsa el botón **Reset** de la placa R3 para que el coche vuelva a registrar su nombre; entonces el punto de acceso será de nuevo ``Zeus_Car-XXXXXX``.

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

Si prefieres controlar el coche con tu red Wi-Fi doméstica, puedes hacer que la ESP32 CAM se una a tu red. La cámara sigue funcionando en modo dual AP + STA, así que el punto de acceso del Zeus Car seguirá disponible:

#. Enciende el Zeus Car. Para activar la ESP32 CAM, cambia el interruptor de modo a **Run** y pulsa el botón **Reset** para reiniciar la placa R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Conecta tu dispositivo móvil a la red Wi-Fi del Zeus Car.

   * El nombre de la red (SSID) es ``Zeus_Car-XXXXXX``, donde ``XXXXXX`` son los últimos seis caracteres de la dirección MAC del ESP32 CAM, y la contraseña es ``12345678``.
   * Si aparece el aviso "Sin acceso a Internet", elige la opción **"Mantener la conexión"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Abre un navegador web en tu dispositivo móvil y ve a ``http://192.168.4.1`` para abrir la página de ajustes de la ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

#. Haz clic en **WIFI** en el menú lateral (o toca la pestaña **WIFI** en la parte inferior de la pantalla) e introduce el nombre y la contraseña de tu red Wi-Fi doméstica.

   * Escribe el nombre de tu Wi-Fi doméstico en **STA SSID** — también puedes elegirlo de la lista escaneada — y su contraseña en **STA password**.
   * Toca **CONFIRM** para guardar los ajustes. Cuando se hayan almacenado, la página mostrará "Success, Restart to apply.".
   * Después de reiniciar, la página **Base** muestra en **IP Address** la dirección IP que tu router ha asignado a la cámara.

   .. image:: img/faq_set_sta.jpg
      :width: 400

#. Reinicia la ESP32 CAM: haz clic en **Reboot** en la página o pulsa el botón **Reset** de la placa R3. La ESP32 CAM se conecta ahora a tu Wi-Fi doméstico y mantiene al mismo tiempo el punto de acceso del Zeus Car.

   .. note::

      Con el firmware de la ESP32 CAM **1.5.4** y posteriores, la cámara funciona en modo dual AP + STA y el comando serie ``MODE`` se ignora. Por eso, cambiar ``WIFI_MODE``, ``SSID`` y ``PASSWORD`` en el sketch de la R3 ya no cambia la cámara al modo STA — configura el Wi-Fi doméstico como se describe arriba.

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

También puedes invertir la cámara desde la página de ajustes de la ESP32 CAM: conecta tu dispositivo móvil a la red Wi-Fi del Zeus Car, abre ``http://192.168.4.1`` y activa **Horizontal flip** o **Vertical flip** en la página **Camera**.

.. image:: img/faq_camera.jpg
     :width: 400

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

#. Conecta tu dispositivo móvil a la misma red Wi-Fi doméstica.
#. Busca ``google`` en Google Play, encuentra la aplicación mostrada a continuación e instálala.

    .. image:: img/google_voice.png

#. Conecta tu dispositivo móvil a la misma red Wi-Fi doméstica.

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
