.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

4. Drift
======================

In questo progetto, imparerai a far derapare la Zeus Car.

.. image:: img/zeus_drift_left.jpg

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``4_drift.ino`` nel percorso ``zeus-car-main\examples\4_drift``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/9ca66dad-7258-4868-a8a4-3bd512bacd72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.
#. Ora la Zeus Car avanzerà per 0,5 secondi, poi eseguirà una derapata di 90 gradi a sinistra e continuerà così. Puoi provare a modificare il valore 45 (``rot``) con un altro valore o un numero negativo per osservare come cambiano l’angolo e la direzione della derapata.


**Come funziona?**

La derapata della Zeus Car è ottenuta aggiungendo il parametro ``drift`` alla funzione di movimento ``carMove()``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot, bool drift)

* ``angle``: La direzione in cui vuoi far muovere l'auto. L’orientamento della testa dell’auto corrisponde a 0 gradi e l’angolo aumenta in senso antiorario.
* ``power``: La potenza di movimento, con un intervallo compreso tra -100% e 100%. Se ``power`` è positivo, l’auto si muove in avanti; se negativo, si muove all’indietro.
* ``rot``: La potenza di rotazione, con un intervallo compreso tra -100% e 100%. Se ``rot`` è positivo, l’auto ruota in senso antiorario; se negativo, ruota in senso orario.
* ``drift``: Impostato su ``false`` per impostazione predefinita. Se impostato su ``true``, abilita la modalità drift.

Pertanto, variando i valori di ``power`` e ``rot``, puoi modificare l’angolo e la direzione della derapata della Zeus Car.
