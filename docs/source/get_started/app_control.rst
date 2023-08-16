.. _play_app_control:

Mit der APP steuern
=========================

Um das Zeus Car über Ihr Mobilgerät zu steuern, müssen Sie die SunFounder Controller APP herunterladen, sich mit dem Zeus Car LAN verbinden und dann Ihren eigenen Controller in der APP erstellen.

.. raw:: html

   <video loop autoplay muted style="max-width:80%">
      <source src="../_static/video/app_control.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>

Schnellanleitung
---------------------

Schauen Sie sich zuerst dieses kurze Anleitungsvideo an und folgen Sie dann den unten angegebenen Anweisungen.

.. raw:: html

   <video loop controls style="max-width:90%">
      <source src="../_static/video/app_control_quick_guide.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>

#. Laden Sie `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)** herunter.

#. Starten Sie das Zeus Car.

    * Bei der ersten Nutzung oder wenn das Batteriekabel getrennt wird, aktiviert das Zeus Car Shield seinen Tiefentladeschutz.
    * Daher sollten Sie das Type-C Kabel für ca. 5 Sekunden anschließen.

    .. image:: img/zeus_charge.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Wenn die Stromanzeige leuchtet, bedeutet dies, dass der Schutzstatus aufgehoben wurde. Schauen Sie nun auf die Batterieanzeigen. Wenn beide Batterieanzeigen aus sind, stecken Sie das Type-C Kabel weiterhin ein, um die Batterie zu laden.

    .. image:: img/zeus_power.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Zu diesem Zeitpunkt startet das Zeus Car normal und der RGB LED Streifen unter dem Auto leuchtet cyanfarben.

    .. image:: img/zeus_car.jpg
        :width: 500
        :align: center
    
    .. raw:: html
        
        <br/>  
    
    * Wenn ein gelbes Licht erscheint, bedeutet dies, dass der Start nicht erfolgreich war. Sie müssen den Schalter auf **Run-Modus** (Rechts im Diagramm) umstellen, damit das ESP32-CAM mit dem Arduino-Board kommunizieren kann.

    .. image:: img/zeus_run.jpg
        :width: 500
        :align: center
    
    .. raw:: html
        
        <br/>  
    
    * Bitte drücken Sie die **Reset**-Taste, um den Code auf dem Arduino-Board erneut zu starten.

    .. image:: img/zeus_reset_button.jpg
        :width: 500
        :align: center
    
    .. raw:: html
        
        <br/>  

#. Verbinden Sie sich mit dem ``Zeus_Car`` WLAN.

    Verbinden Sie Ihr Mobilgerät nun mit dem von Zeus Car ausgestrahlten LAN. Dadurch werden Ihr Mobilgerät und das Zeus Car im selben Netzwerk sein, was die Kommunikation zwischen den Anwendungen auf Ihrem Mobilgerät und dem Zeus Car erleichtert.

    * Finden Sie ``Zeus_Car`` im WLAN Ihres Mobiltelefons (Tablet), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.

    .. image:: img/app_wlan.png
        :width: 500
        :align: center
    
    .. raw:: html
        
        <br/>  
    
    * Der Standardverbindungsmodus ist der AP-Modus. Nach der Verbindung erhalten Sie eine Meldung, dass dieses WLAN-Netzwerk keinen Internetzugang bietet. Bitte wählen Sie "Trotzdem verbinden".

    .. image:: img/app_no_internet.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
#. Erstellen Sie einen Controller.

    * Um einen Controller im SunFounder Controller hinzuzufügen, klicken Sie auf das **+** Symbol.

    .. image:: img/app1.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Für einige Produkte sind voreingestellte Controller verfügbar. Hier wählen wir **Zeus Car**.

    .. image:: img/app_preset.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Geben Sie ihm einen Namen und klicken Sie auf Bestätigen.

    .. image:: img/app_name.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Sie befinden sich jetzt im Controller, der bereits mehrere Widgets eingerichtet hat. Klicken Sie auf den |app_save| Button in der oberen rechten Ecke.

    .. image:: img/app_edit.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
#. Verbinden und starten Sie den Controller.

    * Nutzen Sie den |app_connect| Button, um den SunFounder Controller mit dem Zeus Car zu verbinden und die Kommunikation zu starten. Nach einigen Sekunden erscheint ``Zeus_Car(IP)``, klicken Sie darauf, um sich zu verbinden.

    .. image:: img/app_auto_connect.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    .. note::
        
        Stellen Sie sicher, dass Ihr WLAN mit ``Zeus_Car`` verbunden ist, wenn Sie die obige Meldung für längere Zeit nicht sehen.

    * Nachdem die Meldung "Erfolgreich verbunden" erschienen ist, klicken Sie auf den |app_run| Button. Nun erscheint das Kamera-Bild in der App und Sie können Ihr Zeus Car mit diesen Widgets steuern.

    .. image:: img/app_run.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Hier sind die Funktionen der Widgets.

      * :ref:`app_compass_cali`: Kompasskalibrierung einschalten.
      * **Stop(F)**: Alle Bewegungen des Autos stoppen.
      * **Set Heading(I)**: Nachdem Sie das Auto mit der Hand in eine Richtung ausgerichtet haben, klicken Sie auf dieses Widget, um diese Richtung als Front der Autobewegung festzulegen. Dies ermöglicht eine schnelle Richtungsvorgabe, ohne das Auto langsam mit anderen Widgets in diese Richtung drehen zu müssen.
      * :ref:`app_drift`: Drift-Funktion aktivieren.
      * :ref:`app_move`: Steuern Sie das Auto in alle Richtungen.
      * :ref:`app_speech_control`: Wechseln Sie in den Sprachsteuerungsmodus.
      * :ref:`app_line_track`: Wechseln Sie in den Linienverfolgungsmodus.
      * :ref:`app_follow`: Wechseln Sie in den Follow-Modus.
      * :ref:`app_avoid`: Wechseln Sie in den Hindernisvermeidungsmodus.
      * :ref:`app_rotate_drift`: Dient zur Steuerung der Kopfrichtung.


.. _app_compass_cali:

Kalibrierung(E)
--------------------------

Aktivieren Sie die Kompasskalibrierung, indem Sie auf den |app_cali_e| Button klicken.

Stellen Sie das Zeus-Auto auf den Boden. Nach Aktivierung der Kompasskalibrierung wird das Auto gegen den Uhrzeigersinn zu drehen beginnen und nach etwa 1 Minute anhalten. Wenn es länger als 2 Minuten dreht, ist das Magnetfeld hier komplex. Versuchen Sie, den Standort zu wechseln und erneut zu kalibrieren.

.. _app_drift:

Drift Aktivieren(J)
---------------------

Klicken Sie auf den |app_drift_j| Button, um die Drift-Funktion zu aktivieren.

* Wenn Sie das |app_rotate_q| Widget gegen den Uhrzeigersinn schieben, wird das Zeus Auto nach rechts driften. Beim Loslassen der Hand wird das Auto an seiner aktuellen Position anhalten.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  

* Entsprechend, wenn Sie das |app_rotate_q| Widget im Uhrzeigersinn schieben, wird das Zeus Auto nach links driften und an der aktuellen Position anhalten.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  

.. _app_move:

In alle Richtungen bewegen(K)
----------------------------------

.. raw:: html

   <video loop autoplay muted style="max-width:80%">
      <source src="../_static/video/basic_movement.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Das Zeus Auto bewegt sich in die entsprechende Richtung, wenn Sie das |app_move_k| Widget wischen.

.. image:: img/joystick_move.png
    :align: center

.. raw:: html
    
    <br/>  

Das Auto bewegt sich jedes Mal, wenn Sie wischen. Wenn Sie Ihre Hand also nicht loslassen, bewegt sich das Auto weiter.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  

.. _app_speech_control:

Sprachsteuerung(M)
-------------------

.. warning::
    Android-Geräte können die Sprachsteuerungsfunktion nicht nutzen. Die Sprachsteuerung erfordert eine Internetverbindung des Android-Geräts und die Installation der Google Service Komponente.
    
    Während iOS-Geräte einen Offline-Spracherkennungsmotor verwenden, ist keine Netzwerkverbindung erforderlich; AP- und STA-Modusverbindung sind beide verfügbar.

Das Zeus Auto kann auch über Sprache im SunFounder Controller gesteuert werden. Das Zeus Auto führt die eingestellten Aktionen basierend auf den Befehlen aus, die Sie Ihrem Mobilgerät sagen.

Halten Sie nun das |app_speech_m| Widget gedrückt und sagen Sie einen der folgenden Befehle, um zu sehen, was passiert.

* ``stop``: Alle Bewegungen des Autos können gestoppt werden.
* ``pause``: Die Funktion ähnelt der von Stop, aber wenn die Vorderseite des Autos nicht in die ursprünglich eingestellte Richtung zeigt, wird es sich langsam in die eingestellte Richtung bewegen.
* ``vorwärts``
* ``rückwärts``
* ``links vorwärts``
* ``links rückwärts``
* ``rechts vorwärts``
* ``rechts rückwärts``
* ``nach links bewegen``
* ``nach rechts bewegen``

Nachdem das Auto die oben genannten 8 Befehle erhalten hat, wird es sich in die entsprechende Richtung bewegen, bis es die Befehle ``stop`` oder ``pause`` erhält.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center

* ``links drehen``: Dieser Befehl lässt das Auto sich um 45° nach links drehen, wobei der Körper als Mittelpunkt dient. Anschließend wird es je nach vorherigem Zustand vorwärts fahren oder anhalten. Wenn der vorherige Zustand "stop" war, wird es nach 45° Drehung nach links anhalten; wenn es "vorwärts" war, wird es nach dem Drehen vorwärts fahren.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  

* ``rechts drehen``: Dieser Befehl lässt das Auto sich um 45° nach rechts drehen, wobei der Körper als Mittelpunkt dient, und wird je nach vorherigem Zustand vorwärts fahren oder anhalten.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
 

.. _app_line_track:

Linie(N)
--------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Klicken Sie auf das |app_line_n| Widget, um in den Linienverfolgungsmodus zu wechseln.

Der Zeus Car bietet zwei Modi der Linienverfolgung an: Einen, bei dem die Vorderseite immer in die Bewegungsrichtung zeigt und einen, bei dem die Vorderseite in eine feste Richtung zeigt. Hier wurde der zweite Modus gewählt.

#. Kleben Sie eine 3 cm breite Linie an

    Es gibt acht Sensoren am Omni-Graustufenmodul, und der Abstand zwischen jedem Sensor liegt zwischen 2 und 3 cm. Mindestens zwei Sensoren müssen gleichzeitig die schwarze Linie erkennen. Daher muss die angebrachte Linie mindestens 3 cm breit sein, und der Biegungswinkel sollte nicht kleiner als 90° sein.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
#. Kalibrieren Sie das Omni-Graustufenmodul.

    Da jede Untergrundfarbe unterschiedliche Grauwerte aufweist, ist der werkseitig eingestellte Graustufen-Schwellenwert möglicherweise nicht für Ihre aktuelle Umgebung geeignet. Daher müssen Sie dieses Modul vor dem Gebrauch kalibrieren. Es wird empfohlen, die Kalibrierung durchzuführen, wenn sich die Bodenfarbe deutlich ändert.

    * Stellen Sie den Zeus Car auf eine weiße Oberfläche und drehen Sie das Potentiometer, bis das Grausensorlicht gerade leuchtet.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center
    
    .. raw:: html
        
        <br/>  
    
    * Lassen Sie nun die beiden Graustufensensoren an der Seite genau zwischen der schwarzen Linie und der weißen Oberfläche positionieren und drehen Sie das Potentiometer langsam, bis die Signalanzeige gerade erlischt.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Sie können mehrfach über die schwarze Linie und die weiße Oberfläche fahren, um sicherzustellen, dass die Lichter des Graustufensensors aus sind, wenn sie zwischen der schwarzen Linie und der weißen Oberfläche und an sind, wenn sie auf der weißen Oberfläche sind. Das zeigt an, dass das Modul erfolgreich kalibriert wurde.

#. Stellen Sie den Zeus Car auf Ihre angebrachte Linie, klicken Sie auf das |app_line_n| Widget, und er wird der Linie folgen.

#. Aufgrund der hohen Umgebungsanforderungen des Omni-Graustufenmoduls wird empfohlen, es mehrmals zu kalibrieren, wenn der Verfolgungseffekt nicht zufriedenstellend ist (außerhalb der Spur).

.. _app_follow:

Folgen(O)
------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Klicken Sie auf das |app_follow_o| Widget, um in den Verfolgungsmodus zu wechseln.

Der Ultraschallsensor erkennt Hindernisse vor sich (20 cm) und folgt ihnen. Diese beiden Hindernisvermeidungsmodule ermöglichen es dem Auto, nach links oder rechts zu folgen, müssen jedoch vor der Verwendung kalibriert werden (15cm).

#. Kalibrieren Sie das IR-Hindernisvermeidungsmodul.

    * Platzieren Sie ein Hindernis etwa 15 cm entfernt vom IR-Hindernisvermeidungsmodul.
    * Am Modul befinden sich zwei Potentiometer, eines zur Anpassung der Sendeleistung und eines zur Anpassung der Sendefrequenz. Mit diesen beiden Potentiometern können Sie den Erfassungsabstand einstellen.
    * Dann können Sie ein Potentiometer einstellen, und wenn bei 15 cm das Signallicht auf dem Modul leuchtet, ist die Einstellung erfolgreich. Wenn nicht, stellen Sie das andere Potentiometer ein.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Kalibrieren Sie das andere Hindernisvermeidungsmodul auf die gleiche Weise.

#. Stellen Sie das Zeus-Auto auf einen Tisch oder den Boden und lassen Sie es Ihrer Hand oder anderen Hindernissen folgen.

.. _app_avoid:

Vermeiden(P)
------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

Wenn Sie in den Hindernisvermeidungsmodus wechseln möchten, klicken Sie auf das |app_avoid_p| Widget, ziehen Sie aber zuerst den :ref:`app_follow` heran, um die beiden Hindernisvermeidungsmodule zu kalibrieren.

* Das Zeus Auto wird sich vorwärts bewegen.
* Ein Ultraschallmodul erkennt Hindernisse vor sich. Wenn es eines erkennt, dreht sich das Auto nach links.
* Wenn das linke Hindernisvermeidungsmodul ein Hindernis erkennt, dreht sich das Auto nach rechts, und wenn das rechte Hindernisvermeidungsmodul ein Hindernis erkennt, dreht es sich nach links.

.. _app_rotate_drift:

Richtung steuern(Q)
-------------------------------

* Wenn der |app_drift_j| Button aktiviert ist, wird das |app_rotate_q| Widget verwendet, um das Zeus Auto links und rechts driften zu lassen.

* Wenn das |app_drift_j| Widget deaktiviert ist, wird das |app_rotate_q| Widget verwendet, um die Richtung des Auto-Kopfes zu steuern.

    * Durch das Verschieben des |app_rotate_q| Widgets gegen den Uhrzeigersinn wird auch das Auto gegen den Uhrzeigersinn drehen. Beim Loslassen kehrt der Kopf des Autos in die ursprüngliche Richtung zurück.

    .. image:: img/zeus_turn_left.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Ebenso wird das Auto im Uhrzeigersinn drehen, wenn das |app_rotate_q| Widget im Uhrzeigersinn verschoben wird und in die ursprüngliche Richtung zurückkehren, wenn es losgelassen wird.

    .. image:: img/zeus_turn_right.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
