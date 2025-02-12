.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Explora más a fondo Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _ar_app_control:

17. Control mediante APP
============================

En el proyecto anterior, solo visualizamos las imágenes capturadas por la cámara y utilizamos la función de detección de IA en la aplicación SunFounder Controller.

En este proyecto, intentaremos controlar el movimiento y la dirección del Zeus Car usando el widget de joystick en la aplicación. Veamos cómo funciona.


.. note::
    Instala `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ desde **APP Store (iOS)** o **Google Play (Android)**.


**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, cuando cargues código, primero debes desconectar la ESP32-CAM para evitar conflictos o posibles problemas.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Abre el archivo ``17_app_control.ino`` en la ruta ``zeus-car-main\examples\17_app_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, puedes volver a conectar la ESP32-CAM y mover el interruptor de encendido a la posición ON para iniciar el Zeus Car.

    .. image:: img/plug_esp32_cam.jpg

#. Cambia el interruptor de carga a la posición de ejecución (lado derecho en este diagrama) para iniciar la ESP32-CAM. 

    .. image:: img/zeus_run.jpg

#. Presiona el botón de reinicio para ejecutar nuevamente el programa en la placa Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Conéctate a la red WLAN ``Zeus_Car``.

    * Busca ``Zeus_Car`` en la red Wi-Fi del teléfono móvil (o tableta), introduce la contraseña ``12345678`` y conéctate.

    .. image:: img/app_wlan.png

    * El modo de conexión predeterminado es el modo AP. Una vez conectado, aparecerá un mensaje indicando que no hay acceso a Internet en esta red WLAN. Elige continuar con la conexión.

    .. image:: img/app_no_internet.png

#. Crea un controlador.

    * Para añadir un controlador en SunFounder Controller, haz clic en el icono **+**.

        .. image:: img/app1.png

    * En la sección de plantillas predefinidas, selecciona **Blank** y **Dual Stick**.

        .. image:: img/app_blank.PNG

   * Haz clic en el icono **+** en el área J y selecciona un widget de interruptor. Puede que necesites deslizar hacia la izquierda para verlo.

        .. image:: img/app_switch_wid.png

        .. note::
            Si crees que seleccionaste el widget equivocado, puedes hacer clic en él nuevamente y usar el botón de eliminación para eliminarlo.

            .. image:: img/app_delete.png

    * Haz clic en el icono de configuración en la parte superior derecha para asignarle un nombre.

        .. image:: img/app_name_dirft.png

    * Selecciona un widget de joystick en las áreas K y Q, asígnales un nombre a ambos y guarda el controlador con el botón |app_save|.

    .. image:: img/app_joystick_wid.png

    * Luego, conecta el Zeus Car a tu dispositivo a través del botón |app_connect|. Espera unos segundos y aparecerá ``Zeus_Car(IP)``, haz clic en él para conectarte.

        .. image:: img/app_connect.png

        .. note::
            Asegúrate de que tu Wi-Fi esté conectado a ``Zeus_Car`` si no ves este mensaje después de un tiempo.


#. Ejecuta el controlador.

    Una vez que aparezca el mensaje "Conectado con éxito", haz clic en el botón |app_run| para ver la transmisión en vivo de la cámara en la aplicación. Ahora podrás controlar tu Zeus Car con los widgets.

    Las funciones de los tres widgets son las siguientes:


    **Mover en todas las direcciones (K)**

    El Zeus Car se moverá en la dirección correspondiente cuando deslices el widget |app_move_k|.

    .. image:: img/joystick_move.png
        :align: center

    El coche se mueve con cada deslizamiento. Si no sueltas el joystick, el coche continuará en movimiento.

    .. image:: img/zeus_move.jpg


    **Habilitar derrape (J)**

    Haz clic en el botón |app_drift_j| para habilitar la función de derrape.

    * Si deslizas el widget |app_rotate_q| en sentido antihorario, el Zeus Car derrapará hacia la derecha. Al soltar el joystick, el coche se detendrá en su posición actual.

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * De manera similar, si deslizas el widget |app_rotate_q| en sentido horario, el Zeus Car derrapará hacia la izquierda y se detendrá en su posición actual.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


    **Control de dirección (Q)**

    * Cuando el botón |app_drift_j| está activado, el widget |app_rotate_q| se usa para hacer que el Zeus Car derrape a la izquierda o a la derecha.

    * Cuando el widget |app_drift_j| está desactivado, el widget |app_rotate_q| se usa para controlar la dirección del coche.

        * Si deslizas el widget |app_rotate_q| en sentido antihorario, el coche girará en esa dirección. Al soltarlo, volverá a su dirección original.

        .. image:: img/zeus_turn_left.jpg
            :width: 600
            :align: center

        * De la misma manera, si deslizas el widget |app_rotate_q| en sentido horario, el coche girará en esa dirección y regresará a su posición original al soltarlo.

        .. image:: img/zeus_turn_right.jpg
            :width: 600
            :align: center

