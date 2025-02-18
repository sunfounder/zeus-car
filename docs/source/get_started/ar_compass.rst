.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

7. Bussola
=============

In questo progetto, la Zeus Car si trasformerà in una bussola.
Dovrai impostare una direzione di riferimento e, indipendentemente da come la giri, tornerà sempre a puntare in quella direzione.

.. note::
    Se ci sono cavi elettrici nelle vicinanze della Zeus Car, il campo elettromagnetico potrebbe interferire con il funzionamento del modulo qmc6310, alterando la direzione impostata.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``7_compass.ino`` nel percorso ``zeus-car-main\examples\7_compass``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/672af146-1b45-46f6-b1d9-8ad9ecdcf8c0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

#. Per prima cosa, calibriamo il modulo qmc6310.



    * Posiziona l’auto a terra (assicurati che non ci siano cavi elettrici sotto di essa).
    * Premi |ir_mute| e l’auto inizierà a ruotare su sé stessa.
    * Si fermerà automaticamente quando il campo magnetico in quella posizione sarà completamente registrato. 
    * Se non si ferma dopo più di 2 minuti, premi |ir_power| per interrompere manualmente la rotazione e ripeti la calibrazione in un altro punto.

#. Ruota l’auto nella direzione desiderata e premi |ir_play|. Da quel momento, qualunque sia la direzione in cui la giri, la Zeus Car si riallineerà gradualmente alla direzione impostata.

#. I campi magnetici possono variare tra il pavimento e un tavolo, quindi sarà necessario ripetere la calibrazione se la superficie di appoggio cambia.
