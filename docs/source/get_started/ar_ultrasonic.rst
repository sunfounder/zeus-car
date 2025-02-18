.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

10. Sensore Ultrasonico
==============================

In questo progetto imparerai a leggere la distanza rilevata dal modulo ultrasonico.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``10_ultrasonic.ino`` nel percorso ``zeus-car-main\examples\10_ultrasonic``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b3c702d7-2d4e-48fe-8d8d-7d20f70c9e45/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

    .. note::
        Non scollegare il cavo USB in questo passaggio, poiché è necessario controllare i dati del modulo ultrasonico sul computer.

#. Apri il monitor seriale e assicurati che la velocità di trasmissione (baud rate) sia impostata su 115200. Si consiglia di cliccare sull'icona **Toggle Autoscroll** per visualizzare sempre i dati più recenti.

   * Potrai visualizzare i dati stampati in formato ``distance: 21.11  is_obstacle: 0``.
   * Se un ostacolo viene rilevato entro 20 cm di distanza, il valore ``is_obstacle: 0`` cambierà in ``is_obstacle: 1``.

    .. image:: img/ar_ultrasonic.png

