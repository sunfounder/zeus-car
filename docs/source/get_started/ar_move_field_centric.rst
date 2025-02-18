.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

8. Movimento con Bussola
===============================


Questo progetto si basa sul precedente e integra la funzione della bussola nel movimento della Zeus Car. 
Mentre controlli il movimento dell’auto con il telecomando, se viene deviata da una forza esterna (ad esempio un cane che la spinge), tornerà automaticamente alla direzione originale.


**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``8_move_field_centric.ino`` nel percorso ``zeus-car-main\examples\8_move_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

#. Usa i tasti numerici da 1 a 9 sul telecomando per controllare la Zeus Car in 8 direzioni diverse. Dopo aver premuto un tasto, l’auto continuerà a muoversi fino a quando non premi |ir_power| o il tasto numero 5.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. Premendo una volta |ir_return|, la Zeus Car ruoterà in senso antiorario attorno al proprio asse e si fermerà solo quando premerai |ir_power| o il tasto numero 5.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. Allo stesso modo, premendo |ir_usd|, la Zeus Car ruoterà in senso orario e si fermerà solo quando premerai |ir_power| o il tasto numero 5.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center

#. Premendo il tasto |ir_minus|, l’auto eseguirà una derapata verso sinistra.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. Premendo il tasto |ir_plus|, l’auto eseguirà una derapata verso destra.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


.. note::

    * Se la Zeus Car non si muove correttamente, potrebbe essere necessario ricalibrare la bussola premendo |ir_mute|.
    * Se sposti la Zeus Car dal pavimento a un tavolo, il campo magnetico potrebbe variare ed è necessario ricalibrarla.