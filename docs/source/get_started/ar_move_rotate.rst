.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

3. Movimento e Rotazione
===========================

In questo progetto, la Zeus Car può includere parametri di rotazione per eseguire una rotazione sul posto o muoversi lungo una traiettoria ad arco.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Apri il file ``3_rotate_and_move.ino`` nel percorso ``zeus-car-main\examples\3_rotate_and_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/bf0dfe1b-18c1-4a45-bd38-a9a8e671d66a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car. L’auto ruoterà prima a sinistra, poi a destra per tornare alla posizione originale. Successivamente, inizierà a muoversi lentamente lungo un arco verso l’esterno, con un angolo di sterzata che diminuirà progressivamente fino a quando non inizierà a ruotare su sé stessa.



**Come funziona?**

È stato aggiunto un parametro di potenza di rotazione ``rot`` alla funzione di movimento ``carMove()`` della Zeus Car.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: La direzione in cui vuoi far muovere l’auto. La testa dell’auto è considerata 0 gradi e l’angolo aumenta in senso antiorario.
* ``power``: La potenza di movimento, con un intervallo compreso tra -100% e 100%. Se ``power`` è positivo, l’auto si muove in avanti; se negativo, si muove all’indietro.
* ``rot``: La potenza di rotazione, con un intervallo compreso tra -100% e 100%. Se ``rot`` è positivo, l’auto ruoterà in senso antiorario; se negativo, ruoterà in senso orario.

Se ``power`` è 0 e ``rot`` ha un valore diverso da 0, la Zeus Car ruoterà sul posto. Maggiore è il valore di ``rot``, maggiore sarà la velocità di rotazione. Se ``rot`` è positivo, l’auto ruoterà in senso antiorario, altrimenti in senso orario.

Se ``power`` ha un valore diverso da 0, la Zeus Car si muoverà lungo un arco. L’angolo di sterzata aumenterà con l’aumentare di ``rot`` e, se il valore è abbastanza alto, l’auto inizierà a ruotare su sé stessa.
