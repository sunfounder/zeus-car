.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

6. Luci dell'Auto
==========================


In questo progetto, potrai utilizzare il telecomando per controllare le strisce luminose RGB posizionate sul fondo della Zeus Car, facendole illuminare con colori diversi.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/car_light.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``6_car_light.ino`` nel percorso ``zeus-car-main\examples\6_car_light``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

#. Ora puoi utilizzare i tasti numerici da 1 a 9 sul telecomando per cambiare il colore delle luci dell’auto, premere il tasto 0 per spegnerle e premere |ir_return| per avviare un ciclo di colori. I tasti da 1 a 9 corrispondono ai seguenti colori: rosso, arancione, giallo, verde, ciano, blu, viola, rosa e bianco.
