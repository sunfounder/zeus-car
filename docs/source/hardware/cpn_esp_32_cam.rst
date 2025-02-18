.. note:: 

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e giveaway festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


ESP32-CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L'ESP32-CAM è un modulo fotocamera estremamente compatto con chip ESP32-S, disponibile a un prezzo di circa 10 dollari. Oltre alla fotocamera OV2640 e a diversi GPIO per la connessione di periferiche, è dotato di uno slot per schede microSD, utile per memorizzare le immagini scattate o per archiviare file da servire ai client.

Il modulo può funzionare in modo indipendente come il sistema più compatto, con dimensioni di soli 27×40,5×4,5 mm e un consumo energetico in modalità deep sleep fino a soli 6mA.

L'ESP32-CAM è ampiamente utilizzato in varie applicazioni IoT, risultando adatto per dispositivi smart domestici, controllo wireless industriale, monitoraggio remoto, identificazione wireless tramite QR code, sistemi di posizionamento e molte altre applicazioni nel settore IoT. È una soluzione ideale per progetti IoT.


**Specifiche Tecniche**

.. list-table::
    :widths: 25 50

    * - Modello del modulo
      - ESP32-CAM
    * - Package
      - DIP-16
    * - Dimensioni
      - 27×40,5×4,5 (±0,2) mm
    * - SPI Flash
      - Default 32Mbit
    * - RAM
      - Interna 520KB + Esterna 8MB PSRAM
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR e BLE standard
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfacce supportate
      - UART, SPI, I2C, PWM
    * - Supporto TF Card
      - Fino a 4GB
    * - Pin IO
      - 9
    * - Velocità porta seriale
      - Default 115200 bps
    * - Formati di output immagine
      - JPEG (solo con OV2640), BMP, GRAYSCALE
    * - Gamma di frequenza
      - 2400 ~ 2483,5MHz
    * - Tipo di antenna
      - Antenna PCB integrata, guadagno 2dBi
    * - Potenza di trasmissione
      - 802.11b: 17±2 dBm (@11Mbps)
    * - 
      - 802.11g: 14±2 dBm (@54Mbps)
    * - 
      - 802.11n: 13±2 dBm (@MCS7)
    * - Sensibilità di ricezione
      - CCK, 1 Mbps: -90dBm
    * - 
      - CCK, 11 Mbps: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK): -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM): -70dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps): -67dBm
    * - Consumo energetico
      - Flash spento: 180mA @5V
    * - 
      - Flash acceso alla massima luminosità: 310mA @5V
    * - 
      - Deep-sleep: consumo minimo fino a 6mA @5V
    * - 
      - Modern-sleep: minimo 20mA @5V
    * - 
      - Light-sleep: minimo 6,7mA @5V
    * - Sicurezza
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Intervallo di alimentazione
      - 4,75-5,25V
    * - Temperatura di esercizio
      - -20 ℃ ~ 70 ℃
    * - Ambiente di stoccaggio
      - -40 ℃ ~ 125 ℃ , < 90%RH


**Pinout ESP32-CAM**


La figura seguente mostra il pinout dell'ESP32-CAM (modulo AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Sono presenti tre **GND** e tre pin di alimentazione: 3.3V, 5V e una tensione selezionabile tra 3.3V o 5V.
* **GPIO 1** e **GPIO 3** sono i pin seriali, necessari per il caricamento del codice sulla scheda.
* Inoltre, **GPIO 0** è fondamentale poiché determina se l'ESP32 è in modalità flashing. Quando **GPIO 0** è connesso a **GND**, l'ESP32 entra in modalità flashing.

I seguenti pin sono internamente collegati al lettore di schede microSD:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Data 0
* GPIO 4: Data 1 (anche connesso al LED integrato)
* GPIO 12: Data 2
* GPIO 13: Data 3


**Nota**

* Assicurati che l'alimentazione del modulo sia almeno 5V 2A, altrimenti l'immagine potrebbe presentare delle strisce di disturbo.
* Il pin GPIO32 dell'ESP32 controlla l'alimentazione della fotocamera. Quando la fotocamera è in funzione, è necessario mantenere il GPIO32 basso.
* Poiché GPIO0 è collegato all’XCLK della fotocamera, si consiglia di lasciarlo non connesso quando in uso, senza collegarlo né ad alto né a basso livello.
* Il firmware predefinito è già incluso di fabbrica e non viene fornito per il download separato. Prestare attenzione se si desidera caricare un firmware alternativo.


**Documentazione**

* Schema elettrico: |link_esp32cam_schematic|
* Specifiche della fotocamera (versione in inglese): |link_cam_ov2640|

.. note::
    Tutte le informazioni sopra riportate provengono da |link_aithiner|
