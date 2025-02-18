.. note:: 

    Ciao, benvenuto nella Community di Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Esplora più a fondo il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri entusiasti.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri ultimi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e offerte speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti subito!

FAQ
================

Come Cambiare il Canale Wi-Fi?
----------------------------------

La banda Wi-Fi a 2.4GHz dispone di canali da 1 a 13, ma l’ESP32 supporta solo i canali da 1 a 11. La presenza di altri dispositivi operanti sullo stesso canale potrebbe causare interferenze, compromettendo la connessione. Per ridurre questo problema, puoi provare a cambiare il canale. Il canale predefinito è impostato su 1. Si consiglia di saltare 1-2 canali alla volta quando si seleziona un nuovo canale. Ad esempio, se il canale attuale è 1, prova prima il canale 3 e, se il segnale rimane debole, passa al canale 5.

.. note::

   È richiesta la versione firmware 1.4.1 o superiore per modificare il canale Wi-Fi. Consulta :ref:`update_firmware` per maggiori dettagli.

#. Mantieni l'ESP32 CAM inserito nell'adattatore e accendi lo Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Per attivare l'ESP32 CAM, sposta l'interruttore di modalità sulla posizione **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Trova ``Zeus Car`` nell'elenco delle reti Wi-Fi disponibili sul tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti.

   .. note::

        * La connessione attuale è all'hotspot di Zeus Car, quindi non è disponibile l'accesso a Internet. Se viene richiesto di passare a un'altra rete, seleziona "Rimani connesso".

   .. image:: img/app_wlan.png
        :width: 500

#. Apri un browser web sul tuo dispositivo e vai all’indirizzo ``http://192.168.4.1`` per accedere alla pagina di aggiornamento OTA dell'ESP32 CAM.

   .. image:: img/faq_cam_ota_141.jpg
      :width: 400

#. Nella sezione **Wi-Fi AP Channel**, seleziona un canale diverso.

   * Il canale predefinito è 1. Si consiglia di saltare 1-2 canali alla volta (ad esempio, da 1 a 3, poi a 5 se necessario).  
   * Clicca su **Confirm** per salvare le modifiche.

   .. image:: img/faq_cam_ota_channel.png
      :width: 400

#. Verrà visualizzato un messaggio di conferma che richiede di riavviare il dispositivo. Clicca su **Confirm**.

   .. image:: img/faq_cam_ota_reset.jpg
      :width: 400

#. Premi il pulsante **Reset** per riavviare il dispositivo. Zeus Car sarà ora pronto per l'uso normale.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _update_firmware:

Come Aggiornare il Firmware dell'ESP32 CAM
------------------------------------------------

Segui questi passaggi dettagliati per aggiornare il firmware del tuo ESP32 CAM:

#. Mantieni l'ESP32 CAM inserito nell'adattatore e accendi lo Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Per attivare l'ESP32 CAM, sposta l'interruttore di modalità sulla posizione **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Trova ``Zeus Car`` nell'elenco delle reti Wi-Fi disponibili sul tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti.

   .. note::

      * La connessione attuale è all'hotspot di Zeus Car, quindi non è disponibile l'accesso a Internet. Se viene richiesto di passare a un'altra rete, seleziona "Rimani connesso".

   .. image:: img/app_wlan.png
        :width: 500

#. Clicca sul link seguente per scaricare il file firmware ``ai-camera-firmware-v1.4.1-ota.bin`` e salvalo sul tuo dispositivo.

   * :download:`Firmware ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/download/1.4.1/ai-camera-firmware-v1.4.1-ota.bin>`

#. Apri un browser web sul tuo dispositivo e vai all’indirizzo ``http://192.168.4.1`` per accedere alla pagina di aggiornamento OTA dell'ESP32 CAM.

   .. image:: img/faq_cam_ota.jpg
      :width: 400

#. Nella pagina OTA, clicca sul pulsante per selezionare il file del firmware.

   .. image:: img/faq_cam_ota_choose.png
      :width: 400

#. Seleziona il file ``ai-camera-firmware-v1.4.1-ota.bin`` precedentemente scaricato sul tuo dispositivo e clicca su **OK**.

   .. image:: img/faq_cam_ota_file.png
      :width: 400

#. Clicca su **Update** per avviare il processo di aggiornamento del firmware.

   .. image:: img/faq_cam_ota_update.png
      :width: 400

#. Attendi il completamento dell'aggiornamento. Una volta che il numero di versione visualizzato cambia in ``1.4.1``, l'aggiornamento è andato a buon fine.

   .. image:: img/faq_cam_ota_finish.png
      :width: 400

#. Dopo l'aggiornamento, puoi chiudere il browser web. Premi il pulsante **Reset** per riavviare il dispositivo. L'ESP32 CAM sarà ora pronto per l'uso normale.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _upload_zeus_code:

Come caricare il codice ``zeus-car.ino``? 
-----------------------------------------------

Di default, la scheda Uno R3 dello Zeus Car viene preconfigurata con il firmware necessario, permettendoti di controllarlo tramite l'APP. Se il firmware della tua scheda R3 è stato sovrascritto con altro codice e desideri ripristinarlo per continuare con il processo :ref:`quick_start`, segui questi passaggi per ricaricare il codice sulla tua scheda R3:

#. Collega l'Arduino al computer utilizzando un cavo USB. Poiché l'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione), prima di caricare il codice è necessario scollegare l'ESP32-CAM per evitare conflitti o malfunzionamenti.

   .. image:: img/unplug_cam.png
        :width: 400

#. Scarica il firmware necessario dal link sottostante:

   * :download:`File del firmware per R3 Board <https://github.com/sunfounder/zeus-car/releases/download/1.4.5/zeus-car-1.4.5.zip>`

#. Estrai il file ZIP scaricato, quindi fai doppio clic sul file ``update-arduino-firmware.bat`` per avviare il processo.

   .. image:: img/faq_firmware_file.png

#. Digita il numero corrispondente alla scheda Arduino Uno dello Zeus Car (ad esempio, ``1``) e premi **Invio** per avviare l'aggiornamento.

   .. note::

     * Se la porta COM corretta non appare o se non sei sicuro di quale sia, scollega gli altri dispositivi USB dal computer, lasciando collegato solo il rover.  
     * Se riscontri un errore come ``avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX``, assicurati di aver scollegato l'ESP32-CAM come primo passo.

   .. image:: img/faq_firmware_port.png

#. Dopo alcuni secondi, il nuovo codice verrà caricato con successo sulla scheda Uno R3 dello Zeus Car. Se il caricamento fallisce più volte, prova ad eseguire il file ``update-arduino-firmware-with-bootloader.bat``.

   .. image:: img/faq_firmware_finish.png


.. _ap_to_sta:

Come controllare lo Zeus Car tramite la rete Wi-Fi domestica?
------------------------------------------------------------------

Di default, la scheda Uno R3 è preconfigurata in modalità APP. Questo significa che lo Zeus Car trasmetterà un hotspot, permettendoti di connetterti e controllarlo tramite l'app SunFounder Controller.

Se preferisci controllare il rover tramite la tua rete Wi-Fi domestica, segui questi passaggi per caricare il codice modificato sulla scheda Uno:

#. Scarica i file necessari dal seguente link:

   * :download:`Codici Zeus Car <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

#. Consulta la guida all'installazione: :ref:`install_arduino_ide`.

#. Utilizza il **Library Manager** per installare le librerie ``SoftPWM`` e ``SunFounder AI Camera``. Per i dettagli, vedi :ref:`ar_install_lib`.

#. Vai alla cartella ``zeus-car-main\zeus-car`` e apri il file ``zeus-car.ino``.

   .. image:: img/faq_galaxy_code.png
      :width: 600

#. Commenta le righe della modalità AP, decommenta le righe della modalità STA e sostituisci ``SSID`` e ``PASSWORD`` con le credenziali della tua rete Wi-Fi domestica.

   .. code-block:: arduino

      /** Configure Wifi mode, SSID, password*/
      // #define WIFI_MODE WIFI_MODE_AP
      // #define SSID "Zeus_Car"
      // #define PASSWORD "12345678"

      #define WIFI_MODE WIFI_MODE_STA
      #define SSID "xxxxxxxxxx"
      #define PASSWORD "xxxxxxxxxx"

#. Collega l'Arduino al computer tramite un cavo USB. Poiché l'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione), prima di caricare il codice è necessario scollegare l'ESP32-CAM per evitare conflitti o malfunzionamenti.

   .. image:: img/unplug_cam.png
        :width: 400

#. Clicca sul pulsante **Upload** nell'Arduino IDE per caricare il codice modificato sulla scheda Uno.

   .. image:: img/faq_galaxy_upload.png
      :width: 600

#. Dopo il caricamento, puoi ricollegare l'ESP32-CAM e spostare l'interruttore di alimentazione su ON per avviare lo Zeus Car.

    .. image:: img/plug_esp32_cam.jpg

#. Per attivare l'ESP32 CAM, sposta l'interruttore di modalità sulla posizione **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Assicurati che il tuo dispositivo mobile (tablet o smartphone) sia connesso alla rete Wi-Fi domestica.

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. Apri l'app SunFounder Controller, tocca l'icona ``+`` per creare un nuovo controller, seleziona il preset "Zeus Car", inserisci un nome oppure premi "Conferma" per procedere.

   .. image:: img/app_preset.jpg
        :width: 600

#. L'app cercherà automaticamente lo Zeus Car. Dopo qualche secondo, vedrai il messaggio "Connessione riuscita".

   .. image:: img/app_edit.jpg
        :width: 600
    
#. Ora, toccando il pulsante |app_run| potrai visualizzare il feed video in diretta dalla fotocamera e controllare il rover tramite i widget forniti.

   .. image:: img/app_run123.png
        :width: 600  
    
Come invertire la fotocamera?   
--------------------------------

Se l'immagine della fotocamera appare capovolta mentre utilizzi il SunFounder Controller, puoi correggerla facilmente tramite l'app. Segui questi passaggi:  

1. Tocca il pulsante |app_edit| nell'angolo in alto a destra.  

   .. image:: img/faq_edit.png  
        :width: 500 

2. Clicca sul pulsante **camera** per aprire il popup. Attiva l'interruttore **Inverted** per capovolgere l'immagine.  

   .. image:: img/faq_inverted.png  
        :width: 500  

3. Salva le impostazioni.  

   .. image:: img/faq_save.png  
        :width: 500 

4. Torna all'interfaccia di controllo e clicca sul pulsante |app_run|.  

   .. note::  

        A volte il feed della fotocamera potrebbe non apparire. Se ciò accade, metti in pausa il controller e poi premi nuovamente il pulsante di avvio.  

   .. image:: img/faq_run.png  
        :width: 500 

Errore di compilazione: SoftPWM.h: No such file or directory?
----------------------------------------------------------------

Se ricevi il messaggio di errore "Compilation error: SoftPWM.h: No such file or directory", significa che la libreria ``SoftPWM`` non è installata.

Consulta la guida :ref:`ar_install_lib` per installare le librerie necessarie.

avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e?
---------------------------------------------------------------------

Se il seguente messaggio continua ad apparire dopo aver cliccato sul pulsante Upload, nonostante la scheda e la porta siano state selezionate correttamente:

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

Devi assicurarti che l'ESP32 CAM sia scollegato.

L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, durante il caricamento del codice, è necessario scollegare l'ESP32-CAM per evitare conflitti o problemi di comunicazione.

.. image:: img/unplug_cam.png
    :width: 400
    :align: center

.. _stt_android:

Come utilizzare la funzione STT su un dispositivo Android?
------------------------------------------------------------------------

La funzione STT richiede che il dispositivo Android sia connesso a Internet e che il **Google service component** sia installato.

Ora segui i passaggi seguenti.

#. Modifica la modalità AP del file ``Zeus_Car.ino`` in modalità STA.

    * Apri il file ``Zeus_Car.ino`` situato nella directory ``zeus-car-main/Zeus_Car``.  
    * Commenta il codice relativo alla modalità AP, decommenta quello della modalità STA e inserisci ``SSID`` e ``PASSWORD`` della tua rete Wi-Fi domestica.

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "Zeus_Car"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Salva il codice, seleziona la scheda corretta (Arduino Uno) e la porta, quindi clicca su **Upload** per caricarlo sulla scheda R3.

#. Cerca ``google`` su Google Play, trova l'app mostrata di seguito e installala.

    .. image:: img/google_voice.png

#. Connetti il tuo dispositivo mobile alla stessa rete Wi-Fi specificata nel codice.

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. Apri il controller precedentemente creato nell'app SunFounder Controller e connettilo a ``Zeus_Car`` tramite il pulsante |app_connect|.

    .. image:: img/app_connect.png
        :width: 500
        :align: center

#. Tocca e tieni premuto il widget |app_speech_m| dopo aver cliccato sul pulsante |app_run|. Apparirà un messaggio che indica che l'app sta ascoltando. Pronuncia uno dei seguenti comandi per controllare il movimento del rover:

    * ``stop``: Arresta tutti i movimenti del rover.
    * ``pause``: Funziona in modo simile a Stop, ma se il rover non è rivolto nella direzione originaria, si regolerà lentamente fino a riallinearsi.
    * ``forward`` 
    * ``backward`` 
    * ``left forward``
    * ``left backward``
    * ``right forward``
    * ``right backward``
    * ``move left``
    * ``move right``