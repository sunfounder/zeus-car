.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_app_control:

17. Controllo tramite APP
============================

Nel progetto precedente abbiamo semplicemente visualizzato le riprese della telecamera e utilizzato la funzione di rilevamento AI nell'app SunFounder Controller.

In questo progetto, proveremo a controllare il movimento e la direzione della Zeus Car utilizzando il joystick nell'app. Vediamo come funziona.

.. note::
    Installa `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ dall’**App Store (iOS)** o **Google Play (Android)**.


**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``17_app_control.ino`` nel percorso ``zeus-car-main\examples\17_app_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, puoi ricollegare la ESP32-CAM e spostare l'interruttore di alimentazione su ON per avviare la Zeus Car.

    .. image:: img/plug_esp32_cam.jpg

#. Sposta l'interruttore di upload sulla posizione Run (lato destro nello schema) per avviare la ESP32-CAM.

    .. image:: img/zeus_run.jpg

#. Premi il pulsante di reset per riavviare il programma sulla scheda Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Connettiti alla rete WLAN ``Zeus_Car``.

    * Trova ``Zeus_Car`` nella lista delle reti WLAN del tuo telefono (o tablet), inserisci la password ``12345678`` e connettiti.

    .. image:: img/app_wlan.png

    * La modalità di connessione predefinita è AP. Dopo la connessione, potrebbe apparire un avviso che indica l’assenza di accesso a Internet su questa rete WLAN. Scegli di continuare la connessione.

    .. image:: img/app_no_internet.png

#. Crea un controller.

    * Per aggiungere un controller nell’app SunFounder Controller, clicca sull'icona **+**.

        .. image:: img/app1.png

    * Alcuni prodotti dispongono di controller preconfigurati nella sezione Preset. Qui selezioniamo **Blank** e il template **Dual Stick**.

        .. image:: img/app_blank.PNG

   * Clicca sull’icona + nell'area J e seleziona un widget Switch. Potresti dover scorrere verso sinistra per trovarlo.

        .. image:: img/app_switch_wid.png

        .. note::
            Se hai selezionato il widget sbagliato, puoi cliccarci sopra nuovamente e usare il pulsante "Elimina" per rimuoverlo.

            .. image:: img/app_delete.png

    * Clicca sull'icona delle impostazioni in alto a destra per assegnare un nome al controller.

        .. image:: img/app_name_dirft.png

    * Seleziona un widget Joystick nelle aree K e Q e assegna loro un nome. Infine, usa il pulsante |app_save| per salvare il controller.

    .. image:: img/app_joystick_wid.png

    * Ora collega la Zeus Car al tuo dispositivo tramite il pulsante |app_connect|. Dopo qualche secondo, apparirà ``Zeus_Car(IP)``. Cliccaci sopra per connetterti.

        .. image:: img/app_connect.png

        .. note::
            Assicurati che il Wi-Fi sia connesso a ``Zeus_Car`` se il messaggio non appare dopo un po' di tempo.


#. Avvia il controller.

    Dopo che appare il messaggio "Connessione riuscita", clicca sul pulsante |app_run|. Le riprese della telecamera verranno visualizzate nell'app e potrai controllare la Zeus Car utilizzando i widget.

    Le funzioni dei tre widget sono le seguenti:


    **Movimento in tutte le direzioni (K)**

    La Zeus Car si muoverà nella direzione corrispondente quando scorri il widget |app_move_k|.

    .. image:: img/joystick_move.png
        :align: center

    L'auto si muove ogni volta che trascini il widget. Se tieni il dito premuto senza rilasciare, l'auto continuerà a muoversi.

    .. image:: img/zeus_move.jpg

    **Attivazione Drift (J)**

    Clicca sul pulsante |app_drift_j| per attivare la funzione di drift.

    * Facendo scorrere il widget |app_rotate_q| in senso antiorario, vedrai la Zeus Car derapare verso destra. Rilasciando il controllo, l'auto si fermerà nella posizione attuale.

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * Allo stesso modo, facendo scorrere il widget |app_rotate_q| in senso orario, la Zeus Car deraperà verso sinistra e si fermerà nella posizione attuale.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center

    **Controllo della direzione (Q)**

    * Quando il pulsante |app_drift_j| è attivo, il widget |app_rotate_q| permette alla Zeus Car di derapare a sinistra e a destra.

    * Quando il widget |app_drift_j| è disattivato, il widget |app_rotate_q| viene utilizzato per controllare la direzione della testa del veicolo.

        * Facendo scorrere il widget |app_rotate_q| in senso antiorario, l’auto ruoterà anch’essa in senso antiorario. Rilasciando il controllo, la testa del veicolo tornerà alla direzione originale.

        .. image:: img/zeus_turn_left.jpg
            :width: 600
            :align: center

        * Allo stesso modo, facendo scorrere il widget |app_rotate_q| in senso orario, l’auto ruoterà in senso orario e tornerà alla direzione originale quando il controllo viene rilasciato.

        .. image:: img/zeus_turn_right.jpg
            :width: 600
            :align: center

