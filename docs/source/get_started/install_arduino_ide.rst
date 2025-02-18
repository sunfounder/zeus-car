.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _install_arduino_ide:

Scaricare e Installare Arduino IDE 2.0
=========================================

L’Arduino IDE, ovvero l’**Ambiente di Sviluppo Integrato di Arduino**, fornisce tutto il supporto software necessario per completare un progetto con Arduino. È un software di programmazione sviluppato dal team Arduino, progettato specificamente per scrivere codice e caricarlo sulla scheda Arduino.

Arduino IDE 2.0 è un progetto open-source che rappresenta un grande passo avanti rispetto al suo solido predecessore, Arduino IDE 1.x. Offre un’interfaccia utente rinnovata, un gestore di schede e librerie migliorato, un debugger integrato, il completamento automatico del codice e molte altre funzionalità avanzate.

In questo tutorial, vedremo come scaricare e installare l’Arduino IDE 2.0 su Windows, Mac o Linux.

Requisiti di sistema
-----------------------

* Windows - Windows 10 o versioni successive, 64 bit
* Linux - 64 bit
* Mac OS X - Versione 10.14 "Mojave" o successive, 64 bit

Scaricare Arduino IDE 2.0
-----------------------------

#. Visita |link_download_arduino|.

#. Scarica l’IDE compatibile con il tuo sistema operativo.

    .. image:: img/arduino/sp_001.png

Installazione
---------------

* :ref:`ide_windows`
* :ref:`ide_macos`
* :ref:`ide_linux`

.. _ide_windows:

Windows
^^^^^^^^^^^^^

#. Fai doppio clic sul file ``arduino-ide_xxxx.exe`` per avviare l’installazione.

#. Leggi il Contratto di Licenza e accettalo.

    .. image:: img/arduino/sp_002.png

#. Scegli le opzioni di installazione.

    .. image:: img/arduino/sp_003.png

#. Seleziona la cartella di installazione. Si consiglia di installare il software su un’unità diversa da quella di sistema.

    .. image:: img/arduino/sp_004.png

#. Clicca su **Fine** per completare l’installazione.

    .. image:: img/arduino/sp_005.png

.. _ide_macos:

macOS
^^^^^^^^^^^^^^^^

Fai doppio clic sul file ``arduino_ide_xxxx.dmg`` scaricato e segui le istruzioni per copiare **Arduino IDE.app** nella cartella **Applications**. Dopo alcuni secondi, l’IDE di Arduino sarà installato correttamente.

.. image:: img/arduino/macos_install_ide.png
    :width: 800

.. _ide_linux:

Linux
^^^^^^^^^^^^

Per il tutorial su come installare Arduino IDE 2.0 su un sistema Linux, consulta la guida ufficiale:  
[Arduino IDE 2.0 su Linux](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux)

Avviare l’IDE
--------------

#. Al primo avvio, Arduino IDE 2.0 installerà automaticamente le schede Arduino AVR, le librerie integrate e altri file necessari.

    .. image:: img/arduino/sp_901.png

#. Inoltre, il firewall o il centro di sicurezza del tuo sistema potrebbero richiedere conferma per installare alcuni driver di dispositivo. Accetta tutte le richieste di installazione.

    .. image:: img/arduino/sp_104.png

#. Ora il tuo Arduino IDE è pronto per l’uso!

    .. note::
        Se alcune installazioni non vengono completate a causa di problemi di rete o altri errori, puoi riavviare Arduino IDE e il programma completerà automaticamente il processo. La finestra Output non si aprirà automaticamente al termine, a meno che tu non clicchi su Verifica o Carica.
