.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _play_remote_control:

Fernsteuerung
==========================

Das Zeus-Auto kann mit einer Fernbedienung gesteuert werden, indem man das Auto einschaltet und dann direkt die Tasten der Fernbedienung drückt. Diese Methode ist stabil und weniger anfällig für äußere Störungen, bietet jedoch möglicherweise nicht so flexible Steuerungsmöglichkeiten.

Kurzanleitung
--------------------

Hier ist ein kurzes Tutorial-Video. Bitte sehen Sie sich zuerst das Video an und folgen Sie dann den untenstehenden Anweisungen.

.. raw:: html

   <video loop controls style = "max-width:90%">
      <source src="../_static/video/ir_control_quick_guide.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

#. Beginnen wir mit dem Zeus Car.

    * Bei der ersten Verwendung oder wenn das Batteriekabel ausgesteckt wird, wird die Überentladungsschutzschaltung des Zeus Car Shield aktiviert.
    * Daher müssen Sie das Type-C-Kabel für ungefähr 5 Sekunden einstecken.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/activate_battery.mp4"  type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>
        </div>

    .. raw:: html
        
        <br/>

    
    * Wenn die Stromanzeige leuchtet, bedeutet dies, dass der Schutzstatus aufgehoben wurde. Schauen Sie zu diesem Zeitpunkt auf die Batterieanzeigen. Wenn beide Batterieanzeigen ausgeschaltet sind, stecken Sie das Type-C-Kabel weiterhin ein, um die Batterie zu laden.

    .. image:: img/zeus_power.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Nun müssen Sie den kleineren Schalter nach rechts kippen, um die Kommunikation zwischen dem Auto und der ESP32 CAM herzustellen. Drücken Sie anschließend die Reset-Taste, um den Code neu zu starten. Zu diesem Zeitpunkt werden Sie beobachten, wie die Unterbodenleuchten von Orange zu einem hellen Blau wechseln.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/re_run_code.mp4"  type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>
        </div>

    .. raw:: html
        
        <br/>


#. Drücken Sie die verschiedenen Tasten auf der Fernbedienung, um das Auto zu steuern.

    .. image:: img/remote_control.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>


    * **Stop**: Stoppen Sie alle Bewegungen des Autos.
    * :ref:`ir_compass_cali`: Kompasskalibrierung aktivieren.
    * :ref:`ir_line_track`: Wechseln zum Linienverfolgungsmodus.
    * :ref:`ir_follow`: Wechseln zum Verfolgungsmodus.
    * :ref:`ir_avoid`: Wechseln zum Hindernisvermeidungsmodus.
    * :ref:`drift`: Nach links/rechts driften.
    * **Set Heading**: Nachdem Sie das Auto mit der Hand in eine Richtung gestellt haben, klicken Sie auf diese Taste, um diese Richtung als Vorderseite der Autobewegung festzulegen. Dies ermöglicht es Ihnen, schnell eine Richtung anzugeben, anstatt das Auto langsam mit anderen Tasten in diese Richtung zu drehen.
    * :ref:`rotate_left/right`: Nach links/rechts drehen
    * :ref:`ir_move`: Steuern Sie das Auto in alle Richtungen.
    * **Pause**: Die Funktion ähnelt Stopp, aber wenn das vordere Ende des Autos nicht in die ursprünglich festgelegte Richtung zeigt, wird es langsam in die festgelegte Richtung bewegt.

.. _ir_compass_cali:

Compass Calibration
-----------------------------------

Schalten Sie die Kompasskalibrierung durch Drücken der |ir_mute|-Taste ein.

Stellen Sie das Zeus-Auto auf den Boden. Nach dem Aktivieren der Kompasskalibrierung beginnt das Auto, sich gegen den Uhrzeigersinn zu drehen und stoppt nach ungefähr einer Minute. Wenn es länger als 2 Minuten rotiert, ist das Magnetfeld hier komplex. Versuchen Sie, den Standort zu wechseln und erneut zu kalibrieren.


.. _ir_line_track:

Line Track
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Ihre Browser unterstützt das Videotag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Drücken Sie die |ir_play|-Taste, um in den Linienverfolgungsmodus zu wechseln.

Es gibt zwei Linienverfolgungsmodi im Zeus-Auto: Ein Modus, bei dem der Kopf immer in Bewegungsrichtung zeigt, und ein Modus, bei dem der Kopf in eine feste Richtung zeigt. Hier ist der zweite Modus ausgewählt.

Bevor Sie die Linienverfolgung starten können, müssen Sie das Omni-Graustufenmodul kalibrieren und die Linie befestigen:

#. Kleben Sie eine 3 cm breite Linie:

    Es gibt acht Sensoren am Omni-Graustufenmodul und der Abstand zwischen den Sensoren liegt zwischen 2 und 3 cm. Es müssen zwei Sensoren gleichzeitig die schwarze Linie erkennen. Daher muss die angebrachte Linie mindestens 3 cm breit sein und der Biege winkel darf nicht weniger als 90° betragen.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

#. Kalibrieren Sie das Omni-Graustufenmodul:

    Da jeder Unterboden unterschiedliche Graustufenwerte aufweist, ist der werkseitig eingestellte Graustufenschwellenwert möglicherweise nicht für Ihre aktuelle Umgebung geeignet. Daher müssen Sie dieses Modul vor der Verwendung kalibrieren. Es wird empfohlen, dies jedes Mal zu tun, wenn sich die Bodenfarbe stark ändert.

    * Stellen Sie das Zeus-Auto auf eine weiße Fläche und drehen Sie das Potentiometer, bis das Licht des Grausensors gerade leuchtet.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Positionieren Sie jetzt die beiden Grausensoren so, dass sie genau zwischen der schwarzen Linie und der weißen Oberfläche liegen, und drehen Sie das Potentiometer langsam, bis die Signalanzeige gerade erlischt.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Bewegen Sie das Auto mehrfach über die schwarze Linie und die weiße Fläche, um sicherzustellen, dass die Lichter des Grausensors aus sind, wenn sie zwischen der schwarzen Linie und der weißen Fläche liegen, und eingeschaltet sind, wenn sie auf der weißen Fläche liegen. Dies zeigt an, dass das Modul erfolgreich kalibriert wurde.

#. Platzieren Sie das Zeus-Auto auf Ihrer markierten Linie, drücken Sie die |ir_play|-Taste, und es wird der Linie folgen.

#. Aufgrund der hohen Umgebungsanforderungen des Omni-Graustufenmoduls wird empfohlen, es mehrmals zu kalibrieren, falls der Verfolgungseffekt nicht zufriedenstellend ist (Abweichungen).


.. _ir_follow:

Follow
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Ihre Browser unterstützt das Videotag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Drücken Sie die |ir_backward|-Taste, um in den Folgemodus zu wechseln.

Der Ultraschallsensor erkennt Hindernisse vorne (20 cm) und folgt ihnen. Die zwei Hindernisvermeidungsmodule ermöglichen es dem Auto, nach links oder rechts zu folgen. Sie müssen jedoch vor der Verwendung kalibriert werden (15 cm).

#. Kalibrieren Sie das IR-Hindernisvermeidungsmodul:

    * Beginnen Sie mit der Einstellung des rechten Hindernisvermeidungsmoduls. Während des Transports können Kollisionen dazu führen, dass der Sender und Empfänger im Infrarotmodul kippen. Daher müssen Sie sie manuell begradigen.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Ihr Browser unterstützt das Video-Tag nicht.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Platzieren Sie ein Hindernis etwa 15 cm vom IR-Hindernisvermeidungsmodul entfernt.
    * Am Modul befinden sich zwei Potentiometer: eines zur Einstellung der Sendeleistung und eines zur Einstellung der Sendefrequenz. Durch Anpassen dieser beiden Potentiometer können Sie die Erkennungsentfernung einstellen.
    * Dann können Sie ein Potentiometer einstellen, und wenn bei 15 cm das Signallämpchen am Modul leuchtet, ist die Einstellung erfolgreich. Wenn nicht, stellen Sie das andere Potentiometer ein.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Kalibrieren Sie das andere Hindernisvermeidungsmodul auf die gleiche Weise.

#. Stellen Sie das Zeus-Auto auf einen Tisch oder den Boden und lassen Sie es Ihrer Hand oder anderen Hindernissen folgen.

.. _ir_avoid:

Obstacle Avoidance
--------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Ihre Browser unterstützt das Videotag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Wenn Sie in den Hindernisvermeidungsmodus wechseln möchten, drücken Sie die |ir_forward|-Taste. Konsultieren Sie zuerst den Abschnitt :ref:`ir_follow`, um die beiden Hindernisvermeidungsmodule zu kalibrieren.

* Das Zeus-Auto wird sich vorwärts bewegen.
* Ein Ultraschallmodul erkennt Hindernisse vorne. Bei Erkennung dreht sich das Auto nach links.
* Wenn das linke Hindernisvermeidungsmodul ein Hindernis erkennt, dreht sich das Auto nach rechts und bei Erkennung durch das rechte Modul nach links.

.. _drift:

Drift Left/Right
-------------------------------------------------

Verwenden Sie die Tasten |ir_minus| und |ir_plus|, um das Auto nach links/rechts driften zu lassen.

* Bei Betätigung der |ir_minus|-Taste driftet das Auto nach links.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Bei Betätigung der |ir_plus|-Taste driftet das Auto nach rechts.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Wenn das Auto vor dem Driften gestoppt wurde, bewirkt ein einmaliges Drücken von |ir_minus| oder |ir_plus| einen 90°-Drift des Zeus nach links oder rechts.
* Wenn das Auto vor dem Driften in Bewegung war, driftet es nach Betätigung der Taste 90° nach links oder rechts und fährt dann weiter, bis eine andere Taste gedrückt wird.

.. _ir_move:

Move in All Directions(1 ~ 9)
-------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Videotag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Verwenden Sie die Zahlentasten 1~9, um das Zeus Auto in 8 Richtungen zu steuern.

.. image:: img/remote_control_move.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

.. _rotate_left/right:

Rotate Left/Right(Cycle/USD Key)
-----------------------------------------

* Wenn Sie die |ir_return|-Taste einmal drücken, dreht sich das Auto mit dem Körper als Zentrum um 45° nach links. Abhängig vom vorherigen Zustand wird es vorwärts fahren oder stoppen. Wenn es zuvor gestoppt wurde, wird es nach einer 45°-Linksdrehung anhalten; wenn es vorwärts gefahren ist, wird es nach der Linksdrehung weiterfahren.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Ebenso wird das Auto durch einmaliges Drücken von |ir_usd| um 45° nach rechts drehen und dann je nach vorherigem Zustand vorwärts fahren oder stoppen.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>
