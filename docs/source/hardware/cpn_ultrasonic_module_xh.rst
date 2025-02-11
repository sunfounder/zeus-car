.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

Module Ultrasonique
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG** : Entrée du signal de déclenchement
* **ECHO** : Sortie du signal d’écho
* **GND** : Masse
* **VCC** : Alimentation 5V

Il s'agit du capteur de distance ultrasonique HC-SR04, capable d'effectuer des mesures sans contact dans une plage de 2 cm à 400 cm, avec une précision allant jusqu'à 3 mm. Le module intègre un émetteur ultrasonique, un récepteur et un circuit de contrôle.

Seules 4 broches sont nécessaires pour l’utiliser : VCC (alimentation), TRIG (déclenchement), ECHO (réception) et GND (masse), ce qui le rend très simple à intégrer dans vos projets de mesure.

**Caractéristiques**

* Tension de fonctionnement : DC 5V
* Courant de fonctionnement : 16mA
* Fréquence de fonctionnement : 40Hz
* Portée maximale : 500 cm
* Portée minimale : 2 cm
* Signal d’entrée du déclencheur : impulsion TTL de 10 µs
* Signal de sortie d’écho : signal de niveau TTL proportionnel à la distance mesurée
* Connecteur : XH2.54-4P
* Dimensions : 46 x 20.5 x 15 mm

**Principe de Fonctionnement**

Le principe de mesure repose sur les étapes suivantes :

* Envoi d'un signal de déclenchement de 10 µs en niveau haut sur la broche TRIG.
* Le module émet ensuite une rafale de 8 cycles d’ultrasons à 40 kHz et attend la réception d'un signal réfléchi.
* Si un signal d’écho est détecté, la broche ECHO passe à l’état haut. La durée de ce signal correspond au temps écoulé entre l’émission et la réception de l’onde.
* La distance est calculée selon la formule :

    .. image:: img/ultrasonic_prin.jpg
        :width: 800

Formule : 

* us / 58 = distance en centimètres
* us / 148 = distance en pouces
* distance = (durée du signal haut x vitesse du son (340 m/s)) / 2

**Notes d’Application**

* Il est recommandé de ne pas connecter ce module sous tension. Si nécessaire, connectez d’abord la broche GND pour éviter d’éventuels dysfonctionnements.
* La surface de l’objet mesuré doit être d’au moins 0,5 m² et aussi plane que possible, afin d’assurer des mesures précises.
