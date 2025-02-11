.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

ESP32-CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

L’ESP32-CAM est un module caméra ultra-compact basé sur la puce ESP32-S, disponible pour environ 10 $. En plus de la caméra OV2640 et de plusieurs GPIO pour connecter des périphériques, il dispose d’un lecteur de carte microSD permettant de stocker des images capturées ou des fichiers destinés aux clients.

Le module peut fonctionner de manière autonome en tant que système minimal, avec des dimensions de seulement 27 × 40.5 × 4.5 mm et un courant de veille profonde aussi bas que 6 mA.

L’ESP32-CAM peut être utilisé dans de nombreuses applications IoT, telles que les appareils domestiques intelligents, le contrôle industriel sans fil, la surveillance sans fil, l’identification QR sans fil, le positionnement par signaux et d'autres applications IoT. Il constitue une solution idéale pour ces usages.

**Spécifications techniques**

.. list-table::
    :widths: 25 50

    * - Modèle du module
      - ESP32-CAM
    * - Boîtier
      - DIP-16
    * - Dimensions
      - 27 × 40.5 × 4.5 (±0.2) mm
    * - Mémoire Flash SPI
      - 32 Mbit par défaut
    * - RAM
      - 520 KB interne + 8 MB PSRAM externe
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR et BLE
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Interfaces prises en charge
      - UART, SPI, I²C, PWM
    * - Support de carte TF
      - Jusqu’à 4G
    * - Broches IO
      - 9
    * - Vitesse du port série
      - 115200 bps par défaut
    * - Formats de sortie d’image
      - JPEG (seulement OV2640), BMP, GRAYSCALE
    * - Plage de fréquence
      - 2400 ~ 2483.5 MHz
    * - Type d’antenne
      - Antenne PCB intégrée, gain de 2 dBi
    * - Puissance d’émission
      - 802.11b : 17 ± 2 dBm (@11Mbps)
    * - 
      - 802.11g : 14 ± 2 dBm (@54Mbps)
    * - 
      - 802.11n : 13 ± 2 dBm (@MCS7)
    * - Sensibilité de réception
      - CCK, 1 Mbps : -90 dBm
    * - 
      - CCK, 11 Mbps : -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK) : -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM) : -70 dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps) : -67 dBm
    * - Consommation électrique
      - Flash éteint : 180 mA @ 5V
    * - 
      - Flash allumé à luminosité maximale : 310 mA @ 5V
    * - 
      - Veille profonde : consommation minimale de 6 mA @ 5V
    * - 
      - Veille modem : minimum 20 mA @ 5V
    * - 
      - Veille légère : minimum 6.7 mA @ 5V
    * - Sécurité
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Plage d’alimentation
      - 4.75 - 5.25V
    * - Température de fonctionnement
      - -20 ℃ ~ 70 ℃
    * - Environnement de stockage
      - -40 ℃ ~ 125 ℃, < 90 % HR


**Schéma des broches de l’ESP32-CAM**

L’image suivante montre le schéma des broches de l’ESP32-CAM (module AI-Thinker).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Il y a trois broches **GND** et trois broches d’alimentation : 3.3V, 5V et une broche pouvant être soit 3.3V soit 5V.
* **GPIO 1** et **GPIO 3** sont les broches de communication série, nécessaires pour télécharger du code sur la carte.
* **GPIO 0** joue également un rôle clé, car il détermine si l’ESP32 est en mode de flashage. Lorsque **GPIO 0** est connecté à **GND**, l’ESP32 est en mode de flashage.

* Les broches suivantes sont connectées en interne au lecteur de carte microSD :

    * GPIO 14 : CLK
    * GPIO 15 : CMD
    * GPIO 2 : Data 0
    * GPIO 4 : Data 1 (également relié à la LED embarquée)
    * GPIO 12 : Data 2
    * GPIO 13 : Data 3

**Remarque**

* Assurez-vous que l’alimentation du module est d’au moins 5V 2A, sinon l’image peut contenir des lignes parasites.
* La broche GPIO32 de l’ESP32 contrôle l’alimentation de la caméra. Lorsque la caméra est en fonctionnement, tirez GPIO32 vers le bas.
* Comme GPIO0 est connecté à l’horloge XCLK de la caméra, il doit être laissé en l’air lorsqu’il est utilisé et ne doit pas être connecté à un niveau haut ou bas.
* Le firmware par défaut est déjà installé en usine et aucun téléchargement supplémentaire n’est fourni. Veuillez faire preuve de prudence si vous devez flasher un autre firmware.

**Documentation**

* Schéma électronique : |link_esp32cam_schematic|
* Spécifications de la caméra (version anglaise) : |link_cam_ov2640|

.. note::
    Toutes les informations ci-dessus proviennent de |link_aithiner|