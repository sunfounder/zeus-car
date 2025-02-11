.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

Carte Adaptatrice pour Caméra
================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST** : Permet de réinitialiser l’ESP32-CAM.
* **SCL** : Broche de données série du QMC6310.
* **SDA** : Broche d’horloge série du QMC6310.
* **RXD** : RXD de l’ESP32-CAM. Il est nécessaire d’utiliser ces deux broches série, RXD et TXD, pour télécharger du code sur l’ESP32-CAM.
* **TXD** : TXD de l’ESP32-CAM.
* **5V** : Entrée d’alimentation en courant continu 5V.
* **GND** : Entrée de mise à la masse.

La carte adaptatrice pour caméra, comme son nom l’indique, est une carte d’extension pour l’ESP32-CAM. Elle permet de fixer l’ESP32-CAM sur un robot et de faciliter son câblage.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

De plus, le capteur géomagnétique QMC6310 étant sensible aux interférences des moteurs, nous l’avons placé sur cette carte adaptatrice afin de l’éloigner le plus possible des moteurs.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Caractéristiques**

* Tension de fonctionnement : 5V
* Modèle d’interface : ZH1.5, 7P
* Dimensions : 40mm x 27mm x 15mm
* Protocole de communication : UART et I²C

**Documents**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Schéma

.. image:: img/cam_adapter_sche.png


**À propos du QMC6310**

Le QMC6310 est un capteur magnétique triaxial intégrant des capteurs magnétiques et un circuit de conditionnement du signal ASIC sur une seule puce de silicium. Ce boîtier de type Land Grid Array (LGA) est conçu pour des applications telles que la boussole électronique, la rotation de cartes, les jeux et la navigation personnelle sur des appareils mobiles et portables.

Basé sur une technologie magnétorésistive de haute résolution, le QMC6310 est couplé à un ASIC convertisseur analogique-numérique 16 bits conçu sur mesure. Il offre des avantages tels qu’un faible bruit, une haute précision, une faible consommation d’énergie, une annulation d’offset et une compensation de température. Il permet une précision de cap boussole de 1° à 2°. L’interface série I²C facilite son intégration.

Le QMC6310 est conditionné dans un boîtier LGA de montage en surface mesurant 1.2 x 1.2 x 0.53 mm³ avec 8 broches.

* |link_qmc6310_datasheet|