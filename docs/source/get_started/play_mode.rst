.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_play_mode:

Spielmodus
======================

Im Spielmodus wird der Code bereits im Werk auf das Arduino-Board hochgeladen, und der Zeus Car kann per APP oder Fernbedienung ferngesteuert werden, sobald er eingeschaltet ist.

* :ref:`play_app_control`: Sie müssen den SunFounder Controller auf Ihrem Mobiltelefon oder Tablet installieren, mit dem Sie den Zeus Car mit einem Joystick-Widget in alle Richtungen steuern können, sowie über Sprachsteuerung. Am wichtigsten ist, dass Sie das Echtzeit-Videostreaming, das vom Zeus Car aufgenommen wird, auf der APP sehen können.

* :ref:`play_remote_control`: Wir haben eine einfache Fernbedienung beigelegt, schalten Sie einfach den Zeus Car ein und Sie können ihn mit der Fernbedienung steuern. Dies ist eine gute Wahl für Benutzer, die so schnell wie möglich den Spaß am Steuern des Zeus Car erleben möchten.

.. note::

    Hier ist das Code-Paket für dieses Kit.

    * :download:`SunFounder Zeus Car Kit für Arduino <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

    Wenn Sie nach dem Hochladen eines anderen Codes auf Ihren Arduino in den **Spielmodus** zurückkehren möchten, müssen Sie zuerst :ref:`ar_install_library` durchführen, und dann die Datei ``Zeus_Car.ino``, die unter dem Pfad ``zeus-car-main\Zeus_Car`` zu finden ist, auf das Arduino-Board hochladen.

.. toctree::
    :maxdepth: 2

    app_control
    remote_control
