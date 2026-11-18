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

   Per cambiare il canale Wi-Fi è necessario il firmware **1.4.1 o successivo** dell'ESP32 CAM. Per maggiori dettagli consulta :ref:`update_firmware`.

#. Tieni l'ESP32 CAM inserito nell'adattatore, poi accendi lo Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Per attivare l'ESP32 CAM, sposta l'interruttore di modo in **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Cerca ``Zeus_Car-XXXXXX`` nell'elenco delle reti disponibili del tuo dispositivo mobile (tablet o smartphone), inserisci la password ``12345678`` e connettiti. ``XXXXXX`` sono gli ultimi sei caratteri dell'indirizzo MAC dell'ESP32 CAM, quindi il nome dell'hotspot è diverso per ogni automobile.

   .. note::

        * La connessione attuale è all'hotspot dello Zeus Car, quindi non c'è accesso a Internet. Se viene chiesto di cambiare rete, scegli "Resta connesso".

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Apri un browser web sul tuo dispositivo mobile e vai all'indirizzo ``http://192.168.4.1`` per aprire la pagina delle impostazioni dell'ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: La pagina delle impostazioni è diversa a seconda della versione del firmware dell'ESP32 CAM. La versione A (firmware 1.4.x) è un'unica pagina che raccoglie le opzioni Wi-Fi e OTA, mentre la versione B (firmware 1.5.x e successivi) ha le schede **Base**, **AP**, **WIFI**, **Camera** e **OTA**. Segui i passaggi corrispondenti all'interfaccia visualizzata.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Versione A** (firmware 1.4.x)

   5. Nella sezione **Wi-Fi AP Channel** seleziona un altro canale, quindi fai clic sul pulsante **Confirm**.

      * Il canale predefinito è 1. Quando cambi canale, saltane 1-2 alla volta (ad esempio dal canale 1 al 3 e, se necessario, al 5).

      .. image:: img/faq_cam_ota_channel.png
         :width: 400

   #. Compare una finestra di conferma che chiede di riavviare il dispositivo. Fai clic su **Confirm**.

      .. image:: img/faq_cam_ota_reset.jpg
         :width: 400

   #. Premi il pulsante **Reset** sulla scheda R3 per riavviare l'ESP32 CAM. Lo Zeus Car è ora pronto per il normale funzionamento.

      .. image:: img/zeus_run123.jpg
         :width: 600

**Versione B** (firmware 1.5.x e successivi)

   5. Fai clic su **AP** nel menu laterale (o tocca la scheda **AP** in basso nello schermo), quindi seleziona un altro canale dall'elenco **AP Channel**.

      * Il canale predefinito è 1. Quando cambi canale, saltane 1-2 alla volta (ad esempio dal canale 1 al 3 e, se necessario, al 5).

      .. image:: img/faq_change_channel.jpg
         :width: 400

   #. Quando in cima alla pagina compare il banner "Reboot to take effect.", fai clic su **REBOOT**. Lo Zeus Car è ora pronto per il normale funzionamento.

.. _update_firmware:

Come Aggiornare il Firmware dell'ESP32 CAM
------------------------------------------------

Segui questi passaggi dettagliati per aggiornare il firmware del tuo ESP32 CAM:

#. Tieni l'ESP32 CAM inserito nell'adattatore, poi accendi lo Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Per attivare l'ESP32 CAM, sposta l'interruttore di modo in **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Scarica il file del firmware.

   * Apri `l'ultima versione del firmware dell'ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/latest>`_ — il numero di versione del firmware attuale è mostrato in cima alla pagina.
   * Nell'elenco **Assets** scarica il file ``ai-camera-firmware.vX.X.X-ota.bin``. Il file ``-factory.bin`` dello stesso elenco serve per flashare il modulo con un programmatore e non viene usato per questo aggiornamento.

   .. image:: img/faq_firm_download.png
      :width: 600

#. Connetti il tuo dispositivo mobile alla rete Wi-Fi dello Zeus Car.

   * Il nome della rete (SSID) è ``Zeus_Car-XXXXXX``, dove ``XXXXXX`` sono gli ultimi sei caratteri dell'indirizzo MAC dell'ESP32 CAM, e la password è ``12345678``.
   * Se compare l'avviso "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Apri un browser web sul tuo dispositivo mobile e vai all'indirizzo ``http://192.168.4.1`` per aprire la pagina delle impostazioni dell'ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: In questa pagina le opzioni di aggiornamento OTA compaiono in una delle due interfacce. La versione A (la prima) e la versione B (la seconda) appaiono in base alla versione del firmware. Segui i passaggi corrispondenti all'interfaccia visualizzata.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Versione A** (firmware 1.4.x)

   6. Nella pagina OTA seleziona il file del firmware e avvia l'aggiornamento:

      * Scegli il file ``ai-camera-firmware.vX.X.X-ota.bin`` scaricato in precedenza e fai clic su **Add**.
      * Fai clic sul pulsante **Update** per avviare l'aggiornamento, quindi attendi che finisca.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Al termine dell'aggiornamento il nome dell'hotspot dello Zeus Car diventa ``AI Camera-XXXXXX`` e la password rimane ``12345678``. Premi il pulsante **Reset** sulla scheda R3 in modo che l'auto registri di nuovo il proprio nome; l'hotspot torna così a chiamarsi ``Zeus_Car-XXXXXX``.

**Versione B** (firmware 1.5.x e successivi)

   6. Nella pagina **OTA** controlla la versione del firmware attuale mostrata.

      .. image:: img/faq_upgrade.jpg
         :width: 400
         :align: center

   #. Tocca **Upgrade Firmware**, seleziona il file del firmware e attendi che l'aggiornamento finisca:

      * Tocca il pulsante **Upgrade Firmware**, quindi seleziona il file ``ai-camera-firmware.vX.X.X-ota.bin`` scaricato in precedenza.
      * L'aggiornamento inizia subito e richiede in genere 1-2 minuti. Al termine seleziona **CONFIRM** per riavviare lo Zeus Car.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Al termine dell'aggiornamento il nome dell'hotspot dello Zeus Car diventa ``AI Camera-XXXXXX`` e la password rimane ``12345678``. Premi il pulsante **Reset** sulla scheda R3 in modo che l'auto registri di nuovo il proprio nome; l'hotspot torna così a chiamarsi ``Zeus_Car-XXXXXX``.

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

Se preferisci controllare l'auto tramite il Wi-Fi di casa, puoi far connettere l'ESP32 CAM alla tua rete. La camera continua a funzionare in modalità doppia AP + STA, quindi l'hotspot dello Zeus Car resta comunque disponibile:

#. Accendi lo Zeus Car. Per attivare l'ESP32 CAM, sposta l'interruttore di modo in **Run** e premi il pulsante **Reset** per riavviare la scheda R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Connetti il tuo dispositivo mobile alla rete Wi-Fi dello Zeus Car.

   * Il nome della rete (SSID) è ``Zeus_Car-XXXXXX``, dove ``XXXXXX`` sono gli ultimi sei caratteri dell'indirizzo MAC dell'ESP32 CAM, e la password è ``12345678``.
   * Se compare l'avviso "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Apri un browser web sul tuo dispositivo mobile e vai all'indirizzo ``http://192.168.4.1`` per aprire la pagina delle impostazioni dell'ESP32 CAM.

   .. image:: img/faq_ota_home.jpg
      :width: 400

#. Fai clic su **WIFI** nel menu laterale (o tocca la scheda **WIFI** in basso nello schermo), quindi inserisci il nome e la password della rete Wi-Fi di casa.

   * Inserisci il nome del Wi-Fi di casa in **STA SSID** — puoi anche sceglierlo dall'elenco scansionato — e la password in **STA password**.
   * Tocca **CONFIRM** per salvare. Dopo il salvataggio la pagina mostra "Success, Restart to apply.".
   * Dopo il riavvio, la pagina **Base** mostra in **IP Address** l'indirizzo IP assegnato alla camera dal router.

   .. image:: img/faq_set_sta.jpg
      :width: 400

#. Riavvia l'ESP32 CAM: fai clic su **Reboot** nella pagina oppure premi il pulsante **Reset** sulla scheda R3. L'ESP32 CAM si connette ora al Wi-Fi di casa e mantiene contemporaneamente l'hotspot dello Zeus Car.

   .. note::

      Con il firmware **1.5.4** e successivi dell'ESP32 CAM la camera funziona in modalità doppia AP + STA e il comando seriale ``MODE`` viene ignorato. Modificare ``WIFI_MODE``, ``SSID`` e ``PASSWORD`` nello sketch della R3 non porta quindi più la camera in modalità STA — configura il Wi-Fi di casa come descritto sopra.

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

Puoi anche capovolgere la camera dalla pagina delle impostazioni dell'ESP32 CAM: connetti il dispositivo mobile alla rete Wi-Fi dello Zeus Car, apri ``http://192.168.4.1`` e attiva **Horizontal flip** o **Vertical flip** nella pagina **Camera**.

.. image:: img/faq_camera.jpg
     :width: 400

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

#. Connetti lo Zeus Car alla rete Wi-Fi di casa, in modo che sia l'auto sia il tuo dispositivo mobile abbiano accesso a Internet. Segui :ref:`ap_to_sta` per salvare il Wi-Fi di casa nella pagina delle impostazioni dell'ESP32 CAM — non devi modificare né ricaricare il codice ``Zeus_Car.ino``.
#. Cerca ``google`` su Google Play, trova l'app mostrata di seguito e installala.

    .. image:: img/google_voice.png

#. Connetti il tuo dispositivo mobile alla stessa rete Wi-Fi di casa.

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. Apri il controller precedentemente creato nell'app SunFounder Controller e connettilo a Zeus Car tramite il pulsante |app_connect|.

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
