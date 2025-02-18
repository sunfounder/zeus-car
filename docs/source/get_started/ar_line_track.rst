.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_line_track:

14. Tracciamento della Linea
================================

In questo progetto, imparerai a utilizzare il modulo Omni Grayscale per il tracciamento della linea.

Prima di iniziare, dovrai creare un percorso con del nastro isolante nero. Il tracciato può essere un cerchio, una linea retta o una forma irregolare.

Tuttavia, ci sono due aspetti importanti da considerare:

1. La larghezza della linea deve essere di almeno 3 cm (lo spessore di un nastro isolante standard è di 1,5 cm).
2. L’angolo di curvatura non deve essere inferiore a 90°.

.. image:: img/map.png

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Apri il file ``14_line_track.ino`` nel percorso ``zeus-car-main\examples\14_line_track``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/f1bfb9ad-8bfa-417e-a4c0-10dbdcdc4298/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.


#. A questo punto, la Zeus Car seguirà la linea tracciata. Se l’auto esce dal percorso, potrebbe essere necessario ricalibrare il modulo :ref:`ar_grayscale` o ridurre la velocità.

