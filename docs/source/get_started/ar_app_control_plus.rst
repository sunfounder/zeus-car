.. note:: 

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Acceso exclusivo**: Sé el primero en conocer nuevos productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.


.. _ar_app_control_plus:

18. Control por APP Plus
=============================

Este proyecto integra las funciones de Seguimiento de Línea, Seguimiento de Objetos y Evitación de Obstáculos basadas en :ref:`ar_app_control`.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/app_control.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>

.. note::
    Por favor, instala `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ desde **APP Store(iOS)** o **Google Play(Android)**.


**¿Cómo hacerlo?**

#. La ESP32-CAM y la placa Arduino comparten los mismos pines RX (recepción) y TX (transmisión). Por lo tanto, antes de subir el código, desconecta la ESP32-CAM para evitar conflictos o problemas de comunicación.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Abre el archivo ``18_app_control_plus.ino`` en la ruta ``zeus-car-main\examples\18_app_control_plus``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b67e7245-369b-4218-b12c-d73f95ac3b22/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Una vez que el código se haya cargado correctamente, vuelve a conectar la ESP32-CAM y desliza el interruptor de encendido a la posición ON para iniciar el Zeus Car.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center
        
#. Cambia el interruptor de carga a la posición de ejecución (lado derecho en este diagrama) para activar la ESP32-CAM.

    .. image:: img/zeus_run.jpg

#. Presiona el botón de reinicio para que el programa en la placa Arduino comience a ejecutarse.

    .. image:: img/zeus_reset_button.jpg

#. Conéctate a la red WLAN de ``Zeus_Car``.

    Ahora, conecta tu dispositivo móvil a la red LAN (Local Area Network) generada por el Zeus Car. De esta manera, tu dispositivo y el Zeus Car estarán en la misma red, facilitando la comunicación entre ambos.

    * Busca ``Zeus_Car`` en la lista de redes Wi-Fi en tu dispositivo móvil (tablet o smartphone), introduce la contraseña ``12345678`` y conéctate.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/connect_wifi.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>

    * El modo de conexión predeterminado es el modo AP. Una vez conectado, aparecerá un mensaje indicando que no hay acceso a Internet en esta red WLAN. Por favor, selecciona la opción de continuar conectado.

    .. image:: img/app_no_internet.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Crea un controlador.

    * Para agregar un controlador en SunFounder Controller, toca el icono **+**.

    .. image:: img/app1.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
        
    * Algunos productos tienen controladores preconfigurados. En este caso, selecciona **Zeus Car**, asígnale un nombre o simplemente toca **Confirm**.

    .. image:: img/app_preset.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Una vez dentro, la aplicación buscará automáticamente el Zeus Car. En pocos segundos, aparecerá un mensaje indicando "Conexión exitosa."

    .. image:: img/app_edit.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/> 

    * Ahora, toca el botón |app_run| para ver la transmisión en vivo desde la cámara y controlar el coche mediante los widgets disponibles. 
    
    .. image:: img/app_run123.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Funciones de los widgets disponibles:

    * :ref:`app_compass_cali`: Activar la calibración de la brújula.
    * **Stop(F)**: Detiene todos los movimientos del coche.
    * **Reset Heading(G)**: Una vez colocado el coche en una dirección con la mano, toca este widget para establecer esta dirección como la referencia de movimiento. Esto permite fijar la orientación sin necesidad de girar el coche manualmente.
    * :ref:`app_speech_control`: Activar el modo de control por voz.
    * :ref:`app_drift`: Activar la función de derrape.
    * :ref:`app_move`: Controlar el movimiento del coche en todas las direcciones.
        
    * :ref:`app_line_track`: Los siguientes dos widgets permiten cambiar al modo de seguimiento de línea:

        * **Line no Mag(M)**: Activa el modo de seguimiento de línea sin verse afectado por el campo magnético. En este modo, la orientación del Zeus Car cambiará constantemente durante el seguimiento.
        * **Line(N)**: Activa el modo de seguimiento de línea teniendo en cuenta el campo magnético. En este modo, la orientación del Zeus Car se mantendrá en una dirección específica.

    * :ref:`app_follow`: Cambiar al modo de seguimiento de objetos.
    * :ref:`app_avoid`: Activar el modo de evitación de obstáculos.
    * :ref:`app_rotate_drift`: Controlar la orientación del coche.

.. _app_compass_cali:

Calibration(E) 
--------------------------

Activa la calibración de la brújula haciendo clic en el botón |app_cali_e|.

Coloca el Zeus Car en el suelo. Al activar la calibración de la brújula, el coche comenzará a girar en sentido antihorario y se detendrá aproximadamente en 1 minuto. Si gira por más de 2 minutos, significa que el campo magnético en esta ubicación es complejo. Intenta cambiar de ubicación y calibra nuevamente.


.. _app_drift:

Activar Derrape (J)
---------------------


Haz clic en el botón |app_drift_j| para habilitar la función de derrape.

* Si deslizas el widget |app_rotate_q| en sentido antihorario, verás que el Zeus Car derrapa hacia la derecha. Al soltarlo, el coche se detendrá en su posición actual.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
* De manera similar, si deslizas el widget |app_rotate_q| en sentido horario, el Zeus Car derrapará hacia la izquierda y se detendrá en la posición actual.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_move:

Movimiento en Todas las Direcciones (K)
------------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

El Zeus Car se moverá en la dirección correspondiente cuando deslices el widget |app_move_k|.

.. image:: img/joystick_move.png
    :align: center

.. raw:: html
    
    <br/>  

El coche se mueve una vez cada vez que lo deslizas, por lo que si no sueltas el control, continuará en movimiento.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center


.. raw:: html
    
    <br/>  
 
.. _app_speech_control:


Control por Voz (I)
----------------------


Presionando el widget |app_speech_m| puedes activar la función STT (Speech to Text).

La aplicación SunFounder Controller se integra con el motor de reconocimiento de voz de tu dispositivo móvil. Al mantener presionado el widget **Speech(I)** y hablar en el micrófono de tu dispositivo, este capturará tu voz, la convertirá en texto y enviará el comando al Zeus Car. Si el texto coincide con los comandos preestablecidos en el código, el coche ejecutará la acción correspondiente.

Los siguientes son los comandos preconfigurados en el código. Di cualquiera de ellos y observa cómo responde el Zeus Car:


* ``stop``: Detiene todos los movimientos del coche.
* ``pasue``: Similar a "stop", pero si la orientación del coche no es la original, girará lentamente hasta ajustarse a la dirección establecida.
* ``forward``  
* ``backward``  
* ``left forward``  
* ``left backward``  
* ``right forward``  
* ``right backward``  
* ``move left``  
* ``move right``  

.. note::

    La función STT (Speech to Text) requiere conexión a Internet y los servicios de Google en dispositivos Android. Sin embargo, esto no funciona en el modo AP (Access Point) predeterminado del Zeus Car.

    En el modo AP, el Zeus Car crea una red Wi-Fi local a la que tu dispositivo móvil puede conectarse, pero no proporciona acceso a Internet.

    Para utilizar la función STT en Android, cambia el código del coche de modo AP a STA según las instrucciones en :ref:`stt_android`.

.. note::

    Los dispositivos iOS, que utilizan un motor de reconocimiento de voz sin conexión, funcionan correctamente tanto en modo AP como STA.

Después de recibir cualquiera de los 8 comandos mencionados, el coche continuará moviéndose en la dirección indicada hasta recibir la orden ``stop`` o ``pasue``.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center

* ``turn left``: Este comando hará que el coche gire 45° a la izquierda con el cuerpo como punto de rotación. Luego, avanzará o se detendrá dependiendo del estado anterior. Si estaba detenido, se detendrá después de girar; si estaba avanzando, continuará avanzando después del giro.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
* ``turn right``: Este comando hará que el coche gire 45° a la derecha con el cuerpo como punto de rotación. Luego, avanzará o se detendrá según el estado previo.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_line_track:

Seguimiento de Línea 
------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


Haz clic en el widget |app_line_n| para cambiar al modo de seguimiento de línea.

El Zeus Car ofrece dos modos de seguimiento de línea: uno en el que la parte frontal del coche siempre apunta en la dirección del movimiento y otro en el que la parte frontal permanece fija en una dirección específica. En este caso, se selecciona el segundo modo.


#. Pega una línea de 3 cm de ancho

    El módulo Omni Grayscale cuenta con ocho sensores, con una distancia de entre 2 y 3 cm entre cada uno. Para una detección óptima, al menos dos sensores deben detectar la línea negra simultáneamente. Por lo tanto, la línea que coloques debe tener un ancho mínimo de 3 cm y los ángulos de las curvas no deben ser inferiores a 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
#. Calibra el módulo Omni Grayscale.

    Debido a que cada superficie puede tener diferentes valores de escala de grises, el umbral de fábrica podría no ser adecuado para tu entorno actual, por lo que es necesario calibrar el módulo antes de su uso. Se recomienda recalibrarlo si el color del suelo cambia significativamente.

    * Coloca el Zeus Car sobre una superficie blanca y ajusta el potenciómetro hasta que la luz del sensor de escala de grises se ilumine justo en el punto adecuado.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center
    
    
    .. raw:: html
        
        <br/>  

    * Luego, posiciona los dos sensores de escala de grises de los lados justo entre la línea negra y la superficie blanca. Gira el potenciómetro lentamente hasta que el indicador de señal se apague.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Puedes desplazar repetidamente el coche sobre la línea negra y la superficie blanca para asegurarte de que las luces del sensor de escala de grises se apaguen cuando estén sobre la línea negra y blanca y se enciendan cuando estén sobre la superficie blanca, lo que indicará que la calibración fue exitosa.


#. Coloca el Zeus Car sobre la línea que pegaste, haz clic en el widget |app_line_n| y el coche seguirá la línea.

#. Debido a la sensibilidad ambiental del módulo Omni Grayscale, si el seguimiento no es preciso o se desvía del recorrido, se recomienda repetir la calibración varias veces hasta obtener mejores resultados.

.. _app_follow:

Modo de Seguimiento (O)
-------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Haz clic en el widget |app_follow_o| para cambiar al modo de seguimiento.

El sensor ultrasónico detecta obstáculos a una distancia de hasta 20 cm y sigue su movimiento. Además, los dos módulos de evitación de obstáculos permiten al coche ajustar su dirección hacia la izquierda o derecha. Para un funcionamiento óptimo, estos módulos deben ser calibrados a una distancia de 15 cm antes de su uso.

#. Calibra el módulo de evitación de obstáculos por infrarrojos.

    * Comienza ajustando el módulo de evitación de obstáculos derecho. Durante el transporte, es posible que los transmisores y receptores del módulo infrarrojo se inclinen debido a impactos, por lo que es necesario enderezarlos manualmente.

        .. raw:: html

            <video loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>

        .. raw:: html
            
            <br/> <br/>  

    * Coloca un obstáculo aproximadamente a 15 cm de distancia del módulo de evitación de obstáculos por infrarrojos.
    * El módulo tiene dos potenciómetros: uno para ajustar la potencia de emisión y otro para ajustar la frecuencia de emisión. Mediante estos ajustes, puedes modificar la distancia de detección.
    * Ajusta un potenciómetro y verifica si la luz de señal del módulo se enciende a los 15 cm. Si se ilumina, el ajuste ha sido exitoso; si no, ajusta el otro potenciómetro.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 400
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Repite el mismo proceso para calibrar el otro módulo de evitación de obstáculos.

#. Coloca el Zeus Car sobre una mesa o el suelo y deja que siga tu mano o cualquier otro objeto en movimiento.

.. _app_avoid:

Evitar (P) 
------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Cuando quieras activar el modo de evitación de obstáculos, haz clic en el widget |app_avoid_p|, pero antes consulta la referencia :ref:`app_follow` para calibrar los dos módulos de evitación de obstáculos.

* Zeus Car avanzará en línea recta.
* Un módulo ultrasónico detecta obstáculos al frente; si se detecta uno, el coche girará a la izquierda.
* Cuando el módulo de evitación de obstáculos izquierdo detecta un obstáculo, el coche girará a la derecha, y cuando el módulo derecho detecte un obstáculo, el coche girará a la izquierda.



.. _app_rotate_drift:

Control de Dirección (Q)
-------------------------------

* Cuando el botón |app_drift_j| está activado, el widget |app_rotate_q| se usa para hacer que el Zeus Car derrape hacia la izquierda o la derecha.

* Cuando el widget |app_drift_j| está desactivado, el widget |app_rotate_q| se utiliza para controlar la dirección de la parte frontal del coche.

    * Al deslizar el widget |app_rotate_q| en sentido antihorario, el coche girará también en sentido antihorario. Al soltarlo, la parte frontal del coche volverá a su dirección original.

    .. image:: img/zeus_turn_left.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>     

    * De manera similar, si deslizas el widget |app_rotate_q| en sentido horario, el coche girará en esa dirección y regresará a su posición original al soltarlo.

    .. image:: img/zeus_turn_right.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  