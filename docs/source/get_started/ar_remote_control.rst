.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

5. Controllo Remoto
======================

In questo progetto, imparerai a controllare la Zeus Car utilizzando il telecomando.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/ir_control.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Apri il file ``5_remote_control.ino`` nel percorso ``zeus-car-main\examples\5_remote_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

#. Ora puoi utilizzare i tasti numerici da 1 a 9 sul telecomando per controllare l’auto in 8 direzioni.

    .. image:: img/ar_remote_control.png
        :width: 600
        :align: center

#. Dopo aver premuto un tasto, la Zeus Car continuerà a muoversi fino a quando non premerai |ir_power| o il tasto numero 5.

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