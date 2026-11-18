.. note:: 

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti a noi per esplorare più a fondo Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anticipo agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a eventi speciali e concorsi con premi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

16. Rilevamento AI dall'APP
==============================

In questo progetto, utilizzeremo l’app SunFounder Controller per visualizzare il flusso video in tempo reale e sfruttare le funzionalità di rilevamento AI sul dispositivo mobile, come il riconoscimento facciale e il rilevamento della postura.

SunFounder Controller è un'applicazione che consente agli utenti di personalizzare il controller per il proprio robot o come piattaforma IoT. L’APP integra 11 diversi widget di visualizzazione e controllo, tra cui pulsanti, joystick, indicatori e radar. La pagina del controller è suddivisa in 17 aree da A~Q, dove è possibile posizionare i widget per personalizzare il proprio controller.

Ora vediamo come utilizzare l'APP in modo semplice.

**Come procedere?**

#. L'ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Per evitare conflitti o problemi durante il caricamento del codice, scollega prima l'ESP32-CAM.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``16_ai_detection_from_app.ino`` nella cartella ``zeus-car-main\examples\16_ai_detection_from_app``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/c14c46e7-2e43-4b31-b7e6-b7718e501e96/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, ricollega l'ESP32-CAM e sposta l'interruttore di alimentazione su **ON** per avviare Zeus Car.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Sposta l'interruttore Upload/Run sulla posizione Run (a destra nello schema) per avviare l'ESP32-CAM. 

    .. image:: img/zeus_run.jpg

#. Premi il pulsante di reset per riavviare il programma sulla scheda Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Ora, installa `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ dal **APP Store (iOS)** o **Google Play (Android)** sul tuo dispositivo mobile.


#. Connettiti alla rete WLAN ``Zeus_Car-XXXXXX``.

    * Trova ``Zeus_Car-XXXXXX`` nelle reti Wi-Fi del tuo dispositivo (smartphone o tablet), inserisci la password ``12345678`` e connettiti. ``XXXXXX`` sono gli ultimi sei caratteri dell'indirizzo MAC dell'ESP32 CAM, quindi il nome dell'hotspot è diverso per ogni automobile.

    .. image:: ../img/faq_connect_zeuscar.jpg
        :width: 400

    * La modalità di connessione predefinita è AP mode. Dopo la connessione, potrebbe apparire un messaggio che indica l'assenza di accesso a Internet. Ignora l'avviso e scegli di restare connesso.

    .. image:: img/app_no_internet.png

#. Apri l’APP e crea un nuovo controller.

    * Per aggiungere un controller in SunFounder Controller, tocca l'icona **+**.

        .. image:: img/app1.png

    * Seleziona il modello **Blank** o **Dual Stick** e assegna un nome.

        .. image:: img/view_app1.jpg

    * Una volta all'interno del controller, tocca l'icona |app_camera| per abilitare la funzione di rilevamento AI. Troverai le opzioni Face Detection e Pose Detection.

        .. image:: img/view_app6.jpg

    * Salva tutte le impostazioni toccando il pulsante |app_save|. Se non sono stati selezionati widget, lo schermo apparirà completamente nero.

        .. image:: img/view_app3.jpg

    * Ora collega Zeus Car al tuo dispositivo toccando il pulsante |app_connect|. Dopo alcuni secondi, comparirà ``Zeus_Car(IP)``. Tocca per connetterti.

        .. image:: img/view_app4.jpg

        .. note::
            Assicurati che il tuo Wi-Fi sia connesso a ``Zeus_Car-XXXXXX`` se non vedi il messaggio di connessione per un lungo periodo.

#. Avvia il Controller.

    Una volta visualizzato il messaggio "Connected Successfully", tocca il pulsante |app_run|. Il video in diretta apparirà sull'APP.

    Se il Face Detection è attivato, il viso rilevato verrà evidenziato con un riquadro.

    .. image:: img/view_app7.jpg

    Se il Pose Detection è attivato, la postura verrà tracciata in tempo reale.

    .. image:: img/view_app8.jpg

    .. note::

        Se vuoi passare a un'altra modalità di rilevamento AI, tocca l'icona |app_edit| e ripeti i passaggi precedenti.
