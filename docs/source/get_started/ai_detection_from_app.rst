.. note:: 

    ¡Hola y bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Únete a otros apasionados para profundizar en Raspberry Pi, Arduino y ESP32.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos productos y adelantos especiales.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

16. Detección de IA desde la APP
===================================

En este proyecto, utilizaremos la aplicación SunFounder Controller para ver transmisión de video en tiempo real, así como para emplear las funciones de detección de IA en tu dispositivo móvil, como detección de rostro y postura.

SunFounder Controller es una aplicación que permite a los usuarios personalizar su controlador para manejar su robot o utilizarlo como una plataforma IoT. Esta aplicación integra 11 tipos de widgets para visualización y control, como botones, joysticks, indicadores y radares. La página del controlador tiene 17 áreas (de A a Q) en las que puedes colocar diferentes widgets para personalizar tu propio controlador.

Veamos ahora cómo utilizar la aplicación de manera sencilla.

**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de subir el código, primero debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``16_ai_detection_from_app.ino`` en la ruta ``zeus-car-main\examples\16_ai_detection_from_app``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/c14c46e7-2e43-4b31-b7e6-b7718e501e96/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya subido correctamente, puedes reconectar la ESP32-CAM y deslizar el interruptor de encendido a ON para iniciar la Zeus Car.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Cambia el Interruptor de carga al lado de Run (lado derecho en este diagrama) para activar la ESP32-CAM.

    .. image:: img/zeus_run.jpg

#. Presiona el botón de reinicio para que el programa en la placa Arduino vuelva a ejecutarse.

    .. image:: img/zeus_reset_button.jpg

#. Ahora, instala `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ desde la **APP Store (iOS)** o **Google Play (Android)** en tu dispositivo móvil.


#. Conéctate a la red ``Zeus_Car``.

    * Busca ``Zeus_Car`` en la lista de redes Wi-Fi de tu teléfono o tableta, ingresa la contraseña ``12345678`` y conéctate.

    .. image:: img/app_wlan.png

    * El modo de conexión predeterminado es el modo AP. Una vez conectado, aparecerá un mensaje indicando que no hay acceso a Internet en esta red. Selecciona la opción Permanecer conectado.

    .. image:: img/app_no_internet.png

#. Luego, abre la aplicación y crea un nuevo controlador.

    * Para agregar un nuevo controlador en SunFounder Controller, toca el ícono **"+"**.

        .. image:: img/app1.png

    * Selecciona la plantilla **Blank** o **Dual Stick**, y asígnale un nombre.

        .. image:: img/view_app1.jpg

    * Ahora que estás dentro del controlador, toca el ícono |app_camera| para habilitar la función de detección de IA. Aquí encontrarás opciones de detección de rostro y detección de postura.

        .. image:: img/view_app6.jpg

    * Guarda la configuración tocando el botón |app_save|. Como aún no se han seleccionado widgets, la pantalla aparecerá completamente negra.

        .. image:: img/view_app3.jpg

    * El siguiente paso es conectar la Zeus Car a tu dispositivo mediante el botón |app_connect|. Espera unos segundos y aparecerá la red ``Zeus_Car(IP)``, tócala para conectarte.

        .. image:: img/view_app4.jpg

        .. note::
            Si el mensaje anterior no aparece, asegúrate de que tu dispositivo esté conectado a la red ``Zeus_Car``.

#. Ejecutar el controlador.

    Una vez que aparezca el mensaje "Conectado exitosamente", toca el botón |app_run|. La imagen de la cámara se mostrará en la aplicación.

    Si activaste la detección de rostro, los rostros que aparezcan en pantalla serán detectados y enmarcados.

    .. image:: img/view_app7.jpg

    Si activaste la detección de postura, la aplicación detectará y marcará la postura de la persona en la imagen.

    .. image:: img/view_app8.jpg

    .. note::

        Si deseas cambiar entre diferentes opciones de detección de IA, toca el ícono |app_edit| y repite los pasos anteriores.
