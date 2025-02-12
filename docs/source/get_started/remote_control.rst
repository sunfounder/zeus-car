.. note::

    ¡Hola! Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Únete a nosotros y sumérgete en el fascinante mundo de Raspberry Pi, Arduino y ESP32 junto con otros apasionados.

    **Why Join?**

    - **Expert Support**: Resuelve problemas postventa y supera desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Learn & Share**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Exclusive Previews**: Sé el primero en conocer los anuncios de nuevos productos y obtener adelantos exclusivos.
    - **Special Discounts**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Festive Promotions and Giveaways**: Participa en sorteos y promociones especiales durante las festividades.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _play_remote_control:

Control con el mando a distancia
===================================

El Zeus Car puede ser controlado mediante el mando a distancia simplemente encendiéndolo y presionando los botones correspondientes en el control. Este método es estable y menos susceptible a interferencias externas, aunque la precisión y flexibilidad del control pueden ser limitadas.

Guía rápida
--------------------

Este es un video tutorial rápido. Te recomendamos verlo primero y luego seguir las instrucciones detalladas a continuación.

.. raw:: html

   <video loop controls style = "max-width:90%">
      <source src="../_static/video/ir_control_quick_guide.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

#. Enciende el Zeus Car.

    * Cuando se usa por primera vez o si el cable de la batería se ha desconectado, el Zeus Car Shield activará su circuito de protección contra sobredescarga.
    * Para desactivar esta protección, conecta el cable Type-C durante aproximadamente 5 segundos.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/activate_battery.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>


    * Si el indicador de encendido se ilumina, significa que la protección ha sido desactivada. Luego, revisa los indicadores de batería: si ambos están apagados, continúa cargando la batería con el cable Type-C.

    .. image:: img/zeus_power.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Ahora, cambia el interruptor pequeño hacia la derecha para establecer comunicación entre el coche y la ESP32-CAM. Luego, presiona el botón **Reset** para reiniciar el código. En este punto, notarás que las luces del chasis cambiarán de color naranja a azul claro.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/re_run_code.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>

#. Presiona los diferentes botones del mando a distancia para controlar el coche.

    .. image:: img/remote_control.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * **Stop**: Detiene todos los movimientos del coche.
    * :ref:`ir_compass_cali`: Activa la calibración de la brújula.
    * :ref:`ir_line_track`: Cambia al modo de seguimiento de línea.
    * :ref:`ir_follow`: Cambia al modo de seguimiento de objetos.
    * :ref:`ir_avoid`: Cambia al modo de evasión de obstáculos.
    * :ref:`drift`: Realiza un derrape hacia la izquierda o derecha.
    * **Set Heading**: Una vez que hayas colocado el coche en la dirección deseada, presiona este botón para establecer esa dirección como la referencia principal del movimiento. Esto facilita la orientación sin necesidad de girar lentamente con otras teclas.
    * :ref:`rotate_left/right`: Gira a la izquierda o a la derecha.
    * :ref:`ir_move`: Controla el coche en todas las direcciones.
    * **Pause**: Su función es similar a Stop, pero si el coche no está alineado con la dirección previamente establecida, se moverá lentamente hasta ajustarse a la dirección configurada.

.. _ir_compass_cali:

Calibración de la brújula 
-----------------------------------

Activa la calibración de la brújula presionando la tecla |ir_mute|.

Coloca el Zeus Car sobre una superficie plana. Una vez activada la calibración, el coche comenzará a girar en sentido antihorario y se detendrá en aproximadamente un minuto. Si el giro dura más de dos minutos, el campo magnético en esa zona puede ser complejo. Intenta cambiar la ubicación y realizar la calibración nuevamente.


.. _ir_line_track:

Seguimiento de línea
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Presiona la tecla |ir_play| para cambiar al modo de seguimiento de línea.

El Zeus Car cuenta con dos modos de seguimiento de línea: uno en el que siempre apunta en la dirección del movimiento y otro en el que mantiene una dirección fija. En este caso, se ha seleccionado el segundo modo.

Antes de activar el seguimiento de línea, es necesario calibrar el módulo Omni Grayscale y colocar la línea de referencia, siguiendo estos pasos:

#. Dibuja o coloca una línea de 3 cm de ancho

    El módulo Omni Grayscale cuenta con ocho sensores, separados entre sí por una distancia de entre 2 y 3 cm. Para una detección óptima, al menos dos sensores deben detectar la línea negra al mismo tiempo. Por ello, la línea debe tener al menos 3 cm de ancho y los ángulos de las curvas no deben ser inferiores a 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

#. Calibra el módulo Omni Grayscale

    Dado que cada superficie tiene diferentes valores de escala de grises, el umbral predeterminado de fábrica puede no ser el adecuado para tu entorno. Se recomienda calibrarlo cada vez que el color del suelo cambie significativamente.

    * Coloca el Zeus Car sobre una superficie blanca y ajusta el potenciómetro hasta que el sensor de escala de grises se ilumine.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Luego, coloca los sensores laterales justo en el límite entre la línea negra y la superficie blanca. Ajusta lentamente el potenciómetro hasta que el indicador de señal se apague.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Prueba moviendo el coche sobre la línea negra y la superficie blanca para confirmar que los sensores están calibrados correctamente: deben apagarse al estar en el borde entre ambos colores y encenderse cuando estén completamente sobre la superficie blanca.

#. Coloca el Zeus Car sobre la línea trazada, presiona la tecla |ir_play| y comenzará a seguirla.

#. Debido a la sensibilidad del módulo Omni Grayscale a las condiciones ambientales, si el seguimiento de línea no es preciso, repite la calibración varias veces para mejorar su desempeño.


.. _ir_follow:

Modo de seguimiento
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


Presiona la tecla |ir_backward| para cambiar al modo de seguimiento.

El sensor ultrasónico detecta obstáculos en un rango de 20 cm y sigue su movimiento hacia adelante. Los módulos de evasión de obstáculos permiten que el coche siga objetos a la izquierda o derecha, pero deben calibrarse (a una distancia de 15 cm) antes de su uso.

#. Calibra el módulo de evasión de obstáculos por infrarrojos.

    * Primero, ajusta el módulo derecho. Durante el transporte, los golpes pueden desalinear el emisor y el receptor del sensor infrarrojo, por lo que es posible que necesites enderezarlos manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Coloca un obstáculo a aproximadamente 15 cm del módulo de evasión de obstáculos por infrarrojos.
    * El módulo cuenta con dos potenciómetros: uno para ajustar la potencia de emisión y otro para la frecuencia de envío. Ajustándolos, puedes modificar la distancia de detección.
    * Ajusta uno de los potenciómetros hasta que, a una distancia de 15 cm, el indicador de señal del módulo se ilumine. Si no lo hace, prueba ajustando el otro potenciómetro.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Repite el mismo proceso para calibrar el otro módulo de evasión de obstáculos.

#. Coloca el Zeus Car sobre una mesa o en el suelo y deja que siga tu mano o cualquier otro objeto en movimiento.

.. _ir_avoid:

Evasión de obstáculos
--------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Para activar el modo de evasión de obstáculos, presiona la tecla |ir_forward|. Antes de hacerlo, consulta la sección :ref:`ir_follow` para calibrar los dos módulos de evasión de obstáculos.

* El Zeus Car avanzará en línea recta.
* Un módulo ultrasónico detectará obstáculos en la parte frontal; si detecta uno, el coche girará a la izquierda.
* Si el módulo de evasión de obstáculos izquierdo detecta un obstáculo, el coche girará a la derecha; si el módulo derecho detecta un obstáculo, el coche girará a la izquierda.

.. _drift:

Derrape a la izquierda/derecha
-------------------------------------------------

Usa las teclas |ir_minus| y |ir_plus| para hacer que el Zeus Car derrape hacia la izquierda o la derecha.

* Presiona la tecla |ir_minus| y el coche derrapará hacia la izquierda.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Presiona la tecla |ir_plus| y el coche derrapará hacia la derecha.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Si el coche estaba detenido antes de derrapar, al presionar |ir_minus| o |ir_plus| una vez, el Zeus Car girará 90° a la izquierda o a la derecha.
* Si el coche estaba en movimiento antes de derrapar, tras presionar la tecla, girará 90° en la dirección correspondiente y continuará deslizándose hasta que se presione otra tecla.

.. _ir_move:

Movimiento en todas las direcciones (1 ~ 9)
---------------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Utiliza las teclas numéricas del 1 al 9 para mover el Zeus Car en 8 direcciones diferentes.

.. image:: img/remote_control_move.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

.. _rotate_left/right:

Giro a la izquierda/derecha (Tecla Cycle/USD)
----------------------------------------------

* Al presionar la tecla |ir_return| una vez, el coche girará 45° a la izquierda tomando su propio eje como centro. Dependiendo de su estado previo, continuará avanzando o se detendrá. Si estaba detenido, se detendrá después de girar 45°; si estaba en movimiento, continuará avanzando tras el giro.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Del mismo modo, al presionar la tecla |ir_usd| una vez, el coche girará 45° a la derecha y luego seguirá avanzando o se detendrá según su estado previo.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

